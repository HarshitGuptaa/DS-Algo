#include<iostream>
using namespace std;

int oAdd(int n1,int n2){

    int carry=0,pow=1,res=0;
    while(n1!=0 || n2!=0 || carry!=0){
    int rem1=n1%10;
    int rem2=n2%10;
    int rem=rem1+rem2+carry;

    n1/=10;
    n2/=10;

    
    carry=rem/8;
    rem%=8;
    res+=rem*pow;
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

    int r= oAdd(num1,num2);

    cout<<r;

}

