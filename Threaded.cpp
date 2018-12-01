#include<iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct node{
	int no;
	bool lft=1,rht=1;
	node *left,*right;
};

class threaded{
	
	public:
		node *root,*dummy;
		int key;
		threaded();
		//~threaded();
		void insertion();
		void fastInorder(node* p);
		node* nextInorder(node* p);
		void options();
};

threaded::threaded(){
	root=dummy=NULL;
}

void threaded::insertion(){
	if(root==NULL){
		dummy = new node;
		root =new node;
		dummy->no=0;
		dummy->right=dummy;
		dummy->rht=0;
		dummy->left=root;
		dummy->lft=0;
		root->no=key;
		root->left=dummy;
		root->right=dummy;
		return;
	}else{
		node *t,*temp;
		t=root;
		temp=new node;
		while(1){
			if(key==t->no){					////---Already Exits ....///
				cout<<"Number Already Exits ... ! "<<endl;
				return;
			}
			if(key>t->no && t->rht==1){						///---Curent number Greater  but  in right no node exits... ///
				t->rht=0;
				temp->no=key;
				temp->right=t->right;
				temp->left=t;
				t->right=temp;
				return;
			}
			if(key>t->no && t->rht==0){						///---Curent number Greater but in right node exits... ///
				t=t->right;
			}
			if(key<t->no && t->lft==1){						///---Curent number less  but  in left no node exits... ///
				t->lft=0;
				temp->no=key;
				temp->left=t->left;
				temp->right=t;
				t->left=temp;
				return;
			}
			if(key<t->no && t->lft==0){						///---Curent number less  but  in left node exits... ///
				t=t->left;
			}
		}
	}
}

void threaded::fastInorder(node *p){ 	
	
	if(p==NULL){
		cout<<"tree empty"<<endl;
		return;
	}
	
	while(  ( p=nextInorder(p) ) != dummy ) 
		cout <<p->no<<"  " ;
		
	return;
} 

node* threaded::nextInorder(node* p){
	if(p->rht ==1)
		return(p->right); 
  	
	else{ 
    	p = p->right; 
    	while(p->lft==0) 
    		p = p->left; 
    	
    	return p; 
	} 
}


void threaded:: options()
{
 	cout<<"\n\n ************** Select Option *****************.\n";
 	cout<<"\n Enter any of choices.\n";
 	cout<<"\n 0 : Quitting the Program.\n";
 	cout<<"\n 1 : Print the whole BST .\n";
 	cout<<"\n 2 : Adding (inserting) node in BST.\n";
 	cout<<"\n";
}//--------------------------------------------------------------


int main(){
	char ch;
  	threaded obj;
  	while( 4 )
  	{
    obj.options();
    ch=getch();
    switch(ch)
     {
       	case '0':
			exit(0);
			break;
		
		case '1':
			obj.fastInorder(obj.dummy);
			break;
		case '2':
			cout<<"Enter number : ";
			cin>>obj.key;
			obj.insertion();
			break;
       	default :
			exit(0);
			break;
     } // end of switch.
  } // end of while.
}//-----------------------------------------------


