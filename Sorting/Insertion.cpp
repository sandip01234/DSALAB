#include<iostream>
using namespace std;

int main(){
	int n,key;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int A[n];
	
	cout<<"Enter an element of an array: "<<endl;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}

	for(int i=1;i<n;i++){
		key=A[i];
		int j=i-1;
		while(j>=0 && A[j]>key){
			A[j+1]=A[j];
			j=j-1;
		}
		A[j+1]=key;
	}
	
	cout<<"Sorted array is: ";
	for(int k=0;k<n;k++){
		cout<<A[k]<<" , ";
	}
	return 0;
}
