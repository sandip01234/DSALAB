#include<iostream>
using namespace std;
int GCD(int a,int b){
	if(b==0){
		return a;
	}else{
		return GCD(b,a%b);
	}
}
int main(){
	int num1,num2;
	cout<<"Enter first number: ";
	cin>>num1;
	cout<<"Enter second number: ";
	cin>>num2;
	cout<<"GCD of "<<num1<<" and "<<num2<<" is "<<GCD(num1,num2); 
	return 0;
}
