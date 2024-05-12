#include<iostream>
using namespace std;

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int A[], int low, int high) {
  int pivot = A[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (A[j] <= pivot) {
      i++;
      swap(&A[i], &A[j]);
    }
  }
  swap(&A[i + 1], &A[high]);
  return (i + 1);
}

void quickSort(int A[], int low, int high) {
  if (low < high) {
    int pi = partition(A, low, high);
    quickSort(A, low, pi - 1);
    quickSort(A, pi + 1, high);
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
    
    quickSort(A,0,n-1);
    
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<A[i]<<" , ";
    }
    
    return 0;
}
