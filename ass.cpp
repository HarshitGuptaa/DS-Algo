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



    int main(){
        // int n;
        // cin>>n;

        // while(n-->0){
        //     cin>>

        // }
       // cout<<maxPrime(4);
       vector<int> arr = {1,2,1,2};
       cout<<subset(arr,0,0,0);
       //cout<<combiWthoutRepe(arr,0,0,"");
        return 0;
    }

    // int main(int argc, char const *argv[])
    // {
    //     /* code */


    //     for(auto & e:findAnagrams("cbaebabacd","abc")){
    //         cout<<e<<endl;
    //     }
    //     return 0;
    // }
    


