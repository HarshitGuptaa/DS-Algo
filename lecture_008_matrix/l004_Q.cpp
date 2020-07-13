//SPIRAL PRINTING

#include<vector>
#include<iostream>
using namespace std;


void spiral(vector<vector<int>>&arr){
    int minr=0,minc=0;
    int maxr=arr.size()-1,maxc=arr[0].size()-1;
    int tne=arr.size()*arr[0].size();
    while(tne!=0){
        for(int i=minc; i<=maxc && tne!=0;i++){
            cout<<arr[minr][i]<<" ";
            tne--;
        }
        minr++;
        for(int i=minr; i<=maxr && tne!=0;i++){
            cout<<arr[i][maxc]<<" ";
            tne--;
        }
        maxc--;
        for(int i=maxc; i>=minc && tne!=0;i--){
            cout<<arr[maxr][i]<<" ";
            tne--;
        }
        maxr--;
        for(int i=maxr; i>=minr && tne!=0;i--){
            cout<<arr[i][minc]<<" ";
            tne--;
        }
        minc++;
    }
}




int main(int args, char**argv){
    // int n,m;
    // cout<<"enter rows & col..";
    // cin>>n>>m;
    vector<vector<int>>arr={
        {1,2,3,4,5,6},
        {18,19,20,21,22,7},
        {17,28,29,30,23,8},        
        {16,27,26,25,24,9},
        {15,14,13,12,11,10},

    };
    spiral(arr);
    return 0;
}