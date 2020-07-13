//Array ques

#include<iostream>
#include<vector>
using namespace std;

bool find(vector<int>&arr, int data){
    bool ele=false;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==data){
            ele=true;
            cout<<"\nElement is at position: "<<i+1;
        }
    }    
    if(ele=false){
        cout<<"Element not found!";
    }
}


int maximum(vector<int>&arr){
    int m=arr[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i]>=m){    //m=max(m,arr[i]);
            m=arr[i];     //sir method ^
        }
    }
    cout<<"\nMax elt is: "<<m;
}

int minimum(vector<int>&arr){
    int m;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=m){
            m=arr[i];
        }
    }
    cout<<"\nMin elt is: "<<m;
}


void input(vector<int>&arr){
    cout<<"\nEnter array elts:";
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
}

void display(vector<int>&arr){
    cout<<"\nArray is..";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }    
    cout<<endl;
}

int main(int args, char **argv){
    int size,data;
    cout<<"Enter size";
    cin>>size;
    vector<int>arr(size,0);
    input(arr);
    display(arr);
    cout<<"element to search?";
    cin>>data;
    find(arr,data);
    maximum(arr);
    minimum(arr);
    return 0;
}