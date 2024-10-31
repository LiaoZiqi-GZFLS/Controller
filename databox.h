#include<iostream>
#include<fstream>
#include<cstdio>
#define Lenth 10
using namespace std;
struct node{
	string data[Lenth];
	node *front;
	node *next;
}; 
void databox(){
	int a;
	string s;
	bool k=1,l=1;
	ifstream in("box.txt");
	//ofstream out("box.txt");
//	freopen("box.txt","r",stdin);
	//freopen("box2.txt","w",stdout);
	struct node *h=NULL;
	struct node *t=NULL;
	h = new node;
	t = h;
	t->front = NULL;
	t->next = NULL;
	for(int i=0;i<Lenth;i++){
		in>>t->data[i];
		if(i==0){
			if(t->data[i]=="-142857"){
				cout<<"Error:empty"<<endl;
				return;
				break;
			}
		}
	}
	k=1;
	while(k){
		struct node *p = new node;
		t->next = p;
		p->front = t;
		p->next = NULL;
		t = p;
		for(int i=0;i<Lenth&&k;i++){
			in>>t->data[i];
			if(i==0){
				k=!(t->data[i]=="-142857");
			}
		}
		
	}
	t=t->front;
	delete t->next;
	t->next = NULL;
	in.close();
	//out.close();
//	fclose(stdin);
	//fclose(stdout);
	while(1){
		cout<<"0:exit;1:search;2:replace;3:print;4:add;5:delete;6:store;"<<endl;
		cin>>a;
		switch(a){
			case 0:{
				return;
				break;
			}
			
			case 1:{
				cout<<"Student number"<<endl;
				cin>>s;
				struct node *q;
				q = h;
				k=1;
				l=0;
				while(k){
					if(q->next==NULL&&q->data[0]!=s){
						l=1;
						k=0;
					}
					if(q->data[0]==s){
						for(int i=0;i<Lenth;i++){
					    	cout<<q->data[i]<<endl;
					    }
						k=0;
					}
					q=q->next;
				}
				if(l){
					cout<<"No found"<<endl;
				}
				break;
			}
			
			case 2:{
				cout<<"Student number"<<endl;
				cin>>s;
				struct node *q;
				q = h;
				k=1;
				l=0;
				while(k){
					if(q->next==NULL&&q->data[0]!=s){
						l=1;
						k=0;
					}
					if(q->data[0]==s){
						for(int i=0;i<Lenth;i++){
					    	cin>>q->data[i];
					    }
						k=0;
					}
					q=q->next;
				}
				if(l){
					cout<<"No found"<<endl;
				}
				break;
			}
			
			case 3:{
				struct node *q;
				q=h;
				k=1;
				while(k){
					for(int i=0;i<Lenth;i++){
						cout<<q->data[i]<<endl;
					}
					if(q==t){
						k=0;
					}
					q=q->next;
				}
				break;
			}
			
			case 4:{
				struct node *q = new node;
				t->next = q;
				q->front = t;
				t=q;
				t->next = NULL;
				cout<<"Student number"<<endl;
				for(int i=0;i<Lenth;i++){
					cin>>t->data[i];
				}
				break;
			}
			
			case 5:{
				cout<<"Student number"<<endl;
				cin>>s;
				struct node *q;
				q = h;
				k=1;
				l=0;
				while(k){
					if(q->next==NULL&&q->data[0]!=s){
						l=1;
						k=0;
					}
					if(q->data[0]==s){
						k=0;
					}
					if(q->next!=NULL&&k){
						q=q->next;
					}
				}
				if(l){
					cout<<"No found"<<endl;
				}else{
					if(q==h){
						h=q->next;
						q->next->front = NULL;
					}else{
						if(q==t){
							t=q->front;
							q->front->next = NULL;
						}else{
							q->front->next = q->next;
							q->next->front = q->front;
						}
					}
					delete q;
				}
				break;
			}
			
			case 6:{
	            system("ren box.txt box2.txt");
	            //ifstream in("box.txt");
				ofstream out("box.txt");
				//freopen("box.txt","r",stdin);
	            //freopen("box.txt","w",stdout);
	            struct node *q;
				q=h;
				k=1;
				while(k){
					for(int i=0;i<Lenth;i++){
						out<<q->data[i]<<endl;
					}
					if(q==t){
						k=0;
					}
					q=q->next;
				}
				out<<"-142857"<<endl;
            	//in.close();
            	out.close();
	            //fclose(stdin);
            	//fclose(stdout);
            	system("del box2.txt");
				break;
			}
			
			default:{
				cout<<"wrong order"<<endl;
				break;
			}
		}
	}
	
	//freopen("box.txt","r",stdin);
	//freopen("box2.txt","w",stdout);
	//fclose(stdin);
	//fclose(stdout);
	return;
} 
