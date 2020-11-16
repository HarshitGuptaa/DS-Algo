#include<iostream>
#include<vector>

#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

int fibo(int n,vi &dp){
    if(n<=1) return dp[n]=n;

    if(dp[n]!=0) return dp[n];

    int recAns = fibo(n-1,dp) + fibo(n-2,dp);
    return dp[n]=recAns;
}

int fiboTabu(int n,vi &dp){
    for(int i=1;i<=n;i++){

        if(i==1) {
            dp[i]=i;
            continue;
        }

        dp[i]=dp[i-1] + dp[i-2];
    }
    return dp[n];
}

void fibonacci(){
        int n=5;
        vi dp(n+1,0);
        cout<<fiboTabu(n,dp);
}


//mazePath

int mazePathHV(int sr,int sc,int er,int ec){
    if(sr==er && sc==ec){
        return 1;
    }
    
    int hori=0;
    int vert=0;

    if(sr+1<=er) hori = mazePathHV(sr+1,sc,er,ec);
    if(sc+1<=ec) vert = mazePathHV(sr,sc+1,er,ec);
    
    return hori + vert;
}

//memo
int mazePathHV(int sr,int sc,int er,int ec,vvi &dp){
    if(sr==er && sc==ec){
        return dp[sr][sc]=1;
    }

    if(dp[sr][sc]!=0) return dp[sr][sc];
    
    int hori=0;
    int vert=0;

    if(sr+1<=er) hori = mazePathHV(sr+1,sc,er,ec,dp);
    if(sc+1<=ec) vert = mazePathHV(sr,sc+1,er,ec,dp);
    
    return dp[sr][sc]=hori + vert;
}

int mazePathMulti(int sr,int sc,int er,int ec){
    if(sr==er && sc==ec){
        return 1;
    }
    int count=0;

    for(int i=1;sr+i<=er;i++){
        count+= mazePathMulti(sr+i,sc,er,ec);
    }

    for(int i=1;sc+i<=ec;i++){
        count+= mazePathMulti(sr,sc+i,er,ec);
    }
    
    return count;
}

void mazePath(){
   // cout<<mazePathHV(0,0,1,1);

    int sr=0;
    int sc=0;
    int er=2;
    int ec=2;
    //vector<vector<int>>dp(er+1,vector<int>(ec+1,0));
    //cout<<mazePathHV(sr,sc,er,ec,dp);

    cout<<mazePathMulti(sr,sc,er,ec);

}


//leet-70

int climbStairs(int st,int n){

    if(st==n){
        return 1;
    }

    int count=0;

    if(st+1<=n) count+=climbStairs(st+1,n);
    if(st+2<=n) count+=climbStairs(st+2,n);
    
    return count;
}

//doing from end
int climbStairs(int n){

    if(n==0){
        return 1;
    }

    int count=0;

    count+=climbStairs(n-1);
    count+=climbStairs(n-2);
    
    return count;
}


//leet 746
int minCostClimbingStairs_01(int n,vi &cost) {
        
    if(n<=1) return cost[n];

    int c1 = minCostClimbingStairs_01(n-1,cost);
    int c2 = minCostClimbingStairs_01(n-2,cost);

    return min(c1,c2) + cost[n];
}

void minCostClimbingStairs(){
    vi cost = {10, 15, 20};
    cost.push_back(0);
    int n = cost.size();
    vi dp(n,0);

    cout << minCostClimbingStairs_01(n-1,cost);
}

void set1(){
    // fibonacci();
    //mazePath();
    cout<<climbStairs(0,3);
    //minCostClimbingStairs();
}



//pair ans single up

int pairandsingleup_01(int n,vi & dp){

    if(n<=1) return dp[n]=1;

    if(dp[n]!=0) return dp[n];

    int single = pairandsingleup_01(n-1,dp);
    int pair = (n-1)*pairandsingleup_01(n-2,dp);

    return dp[n]= single + pair;
}

int pairandsingleup_02(int n,vi & dp){

    for(int i=0;i<=n;i++){
        if(i<=1) {
            dp[i]=1;
            continue;
        }

        int single = dp[i-1];
        int pair = (i-1)*dp[i-2];

        dp[i]= single + pair;
    }
    return dp[n];
    
}

void pairandsingleup(){
    int n=3;
    vi dp(n+1,0);
    //cout<<pairandsingleup_01(n,dp);
    cout<<pairandsingleup_02(n,dp)<<endl;
    for(int ele:dp){
        cout<<ele<<" ";
    }

}


//leet-45
int jump_01(int st,int end,vi &nums){

    if(st==end) return 0;
    if(nums[st]==0) return (int)1e7;
    int minJump = (int)1e7;

    for(int i=1;i<=nums[st]&&st+i<=end;i++){
        int recAns = jump_01(st+i,end,nums)+1;
        minJump = min(minJump,recAns);
    }

    return minJump;
}

