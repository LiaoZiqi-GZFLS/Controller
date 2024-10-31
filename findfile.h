#include<iostream>
#include<windows.h>
void findfile(char (&ch)[50][50], int &num){
	using namespace std;
	
	char path[50];
	cout<<"inpt(xx\\xx\\*.*): "<<endl;
	gets(path);
	//cout<<path<<endl;
	
	HANDLE file;  
	LPCTSTR lpFileName=path/*"*.png"*/;//path.c_str();  
	WIN32_FIND_DATA pNextInfo;  
	file=FindFirstFile(lpFileName, &pNextInfo);  
	if (file == INVALID_HANDLE_VALUE)	
	{  
		cout<<"搜索失败"<<endl;  
		num=0;
		//system("pause"); 
		return; 
		//exit(0);  
	}  
	cout<<"得到文件："<<pNextInfo.cFileName<<endl;//Line13
	//ch[0]=pNextInfo.cFileName;
	for(int i=0;i<50;i++){
		if(pNextInfo.cFileName[i]=='\0') break;
		ch[0][i]=pNextInfo.cFileName[i];
	}
	int count=1;
	while (FindNextFile(file, &pNextInfo))  
	{  
	    if (pNextInfo.cFileName[0] == '.')  
		     continue;  
	    cout<<"得到文件："<<pNextInfo.cFileName<<endl;  
	    //ch[count-1]=pNextInfo.cFileName;
	    
	   	for(int i=0;i<50;i++){
	    	ch[count-1][i]=pNextInfo.cFileName[i];
		}
		count++;
	} 
	num=count;
	cout<<"count = "<<count<<endl;
	return;
}
/*int main(){
	findfile();
	return 0;
}*/
