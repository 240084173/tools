#include "imageBatchProcess.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

ImageBatchProcess::ImageBatchProcess()
{
	
}

ImageBatchProcess::~ImageBatchProcess()
{
}

int ImageBatchProcess::dfsFolder(string folderPath, ofstream &fout,vector<string> suffix)
{
	DIR *pDir;
	struct dirent *file;
	struct stat sb;

	//cout<<folderPath.c_str()<<endl;
	if(!(pDir = opendir(folderPath.c_str())))
	{
		cout<<"error"<<endl;
		return -1;
	}

	while((file = readdir(pDir)) != NULL)
	{
	    if(strcmp(file->d_name,".")==0 || strcmp(file->d_name,"..")==0)
			continue;

		if(file->d_type & DT_DIR)
		{
			dfsFolder(folderPath+file->d_name+"/",fout,suffix);
		}
		else
		{
			for (vector<string>::iterator it=suffix.begin();it!=suffix.end();it++)
			{
				string temp=file->d_name;
				//cout<<temp.substr(temp.size()-(*it).size(),(*it).size())<<endl;
				if (temp.substr(temp.size()-(*it).size(),(*it).size())==(*it))
				{
					fout<<folderPath+file->d_name<<endl;
					//cout<<folderPath+file->d_name<<endl;
				}
			}
		}
	}
	return 0;
}

