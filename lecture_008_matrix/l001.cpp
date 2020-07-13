#include<vector>
#include<iostream>
using namespace std;


void display(vector<vector<int>>&arr,int n,int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
    cout<<endl;
    }
}

//FOREACH METHOD OF DISPLAY.......FOREACH CAN ONLY BE USED FOR DISPLAY,NOT SETTING VALUES
// void display(vector<vector<int>>&arr,int n,int m){
//     for(vector<int> ar:arr){
//         for(int ele:ar){
//             cout<<ele<<" ";
//         }
//     cout<<endl;
//     }
// }


// void input(vector<vector<int>>&arr,int n,int m){
//     for(int i=0; i<n; i++){
//         for(int j=0; j<arr[i].size();j++){
//             cin>>arr[i][j];
//         }
//     }
// }


int main(int args, char**argv){
    int n,m;
    cout<<"enter rows & col..";
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m,10));
    // input(arr,n,m);
    display(arr,n,m);
    return 0;
}