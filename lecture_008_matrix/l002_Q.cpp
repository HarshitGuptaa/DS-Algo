#include<vector>
#include<iostream>
using namespace std;


void wavedisplay(vector<vector<int>>&arr,int n,int m){
    for(int i=0; i<n; i++){
        if(i%2==0){
        for(int j=0; j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        }else{
        for(int j=arr[i].size()-1; j>=0;j--){
            cout<<arr[i][j]<<" ";
        }
    }

    cout<<endl;
    }
}



void input(vector<vector<int>>&arr,int n,int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<arr[i].size();j++){
            cin>>arr[i][j];
        }
    }
}


int main(int args, char**argv){
    int n,m;
    cout<<"enter rows & col..";
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m,0));
    input(arr,n,m);
    wavedisplay(arr,n,m);
    return 0;
}