#include <iostream>
#include <fstream>
#include <dirent.h>
#include "imagebatchprocess.h"

using namespace std;
using namespace cv;

int main(int argc,char *argv[])
{
    string imageFolderPath = "/media/project/deeplearning/data/Challenge2_Training_Task12_Images/";
	string imageFolderPath_txt = "img_path.txt";
	string tempsuffix[] = {"jpg","png","bmp"};
	vector<string> suffix(tempsuffix, tempsuffix+3);
    ImageBatchProcess path_dfs;
	ofstream filename; //write
	filename.open(imageFolderPath_txt.c_str());
	path_dfs.dfsFolder(imageFolderPath,filename,suffix);
	filename.close();
	return 0;
}
