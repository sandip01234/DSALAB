#include<iostream>
using namespace std;

int main(){
    int n, size;
    cout << "Enter the size of the hash table: ";
    cin >> n;
    cout << "How many elements do you want to enter? ";
    cin >> size;

    int A[n];
    int B[n] = {0}; 
    int C[n] = {0}; 
    int x;
    
    cout << "Enter elements of the array: ";
    for(int i = 0; i < size; i++) {
        cin >> x;
        int pos = x % n;
        int index = pos;
        int probe_count = 0;

        if(B[pos] != 0){
            do{
                pos++; 
                if(pos == n){
                    pos = 0;
                }
                probe_count++;
            } while(B[pos] != 0);
        }
        A[pos] = x; 
        B[pos] = 1;
        C[pos] = probe_count+1; 
    }

    cout << "Index\t\tProbe\t\tElement" << endl;
    for(int i = 0; i < n; i++) {
        cout << i << "\t\t";
        if(B[i] == 0) {
            cout << "0\t\tEmpty" << endl;
        } else {
            cout << C[i] << "\t\t" << A[i] << endl;
        }
    }
    return 0;
}
