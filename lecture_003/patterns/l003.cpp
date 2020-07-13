//half diamond
#include<iostream>
using namespace std;


void halfDiamond(int rows){
    int nsp = rows-1;
    int nst = 1;
    for(int r=1;r<=rows;r++){
        for(int csp=1;csp<=nsp;csp++){
            cout<<" ";
        }
        for(int cst=1;cst<=nst;cst++){
            cout<<"*";
        }
        nst+=2;
        nsp--;
        
        cout<<endl;
    }
}

int main(int args, char **argv){
    int rows;
    cout<<"Enter number of rows..";
    cin>>rows;
    halfDiamond(rows);
}