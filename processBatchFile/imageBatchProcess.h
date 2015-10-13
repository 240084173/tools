#ifndef IMAGEBATCHPROCESS_H
#define IMAGEBATCHPROCESS_H

#include <fstream>
#include <vector>
using namespace std;

class ImageBatchProcess
{
public:
	ImageBatchProcess();
	~ImageBatchProcess();

	int dfsFolder(string folderPath, ofstream &fout,vector<string> suffix);
};

#endif
