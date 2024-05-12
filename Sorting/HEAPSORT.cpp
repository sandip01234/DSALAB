#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void heapify(int A[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && A[left] > A[largest])
      largest = left;
  
    if (right < n && A[right] > A[largest])
      largest = right;
  
    if (largest != i) {
      swap(A[i], A[largest]);
      heapify(A, n, largest);
    }
 }
  
  void heapSort(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(A, n, i);
  
     for (int i = n - 1; i >= 0; i--) {
        swap(A[0], A[i]);
        heapify(A, i, 0);
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
    
    heapSort(A, n);
    
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<A[i]<<" , ";
    }
    
    return 0;
}

