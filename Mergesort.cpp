#include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
 void  merge(int arr[], int left, int mid, int right){
    int n1,n2;
    n1=mid-left+1;
    n2=right-mid;
    int leftarray[n1];
    int rightarray[n2];
    for(int i=0; i<n1;i++){
        leftarray[i]=arr[left+i];
    }
      for(int j=0; j<n2;j++){
        rightarray[j]=arr[mid+j+1];
    }
    int i=0,j=0,k=left;
    while(i<n1&&j<n2){
        if(leftarray[i]<=rightarray[j]){
            arr[k++]=leftarray[i++];
        }
         else{
            arr[k++]=rightarray[j++];
         }
    }
    while(i<n1){
        arr[k++]=leftarray[i++];
    }
     while(j<n2){
        arr[k++]=rightarray[j++];
     }
 }
 void  display(int arr[], int N){
    for(int i=0;i<N;i++){
        cout<<arr[i]<<"\t";
    }
 }
 void sorting(int arr[],int left, int right){
    if(left< right){
    
   int  mid=left+(right-left)/2;
   sorting(arr,left, mid);
   sorting(arr, mid+1, right);
   merge(arr, left, mid, right);
 }}
 int main(){
     
     int arr[]={29, 6, 89, 33, 12, 9, 7, 31};
     int N=sizeof(arr)/sizeof(arr[0]);
     sorting(arr, 0, N-1);
     display(arr, N-1);
     return 0;
 }