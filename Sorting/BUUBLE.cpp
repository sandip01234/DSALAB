#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int A[n];
	
	cout<<"Enter an element of an array: "<<endl;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	
	for(int i=0; i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(A[j]>A[j+1]){
				int temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
	
	cout<<"Sorted array is: ";
	for(int i=0;i<n;i++){
		cout<<A[i]<<" , ";
	}
	
	return 0;
}
