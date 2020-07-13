#include<iostream>
using namespace std;

int Dtob2(int n,int b){
    int res=0,pow=1;
    while(n!=0){
        int rem=n%b;
        res=rem*pow+res;
        n/=b;
        pow=pow*10;
    }
    cout<<res;
}

int numToD(int n,int b){
    int res=0,pow=1;
    while(n!=0){
        int rem=n%10;
        res=rem*pow+res;
        n/=10;
        pow=pow*b;
    }
    cout<<res<<endl;
    return res;
}

int main(int args, char **argv){
    int num,base1,base2;
    cout<<"Enter number..";
    cin>>num;
    cout<<"Enter base1..";
    cin>>base1;
    cout<<"Enter base2..";
    cin>>base2;
    int r = numToD(num,base1);
    Dtob2(r,base2);
}

