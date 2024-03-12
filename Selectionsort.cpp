#include<iostream>
using namespace std;
void sorting(int arr[], int N){
    for(int i=0;i<N;i++){
        int min=i;
        for(int j=i+1;j<N;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={12, 9, 65, 83, 1,42, 33, 13l, 9, 81, 4,53,2};
    int N=sizeof(arr)/sizeof(arr[0]);
    sorting(arr,N);
    return 0;
}
