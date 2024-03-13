#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define NO_OF_CHAR 256
void badcharhist(string str, int size, int  badchar[NO_OF_CHAR]){
     int i;
      for(i=0;i<NO_OF_CHAR;i++){
        badchar[i]=i;
      }
      for(i=0;i<size;i++){
        badchar[(int)str[i]]=i;
      }
}
void search(string txt, string pat){
    int m=pat.length();
    int n=txt.length();
     int badchar[NO_OF_CHAR];
    badcharhist(pat, m, badchar);
    int s=0;
    while(s<=n-m){
        int j=m-1;
        while(j>=0&& pat[j]==txt[s+j])
        j--;
        if(j<0){
            cout<<"pattern found "<<s<<endl;
            s+=(s+m<n)? (m-badchar[txt[s+m]]):1;
        }
        else{
            s+=max(1, j-badchar[txt[s+j]]);
        }
    }
}
 int main(){
     string txt; string pat;
     
     cout<<"Enter the sequence :";
     cin>>txt;

     cout<<"Enter the pattern";
     cin>>pat;
      
     search(txt,pat);
     return 0;

 }