#include <iostream>
#include <vector>
#include <string>
#include <io.h>
using namespace std;
struct _file{
	long name;
	long path;
};
inline void getfileall(string path,vector<string> &dirpath){
	struct _finddata_t fileinfo;    //_finddata_t是一个结构体，要用到#include <io.h>头文件；
	long ld;
	if ((ld = _findfirst((path+"\\*").c_str(), &fileinfo)) != -1l){
		do{
			if ((fileinfo.attrib&_A_SUBDIR)){  //如果是文件夹；
				if (strcmp(fileinfo.name, ".")!=0 && strcmp(fileinfo.name, "..")!=0){  //如果文件名不是.或者..则递归获取子文件中的文件；
					getfileall(path +"\\"+ fileinfo.name, dirpath);  //递归子文件夹；
				}
			}
			else   //如果是文件；
			{
				dirpath.push_back(path + "\\" + fileinfo.name);
				cout << path+"\\"+fileinfo.name << endl;//输出 
			}
		} while (_findnext(ld, &fileinfo) == 0);
		_findclose(ld);
	}
}

/*int main(){
	string  path = "C:\\Users\\Student\\Desktop";   //由于\是转义字符的起始字符，路径中要用\\，也可以只用一个/;
	vector<string> dirpath;     //保存文件的路径；
	getfileall(path, dirpath);  
	return 0;
}*/
