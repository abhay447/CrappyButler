#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string.h>
#include "model/words.h"
using namespace std;


/*=============================**
||The following function loads ||
||the coefficients for alfa    ||
||result calculation.		   ||
||See generateCoefficients.cpp ||
**=============================*/

map<string,double> ResultFactors()
{
    map<string,double> factors;
	string name;
	double value;
    string file_path("coefficients.cof");
    ifstream ifs;
    ifs.open(file_path.c_str());
    string line;
    while(getline(ifs,line))
    {
		istringstream iss(line);
		iss>>name>>value;
		factors[name]=value;
    }
    return factors;
}

/*=============================**
||The following function loads ||
||the feature-data of all words||
||in training set.             ||
**=============================*/

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

/*=============================**
||The following function loads ||
||the feature-data generated   ||
||by spoken word.			   ||
**=============================*/
words loadTest()
{
	string file_path("test/result/results.rst");
	ifstream ifs;
	ifs.open(file_path.c_str());
	string line;
	string test_name("test");
	getline(ifs,line);
	words WORD(test_name,line);
	return WORD;
}

int main()
{
	vector<words>      allwords;
	allwords        =  loadDB();
	words testWord  =  loadTest();
	vector<string>     roughMatches;
	map<string,double> Coefficients;
	map<string,double> alfaResult;
	map<string,double> betaResult;
	map<string,double> gammaResult;
	map<double,string> FinalResult;
	float              sigmaAlfa=0.0,sigmaBeta=0.0,sigmaGamma=0.0;

	Coefficients	= ResultFactors();

	for(int i=0; i<allwords.size(); i++)
	{
		float alfa=0.0,beta=0.0,beta1=0.0,beta2=0.0,gamma=0.0;
		float spreadSq,spread;

		/*=============================**
		||Alfa result is weighted sum  ||
		||distance from mean for each  ||
		||to the power minus one       ||
		**=============================*/

		float FftSqRes    = allwords[i].compareFftSq(testWord.getfftsq());
		if(FftSqRes>0)
			alfa += (Coefficients["FftSq"])*FftSqRes;

		float FftSqMomRes = allwords[i].compareFftSqMom(testWord.getfftsq_mom());
		if(FftSqMomRes>0)
			alfa += (Coefficients["FftSqMom"])*FftSqMomRes;

		float FftRes      = allwords[i].compareFft(testWord.getfft());
		if(FftRes>0)
			alfa += (Coefficients["Fft"])*FftRes;

		/*float FftMomRes   = allwords[i].compareFftMom(testWord.getfft_mom());
		if(FftMomRes>0)
			alfa += Coefficients["FftMom"]*FftMomRes;*/

		beta1 += fabs(allwords[i].getfftsq_mom() - testWord.getfftsq_mom()) ;
		beta2 += fabs(allwords[i].getfft_mom() - testWord.getfft_mom());

		/*beta1 += fabs(allwords[i].getfftsq_mom() - testWord.getfftsq_mom()) ;
		beta2 += fabs(allwords[i].getfft_mom()   - testWord.getfft_mom());*/

		/*=============================**
		||The Beta and Gamma results   ||
		||also work on distance from   ||
		||mean approach on mel features||
		**=============================*/


		alfaResult[allwords[i].getName()]   = 1/alfa;
		betaResult[allwords[i].getName()]   = 1/(beta2);
		gammaResult[allwords[i].getName()]  = 1/(beta1);

		sigmaAlfa  += 1/alfa;
		sigmaBeta  += 1/(beta2);
		sigmaGamma += 1/(beta1);
	}

	cout<<"===============ALFA  RESULT================="<<endl;
	for(int i=0; i<allwords.size(); i++)
	{
		cout<<allwords[i].getName()<<"= = = = = "<< alfaResult[allwords[i].getName()]<<endl;
	}

	cout<<"===============BETA  RESULT================="<<endl;
	for(int i=0; i<allwords.size(); i++)
	{
		cout<<allwords[i].getName()<<"= = = = = "<< betaResult[allwords[i].getName()]<<endl;
	}

	cout<<"===============GAMMA RESULT================="<<endl;
	for(int i=0; i<allwords.size(); i++)
	{
		cout<<allwords[i].getName()<<"= = = = = "<< gammaResult[allwords[i].getName()]<<endl;
	}

	cout<<"==========================================="<<endl;
	for(int i=0; i<allwords.size(); i++)
	{
		double net = 1.0;
		if(sigmaAlfa!=0)
			net +=  pow((alfaResult[allwords[i].getName()]  / sigmaAlfa),1.0)     * 1.00;
		if(sigmaBeta!=0)
			net +=  pow((betaResult[allwords[i].getName()]  / sigmaBeta),0.5)     * 2.00;
		if(sigmaGamma!=0)
			net +=  pow((gammaResult[allwords[i].getName()]  / sigmaGamma),1.5)   * 0.00;
		cout<<allwords[i].getName()<<"= = = = = "<< net <<endl;
		FinalResult[net]=allwords[i].getName();
	}

	map<double,string>::iterator it;
	it = FinalResult.begin();
	advance(it,FinalResult.size()-1);
	cout<< it->second<<endl;
	return 0;
}
