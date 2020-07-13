#include<iostream>
using namespace std;

void numDiamond(int rows){
    int nst=1;
    int nsp=rows/2;

    for(int r=1; r<=rows; r++){
        for(int csp=1; csp<=nsp; csp++){
            cout<<" ";
        }
        int ele=r;
        if(r>(rows+1)/2){
            ele=rows-r+1;
        }
        for(int cst=1; cst<=nst; cst++){
            cout<<ele;
            if(cst>nst/2){
                ele--;
            }else{
                ele++;
            }
        }

        if(r<=rows/2){
            nst+=2;
            nsp--;
        }else{
            nst-=2;
            nsp++;
        }
        cout<<endl;
    }
}

int main(int args, char **argv){
    int rows;
    cout<<"Enter rows..";
    cin>>rows;
    numDiamond(rows);
}