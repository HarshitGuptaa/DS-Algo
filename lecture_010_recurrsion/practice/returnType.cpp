#include<vector>
#include<iostream>
using namespace std;

vector<vector<int>>dirVal={{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};
vector<string>dir={"R","1","U","2","L","3","D","4"};

bool isSafe(int x, int y, int er, int ec, vector<vector<bool>>&board){
    if(x<0 || y<0 || x>er || y>ec || board[x][y]) return false;
    return true;
}

int floodFill(int sr, int sc, int er, int ec, vector<vector<bool>>&board, vector<vector<int>> &dirVal, vector<string>&dir, string ans){
    if(sr==er&&sc==ec){
        cout<<ans<<endl;
        return 1;
    }
    int count =0;
    board[sr][sc]=true;
    for(int i=0;i<8;i++){
        int x=sr+dirVal[i][0];
        int y=sc+dirVal[i][1];

        if(isSafe(x,y,er,ec,board)){
            count += floodFill(x,y,er,ec,board,dirVal,dir,ans+dir[i]);
        }

    }
    board[sr][sc]=false;
    return count;
}

int main(int args, char**argv){
    vector<vector<bool>>board(3,vector<bool>(3,false));
    cout << floodFill(0,0,2,2,board,dirVal,dir,"");
    return 0;
}