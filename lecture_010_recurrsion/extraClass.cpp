#include<iostream>
#include<vector>

using namespace std;


void LexicographicalOrder(int st,int end){

    if(st>=end){
        return;
    }

    cout<<st<<endl;
    for(int i=0;i<10;i++){
        if(st*10+i<end){
            LexicographicalOrder(st*10+i,end);
        }else break;
    }
    
    if(st+1<10){
        LexicographicalOrder(st+1,end);
    }

}

//leet 1079
// int numTilePossibilities(string str) {

//     if(str.length()==0){
//         return 0;
//     }        
//     int count=0;
//     vector<bool>vis(26,false);
//     for(int i=0;i<str.length();i++){
//         int chIdx = str[i]-'A';
//         if(!vis[chIdx]){
//             string nstr = str.substr(0,i) + str.substr(i+1);
//             count+=numTilePossibilities(nstr)+1;
//         }

//     }
//     return count;
// }

    int numTilePossibilities(string str) {

    if(str.length()==0){
        return 0;
    }        
    int count=0;
    
    // vector<bool>vis(26,false);
    int vis=0;
        
    for(int i=0;i<str.length();i++){
        int mask = 1 << (str[i]-'A');
        if((vis&mask)==0){
            vis^=mask;
            string nstr = str.substr(0,i) + str.substr(i+1);
            count+=numTilePossibilities(nstr)+1;
        }
    }
    return count;
}

//leet 22
vector<string>res;
    vector<string> generateParenthesis(int n) {
        
        generateParenthesis_(0,0,n,"");
        return res;
    }
    
    void generateParenthesis_(int ob,int cb,int n,string ans){
        if(ob+cb==2*n){
            res.push_back(ans);
            return;
        }
        
        if(ob<n){
            generateParenthesis_(ob+1,cb,n,ans+'(');
        }
                
        if(cb<ob){
            generateParenthesis_(ob,cb+1,n,ans+')');
        }
    }

//aeroplane game

int main(int argc, char const *argv[])
{
    /* code */
    LexicographicalOrder(1,1000);
    return 0;
}
