#include<iostream>
#include <string.h>
#include "databox.h" 
#include "findfile.h"
#include "file.hpp"
using namespace std;
_list *head;
_file *h;
bool l=0;
void strre(char (&ch)[50], string &str2){
	int i=0;
	while(str2[i]!='\0'){
		ch[i]=str2[i];
		i++;
	}
	return;
}
void strre2(char (&ch)[50], string &str2){
	for(int i=0;i<50;i++){
		str2[i]=ch[i];
	}
	str2[49]='\0';
	return;
}
void strclear(char (&ch)[50]){
	for(int i=0;i<50;i++){
		ch[i]='\0';
	}
	return;
}
int main (){
   char command[50];
   char filename[50][50];
   int a;
   int num=0;
   string s;
   bool k;
   k=1;
   while(k){
	strclear(command);
   	gets(command);
   	s=command;
   	//strre2(command,s);
   	if(s=="help"){
   		cout<<"help:exit/cmd/databox/findfile/filelist/file/file+"<<endl;
   		cout<<"controller is made by GZFLS Lazybones LZQ"<<endl;
   		cout<<"Any commercial use without telling the author is illegal."<<endl;
   		continue;
	   }
	if(s=="exit"){
		return 0;
		continue;
	}
	if(s=="cmd"){
		strcpy(command, "cmd" );
  		system(command);
  		continue;
	}
	if(s=="databox"){
		//strcpy(command,"call databox.exe");
  		//system(command);
  		databox();
  		continue;
	}
	if(s=="findfile"){
		findfile(filename,num);
		continue;
	}
	if(s=="filelist"){
		if(num==0){
			cout<<"No file"<<endl;
			continue;
		}
		for(int i=0;i<num;i++){
			for(int j=0;j<50;j++){
				if(filename[i][j]=='\0'){
					j=50;
					continue;
				}
				cout<<filename[i][j];
			}
			cout<<endl;
		}
		cout<<"文件数目:"<<num<<endl;
		continue;
	}
	if(s=="file"){
		//string  path = "C:\\Users\\Student\\Desktop";
		if(l==1){
			cout<<"路径树已存在，是否覆盖？(Y/N)"<<endl;
			string path;
			cin>>path;
			if(path!="Y") continue;
			//清除树
			delfileall(h);
		}
		//创建树 
		l = 1;
		string path;
		cout<<"input(path):"<<endl; 
		cin>>path;
		h = new _file;
		h->father = NULL;
		h->num = 0;
		h->name = rename(path);
		h->path = path;
		head = new _list;
		h->son = head;
		head->addr = h;
		head->front = NULL;
		head->next = NULL;
		vector<string> dirpath;
		getfileall(path, dirpath,head,h); 
		continue;
	}
	if(s=="file+"){
		cout<<"input(objective):"<<endl;
		string objective;
		cin>>objective;
		cout<<"inout(operation):"<<endl;
		string operation;
		cin>>operation;
		searchfileall(h,objective,operation);
		continue;
	}
	//default
	//cout<<"Wrong order!"<<endl<<"Type 'help' for more information."<<endl;
	//strcpy(command," ");
	//strclear(command);
	//strre(command,s);
  	system(command);
   }
   
   return(0);
}
