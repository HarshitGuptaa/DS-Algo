#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void display(vector<int>&arr,int i){
    if(i==arr.size()){
        return;
        
    }
    cout<<arr[i]<<" ";
    display(arr,i+1);
}

int maximum(vector<int>&arr,int i){
    if(i==arr.size()){
        return INT_MIN;
    }
    int recAns=maximum(arr,i+1);
    return max(arr[i],recAns);
}
int minimum(vector<int>&arr,int i){
    if(i==arr.size()){
        return INT_MAX;
    }
    int recAns=minimum(arr,i+1);
    return min(arr[i],recAns);
}
bool find(vector<int>&arr,int i,int data){
    if(arr[i]==data) return true;
    if(i==arr.size()) return false;
    find(arr,i+1,data);
}

//MIRROR INVERSE
void inverse(vector<int>& arr,int idx){
    if(idx==arr.size()) return;
    
    int val=arr[idx];
    inverse(arr,idx+1);
    arr[val]=idx;   
}



//ALLINDEX print an array containing values of all indexes where an elt is found 
vector<int>  allIndex(vector<int>&arr,int i,int data,int count){
    if(i==arr.size()){
        vector<int>base(count,0);
        return base;
    } 
    if(arr[i]==data){
        count++;
    }

    vector<int> recarr= allIndex(arr,i+1,data,count);
    if(arr[i]==data){
        recarr[count-1]=i ;
    }
    return recarr;
}

int main(int args, char **argv){
    vector<int>arr={10,20,30,40,50,60,70,10,80};
    //int m=arr[0];
    //display(arr,0);
    //cout<<maximum(arr,0)<<endl;
    //cout<<minimum(arr,0);
    //cout<<find(arr,0,20);
    vector<int>ans=allIndex(arr,0,10,0);
    display(ans,0);

}