int jump_02(int st,int end,vi &nums,vi &dp){

    if(st==end) return dp[st] = 0;
    if(nums[st]==0) return dp[st] = (int)1e7;
    int minJump = (int)1e7;

    if(dp[st] !=0) return dp[st] ;

    for(int i=1;i<=nums[st]&&st+i<=end;i++){
        int recAns = jump_02(st+i,end,nums,dp)+1;
        minJump = min(minJump,recAns);
    }

    return dp[st] = minJump;
}

int jump_03(int end,vi &nums,vi &dp){

    for(int st = end;st>=0;st--){

    if(st==end) {
      dp[st] = 0;
      continue;  
    } 
    
    if(nums[st]==0){
        dp[st] = (int)1e7;
        continue;
    }

    int minJump = (int)1e7;

    for(int i=1;i<=nums[st]&&st+i<=end;i++){
        int recAns = dp[st+i]+1;
        minJump = min(minJump,recAns);
    }

     dp[st] = minJump;
    
    }
    return dp[0];
}

void jump(){
    vi nums = {2,3,1,1,4};
    vi dp(nums.size()+1,0);
   //cout<<jump_01(0,nums.size()-1,nums);
   //cout<<jump_02(0,nums.size()-1,nums,dp);
   cout<<jump_03(nums.size()-1,nums,dp)<<endl;
   for(int ele:dp){
       cout<<ele<<" ";
   }

}

//partition of a set into k subsets

int parti_01(int n,int k){

    if(n==k || k==1){
        return 1;
    }

    int count=0;
    count+=parti_01(n-1,k-1);
    count+=k*parti_01(n-1,k);

    return count;
}

void parti(){
    int n=4;
    int k=2;
    cout<<parti_01(n,k);
}


//gold mine
vvi dir = {{-1,1},{0,1},{1,1}};

bool isSafe(int x,int y,vvi & mat){
    if(x>=0 && y>=0 && x<mat.size()&&y<mat[0].size()) return true;
    return false;
}

int goldmine_01(int x,int y,vvi &mat){
    if(y==mat[0].size()-1){
        return mat[x][y];
    }

    int maxAns = (int)-1e6;

    for(int i=0;i<dir.size();i++){
        int r=x+dir[i][0];
        int c=y+dir[i][1];

        if(isSafe(r,c,mat)){
            int recAns = goldmine_01(r,c,mat) + mat[x][y];
            maxAns = max(recAns,maxAns);
        }
    }
    return maxAns;
}

void goldmine(){
    vvi mat =  {{1, 3, 3},
                {2, 1, 4},
                {0, 6, 4}};

    int ans = (int)-1e6;
    for(int i=0;i<mat.size();i++){
        ans = max(ans,goldmine_01(i,0,mat));
    }
    cout<<ans<<endl;
}




int maxSquare=0;

int maxSubMat_01(int x,int y, vvi &arr,vvi&dp){
    if(x<1 || y<1){
        return dp[x][y] = arr[x][y];
    }

    int minPossSquare = 0;

    if(dp[x][y]!=-1) return dp[x][y];

    int left =  maxSubMat_01( x, y-1, arr,dp);
    int diag = maxSubMat_01( x-1, y-1, arr,dp);
    int up = maxSubMat_01( x-1, y, arr,dp);

    if (arr[x][y]==1)  //it checks for above,left and nw, if they have 1 then it is a square
    {
        minPossSquare=min(min(left,diag),up)+1;
    }else{
        dp[x][y]=0;
    }
    
    maxSquare = max(maxSquare,minPossSquare);
    dp[x][y] = minPossSquare;
    return maxSquare;
}

//dp solution
int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)return 0;//if empty return 0
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int dp[n][m];//creating a 2d array 
        
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i]-'0';//copy first row from original array
        }
        for(int i=0;i<n;i++){
            dp[i][0]=matrix[i][0]-'0';//copy first col from original array
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]=='1'){//if char is 1 then
                    //add 1+min from up(i-1,j),left(i,j-1),top(i-1,j-1)
                    dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])) + 1;
                }
                else{//if 0 keep it as 0 in dp array
                    dp[i][j]=0;
                }
            }
        }
        int maxi=dp[0][0];//find the maximum element from the dp which is our side of largest square
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]>maxi){
                    maxi=dp[i][j];
                }
            }
        }
        //return the area  side*side
        return maxi*maxi;
    }

