# CrappyButler
A simple voice activated digital assitant with a limited vocabulary for linux platform.<br />
For now the word classification process is quite slow but we are trying to improve it.<br />
Dependencies:<br />
1)Alsa<br />
2)fftw3<br />
You may also need an openweathermap api key for weather data<br />

#Steps:<br />
1)Go the recordings directory and record multiple recordings for the same word.
This should generate a number of pcm files.<br /> Cut all the pcms and make a new 
folder in train with the name same as the word to be trained.<br />
2)Repeat step 1 for different words.<br />
3)Run ./trainer.sh,this trains your model.<br />
4)Run ./validator.sh ,this script validates the accuracy of classification.<br />
It prints how accurately it can classify a word.The list printed is in 
alphabetic order.<br />
5)Go to buffer/responses/weather.py and insert your openweathermaps api key.<br />
6)Edit speaker.sh for command bindings.<br />
7)Sit back and run speaker.sh and command the butler.<br />
Optional:Bind speaker.sh to a keyboard shortcut

