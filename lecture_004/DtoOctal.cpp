#include<iostream>
using namespace std;

void DtoO(int n){
    int res=0,pow=1;
    while(n!=0){
        int rem=n%8;
        res=rem*pow + res;
        n/=8;
        pow*=10;
    }
    cout<<res;
}

int main(int args, char **argv){
    int num;
    cout<<"Enter number..";
    cin>>num;
    DtoO(num);
}

