#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string.h>
#include <boost/algorithm/string/replace.hpp>
using namespace boost;
using namespace std;
int main(int argc,char* argv[])
{
	string file_name(argv[1]);
	string folder_path(argv[2]);
	ifstream myfile;
	myfile.open(file_name.c_str());
	double  a,mean,t,var,stddev,temp=0,cover_time=1;
	vector<double> b;
	int segments=0,FREQUENCY=22100;
	while(!myfile.eof())
	{
		myfile>>a;
		b.push_back(a);
	}
	myfile.close();

	mean=accumulate(b.begin(), b.end(), 0.0000)/b.size();
	for(double t :b)
            temp += (mean-t)*(mean-t);
	var=temp/b.size();
	stddev=sqrt(var);
	//cout<<mean<<endl;
	//cout<<stddev<<endl;

	int step=FREQUENCY*cover_time;
	int i=0;
	int flag=0;
	while(i<b.size())
	{
		float mymean,myvar,mytemp=0,mydev;
		mymean=accumulate(b.begin()+i, b.begin()+i+step, 0.0000)/step;
	    for(int j=i;j<i+step;j++)
            mytemp += (mymean-b[j])*(mymean-b[j]);
	    myvar=mytemp/step;
	    mydev=sqrt(myvar);

		if((mymean+mydev)<(mean+stddev) || (mymean-mydev)>(mean-stddev))
			flag++;
		else
		{
			if(flag!=0)
			{
				segments++;
			}
			else
			{	
				replace_all(folder_path,"train","result");
				ofstream outfile;
				string buffer=folder_path+"/"+file_name;//+to_string(segments);
				buffer+=".txt";
				outfile.open(buffer,ios_base::app);
				for(int j=i;j<i+step;j++)
		            outfile<<b[j]<<"\n";
				outfile.close();
			}
			flag=0;
		}
		i+=step/8;
	}
	//cout<<segments;
	return 0;
}
