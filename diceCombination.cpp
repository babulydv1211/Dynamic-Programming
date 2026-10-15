#include<iostream>
#include<vector>
#include<climits>
#define ll long long int
#define mod 1000000007
using namespace std;
vector<ll>dp;
ll f(int n){
  if(n==0) return 1;
  if(dp[n]!=-1) return dp[n];
  ll count=0;
  for(int i=1;i<=6;i++){
    if(n-i<0) break;
      count= (count%mod+f(n-i)%mod)%mod;
  }
  return dp[n]=count%mod;
}

int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+1,-1);
    cout<<f(n);
    return 0;
}