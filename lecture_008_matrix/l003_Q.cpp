//EXIT POINT

#include<vector>
#include<iostream>
using namespace std;


void exitPoint(vector<vector<int>>&arr){
    int r=0,c=0,dir=0;
    while(true){
        dir=(dir+arr[r][c])%4;
        if(dir==0){
            c++;
            if(c==arr[r].size()){
                cout<<r<<","<<c-1;
                break;
            }
        }
        else if(dir==1){
            r++;
            if(r==arr.size()){
                cout<<r-1<<","<<c;
                break;
            }
        }
        else if(dir==2){
            c--;
            if(c==-1){
                cout<<r<<","<<c+1;
                break;
            }
            
        }    
        else if(dir==3){
            r--;
            if(r==-1){
                cout<<r+1<<","<<c;
               break;

            }
        }
    }
    
}



// void input(vector<vector<int>>&arr){
//     for(int i=0; i<arr.size(); i++){
//         for(int j=0; j<arr[i].size();j++){
//             cin>>arr[i][j];
//         }
//     }
// }


int main(int args, char**argv){
    // int n,m;
    // cout<<"enter rows & col..";
    // cin>>n>>m;
    vector<vector<int>>arr={
        {0,0,0,0,0,1},
        {1,0,0,0,1,0},
        {0,1,0,1,0,0},        
        {0,1,0,0,1,0},
        {1,0,0,0,0,1},

    };
    // input(arr);
    exitPoint(arr);
    return 0;
}