void maxSubMat(){
    vvi arr = {{1, 0, 1 ,0 ,0},
            {1, 0, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 0, 0 ,1, 0}};
    
    vvi dp(arr.size()+1,vector<int>(arr[0].size()+1,-1));
    cout<<maxSubMat_01(arr.size()-1,arr[0].size()-1,arr,dp)<<endl;
    for(vi ar:dp){
        for(int ele:ar){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

int tileFloor_01(int n,int m,vector<int>&dp){
    if(n<m) return dp[n]=1;
    if(n==m) return dp[n]=2;
    
    if(dp[n]!=0) return dp[n];
    
    int hori = tileFloor_01(n-m,m,dp);
    int verti = tileFloor_01(n-1,m,dp);

    return dp[n]= (hori + verti)%((int)1e9+7);
}

void tileFloor(){

}


//coins to make target

int coinChangePermu(vi &coins,int target, vi & dp){
    if(target==0) return dp[target]= 1;

    if(dp[target]!=0) return dp[target];
    int count=0;

    for(int ele: coins){
        if(target-ele>=0) count+= coinChangePermu(coins,target - ele,dp);
    }
    return dp[target]=count;
}

int coinChangePermuDP(vi &coins,int target, vi & dp){
    for(int tar=0;tar<=target;tar++){
        
        if(tar==0) {
            dp[tar]= 1;
            continue;
        }

    int count=0;

    for(int ele: coins){
        if(tar-ele>=0) count+= dp[tar - ele];
    }
    }
    return dp[target];
}

//target sum: combination of coins to make target

int targetSum(int target,int idx,vi & coins,vvi &dp){
    if(target==0 || idx == coins.size()){
        if(target==0) return dp[target][idx] = 1;
        return dp[target][idx] = 0;
    }

    if(dp[target][idx] !=0) return dp[target][idx] ;

    int count=0;

    if(target-coins[idx]>=0) count+=targetSum(target-coins[idx],idx+1,coins,dp);
    
    count+=targetSum(target,idx+1,coins,dp);

    return dp[target][idx] = count;
}


//knapsack

int knapSack(vi & weight,vi &cost,int cap,int n){
    if(cap==0 || n==0){
        return 0;
    }

    int picked = 0;
    int unpicked = 0;

    if(cap - weight[n-1]>=0) picked = knapSack(weight,cost,cap-weight[n-1],n-1) + cost[n];
    unpicked = knapSack(weight,cost,cap,n-1);

    return max(picked,unpicked);
}


//String Set

//isPalindromic Substring

bool isPalindromeSubstring(string str){
    int n=str.length();
    vector<vector<bool>>dp(n,vector<bool>(n,false));
    for(int gap=0;gap<n;gap++){
        for(int i=0,j=gap;j<n;i++,j++){
            if(gap==0) dp[i][j]=true;
            else if(gap==1 && str[i]==str[j]) dp[i][j]=true;
            else{
                dp[i][j]=str[i]==str[j]&&dp[i-1][j-1];
            }
        }
    }
    return dp[0][n-1];
}

//leet 5
int longestPalindromeSubstring(string str){
    int n=str.length();
    vector<vector<int>>dp(n,vector<int>(n,0));
    int maxAns=0;

    for(int gap=0;gap<n;gap++){
        for(int i=0,j=gap;j<n;i++,j++){
            if(gap==0) dp[i][j]=1;
            else if(gap==1 && str[i]==str[j]) dp[i][j]=2;
            else if(str[i]==str[j] && dp[i+1][j-1]!=0){
                dp[i][j]=dp[i+1][j-1]+2;
            }
            if(dp[i][j]>maxAns) maxAns=dp[i][j];
        }
    }
    return maxAns;
}

//count palind also same leet 647

//leet 516

int longestPaliSubseq(int si,int ei,string str,vector<vector<int>>&dp){
    if(si>ei) return dp[si][ei]= 0;
    if(si==ei) return dp[si][ei]= 1;

       if(dp[si][ei]!=0) return dp[si][ei];
    int len=0;
    if(str[si]==str[ei]) len = longestPaliSubseq(si+1,ei-1,str,dp)+2;
    else len = max(longestPaliSubseq(si+1,ei,str,dp),longestPaliSubseq(si,ei-1,str,dp));
    
    return dp[si][ei]=len;
}

    
    int longestPalindromeSubseq(string str) {
        int n=str.length();
        vector<vector<int>>dp(n,vector<int>(n,0));
        return longestPaliSubseq(0,n-1,str,dp);
    }

//Geeks: https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1
int countPaliSubseq(string str,int si,int ei, vvi &dp){

    if(si>ei) return dp[si][ei]= 0;
    if(si==ei) return dp[si][ei]=1;
    
    if(dp[si][ei]!=0) return dp[si][ei];
   
    int middleString = countPaliSubseq(str,si+1,ei-1,dp);
    int excludingFirst = countPaliSubseq(str,si+1,ei,dp);
    int excludingLast = countPaliSubseq(str,si,ei-1,dp);
    int ans=excludingFirst+excludingLast;

    if(str[si]==str[ei]) dp[si][ei]= (middleString+1) + (ans-middleString);
    else dp[si][ei]=  (ans-middleString);

    return dp[si][ei];
}

int countPS(string str)
{
   //Your code here
       int n=str.size();
    int dp[n][n]={0};
    for(int gap=0;gap<n;gap++){
        for(int si=0,ei=gap; ei<n; si++,ei++){

    if(si>ei){
        dp[si][ei]= 0;
        continue;
    }
    if(si==ei){
      dp[si][ei]=1;
      continue;
    } 
    
    int middleString = dp[si+1][ei-1];
    int excludingFirst = dp[si+1][ei];
    int excludingLast = dp[si][ei-1];
    int ans=excludingFirst+excludingLast;

    if(str[si]==str[ei]) dp[si][ei]= (middleString+1) + (ans-middleString);
    else dp[si][ei]=  (ans-middleString);

        }
    }
return dp[0][n-1];
   
}

void PaliSubseq(){
    string str="aab";
    int n=str.size();
    int si=0;
    int ei=n-1;
    vvi dp(n,vector<int>(n,0));
    cout<<countPaliSubseq(str,si,ei,dp)<<endl;
    cout<<countPS(str);
}

//leet 115
int distinctSubseq(int n,int m,string &s,string &t,vvi &dp){
    if(n<m) return dp[n][m]=0;
    if(m==0) return dp[n][m]=1;
    
    if(dp[n][m]!=-1) return dp[n][m];

    if(s[n-1]==t[m-1]) return dp[n][m] = distinctSubseq(n-1,m-1,s,t,dp) + distinctSubseq(n-1,m,s,t,dp);
    else return dp[n][m] = distinctSubseq(n-1,m,s,t,dp);
}

int numDistinct(string s, string t){
    int n=s.length();
    int m=t.length();
    vvi dp(n+1,vector<int>(m+1,-1));
    return distinctSubseq(n,m,s,t,dp);    
}

int longestCommSubseq(string s,string t,int n,int m,vvi &dp){
    if(n==0 || m==0) return dp[n][m]= 0;

    if(dp[n][m]!=0) return dp[n][m];
    int ans=0;
    if(s[n-1] == t[m-1]) ans = longestCommSubseq(s,t,n-1,m-1,dp) + 1;
    else ans = max(longestCommSubseq(s,t,n-1,m,dp),longestCommSubseq(s,t,n,m-1,dp));

    return dp[n][m]=ans;
}

int longestCommSubseqDP(string s,string t,int n,int m,vvi &dp){
   
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){



    if(i==0 || j==0) { 
        dp[i][j]= 0;
        continue;
    }

    int ans=0;
    if(s[i-1] == t[j-1]) ans = dp[i-1][j-1] + 1;
    else ans = max(dp[i-1][j],dp[i][j-1]);

    dp[i][j]=ans;

       }
   }
    return dp[n][m];
}

void LCS(){

}


//Lis
int LISleft2right(vi &arr){
    int n=arr.size();
    vi dp(n+1,0);
    int max_=0;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]) dp[i]=max(dp[i],dp[j]+1);
                max_ = max(max_,dp[i]);
            
        }
    }
    return max_;
}

