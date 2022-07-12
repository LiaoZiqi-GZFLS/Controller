#include<iostream>
#include<vector>
#include<string.h>
#include<io.h>
//#include<fstream>
using namespace std;
struct _file{
	string name;
	string path;
	int num;
	_file *up;
	_file *down;
	_file *left;
	_file *right;
};
void initfile(_file *ob){
	ob->up =NULL;
	ob->down = NULL;
	ob->left = NULL;
	ob->right = NULL;
	ob->num = 0;
	ob->path = "\0";
	ob->name = "\0"; 
	return;
}
void delfileall(_file *ob){
	if(ob==NULL) return;
	//cout<<"free: "<<ob->path<<endl;
	if(ob->down!=NULL){
		delfileall(ob->down);
	}
	if(ob->right!=NULL){
		delfileall(ob->right);
	}
	delete ob;
	return;
}
void printfileall(_file *ob){
	cout<<ob->path<<endl;
	if(ob->down!=NULL){
		printfileall(ob->down);
	}
	if(ob->right!=NULL){
		printfileall(ob->right);
	}
	return;
}
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
string repath(string &path){
	if(path[path.length()-1]=='\\'){
		path[path.length()-1]=path[path.length()-2]='\0';
	}
	char ch='\\';
	char str[path.length()];
	strcpy(str,path.data());
	int t = strlen(str);
	char *pch = strrchr(str,ch);
	if(pch==NULL) return "\0";
	int h = pch - str;
	string _str;
	for(int i=0;i<h;i++){
		_str+=path[i];
	}
	return _str;
}
string af(string _name){
	_name = rename(_name);
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
string fr(string _name){
	_name = rename(_name);
	char ch='.';
	char str[_name.length()];
	strcpy(str,_name.data());
	int t = strlen(str);
	char *pch = strrchr(str,ch);
	if(pch==NULL) return "\0";
	int h = pch - str;
	string _str;
	for(int i=0;i<h;i++){
		_str+=_name[i];
	}
	return _str;
}
bool jun(string _name, string ob){
	bool j=0,k=0,l=0;
	if(ob=="*") return 1;
	if(repath(ob)=="\0"){
		j=1;
	}else{
		if(repath(_name)==repath(ob)){
			j=1;
		}
	}
	if(rename(ob)=="*") return j;
	if(rename(ob)==rename(_name)) return j;
	if(fr(ob)=="*"){
		k=1;
	}else{
		if(fr(_name)==fr(ob)){
			k=1;
		}
	}
	if(af(ob)=="*"){
		l=1;
	}else{
		if(af(_name)==af(ob)){
			l=1;
		}
	}
	return j&&k&&l;
}
void strre(char (&ch)[50], string &str2){
	int i=0;
	while(str2[i]!='\0'){
		ch[i]=str2[i];
		i++;
		if(i>=50) return;
	}
	return;
}
void strclear(char (&ch)[50]){
	for(int i=0;i<50;i++){
		ch[i]='\0';
	}
	return;
}
void oper(string path, string op){
    char command[50];
    string s;
	strclear(command);
	if(op=="list"){
		cout<<path<<endl;
		strclear(command);
	}
	if(op=="type"){
		s="type "+path;
		strcpy(command,s.data());
	}
	if(op=="del"){
		s="del "+path;
		strcpy(command,s.data());
	}
	if(op=="print"){
		s="print "+path;
		strcpy(command,s.data());
	}
	if(op=="lookfor"){
		string str;
		cout<<"input(str):"<<endl;
		cin>>str;
		s="type "+path+" | findstr "+str;
		strcpy(command,s.data());
		//strcpy(command,s.data());
		//ifstream in("temp.txt");
		//ofstream out("temp.txt");
	}
	system(command);
	return;
}
void searchfileall(_file *f, string ob,string op){
	//cout<<"search: "<<f->path<<endl;
	if(f->down!=NULL){
		searchfileall(f->down, ob, op);
	}
	if(f->right!=NULL){
		searchfileall(f->right, ob, op);
	}
	if(jun(f->path,ob)){
		oper(f->path,op);
	}
	return;
}
inline void getfileall(string path,vector<string> &dirpath,_file *up,_file *left){
	struct _finddata_t fileinfo;    //_finddata_t是一个结构体，要用到#include <io.h>头文件；
	long ld;
	_file *p=NULL,*q=NULL,*k=NULL;
	p = new _file;
	p->name = rename(path);
	p->path = path;
	p->left = left;
	p->right = NULL;
	p->up = up;
	p->down = NULL;
	p->num = 0;
	if(up!=NULL&&up->down==NULL){
		up->down = p;
	}
	if(left!=NULL){
		left->right = p;
	}
	if ((ld = _findfirst((path+"\\*").c_str(), &fileinfo)) != -1l){
		do{
			p->num+=1;
			if ((fileinfo.attrib&_A_SUBDIR)){  //如果是文件夹；
				if (strcmp(fileinfo.name, ".")!=0 && strcmp(fileinfo.name, "..")!=0){  //如果文件名不是.或者..则递归获取子文件中的文件；
					getfileall(path +"\\"+ fileinfo.name, dirpath, p, k);  //递归子文件夹；
					if(k!=NULL){
						k = k->right;
					}else{
						k = p->down;
					}
				}else{
					p->num-=1;
				}
			}
			else   //如果是文件；
			{
				dirpath.push_back(path + "\\" + fileinfo.name);
				cout << path+"\\"+fileinfo.name << endl;//输出 
				q = new _file;
				q->name = fileinfo.name;
				q->path = path+"\\"+fileinfo.name;
				q->up = p;
				q->left = k;
				q->down = NULL;
				q->right = NULL;
				if(p!=NULL&&p->down==NULL){
					p->down = q;
				}
				if(k!=NULL){
					k->right = q;
				}
				k = q;
			}
		} while (_findnext(ld, &fileinfo) == 0);
		_findclose(ld);
	}
}

/*int main(){
	string  path = "C:\\Users\\Student\\Desktop";   //由于\是转义字符的起始字符，路径中要用\\，也可以只用一个/;
	vector<string> dirpath;     //保存文件的路径；
	getfileall(path, dirpath ,NULL,NULL);  
	return 0;
}*/
