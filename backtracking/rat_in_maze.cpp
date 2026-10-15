#include<iostream>
#include<vector>
using namespace std;

int ans;
bool canWeGo(int n,int i,int j,vector<vector<int>>& grid){
    return i>=0 && j>=0 && i<n && j<n && grid[i][j]==0;

}

void f(vector<vector<int>> &grid,int n,int i,int j){
     if(i==n-1 && j==n-1){
        ans+=1;
        return;//base case;
     }
    grid[i][j]=2; //2 means visited
     //yaha se 4 dir main jayenge
     //left move
    if(canWeGo(n,i,j-1,grid)){
         f(grid,n,i,j-1);
    }
    //up move
    if(canWeGo(n,i-1,j,grid)){
        f(grid,n,i-1,j);
    }
     //right move
    if(canWeGo(n,i,j+1,grid)){
        f(grid,n,i,j+1);
    }
    //down move
    if(canWeGo(n,i+1,j,grid)){
       f(grid,n,i+1,j);
    }
    //en four case ans aya ya nhi ans we revert grid;
    grid[i][j]=0;

}

int  ratInMaze(vector<vector<int>>&grid,int n){
        ans=0;
        f(grid,n,0,0);
        return ans;
}



int main(){
    vector<vector<int>>grid={
        {0,0,1,0,0,1,0},
        {1,0,1,1,0,0,0},
        {0,0,0,0,1,0,1},
        {1,0,1,0,0,0,0},
        {1,0,1,1,0,1,0},
        {1,0,0,0,0,1,0},
        {1,1,1,1,0,0,0},
    };
    cout<<ratInMaze(grid,7);
    return 0;
}