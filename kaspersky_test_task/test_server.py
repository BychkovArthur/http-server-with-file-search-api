import unittest
from make_request import *
import json


class TestServer(unittest.TestCase):
    '''Здесь предложен набор тестов для запросов к серверу.
    Как сказано в задании, "Сервер должен осуществлять поиск только внутри определённой директории. Такая директория
    может задаваться аргументом при запуске сервера." Нужно указать верную директорию в файле views.py
    Эти тесты предложены для каталога kaspersky_tests'''

    def test_no_matching_files(self):
        '''Зададим условия, которые точно не будут соблюдаться, например, дату создания поставим 1 января 2025 года, а
        все остальные ограничения будут такими, чтобы каждый файл проходил'''
        body = {
            "text": "",
            "file_mask": "*",
            "size": {
                "value": -1,
                "operator": "ge"
            },
            "creation_time": {
                "value": "2025-01-01T00:00:00+00:00",
                "operator": "ge"
            }
        }
        body = json.dumps(body)
        self.assertEqual(send_get_request(send_post_request(body).get('search_id')), {'finished': True, 'paths': []})

    def test_some_matching_files(self):
        '''Сделаем запрос, при котором будут найдены несколько файлов.
        В данном случае, у меня 2 файла, в которых есть текст text, это "cpp3.cpp" и "test_case_2.txt"'''
        body = {
            "text": "text",
            "file_mask": "*",
            "size": {
                "value": -1,
                "operator": "ge"
            },
            "creation_time": {
                "value": "1970-04-23T00:00:00+03:00",
                "operator": "ge"
            }
        }
        body = json.dumps(body)
        self.assertEqual(send_get_request(send_post_request(body).get('search_id')), {'finished': True, 'paths': ['C:\\Users\\Artur\\Desktop\\kaspersky_tests\\cpp3.cpp', 'C:\\Users\\Artur\\Desktop\\kaspersky_tests\\test_case_2.txt']})

    def test_some_matching_files_2(self):
        '''Изменим входные данные предыдущего теста так, чтобы только файлы с датой позднее 23.04.2023 00:00 по UTC находились
        Файл "cpp3.cpp" создан 25 сентября 2022 г., 14:04:00
        Файл "test_file_case_2.txt" создан 23 апреля 2023 г., 11:07:32'''
        body = {
            "text": "text",
            "file_mask": "*",
            "size": {
                "value": -1,
                "operator": "ge"
            },
            "creation_time": {
                "value": "2023-04-23T00:00:00+00:00",
                "operator": "ge"
            }
        }
        body = json.dumps(body)
        self.assertEqual(send_get_request(send_post_request(body).get('search_id')), {'finished': True, 'paths': ['C:\\Users\\Artur\\Desktop\\kaspersky_tests\\test_case_2.txt']})

    def test_archive_files(self):
        '''Повторим запрос 2 теста, однако, добавив архив, в котором будет содержаться файл с текстом "abc"
        и будем искать именно этот текст. В этом случае у меня в каталоге есть 2 подходящих файла'''
        body = {
            "text": "abc",
            "file_mask": "*",
            "size": {
                "value": -1,
                "operator": "ge"
            },
            "creation_time": {
                "value": "1970-04-23T00:00:00+03:00",
                "operator": "ge"
            }
        }
        body = json.dumps(body)
        self.assertEqual(send_get_request(send_post_request(body).get('search_id')),
                            {'finished': True, 'paths': ['C:\\Users\\Artur\\Desktop\\kaspersky_tests\\cpp2.cpp',
                            'C:\\Users\\Artur\\Desktop\\kaspersky_tests\\test_archive.zip\\test_file_case_4.txt']})

    def test_file_mask_cpp(self):
        '''Найдем все файлы, которые начинаются на cpp, их содержимое, вес, дата создания не важны'''
        body = {
            "text": "",
            "file_mask": "cpp*",
            "size": {
                "value": -1,
                "operator": "ge"
            },
            "creation_time": {
                "value": "1970-04-23T00:00:00+03:00",
                "operator": "ge"
            }
        }
        body = json.dumps(body)
        self.assertEqual(send_get_request(send_post_request(body).get('search_id')),
                            {'finished': True, 'paths': ['C:\\Users\\Artur\\Desktop\\kaspersky_tests\\cpp 13.cpp',
                            'C:\\Users\\Artur\\Desktop\\kaspersky_tests\\cpp11.cpp',
                            'C:\\Users\\Artur\\Desktop\\kaspersky_tests\\cpp12.cpp',
                            'C:\\Users\\Artur\\Desktop\\kaspersky_tests\\cpp2.cpp',
                            'C:\\Users\\Artur\\Desktop\\kaspersky_tests\\cpp3.cpp']})


if __name__ == "__main__":
  unittest.main()
