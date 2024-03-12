#include<iostream>
 using namespace std;
 class Heapsort{
    public:
     void heapify(int arr[],int N,int i);
     void sorting(int arr[], int N);
     void display(int arr[], int N);
 };
 void Heapsort:: heapify(int arr[],int N, int i){
    int largest=i;
     int l=2*i+1;
     int r= 2*i+2;
     if(l<N&& arr[l]>arr[largest]){
        largest=l;
     }
      if(r<N&& arr[r]>arr[largest]){
        largest=r;
     }
      if(largest!=i){
         swap(arr[i],arr[largest]);
         heapify(arr, N, largest);
      }
 }
 void Heapsort:: sorting(int arr[], int N){
    for(int i=N/2-1;i>=0;i--){
        heapify(arr, N,i);
    }
    for(int i=N-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr, N,0);
    }
 } 
 void Heapsort:: display(int arr[], int N){
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
 }
 int main(){
     Heapsort h;
      int arr[]={19,4,24,88,97,1,6,2,41};
      int N=sizeof(arr)/sizeof(arr[0]);
     h.sorting(arr, N);
     h.display(arr, N);
      return 0;
 }