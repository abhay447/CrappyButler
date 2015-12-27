#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<fftw3.h>

/*===============================**
||I had very less idea about this||
||library and played with it till||
||started to work in my favour.  ||
||Most of the code is a          ||
||copy/paste from Stackoverflow  ||
**===============================*/
using namespace std;
int main(int argc,char* argv[])
{
	string file_name(argv[1]);
	string folder_path(argv[2]);
	ifstream myfile;
	myfile.open(file_name.c_str());
	float a;
	vector<float> b;
	while(!myfile.eof())
	{
		myfile>>a;
		b.push_back(a);
	}
	myfile.close();
	int N=pow(2,ceil((int)log2(b.size())));
	//int N=8192;
	//cout<<N;
	//fftw_complex out[N/2+1],in2[N]; /* double [2] */
	//double*       in  = static_cast<double*      >(fftw_malloc((N/2+1) * sizeof(double)));
	double out[N+1];//,in2[N];
	double in[N];
	fftw_plan p, q;
	for (int i = 0; i < N; i++)
	{
		if(i>b.size())
			in[i]=0;
		else
		    in[i] = b[i];
	}
	for (int i = 0; i < N+1; i++)
	{
		out[i]=0;
	}
	fftw_r2r_kind kind=FFTW_REDFT00;
//	kind = (fftw_r2r_kind)fftw_malloc(sizeof(fftw_r2r_kind));
	//p = fftw_plan_dft_r2c_1d(N, in, out,FFTW_ESTIMATE);
	p = fftw_plan_r2r_1d(N, in, out,FFTW_REDFT00,FFTW_ESTIMATE);
	fftw_execute(p);
	int FS=22100;
	string out_path=folder_path+"/fft/"+file_name+".fft";
	ofstream ofs;
	ofs.open(out_path.c_str(),ios_base::app);
	for (int i = 0; i < N+1; i++)
	{
		//cout<<i<<"  "<<((double)FS*i/(N/2+1))<<" : "<<sqrt(out[i][0]*out[i][0]+out[i][1]*out[i][1])<<endl;
		//ofs<<ceil((double)FS*i/(N/2+1))<<" "<<sqrt(out[i][0]*out[i][0])<<"\n";//+out[i][1]*out[i][1])<<"\n";
		ofs<<ceil((double)FS*i/(N+1))<<" "<<sqrt(out[i]*out[i])<<"\n";//+out[i][1]*out[i][1])<<"\n";
	}
	ofs.close();
	fftw_destroy_plan(p);

	return 0;
}
