#include<iostream>
#include<math.h>
#include<vector>
#define inf INT_MAX
using namespace std;
vector<int>dp;

// int fn(int n){
//     if(n==1) return 0;
//     if(n==2 || n==3) return 1;
//     return 1+min(fn(n-1), min((n%2)==0? fn(n/2):inf, (n%3)==0?fn(n/3):inf));
//  }

int ftd(int n){
    if(n==1) return 0;
    if(n==2 || n==3) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]= 1+min(ftd(n-1), min((n%2)==0? ftd(n/2):inf, (n%3)==0?ftd(n/3):inf));
}
  

int main(){
    int n;
    cout<<"Enter the number:";
    cin>>n;
    dp.clear();
    dp.resize(1005,-1);
    cout<< ftd(n);
    
    return 0;

}
