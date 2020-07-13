#include<iostream>
using namespace std;


void fullDiamond(int rows){
    int nsp = rows/2;  //3 spaces in 1st line when 7 rows
    int nst = 1;
    for(int r=1;r<=rows;r++){
        for(int csp=1;csp<=nsp;csp++){
            cout<<" ";
        }
        for(int cst=1;cst<=nst;cst++){
            cout<<"*";
        }
        if(r<=rows/2){
        nst+=2;
        nsp--;
        }
        else{
        nst-=2;
        nsp++;
        }
        cout<<endl;
    }
}

int main(int args, char **argv){
    int rows;
    cout<<"Enter number of rows..";
    cin>>rows;
    fullDiamond(rows);
}