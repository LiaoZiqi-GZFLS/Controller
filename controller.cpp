#include<iostream>
#include <string.h>
#include "databox.h" 
#include "findfile.h"
#include "file.hpp"
using namespace std;
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
		cout<<"文件数目:"<<num<<endl;
		continue;
	}
	if(s=="file"){
		//string  path = "C:\\Users\\Student\\Desktop";
		string path;
		cout<<"input(path):"<<endl; 
		cin>>path;
		vector<string> dirpath;
		getfileall(path, dirpath);  
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
