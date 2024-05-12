#include<iostream>
using namespace std;

void binarySearch(int A[], int x, int low, int high) {
    int c = 0;  
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (A[mid] == x){
            cout << x << " found at " << mid << " position." << endl;
            c = 1;
        }
        
        if (A[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
  
    if (c == 0) {
        cout << x << " not found." << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of an array: ";
    cin >> n;
    
    int A[n];
    cout << "Enter elements of array (in sorted order): ";
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    int x;
    cout << "Enter the element to search: ";
    cin >> x;
    
    binarySearch(A, x, 0, n - 1);
    
    return 0;
}
