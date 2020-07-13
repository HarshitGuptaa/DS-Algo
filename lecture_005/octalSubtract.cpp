#include<iostream>
using namespace std;

int oSub(int n1,int n2){
    int borrow=0,pow=1,res=0;
    while(n1!=0||n2!=0){
    int rem1=n1%10;
    int rem2=n2%10;
    int rem=rem1-rem2+borrow;
    n1/=10;
    n2/=10;
    if(rem<0){
        rem+=8;
        borrow=-1;
    }else{
        borrow=0;
    }
    res=rem*pow+res;
    pow*=10;
    }

    return res;
}

int main(int args, char **argv){
    int num1,num2;
    cout<<"Enter num1: ";
    cin>>num1;
    cout<<"Enter num2: ";
    cin>>num2;

    bool isNeg=false;
    if(num1<num2){
        isNeg=true;
        int temp=num1;
        num1=num2;
        num2=temp;
    }
    int r= oSub(num1,num2);
    if(isNeg){
        r*=-1;
    }
    cout<<r;

}

