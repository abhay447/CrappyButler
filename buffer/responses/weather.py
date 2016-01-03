import pyttsx,pyowm
engine = pyttsx.init()
rate = engine.getProperty('rate')
engine.setProperty('rate', rate-50)
engine.say('Searching for weather data in varanasi.')
engine.say('Please wait for processing of request')

owm = pyowm.OWM('f7de1c2dbbc5ee27502aa0043ebcda36')
observation = owm.weather_at_place('Varanasi')
w = observation.get_weather()
condition = w.get_status()
min_temp = w.get_temperature('celsius')['temp_min']
max_temp = w.get_temperature('celsius')['temp_max']
humidity = w.get_humidity()
wind_speed=w.get_wind()['speed']

weather_notes = "Weather now is "+str(condition)+" with "+str(humidity)+" percent humidity"
weather_notes += "\n. The temperature is expected to lie between "+str(min_temp)+" and "+str(max_temp)+" degree celsius"
weather_notes += ", with a wind speed of "+str(wind_speed)+" meters per second"
weather_notes += "\n. Have a nice day sir"
engine.say(weather_notes)
engine.runAndWait()

