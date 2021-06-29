#include<iostream>
using namespace std;

int main(){
        int t;
        cin>>t;
        while(t--){
            int n,count=1;
            cin>>n;
            for(int i=2;i<=n;i++){
                if(i%2!=0){
                    if(i*2>n) count++;
                }
            }
            cout<<count<<endl;
        }
        return 0;
}

