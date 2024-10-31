#include <iostream>
#include <vector>
#include <string>
#include <io.h>
#include <fstream>
using namespace std;
struct _file;
struct _list{
	_file *addr;
	_list *front;
	_list *next;
};
struct _file{
	string name;
	string path;
	int num;
	_list *son;
	_file *father;
};
string rename(string &path){
	if(path[path.length()-1]=='\\'){
		path[path.length()-1]=path[path.length()-2]='\0';
	}
	char ch='\\';
	char str[path.length()];
	strcpy(str,path.data());
	int t = strlen(str);
	char *pch = strrchr(str,ch);
	if(pch==NULL) return path;
	int h = pch - str;
	string _str;
	for(int i=h+1;i<t;i++){
		_str+=path[i];
	}
	return _str;
}
inline void getfileall(string path,vector<string> &dirpath,_list *father,_file *f){
	struct _finddata_t fileinfo;    //_finddata_t是一个结构体，要用到#include <io.h>头文件；
	struct _file *h=NULL,*q=NULL,*o=NULL;
	struct _list *p=NULL,*k=NULL;
	h = new _file;
	h->path = path;
	h->name = rename(path);
	h->num = 0;
	father->addr = h;
	long ld;
	if ((ld = _findfirst((path+"\\*").c_str(), &fileinfo)) != -1l){
		do{
			h->num++;
			h->father = f;
			if ((fileinfo.attrib&_A_SUBDIR)){  //如果是文件夹；
				if (strcmp(fileinfo.name, ".")!=0 && strcmp(fileinfo.name, "..")!=0){  //如果文件名不是.或者..则递归获取子文件中的文件；
					p = new _list;
					if(h->num==0){
						h->son = p;
						p->front = NULL;
						//cout<<"!"<<k->addr->path<<endl;
					}else{
						p->front = k;
						//cout<<"!!"<<k->addr->path<<endl;
						k->next = p;
					}
					p->next = NULL;
					k = p;
					getfileall(path +"\\"+ fileinfo.name, dirpath,p,h);  //递归子文件夹；
				}else{
					h->num--;
				}
			}
			else   //如果是文件；
			{
				dirpath.push_back(path + "\\" + fileinfo.name);
				cout << path+"\\"+fileinfo.name << endl;//输出 
				q = new _file;
				q->father = h;
				q->name = fileinfo.name;
				q->path = path+"\\"+fileinfo.name;
				q->son = NULL;
				q->father = h;
				q->num = 0;
				p = new _list;
				p->addr = q;
				if(h->num==0){
					h->son = p;
					p->front = NULL;
				}else{
					p->front = k;
					//k->next = p;
				}
				p->next = NULL;
				k = p;
			}
		} while (_findnext(ld, &fileinfo) == 0);
		_findclose(ld);
	}
	//cout<<f->num<<endl;
}

inline void delfileall(_file *f){
	//_file *p=NULL,*q=NULL;
	_list *k=NULL;
	if(f->num>=0){
		k = f->son;
		for(int i=1;i<=f->num;i++){
			delfileall(k->addr);
			k = k->next;
		}
	}
	delete f->son;
	delete f;
}

string en(string _name){
	char ch='.';
	char str[_name.length()];
	strcpy(str,_name.data());
	int t = strlen(str);
	char *pch = strrchr(str,ch);
	if(pch==NULL) return "\0";
	int h = pch - str;
	string _str;
	for(int i=h+1;i<t;i++){
		_str+=_name[i];
	}
	return _str;
}
string na(string _name){
	char ch='.';
	char str[_name.length()];
	strcpy(str,_name.data());
	int t = strlen(str);
	char *pch = strrchr(str,ch);
	if(pch==NULL) return "\0";
	int h = pch - str;
	string _str;
	for(int i=0;i<h-1;i++){
		_str+=_name[i];
	}
	return _str;
}

void jun(string path,string _name,string ob,string op){
	if(ob=="*"){
		if(op=="print"){
			cout<<path<<endl;
		}
	}
	if(na(ob)=="*"){
		if(en(_name)==en(ob)){
			if(op=="del"){
				string str="del "+path;
				char str2[str.length()];
				strcpy(str2,str.data());
				system(str2);
			}
			if(op=="search"){
				string s;
				cin>>s;
				s = "findstr " + s + " " + path;
				char str[s.length()];
				strcpy(str,s.data());
				system(str);
			}
		}
	}
	return;
}

inline void searchfileall(_file *f,string ob,string op){
	_list *k=NULL;
	if(f->num>0){
		k = f->son;
		for(int i=1;i<=f->num;i++){
			searchfileall(k->addr,ob,op);
			k = k->next;
		}
	}
	cout<<f->num<<endl;
	jun(f->path,f->name,ob,op);
}

/*int main(){
	string  path = "C:\\Users\\Student\\Desktop";   //由于\是转义字符的起始字符，路径中要用\\，也可以只用一个/;
	vector<string> dirpath;     //保存文件的路径；
	getfileall(path, dirpath);  
	return 0;
}*/
