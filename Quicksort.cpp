#include<iostream>
using namespace std;
int partition(int arr[], int low, int high){
    int pivot=arr[high];
    int i=(low-1);
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
 void sorting(int arr[], int low,int high){
    if(low<high){
        int p=partition(arr, low,high);
        sorting(arr,low,p-1);
        sorting(arr,p+1,high);
    }
 }
 void display(int arr[],int N){
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
 }
 int main(){
     int arr[]={12,5,34,9,44,5,14,99,41,44,67,98};
     int N= sizeof(arr)/sizeof(arr[0]);
     sorting(arr, 0,N-1);
     display(arr, N);
 }