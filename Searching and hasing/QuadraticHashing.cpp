#include<iostream>
using namespace std;

int main(){
    int n, size;
    cout << "Enter the size of the hash table: ";
    cin >> n;
    cout << "How many elements do you want to enter? ";
    cin >> size;

    int A[n], B[n]={0},C[n]={0}; 
    int x;
    
    cout << "Enter elements of the array: ";
    for(int i = 0; i < size; i++) {
        cin >> x;
        int pos = x % n; 
        int index = pos;
        int c=0;
        if(B[pos] == 1) {
            do {
                c++;
                pos = (index + c * c) % n; 
            } while (B[pos] != 0); 
        }
        A[pos] = x; 
        B[pos] = 1; 
        C[pos]=c+1;
    }

    cout << "Index\t\tElement\t\tProb" << endl;
    
    for(int i = 0; i < n; i++) {
        cout << i << "\t\t" ;
        if(B[i]==0){
            cout<<"Empty"<<endl;
        }else{
            cout << A[i] <<"\t\t"<<C[i]<< endl;   
        }
    }
    return 0;
}
