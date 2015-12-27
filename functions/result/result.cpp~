#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<string.h>
#include <boost/algorithm/string/replace.hpp>
using namespace boost;
using namespace std;

/*=======================================================**
||This files loads all values from array_fft.xyz         ||
||and writes the mean and standard deviation of features ||
||in results.rst                                         ||
**=======================================================*/
vector<float> getStats(vector<float> b)
{
	vector<float> result;
	float  mean,t,var,stddev,temp=0;
	mean=accumulate(b.begin(), b.end(), 0.0000)/b.size();
	for(float t :b)
            temp += (mean-t)*(mean-t);
	var=temp/b.size();
	stddev=sqrt(var);
	result.push_back(mean);
	if(stddev!=0)
		result.push_back(log10(stddev));
	else
		result.push_back(0);
	return result;
}

int main()
{
	string fft_file_name("fft/array_fft.xyz");
	string out_path("results.rst");
	string line;
	ifstream myFile;
	ofstream ofs;
	vector<float> result;
	ofs.open(out_path.c_str(),ios_base::app);
	vector<float> sq_vec,sq_mom_vec,lin_vec,lin_mom_vec;
	/* read fft features*/
	myFile.open(fft_file_name.c_str());
	//	clear vectors
	sq_vec.clear();
	sq_mom_vec.clear();
	lin_vec.clear();
	lin_mom_vec.clear();
	// cleared vectors
	while(getline(myFile,line))
	{
		istringstream iss(line);
		float sq,sq_mom,lin,lin_mom;
		while(iss>>sq>>sq_mom>>lin>>lin_mom)
		{
			sq_vec.push_back(sq);
			sq_mom_vec.push_back(sq_mom);
			lin_vec.push_back(lin);
			lin_mom_vec.push_back(lin_mom);
		}			
	}
	myFile.close();
	/*reading fft features finished*/
	/*write fft features*/
	result=getStats(sq_vec);
	ofs<<result[0]<<" "<<result[1]<<" ";
	result=getStats(sq_mom_vec);
	ofs<<result[0]<<" "<<result[1]<<" ";
	result=getStats(lin_vec);
	ofs<<result[0]<<" "<<result[1]<<" ";
	result=getStats(lin_mom_vec);
	ofs<<result[0]<<" "<<result[1]<<" ";
	/*writing fft features finished*/	
	ofs.close();
	return 0;
}
