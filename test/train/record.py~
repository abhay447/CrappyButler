import alsaaudio, wave, numpy,time

inp = alsaaudio.PCM(alsaaudio.PCM_CAPTURE)
inp.setchannels(1)
inp.setrate(22100)
inp.setformat(alsaaudio.PCM_FORMAT_S16_LE)
inp.setperiodsize(1024)

duration=3

w = wave.open('test.wav', 'w')
w.setnchannels(1)
w.setsampwidth(2)
w.setframerate(22100)

start_time=time.time()
while True:
	l, data = inp.read()
	a = numpy.fromstring(data, dtype='int16')
#	print numpy.abs(a).mean()
	w.writeframes(data)
	if time.time()-start_time>duration:
		break