int maximumIncreasingSumSubsequence(vi &arr){
    int n=arr.size();
    vi dp(n+1,0);
    int maxSum=0;
    for(int i=0;i<n;i++){
        dp[i]=arr[i];
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                dp[i]=max(dp[i],dp[j]+arr[i]);
            }
            maxSum = max(maxSum,dp[i]);
        }
    }
    return maxSum;
}


void LIS(){
    vi arr = {3, 10, 2, 1, 20};
    cout<<LISleft2right(arr);
}


//MCM

int MCM_rec(vi &arr,int si,int ei,vvi &dp){
    if(si+1==ei) return dp[si][ei]= 0;

    if(dp[si][ei]!=-1) return dp[si][ei];
    int ans = 0;

    for(int cut=si+1;cut<ei;cut++){
        int leftAns = MCM_rec(arr,si,cut,dp);
        int rightAns = MCM_rec(arr,cut,ei,dp);

        int myAns = leftAns + arr[si]*arr[cut]*arr[ei] + rightAns;
        if(myAns<ans){
            ans = myAns;
        }
    }
    return dp[si][ei]= ans;
} 
void MCM(){
    vi arr = {};
    int n=arr.size();
    vvi dp(n+1,vector<int>(n+1,-1));
    cout<<MCM_rec(arr,0,n-1,dp);
} 

void set2(){
   // pairandsingleup();
   //jump();
   //parti();
//    goldmine();
//maxSubMat();
//PaliSubseq();
LIS();
}


int main(){
    //set1();
    set2();
    return 0;
}
