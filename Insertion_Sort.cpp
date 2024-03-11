#include<iostream>
using namespace std;
class Insertion_sort{
    public: void solve(int arr[], int n);
    void display(int arr[] , int n);

};
void Insertion_sort::solve(int arr[],int n){
    for(int i=0;i<n;i++){
    int j=i-1;
    int key=arr[i];
    while(j>=0&&arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
    }
}
void Insertion_sort::display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
}
int main(){
 int arr[]={23, 54,1,12, 0, 44, 13,4};
 int n= sizeof (arr)/sizeof (arr[0]);
 Insertion_sort g;
 g.solve(arr, n);
 g.display(arr,n);
 return 0;
}
