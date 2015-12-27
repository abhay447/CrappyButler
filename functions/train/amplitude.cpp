#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<math.h>
using namespace  std;

/*==================================**
||This file reads 2 bytes at  a time||
||from a pcm file and writes a short||
||int per line in an amplitude file.||
**==================================*/

static std::vector<char> ReadAllBytes(string filename);

int main(int argc,char* argv[])
{
	string file_name(argv[1]);
	string folder_path(argv[2]);
	string in_path=folder_path+"/"+file_name;
	string out_path=folder_path+"/"+file_name+".txt";
	
	vector<char> filer=ReadAllBytes(in_path);
	double time=0,step=1/22100.0;
    ofstream ofs;
	ofs.open(out_path.c_str(),ios_base::app);
	for (int i = 0; i < filer.size(); i += 2)
	{
    int c = (filer[i+1] << 8) | filer[i];
    double t = c/32768.0;
	ofs<<t<<"\n";
    time+=step;
	}
	ofs.close();
	return 0;
}

static std::vector<char> ReadAllBytes(string filename)
{
    ifstream ifs(filename.c_str(), ios::binary|ios::ate);
    ifstream::pos_type pos = ifs.tellg();

    std::vector<char>  result(pos);

    ifs.seekg(0, ios::beg);
    ifs.read(&result[0], pos);

    return result;
}
