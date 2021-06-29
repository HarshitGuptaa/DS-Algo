#include<iostream>
#include<vector>
#include<string>


using namespace std;

//codechef -> 2

int main(){
    string s="codechef";

    int i=4;
    string st;
    st = s.substr(0,i) + s.substr(i+1);
    cout<<st;

    return 0;
}
