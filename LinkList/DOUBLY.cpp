//Doubly LinkList
#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		
		Node(){
			cout<<"Enter a data for New Node: ";
			cin>>data;
			this->data=data;
			this->next=NULL;
			this->prev=NULL;
		}
};

class LinkList{
	Node* head=NULL;
	Node* temp1;
	Node* temp2;
	public:
		void InsertB(){
			Node* newNode=new Node();
			if(head==NULL){
				head=newNode;	
			}else{
				temp1=head;
				newNode->next=temp1;
				temp1->prev=newNode;
				head=newNode;
			}
		}
		
		
		void InsertE(){
			Node* newNode=new Node();
			if(head==NULL){
				head=newNode;	
			}else{
				temp1=head;
				while(temp1->next!=NULL){
					temp1=temp1->next;
				}
				temp1->next=newNode;
				newNode->prev=temp1;
			}
		}
		
		void InsertS() {
    		int pos;
    		cout << "Enter a position: ";
    		cin >> pos;
    
    		int counter = 0;
    		temp1 = head;
   
    		if (pos == 1) {
    			InsertB();
    			return;
    		}

    		while (temp1 != NULL) {
        		counter++;
        		if (counter == pos-1) {
					if(temp1->next==NULL){
						InsertE();
						return;
					} 
        			Node* newNode = new Node();
            		newNode->next = temp1->next;
            		temp1->next = newNode;
            		newNode->prev=temp1;
            		return;
        		}
        		temp1 = temp1->next;
    		}
    		cout << "Invalid Position." << endl;
		}

		
		void DeleteB(){
			if(head==NULL){
				cout<<"Link List is Empty."<<endl;
			}else{
				temp1=head;
				cout<<"Deleted Item: "<<temp1->data<<endl;
				if(temp1->next==NULL){
					head=NULL;
				}else{
					temp1=temp1->next;
					temp1->prev=NULL;
					head=temp1;
				}
			}
		}
		
		void DeleteE(){
			if(head==NULL){
				cout<<"Link List is Empty."<<endl;
			}else{
				temp1=head;
				if(temp1->next==NULL){
					cout<<"Deleted Item: "<<temp1->data<<endl;
					head=NULL;
				}else{
					while(temp1->next->next!=NULL){
						temp1=temp1->next;
					}
					cout<<"Deleted Item: "<<temp1->next->data<<endl;
					temp1->next=NULL;
				}	
			}
		}
		
		void DeleteS() {
    		int pos;
    		cout << "Enter a position: ";
    		cin >> pos;
    
    		int counter = 0;
    		temp1 = head;
   
    		if (pos == 1) {
    			DeleteB();
    			return;
    		}else{
    			while (temp1 != NULL) {
    				counter++;
        			if (counter == pos-1) { 
						if(temp1->next==NULL){
							cout << "Invalid Position." << endl;
						}else{
							if(temp1->next->next==NULL){
								DeleteE();
								return;
							}
							cout<<"Deleted Item: "<<temp1->next->data<<endl;
							temp2=temp1->next->next;
							temp2->prev=temp1;
							temp1->next=temp2;
						}
						return;
        			}
        			temp1 = temp1->next;
    			}
    		cout << "Invalid Position." << endl;
			}	
		}
		
		void Search(){
			if(head==NULL){
				cout<<"Link List is Empty."<<endl;
			}else{
				int element,c,counter;
				cout<<"Enter a element to search: ";
				cin>>element;
				temp1=head;
				c=counter=0;
				do{
					c++;
					if(temp1->data==element){
						counter++;
						cout<<element<<" found at "<<c<<"th position."<<endl;
					}
					temp1=temp1->next;
				}while(temp1!=NULL);	
				if(counter==0){
					cout<<element<<" is not in LinkList."<<endl;
				}
			}
		}
		
		void Traverse(){
			if(head==NULL){
				cout<<"Link List is Empty."<<endl;
			}else{
				temp1=head;
				do{
					cout<<temp1->data<<" , ";
					temp1=temp1->next;
				}while(temp1!=NULL);
				cout<<endl;
			}
		}
};

int main(){
	LinkList obj;
	int choice;
	do{
		do{
			cout<<"Enter choice: "<<endl;

			cout<<"1. Insert At Begining"<<endl;
			cout<<"2. Insert At End"<<endl;
			cout<<"3. Insert At Specific Position"<<endl;
			cout<<"4. Delete At Begining"<<endl;
			cout<<"5. Delete At End"<<endl;
			cout<<"6. Delete At Specific Position"<<endl;
			cout<<"7. Traverse"<<endl;
			cout<<"8. Search"<<endl;
			cout<<"9. Exit"<<endl;
			cin>>choice;
		}while(choice>9 || choice<0);
		switch(choice){
			case 1:
				obj.InsertB();
				break;

			case 2:
				obj.InsertE();
				break;

			case 3:
				obj.InsertS();
				break;

			case 4:
				obj.DeleteB();
				break;

			case 5:
				obj.DeleteE();
				break;

			case 6:
				obj.DeleteS();
				break;

			case 7:
				obj.Traverse();
				break;

			case 8:
				obj.Search();
				break;

			default:
				break;
		}
	}while(choice!=9);

	return 0;
}
