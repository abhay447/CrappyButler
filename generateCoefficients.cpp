#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string.h>
#include "model/words.h"
using namespace std;

/*==================================**
|| This program is used to 			||
|| generate coefficients for		||
|| alfa results in roughCom.cpp	    ||
**==================================*/

vector<words> loadDB()
{
	vector<words> mywords;		//word data vector
	string file_path("words.tbl");
	ifstream ifs;
	ifs.open(file_path.c_str());
	string line;
	while(getline(ifs,line))
	{
		words WORD(line);
		mywords.push_back(WORD);
	}
	return mywords;
}


int main()
{
	vector<words> allwords;
	allwords=loadDB();

	double FftSqError = 0.0, FftSqMomError = 0.0;
	double FftError   = 0.0, FftMomError   = 0.0;
	double netError   = 0.0;

	/*=============================**
	||Coefficients are calculated  ||
	||by their respective weights  ||
	||in net error.				   ||
	**=============================*/

	for(int i = 0; i < allwords.size(); i++)
	{
		FftSqError    += pow(10, allwords[i].getfftsq_sd());
        FftSqMomError += pow(10, allwords[i].getfftsq_mom_sd());
        FftError      += pow(10, allwords[i].getfft_sd());
        FftMomError   += pow(10, allwords[i].getfft_mom_sd());
	}

	netError = FftSqError + FftError;

	ofstream ofs;
	ofs.open("coefficients.cof");
	{
		ofs<<"FftSq "    << netError/FftSqError    << endl;
		ofs<<"FftSqMom " << netError/FftSqMomError << endl;
		ofs<<"Fft "      << netError/FftError      << endl;
		ofs<<"FftMom "   << netError/FftMomError   << endl;
	}
	ofs.close();

	return 0;
}
