// #include<iostream>

// using namespace std;


// int facto(int n){
//     int ans =1;
//     for(int i=1;i<=n;i++){
//         ans*=i;
//     }
//     return ans;
// }

// int main(int args, char **argv){
//     int n;
//     cout<<"Enter number for factorial";
//     cin>>n;
//     cout<<"factorial :"<<facto(n);
//     return 0;
// }


//AT HOME
#include<iostream>

using namespace std;

int facto(int n){
    int fact = 1;
    for(int i =1;i<=n;i++){
        fact*=i;
    }
    return fact;
}
int nCr(int n, int r){
    int ncr = facto(n)/(facto(r)*facto(n-r));
    cout<<"The nCr is : "<<ncr;
}



int main(){
    int n,r;
    char ans;
    cout<<"Enter number: ";
    cin>>n;
    cout<<"The factorial is : "<<facto(n);
    cout<<"\nDo you wish to find nCr..? Say (y/n)";
    cin>>ans;
    if(ans=='y'){
        cout<<"Give the value of r: ";
        cin>>r;
        nCr(n,r);
    }
}