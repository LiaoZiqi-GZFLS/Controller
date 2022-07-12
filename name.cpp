#include<iostream>
#include<string.h>
using namespace std;
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
	cout<<"bool:  "<<j<<k<<l<<endl; 
	return j&&k&&l;
}
int main(){
	string s1,s2;
	while(1){
		cin>>s1>>s2;
		cout<<"Name:  "<<rename(s1)<<endl;
		cout<<"Path:  "<<repath(s1)<<endl;
		cout<<"Front: "<<fr(s1)<<endl;
		cout<<"After: "<<af(s1)<<endl;
		cout<<"Name:  "<<rename(s2)<<endl;
		cout<<"Path:  "<<repath(s2)<<endl;
		cout<<"Front: "<<fr(s2)<<endl;
		cout<<"After: "<<af(s2)<<endl;
		cout<<"bool:  "<<jun(s1,s2)<<endl;
	}
	return 0;
}
