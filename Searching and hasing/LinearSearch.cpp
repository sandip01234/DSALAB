#include<iostream>
using namespace std;

void search(int A[], int n, int x) {
  for (int i = 0; i < n; i++){
    if (A[i] == x)
        cout<<"Found at "<<i+1<<" position."<<endl;
  }
}

int main(){
    int n;
    cout<<"Enter an size of an array: ";
    cin>>n;
    
    int A[n];
    cout<<"Enter element of array: ";
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    
    int x;
    cout<<"Enter an element to search: ";
    cin>>x;
    
    search(A,n,x);
    
    return 0;
}
