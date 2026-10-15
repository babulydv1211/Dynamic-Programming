#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size  of array:";
    cin>>n;
    int k=2;
    vector<int>v(n);
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    int maxLen=INT_MIN;
    int len=INT_MIN;
    int flips=0;
    int i=0,j=0;
    while(j<n){
        if(v[j]==1){
            j++;
        }
        else{ //v[j]==0
            if(flips<k){
                flips++;
                j++;
            }
            else{
                len=j-i;
                maxLen=max(len,maxLen);
                while(v[i]==1) i++;
                i++;
                j++;
            }
        }
        
    }
    len=j-i;
    maxLen=max(maxLen,len);

    cout<<maxLen;

}