#include <iostream>
#include <fstream>
#include <dirent.h>
#include "imageBatchProcess.h"

using namespace std;

int main(int argc,char *argv[])
{
    string imageFolderPath = "/home/stbook/hqy/image/features/BaojiTraffic1000/";
	string imageFolderPath_txt = "img_path.txt";
	string tempsuffix[] = {"bin","txt","fc6.binary"};
	vector<string> suffix(tempsuffix, tempsuffix+3);
    ImageBatchProcess path_dfs;
	ofstream filename; //write
	filename.open(imageFolderPath_txt.c_str());
	path_dfs.dfsFolder(imageFolderPath,filename,suffix);
	filename.close();
	return 0;
}

//linux shell : find /media/project/ > file.txt -path '*.jpg'
