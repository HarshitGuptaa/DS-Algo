//ROTATION OF ARRAY
//EXTRA ARRAY CANT BE USED, time complexity: O(n)

#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int>&arr,int lower,int upper){
    int tmp;
    while(lower<upper){
        tmp=arr[lower];
        arr[lower]=arr[upper];
        arr[upper]=tmp;
        lower++;
        upper--;
    }
}


void rotate(vector<int>&arr,int r){
    r%=arr.size();
    r=r<0?r+arr.size():r;
    
    reverse(arr,0,r-1);
    reverse(arr,r,arr.size()-1);
    reverse(arr,0,arr.size()-1);


    cout<<"\nnew Array is..";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

}

void input(vector<int>&arr){
    cout<<"\nEnter array elts:";
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
}

int main(int args, char **argv){
    int r,size;
    cout<<"Enter size of array..";
    cin>>size;
    vector<int>arr(size,0);
    input(arr);
    cout<<"enter rotation..";
    cin>>r;
    rotate(arr,r);
    return 0;
}