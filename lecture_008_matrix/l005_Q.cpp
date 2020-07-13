//ROTATE MATRIX CLOCKWISE & ANTICLOCKWISE

#include<vector>
#include<iostream>
using namespace std;


void display(vector<vector<int>>&arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
    cout<<endl;
    }
}

void transpose(vector<vector<int>>&arr){
    for(int i=0; i<arr.size();i++){
        for (int j=i; j<arr[0].size();j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
}

void swapC(vector<vector<int>>&arr){
    int c1=0;
    int c2=arr[0].size()-1;
    while(c1<c2){
        for(int r=0; r<arr.size();r++){
            swap(arr[r][c1],arr[r][c2]);
        }
        c1++;
        c2--;
    }
}
void swapR(vector<vector<int>>&arr){
    int r1=0;
    int r2=arr.size()-1;
    while(r1<r2){
        
            swap(arr[r1],arr[r2]);
        
        r1++;
        r2--;
    }
}

void rotate90(vector<vector<int>>&arr,bool isClockwise){
    transpose(arr);
    if(isClockwise){
        swapC(arr);
    }else swapR(arr);
}

int main(int args, char**argv){

    vector<vector<int>>arr={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    rotate90(arr,true);
    display(arr);
    return 0;
}