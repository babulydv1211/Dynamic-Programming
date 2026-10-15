#include<iostream>
#include<vector>
#include<climits> 
using namespace std;
vector<int>dp;
vector<int> get_digits(int n){
  vector<int>result;
  while(n>0){
    if(n%10!=0){
        result.push_back(n%10);
    }
    //reduce the num
    n=n/10;
  }
  return result;
}

int reduce(int n){
    if(n==0) return n;
    if(n<=9) return 1;
    if(dp[n]!=-1) return dp[n];
    vector<int>d=get_digits(n);
    int sol=INT_MAX;
    for(int i=0;i<d.size();i++){
        sol=min(sol,reduce(n-d[i]));
    }
    return dp[n]=1+sol;
}


int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+1,-1);
    cout<< reduce(n);
}