#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// auto speedUp = [](){
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//     return nullptr;
// }();

// sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b) {
//         if (a[0] == b[0])
//             return b[1] < a[1]; // other - this
//         return a[0] < b[0];     // this - other., for cpp replace '-' with '<' default
//     });

unordered_set<string> map;
    void permu(string str,string ans){
        if(str.length()==0){
            //cout<<ans<<endl;
            map.insert(ans);
            return;
        }
        
            for(int i=0;i<str.length();i++){
                string str2=str.substr(0,i) + str.substr(i+1);
                permu(str2,ans+str[i]);
            }
            
        
    }

    vector<int> findAnagrams(string s, string p) {
        permu(p,"");
        vector<int>ans;
        for(int i=0;i<s.length();i++){
            if(map.find(s.substr(i,3))!=map.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }

    int maxPrime(int n){
        int i=3;
        
        int ans=2;
        while(n>1){
            bool isprime=true;
            for(int k=2;k<i;k++){
                if(i%k==0) isprime=false;
            }

            if(isprime){
              ans=max(ans,i);
              n--;
            }
            i++;
        }
        return ans;
    }



int subset(vector<int>&arr,int tar,int idx,int sum){
    if(idx==arr.size()){
    if(sum==0) return 1;
    return 0;
    }

    int count=0;

    count+= subset(arr,tar,idx+1,sum+arr[idx]);
    count+= subset(arr,tar,idx+1,sum);

    return count;
}

    int power(long long x, unsigned int y, int p){
        int res = 1;

        x = x % p;
        if(x==0) return 0;

        while(y>0){
            if(y&1) res = (res*x) % p;
            y = y>>1;
            x = (x*x) % p;
        }
        return res;
    }

    // int main(){
    //     int t;
    //     cin>>t;
    //     while(t--){
    //         char a[3][3];
    //         int countx=0,counto=0,winx=0,wino=0,count_=0;
    //         for(int i=0;i<3;i++){
    //             for(int j=0;j<3;j++){
    //                 cin>>a[i][j];
    //                 if(a[i][j]=='X') countx++;
    //                 else if(a[i][j]=='O') counto++;
    //                 else if(a[i][j]=='_') count_++;
    //             }
    //         }

    //         for(int i=0;i<3;i++){
    //             if(a[i][0]==a[i][1] and a[i][2]==a[i][1]){
    //                 if(a[i][0]=='X') winx++;
    //                 else if(a[i][0]=='O') wino++;
    //             }
    //         }

    //         for(int i=0;i<3;i++){
    //             if(a[0][i]==a[1][i] and a[2][i]==a[1][i]){
    //                 if(a[0][i]=='X') winx++;
    //                 else if(a[0][i]=='O') wino++;
    //             }
    //         }

    //         if(a[0][0]==a[1][1] and a[2][2]==a[1][1]){
    //             if(a[1][1]=='X') winx++;
    //             else if(a[1][1]=='O') wino++;
    //         }

    //         if(a[0][2]==a[1][1] and a[2][0]==a[1][1]){
    //             if(a[1][1]=='X') winx++;
    //             else if(a[1][1]=='O') wino++;
    //         }

    //         if(counto > countx) cout<<3<<endl;
    //         else if(countx - counto > 1) cout<<3<<endl;
    //         else if((countx > counto) and winx==1 and wino==0) cout<<1<<endl;
    //         else if((countx == counto) and wino==1 and winx==0) cout<<1<<endl;
    //         else if(count_==0 and (winx+wino==0)) cout<<1<<endl;
    //         else if(count_==0 and winx==2) cout<<1<<endl;
    //         else if(count_>0 and (winx+wino==0)) cout<<2<<endl;
    //         else cout<<3<<endl;
    //     }
    //     return 0;
    // }

    int combiWthoutRepe(int arr[],int idx,int n, string ans){
    if(idx==n-1){
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i=idx;i<n;i++){
        // if(target-arr[i]>=0){
            count+=combiWthoutRepe(arr,i,n,ans+to_string(arr[i])+" ");
        // }
    }
    return count;
}

    int main(){
        
        int arr[4]={1,2,3,4};
        cout<<combiWthoutRepe(arr,0,4,"");
        return 0;
    }



