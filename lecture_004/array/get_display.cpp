#include<iostream>
#include<vector>
using namespace std;

    void get(vector<int>&arr,int n) {
        cout<<"Enter data..";
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
    }       
    void display(vector<int>&arr,int n) {
        cout<<"Inserted array is..";
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }


int main(int args, char **argv){
    int n;
    cout<<"Enter size of array..";
    cin>>n;
    vector<int>arr(n,0);
    get(arr,n);
    display(arr,n);
    return 0;
}