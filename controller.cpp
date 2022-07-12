#include<iostream>
#include<string.h>
#include<windows.h>
#include "databox.h" 
#include "findfile.h"
#include "file.hpp"
//#pragma execution_character_set("utf-8") 
using namespace std;
int main (){
	//SetConsoleOutputCP(CP_UTF8);
	_file *f=NULL;
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
   	if(s=="help"){
   		cout<<"help:exit/cmd/databox/findfile/filelist/file"<<endl;
   		cout<<"controller is made by GZFLS Lazybones LZQ"<<endl;
   		cout<<"Any copy or use without telling the author is illegal."<<endl;
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
		cout<<"Number of files: "<<num<<endl;
		continue;
	}
	if(s=="file"){
		//string  path = "C:\\Users\\Student\\Desktop";
		if(f!=NULL){
			char c;
			cout<<"File-tree is existing, replace? (Y/N)"<<endl;
			cin>>c;
			if(c!='Y') continue;
			delfileall(f);
			f = NULL;
		}
		string path;
		cout<<"input(path):"<<endl; 
		cin>>path;
		vector<string> dirpath;
		f = new _file;
		initfile(f);
		getfileall(path, dirpath, f, NULL);  
		continue;
	}
	if(s=="file+"){
		if(f==NULL){
			cout<<"No file!"<<endl;
			continue;
		}
		cout<<"tips: print/del/search"<<endl;
		string str;
		cin>>str;
		if(str=="print"){
			printfileall(f);
		} 
		if(str=="del"){
			delfileall(f);
			f = NULL; 
		}
		if(str=="search"){
			string str1,str2;
			cout<<"objective: "<<endl;
			cout<<"tips: *.*"<<endl;
			cin>>str1;
			cout<<"operation: "<<endl;
			cout<<"tips: list/type/del/print/lookfor"<<endl;
			cin>>str2;
			searchfileall(f,str1,str2);
		}
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
