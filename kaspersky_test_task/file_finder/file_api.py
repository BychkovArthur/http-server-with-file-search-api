import json
import os
import uuid
import datetime
import fnmatch
import zipfile


class FileSearch:
    REQUEST_ID = {}

    def __init__(self, request, root):
        body = json.loads(request.body)
        self.text = body.get('text')
        self.file_mask = body.get('file_mask')
        self.size = body.get('size')
        self.creation_time = body.get('creation_time')
        self.__set_uuid()
        self.root = root

    # Генерация уникального ключа
    def __set_uuid(self):
        self.search_id = str(uuid.uuid4())
        type(self).REQUEST_ID.update({self.search_id: {"finished": False}})

    # Операторы сравнение, что записаны словами, переведем в обычные операторы и выполним сравнение
    @staticmethod
    def compare(operator, value_1, value_2):
        if operator == 'eq':
            return value_1 == value_2
        elif operator == 'gt':
            return value_1 > value_2
        elif operator == 'lt':
            return value_1 < value_2
        elif operator == 'ge':
            return value_1 >= value_2
        elif operator == 'le':
            return value_1 <= value_2
        else:
            raise TypeError("Указан неверный оператор сравнения")

    def __check_size(self, file_size):
        return self.compare(self.size.get('operator'), file_size, self.size.get('value'))

    def __check_name(self, file):
        return fnmatch.fnmatch(file, self.file_mask)

    def __check_date(self, file_creation_time):
        request_datetime = datetime.datetime.strptime(self.creation_time.get('value'), '%Y-%m-%dT%H:%M:%S%z')  # Формат времени указанного в запросе в формате RFC3339 без милисекунд, т.к. в примере их не было
        request_datetime = datetime.datetime.timestamp(request_datetime)  # Преобразование в UNIX - время для удобного сравнения
        return self.compare(self.creation_time.get('operator'), file_creation_time, int(request_datetime))

    def __check_file_text(self, path):
        # Для того чтобы проверить вхождение текста в файл, откроем его в режиме чтения бинарного файла
        # Если возможно, декодируем его в кодировку UTF-8 и проверим, если ли подстрока в файле
        with open(path, "rb") as f:
            try:
                content = f.read().decode("utf-8")
            except UnicodeDecodeError:
                return False  # Пропускаем не текстовые файлы
            if self.text in content:
                return True

    def __check_file(self, path, file):
        file_creation_time = int(os.path.getctime(path))
        file_size = os.path.getsize(path)
        return self.__check_size(file_size) and self.__check_name(file) and self.__check_date(file_creation_time) and self.__check_file_text(path)

    def __archive_search(self, path):
        good_files = []
        with zipfile.ZipFile(path, 'r') as archive:
            for archive_file in archive.infolist():
                file_creation_time = datetime.datetime(*archive_file.date_time)  # Дата создания файла в архиве
                file_creation_time = int(datetime.datetime.timestamp(file_creation_time))  # Переводим в UNIX формат
                if self.__check_size(archive_file.file_size) and self.__check_name(archive_file.filename) and self.__check_date(file_creation_time):
                    with archive.open(archive_file.filename, 'r') as file:
                        try:
                            content = file.read().decode("utf-8")
                        except UnicodeDecodeError:
                            break
                        if self.text in content:
                            good_files.append(archive_file.filename)
        return good_files

    def search_file(self):
        paths = []
        for root, dirs, files in os.walk(self.root):
            for file in files:
                path = os.path.join(root, file)
                if file.endswith('.zip'):
                    paths += [path + '\\' + i for i in self.__archive_search(path)]
                if self.__check_file(path, file):
                    paths.append(path)
        type(self).REQUEST_ID[self.search_id] = {"finished": True, "paths": paths}  # Сообщаем, что поиск по данному uuid завершился
