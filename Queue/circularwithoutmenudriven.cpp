#include<iostream>
#define ML 10
using namespace std;
class Circular{
    private:
        int front=-1,rear=-1;    
        int arr[ML];
    public:
        void deque();
        void traverse();
        bool isEmpty();
        void enque(int x);
        bool isFull();  
};

bool Circular::isFull(){
    if((rear+1)%ML==front)
    {
        return 1;
    }else{
        return 0;
    }
}

bool Circular::isEmpty(){
    if(rear==-1&&front==-1)//default case
    {
        return 1;
    }else{return 0;}
}

void Circular::deque(){
    if(isEmpty()){
        cout<<"Can't deque queue is already empty."<<endl;
    }else if(front==rear){
        cout<<arr[front]<<" will be dequed."<<endl;
        front=-1;
        rear=-1;
	}else{
        cout<<arr[front]<<" will be dequed."<<endl;
        front=(front+1)%ML;
    }
}

void Circular::traverse(){
    if(isEmpty()){
        cout<<"Cannot traverse queue is empty."<<endl;
    }else{
        cout<<"The contents of Circular queue are: "<<endl;
        for(int i=front;i!=rear;i=(i+1)%ML)
        {
            cout<<arr[i]<<"  ";
        }
        cout<<arr[rear]<<"  "<<endl;
    }
}

void Circular::enque(int x){
    if(front==-1&&rear==-1){
        front++;
        rear++;
        cout<<x<<" has been enqueued."<<endl;
        arr[rear]=x;
    }else{
        cout<<x<<" has been enqueued."<<endl;
        rear=(rear+1)%ML;
        arr[rear]=x;
    }
}

int main(){
    Circular c1;
    c1.enque(1);
    c1.enque(2);
    c1.enque(3);
    c1.enque(4);
    c1.enque(5);
    c1.traverse();
    c1.deque();
    c1.deque();
    c1.traverse();
    return 0;
}
