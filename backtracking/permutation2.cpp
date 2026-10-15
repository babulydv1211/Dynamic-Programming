#include<iostream>
using namespace std;

void permutation(string str,int i){
       if(i==str.size()-1) {
        cout<<str<<"\n";
        return; 
       }
       for(int idx=i;idx<str.size();idx++){
          //swap jo bhi char ko krna h uska index pass kr do
          swap(str[idx],str[i]);
          permutation(str,i+1);
          swap(str[idx],str[i]);
       }
    }

     int main(){
    permutation("abc",0);
      return 0;
    }