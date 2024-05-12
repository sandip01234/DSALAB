#include<iostream>
using namespace std;
int Factorial(int n){
	if(n==1){
		return 1; 
	}else{
		return n*Factorial(n-1);
	}
}
int main(){
	int num;
	cout<<"Enter a number: ";
	cin>>num;
	int result=Factorial(num);
	cout<<"Factorial of "<<num <<" is: "<<result;
	return 0;
}
