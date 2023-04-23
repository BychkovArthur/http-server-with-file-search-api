from django.http import JsonResponse
from django.views.decorators.csrf import csrf_exempt
from .file_api import FileSearch


@csrf_exempt
def post(request):
    if request.method == 'POST':
        '''Указываем директорию, в которой будем делать поиск. Реализовал так, как сказано в задании, но мне кажется, 
        лучше бы было, если бы эта директория поступала в POST запросе'''
        request_to_api = FileSearch(request, 'C:\\Users\\Artur\\Desktop\\kaspersky_tests')
        request_to_api.search_file()
        return JsonResponse({"search_id": request_to_api.search_id})


def get(request, search_id):
    search_id = str(search_id)
    if request.method == 'GET':
        if search_id in FileSearch.REQUEST_ID:
            return JsonResponse(FileSearch.REQUEST_ID[search_id])
        else:
            raise KeyError('Не существует запроса с таким id')
