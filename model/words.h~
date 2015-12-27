#ifndef words_H
#define words_H
#include <string>
#include <map>
#include <sstream>
#include <math.h>
using namespace std;

/*==================================REFERENCE=============================================**
||fftsq      -> moment around EVF above threshold divided by EVF and a factor             ||
||fftsq_mom  -> mel feature for EVF above threshold                                       ||
||fft        -> moment around mean frequency above threshold divided by axis and a factor ||
||fft_mom    -> mel feature for mean frequency                                            ||
||EVF        -> (sigma(Fi*Intensity^n)/sigma(Fi))^(1/n)                                   ||
||Mean Freq. -> sigma(Fi*Intensity)/sigma(Fi)                                             ||
||mel feature-> 1127.01048*log10 (1 + axis / 700)                                         ||
||P.S.--------> See bellfft.cpp in functions/fft/ to get an idea about implementation     ||
||P.P.S.------>I have to rename the variables to make more sense						  ||
**========================================================================================*/

class words
{
	string name;
	float fftsq,fftsq_sd;
    float fftsq_mom,fftsq_mom_sd;
    float fft,fft_sd;
    float fft_mom,fft_mom_sd;
	public:
		string getName(){return name;}

		float getfftsq(){return fftsq;}
        float getfftsq_sd(){return fftsq_sd;}
        float getfftsq_mom(){return fftsq_mom;}
        float getfftsq_mom_sd(){return fftsq_mom_sd;}
        float getfft(){return fft;}
        float getfft_sd(){return fft_sd;}
        float getfft_mom(){return fft_mom;}
        float getfft_mom_sd(){return fft_mom_sd;}

		float compareFftSq(float FFTSQ);
		float compareFftSqMom(float FFTSQMOM);
		float compareFft(float FFT);
		float compareFftMom(float FFTMOM);

		words(string Name,string line);
		words(string line);
};

words::words(string Name,string line)
{
	name=Name;
	istringstream iss(line);
	iss>>fftsq>>fftsq_sd>>fftsq_mom>>fftsq_mom_sd>>fft>>fft_sd>>fft_mom>>fft_mom_sd;
}

words::words(string line)
{
    istringstream iss(line);
    iss>>name>>fftsq>>fftsq_sd>>fftsq_mom>>fftsq_mom_sd>>fft>>fft_sd>>fft_mom>>fft_mom_sd;
}


//functions to compare certain values with features from loaded word
//check alfa results in roughComp.cpp for implementations
float words::compareFftSq(float FFTSQ)
{
    return fabs(FFTSQ-fftsq);
}

float words::compareFftSqMom(float FFTSQMOM)
{
    return fabs(FFTSQMOM-fftsq_mom);
}

float words::compareFft(float FFT)
{
    return fabs(FFT-fft);
}

float words::compareFftMom(float FFTMOM)
{
    return fabs(FFTMOM-fft_mom);
}

#endif
