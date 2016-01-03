from lxml import html
import pyttsx, requests, datetime, time, os

myTime = datetime.datetime.now().time()
myTime = str(myTime).split(":")

engine = pyttsx.init()
rate = engine.getProperty('rate')
engine.setProperty('rate', rate-50)
engine.say('Please wait while we gather news headlines from D D news for '+myTime[0]+' '+myTime[1]+' hours')
engine.runAndWait()

main_page = requests.get("http://ddinews.gov.in/Home%20-%20Headlines/Pages/Default.aspx")
main_tree = html.fromstring(main_page.text)
LINKS=main_tree.xpath('//div[@class="storyHeadlines"]/div[1]/span[1]/a/@href')
HEADLINES = []

for link in LINKS:
	sub_page = requests.get(link)
	sub_tree = html.fromstring(sub_page.text)
	headline = sub_tree.xpath('//div[@id="ctl00_PlaceHolderMain__migidNDescription__ControlWrapper_RichHtmlField"]/text()')
	headline = "".join(headline)
	headline.replace(r"\r\n","")
	headline.replace(r"\n","")
	HEADLINES.append(headline)
	os.system('aplay buffer/responses/beep-04.wav >/dev/null 2>&1')
	engine.say(headline)
	#print headline
	
engine.setProperty('rate', rate)
engine.say("Thats all for now, Haastalavista Baby.")
engine.say(" ")
engine.runAndWait()


