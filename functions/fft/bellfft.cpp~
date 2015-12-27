#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<math.h>
#include<map>

/*==========================**
||Read this file along with ||
||model/words.h for better  ||
||understanding             ||
||amplitude refers to       ||
||intensity of a frequency  || 
**==========================*/

using namespace std;
int main(int argc,char* argv[])
{
	ifstream ifs(argv[1]);
	string folder_path(argv[2]);
	string line;
	map<float,float> mymap;
	while(getline(ifs,line))
	{
		istringstream iss(line);
		float frequency,amplitude;
		while(iss>>frequency>>amplitude)
			mymap.insert(pair<float,float>(amplitude,frequency));
			/*------Amplitude first for Easy thresholding------*/
	}

	//Threshold of 96.5%, filter out frequencies below threshold//
	float threshold=0.999;
	map<float,float>::iterator it;
	it=mymap.begin();
    advance(it,mymap.size()*threshold);

	//Considering frequency to be x and frequencies to be mass--//
	//taking calculations in powers 1 and 2-------------------//
	double mixi=0,mixisq=0,mi=0,moment=0,axis;
	for (; it!=mymap.end(); ++it)
	{
		mixisq+=it->first*it->second*it->second*it->second*it->second;
		mixi+=it->first*it->second;
		mi+=it->first;
	}

	//output file to write individual training data ---------//
	string out_path=folder_path+"/array_fft.xyz";
	ofstream ofs;
    ofs.open(out_path.c_str(),ios_base::app);


	//Power 4 Calculations-----------------------------------//
	axis=pow((mixisq/mi),1.0/4.0);
	it=mymap.begin();
    advance(it,mymap.size()*threshold);
    double base=it->first;
    for (; it!=mymap.end(); ++it)
    {
		double r=axis-it->second;
        moment+=(it->first-base)*r*r;
    }
    float mel = 1127.01048*log10 (1 + axis / 700);
	//cout<<axis<<"==>"<<log10(moment)<<endl;
	ofs<<moment/pow(10,9)<<" "<<mel<<" ";//log10(fabs(moment))<<" ";

	//Power 1 Calculations-----------------------------------//
	axis=(mixi/mi);
	moment=0;
    it=mymap.begin();
    advance(it,mymap.size()*threshold);
    base=it->first;
    for (; it!=mymap.end(); ++it)
    {
        double r=axis-it->second;
        moment+=(it->first-base)*r*r;
    }
    //cout<<axis<<"==>"<<log10(moment)<<endl;
	ofs<<moment/pow(10,9)<<" "<<1127.01048*log10 (1 + axis / 700)<<endl;//log10(fabs(moment))<<endl;
	ofs.close();
	return 0;
}
