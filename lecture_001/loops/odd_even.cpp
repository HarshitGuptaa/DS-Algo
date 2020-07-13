#include<iostream>
using namespace std;
int main(int args, char **argv){
    
    cout<<"Even :";
    for(int i=1;i<=10;i++){
        
        if(i%2==0){
            cout<<" "<<i;
        }

    }
    cout<<"\nOdd :";
    for(int i=1;i<=10;i++){
        if(i%2!=0) {
            cout<<" "<<i;
        }
    }


}