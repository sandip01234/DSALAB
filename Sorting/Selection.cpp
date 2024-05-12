#include<iostream>
using namespace std;

int main(){
	int n,min;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int A[n];
	
	cout<<"Enter an element of an array: "<<endl;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	
	
	for(int i=0;i<n-1;i++){
		min=i;
		for(int j=i+1;j<n;j++){
			if(A[j]<A[min]){
				min=j;
			}
		}
		if(min!=i){
			int temp=A[i];
			A[i]=A[min];
			A[min]=temp;
		}
	}
	
	
	cout<<"Sorted array is: ";
	for(int k=0;k<n;k++){
		cout<<A[k]<<" , ";
	}
	
	return 0;
}
