#include <dirent.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string.h>
#include "model/words.h"
using namespace std;
int main()
{
	vector<words> mywords;		//word data vector
	//folder read operations for loading the vector//
    const char* PATH = "./result/";
    DIR *dir = opendir(PATH);
    struct dirent *entry = readdir(dir);
    while (entry != NULL)
    {
        if (entry->d_type == DT_DIR)
		{
			try
			{
				string name(entry->d_name);
				string file_path;
				file_path="./result/"+name+"/results.rst";
				ifstream ifs;
				ifs.open(file_path.c_str());
				string line;
				getline(ifs,line);
				if(line!="")
				{
					words WORD(name,line);
					mywords.push_back(WORD);
				}
			}
			catch(invalid_argument& e)
			{
				cout<<"error captured"<<endl;
				throw 20;
			}
		}
        entry = readdir(dir);
    }
    closedir(dir);
	//folder read and words vector loading completed//
	//write the vector to the word table file//
	ofstream ofs;
	ofs.open("words.tbl");
	for(int i=0;i<mywords.size();i++)
	{
		ofs<<mywords[i].getName()<<" "<<\
		mywords[i].getfftsq()<<" "<<mywords[i].getfftsq_sd()<<" "<<\
		mywords[i].getfftsq_mom()<<" "<<mywords[i].getfftsq_mom_sd()<<" "<<\
		mywords[i].getfft()<<" "<<mywords[i].getfft_sd()<<" "<<\
		mywords[i].getfft_mom()<<" "<<mywords[i].getfft_mom_sd()<<endl;
	}
	ofs.close();
    return 0;
}
