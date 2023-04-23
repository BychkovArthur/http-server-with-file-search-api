import requests


def send_post_request(body):
	BASE_URL = 'http://127.0.0.1:8000'
	headers = {"Content-Type": "application/json"}
	response = requests.post(f"{BASE_URL}/search/", data=body, headers=headers)
	return response.json()


def send_get_request(search_id):
	BASE_URL = 'http://127.0.0.1:8000'
	return requests.get(f"{BASE_URL}/searches/{search_id}/").json()
