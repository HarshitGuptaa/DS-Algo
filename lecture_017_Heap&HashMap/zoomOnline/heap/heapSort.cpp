#include<iostream>
#include<vector>
    
using namespace std;
    
    int compareTo(vector<int>&arr, int child, int parent,bool isMax){
        if(isMax){                      //isMax true : max heap
            return arr[child]-arr[parent];
        }else{
            return arr[parent]-arr[child];
        }
    }
    
    
    
    
    void downHeapify(vector<int>&arr,int idx,int lidx,bool isMax){
        int maxIdx = idx;
         int lci = 2*idx+1;
         int rci = 2*idx+2;

        if(lci<=lidx && compareTo(arr,lci, maxIdx,isMax)>=0){
            maxIdx = lci;
        }

        if(rci<=lidx && compareTo(arr,rci, maxIdx,isMax)>=0){
            maxIdx = rci;
        }

        if(maxIdx!=idx){
            swap(arr[maxIdx], arr[idx]);
            downHeapify(arr,maxIdx,lidx,isMax);
        }
    }

int main(int argc, char const *argv[])
{
    vector<int> arr = { 10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13 };
    bool isMax = false;
    int n=arr.size()-1;

    for(int i=n;i>=0;i--){
        downHeapify(arr,i,n,isMax);
    }

    for(int i=0;i<=n;i++){
        for(int ele:arr){
            cout<<ele<<" ";
        }
        cout<<endl;
        swap(arr[0],arr[n-i]);
        downHeapify(arr,0,n-i-1,isMax);
    }



    return 0;
}

