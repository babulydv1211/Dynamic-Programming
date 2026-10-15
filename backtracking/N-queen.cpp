// #include<iostream>
// #include<vector>
// using namespace std;
// vector<vector<char>>grid;
// vector<vector<string>> res;
// bool canPlaceQueen(int row,int col,int n){
//        //column check
//        for(int i=row;i>=0;i--){
//            if(grid[i][col]=='Q'){
//             return false;
//            }
//        }
//        //left diag check
//        for(int i=row-1,j=col-1;i>=0 && j>=0; i--,j--){
//               if(grid[i][j]=='Q'){
//                 return false;
//               }
//        }
//        //Right  diag check
//        for(int i=row-1,j=col+1;i>=0 && j<n; i--,j++){
//               if(grid[i][j]=='Q'){
//                 return false;
//               }
//        }
//        return true;//no attack
// }

// void f(int row,int n){
//     if(row==n) {
//         //we got one possible ans
//         vector<string>temp;
//         for(int i=0;i<n;i++){
//             string res="";
//             for(int j=0;j<n;j++){
//                 res+=grid[i][j];
//             }
//             temp.push_back(res);
//         }
//         res.push_back(temp);
//         return ;
//     }

//     for(int col=0;col<n;col++){
//         if(canPlaceQueen(row,col,n)){
//           grid[row][col]='Q';
//           f(row+1,n);
//           grid[row][col]='.';
//         }
//     }
// }


// vector<vector<string>> nqueen(int n){
//     grid.clear();
//     res.clear();
//     grid.resize(n,vector<char>(n,'.'));
//     f(0,n);
//     return res;
// }



// int main(){
//  nqueen(4);
//   return 0;
// }

#include<iostream>
#include<vector>
using namespace std;
vector<vector<char>>grid;

bool canQueenPlaces(int row,int col,int n){
      //column check
      for(int i=row-1;i>=0;i--){
        if(grid[i][col]=='Q') return false;
      }
      //left diagonal check
      for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(grid[i][j]=='Q') return false;
      }
      //right diagonal
      for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
          if(grid[i][j]=='Q') return false;
      }
      return true;
}

void f(int row,int n){
    //base
    if(row==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j];
            }
            cout<<"\n";
        }
        return;
    }
    for(int col=0;col<n;col++){
      if(canQueenPlaces(row,col,n)){
        grid[row][col]='Q';
        f(row+1,n);
        grid[row][col]='.';
      }
    }
}

 vector<vector<int>>nqueen(int n){
      grid.resize(n,vector<char>(n,'.'));
      f(0,n);
 }

int main(){
    nqueen(4);
  return 0;
}