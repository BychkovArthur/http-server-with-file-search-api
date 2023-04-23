# http-server-with-file-search-api

* Для работы сервера и запросов нужно установить Django и requests
* .\kaspersky project\kaspersky_test_task\file_finder\file_api.py - само API
* В папке kaspersky_tests находятся файлы для теста запроса к серверу

Было реализовано доп задание по поиску файлов внутри архивов (не вложенных)

Чтобы проверить работу запросов нужно изменить пути до файлов в kaspersky_tests (которые на вашей локальной машине). В тест с проверкой даты нужно поместить файл с давней датой создания (т.к. при скачке дата создания файла может обновиться и тест будет работать некорректо, вам нужно вместо файли cpp3.cpp поместить какой-нибудь файлик с датой создании, раньше чем указанная в POST-запросе).

Так же, в задании указано: "Сервер должен осуществлять поиск только внутри определённой директории. Такая директория может задаваться аргументом при запуске сервера.", 
это делается во views.py

Чтобы запустить сервер: В папке kaspersky_test_task запустить сервер командой: python manage.py runserver (должен быть установлен django и requests)

Чтобы отправить тестовые запросы к серверу просто запустить test_server.py
