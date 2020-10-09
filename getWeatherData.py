import requests
apiKey = open('api-key','r').readline().rstrip()
url = "http://api.openweathermap.org/data/2.5/weather?id=1283240&appid="+apiKey+"&units=metric&lat=27.7654&long=85.3653"

response = requests.request("GET", url)

data = response.json()
temp = str(data['main']['temp'])
weather = str(data['weather'][0]['main'])
humidity = str(data['main']['humidity'])
weatherDesc = str(data['weather'][0]['description'])
print("KTM "+temp+"C "+weather+"~"+humidity+"% "+weatherDesc)
