#include<iostream>
#include<vector>
#include<algorithm>

#define vi vector<int>
#define vii vector<vi>
#define vs vector<string>
#define vbb vector<vector<bool>>

using namespace std;

void display(vi &arr){
    for(int ele:arr){
        cout<<ele<<" ";
    }
    cout<<endl;
}

void display2(vii &arr){
    for(vi ar:arr){
        for(int ele:ar){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//fibo
//normal rec
int fibo(int n){
    if(n<=1) return n;
    
    int ans = fibo(n-1) + fibo(n-2);
    return ans;
}

//memorizarion
int fibo1(int n,vi&dp){
    if(n<=1){
        dp[n] = n;
        return n;
    } 
    
    if(dp[n]!=0) return dp[n];  //agar array m ans h to call lgane ki no need

    int ans = fibo1(n-1,dp) + fibo1(n-2,dp);

    dp[n] = ans; //array m save krate jao taaki aage calls bache 

    return ans;
}

//tabulation
int fibo2(int n,vi&dp){
    for(int i=0;i<=n;i++){
        if(i<=1){
            dp[i] = i;
            continue;
        }
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}


//=======================================================================
//maze path HV

//normal rec
int mazePathHV_01(int sr,int sc,int er,int ec){
    
    if(sr==er && sc==ec){
        return 1;
    }
    int count =0;
    if(sc+1<=ec)
        count += mazePathHV_01(sr,sc+1,er,ec);

    if(sr+1<=er)
        count+= mazePathHV_01(sr+1,sc,er,ec);

    return count;
}

//memorization
int mazePathHV_02(int sr,int sc,int er,int ec,vii &dp){
    
    if(sr==er && sc==ec){
        dp[sr][sc]=1;
        return 1;
    }
    int count =0;

    if(dp[sr][sc]!=0) return dp[sr][sc];
    
    if(er==ec && dp[sc][sr]!=0) return dp[sc][sr]; //optimization coz of symmetry / optional to make better

    if(sc+1<=ec) count += mazePathHV_01(sr,sc+1,er,ec);
    if(sr+1<=er) count+= mazePathHV_01(sr+1,sc,er,ec);
    
    dp[sr][sc] = count;
    if(er==ec) dp[sc][sr]=count; //optimization
    
    return count;
}

//tabulation
int mazePathHV_03(int er,int ec,vii &dp){
    
    for(int sr=er;sr>=0;sr--){
        for(int sc=ec;sc>=0;sc--){

            if(sr==er && sc==ec){
                dp[sr][sc]=1;
                continue;
            }
            int count =0;

            if(sc+1<=ec) count += dp[sr][sc+1];
            if(sr+1<=er) count += dp[sr+1][sc];

            dp[sr][sc] = count;
        }
    }

   
    return dp[0][0];
}

//===========================================================================
//mazepath multimove

int mazePathMulti(int sr,int sc,int er,int ec){
    if(sr==er && sc==ec){
        return 1;
    }
    int count =0 ;
    for(int jump=1;sr+jump<=er;jump++) count+= mazePathMulti(sr+jump,sc,er,ec);
    for(int jump=1;sc+jump<=ec;jump++) count+= mazePathMulti(sr,sc+jump,er,ec);
    for(int jump=1;sr+jump<=er && sc+jump<=ec;jump++) count+= mazePathMulti(sr+jump,sc+jump,er,ec);

    return count;
}

//memorization
int mazePathMulti_01(int sr,int sc,int er,int ec,vii &dp){
    if(sr==er && sc==ec){
        dp[sr][sc] = 1;
            return 1;
    }
    int count =0 ;

    if(dp[sr][sc]!=0) return dp[sr][sc];

    for(int jump=1;sr+jump<=er;jump++) count+= mazePathMulti_01(sr+jump,sc,er,ec,dp);
    for(int jump=1;sc+jump<=ec;jump++) count+= mazePathMulti_01(sr,sc+jump,er,ec,dp);
    for(int jump=1;sr+jump<=er && sc+jump<=ec;jump++) count+= mazePathMulti_01(sr+jump,sc+jump,er,ec,dp);

    return dp[sr][sc] = count;
}

//tabulation
int mazePathMulti_02(int er,int ec,vii &dp){
    
    for(int sr=er;sr>=0;sr--){
        for(int sc=ec;sc>=0;sc--){
             if(sr==er && sc==ec){
                dp[sr][sc] = 1;
                continue;
             }
            int count =0 ;

            for(int jump=1;sr+jump<=er;jump++) count+= dp[sr+jump][sc];
            for(int jump=1;sc+jump<=ec;jump++) count+= dp[sr][sc+jump];
            for(int jump=1;sr+jump<=er && sc+jump<=ec;jump++) count+= dp[sr+jump][sc+jump];

            dp[sr][sc] = count;

            
        }
    }
    return dp[0][0];
}

//==========================================================================
//board numbers to reach a target
//recur
int boardPath(int st, int end,vi &dp){
    if(st==end){
        return 1;
    }

    int count = 0;

    for(int dice=1; dice<=6 && st+dice<=end; dice++){
        count+=boardPath(st+dice,end,dp);
        
    }
    return count;
}

//memorization
int boardPath_01(int st, int end,vi &dp){
    if(st==end){
        dp[st] = 1;
        return 1;
    }
    int count = 0;

    if(dp[st]!=0) return dp[st];

    for(int i=1;i<=6 && st+i<=end;i++){
        count+=boardPath_01(st+i,end,dp);
        
    }

    dp[st]=count;

    return count;
}

//tabulation
int boardPath_02(int end,vi &dp){
    
    for(int st=end;st>=0;st--){

    if(st==end){
        dp[st] = 1;
        continue;
    }
    int count = 0;

    for(int i=1;i<=6 && st+i<=end;i++){
        count+=dp[st+i];
        
    }
    dp[st]=count;
    }
    return dp[0];
}

//board path with givrn array of poss outcomes
//memorization
int boardPath_01_giveOutcomes(int st, int end, vector<int> &outcomes, vector<int> &dp){
    if(st==end){
        dp[st]=1;
        return 1;
    }
    int count = 0;
    if(dp[st]!=0) return dp[st];
    
    for(int i=0;i<outcomes.size();i++){
        if(st+outcomes[i]<=end){
            count+=boardPath_01_giveOutcomes(st+outcomes[i],end,outcomes,dp);
        }
    }

    dp[st]=count;
    return count;
}
//tabulation
int boardPath_02_giveOutcomes(int end, vector<int> &outcomes, vector<int> &dp){
    
    for(int st = end;st>=0;st--){
    
    if(st==end){
        dp[st]=1;
        continue;
    }
    int count = 0;
    
    for(int i=0;i<outcomes.size();i++){
        if(st+outcomes[i]<=end){
            count+=dp[st+outcomes[i]];
        }
    }
    dp[st]=count;
    
    
    }

    return dp[0];
}


//leetcode 70
    //memo
    int climbStairs(int st,int end,vector<int>&dp){
        if(st==end){
            dp[st]=1;
            return 1;
        }
        
        int count=0;
        if(dp[st]!=0) return dp[st];
        for(int i=1;i<=2 && st+i<=end;i++){
            count+=climbStairs(st+i,end,dp);
        }
        dp[st]=count;
        return count;
    }

    //tabu
    int climbStairsDP(int end,vector<int>&dp){
        for(int st=end;st>=0;st--){ 
        
            if(st==end){
                dp[st]=1;
                continue;
            }
        
            int count=0;
            for(int i=1;i<=2 && st+i<=end;i++){
                count+=dp[st+i];
            }
            dp[st]=count;    
        }
        return dp[0];
    }
//leetcode 746

//0 push backed in cost array 
//min 2 elts present
int minCostClimbingStairs_01(int n, vector<int> &cost, vector<int> &dp) //n acts as index, cost[3]=0 in 10 15 20 exmpl
{
    if (n <= 1)
        return cost[n];
    if (dp[n] != 0)
        return dp[n];
    int c1 = minCostClimbingStairs_01(n - 1, cost, dp);
    int c2 = minCostClimbingStairs_01(n - 2, cost, dp);

    return dp[n] = min(c1, c2) + cost[n];
}

int minCostClimbingStairs_02(int n, vector<int> &cost, vector<int> &dp)
{

    for (int i = 0; i <= n; i++)
    {
        if (i <= 1)
        {
            dp[i] = cost[i];
            continue;
        }

        int c1 = dp[i - 1];
        int c2 = dp[i - 2];

        dp[i] = min(c1, c2) + cost[i];
    }

    return dp[n];
}

int minCostClimbingStairs_03(vector<int> &cost)
{

    if (cost.size() == 1)
        return cost[0];
    if (cost.size() == 2)
        return min(cost[0], cost[1]);

    int a = cost[0];
    int b = cost[1];
    for (int i = 2; i < cost.size(); i++)
    {
        int ans = cost[i] + min(a, b);
        a = b;
        b = ans;
    }

    return min(a, b);
}

int minCostClimbingStairs(vector<int> &cost)
{
    cost.push_back(0);
    int n = cost.size();

    vector<int> dp(n, 0);
    int a =  minCostClimbingStairs_01(n - 1, cost, dp);
    display(dp);
    return a;
}

//leetcode 64
int minPathSum(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == m - 1)
            {
                continue;
            }

            int c1 = j + 1 < m ? arr[i][j + 1] : 1e6;
            int c2 = i + 1 < n ? arr[i + 1][j] : 1e6;

            int minCost = min(c1, c2);
            arr[i][j] += minCost;
        }
    }

    return arr[0][0];
}


void set1(){
    //cout<<fibo(10);
    int n=2;
    //vi dp(n+1,0);
    //cout<<fibo2(n,dp);

    // for(string s:mazepath(0,0,2,2)){
    //     cout<<s<<endl;
    // }

    vii dp(n+1,vi(n+1,0));
    //cout<<mazePathHV_02(0,0,2,2,dp);
    //cout<<mazePathHV_03(n,n,dp);
     cout<<mazePathMulti(0,0,2,2)<<endl;
   // cout<<mazePathMulti_01(0,0,2,2,dp)<<endl;
    //cout<<mazePathMulti_02(2,2,dp);
     

    //cout<<boardPath_01(0,n,dp)<<endl;
    //cout<<boardPath_02(n,dp)<<endl;
    
    //vi arr = {2,3,7,5};
    //cout<<boardPath_01_giveOutcomes(0,n,arr,dp)<<endl;
    //cout<<boardPath_02_giveOutcomes(n,arr,dp)<<endl;
    
    //vi cost={10,15,20};
    //cout<<minCostClimbingStairs(cost);
    //display(dp);
    //display2(dp);

}


//Pair and single up
//rec
int pairAndSingleUp(int n,vi &dp){
    if(n<=1){
        return 1;
    }

    int count=0;
    
    count+=pairAndSingleUp(n-1,dp); //single
    count+=(n-1)*pairAndSingleUp(n-2,dp); //pair   apply for loop here if print ans too

    return count;
}

//memorization
int pairAndSingleUp_01(int n,vi &dp){
    if(n<=1){
        dp[n]=1;
        return 1;
    }
    int count=0;
    
    if(dp[n]!=0) return dp[n];

    count+=pairAndSingleUp_01(n-1,dp); //single
    count+=(n-1)*pairAndSingleUp_01(n-2,dp); //pair   apply for loop here if print ans too

    return dp[n]=count;
}

//tabulation --- we see from dp array that to start from base case
int pairAndSingleUp_02(int n,vi &dp){

    for(int i=0;i<=n;i++){
    
    if(i<=1){
        dp[i]=1;
        continue;
    }
        int count=0;
    
    //    if(dp[i]!=0) return dp[i];

        count+=dp[i-1]; //single
        count+=(i-1)*dp[i-2]; //pair   apply for loop here if print ans too

        dp[i]=count;
    }

    return dp[n];
}

//more optimized
int pairAndSingleUp_03(int n){ 
    if(n<=1){
        return 1;
    }
    int a=1;
    int b=1;
    int ans=0;
    for(int i=2;i<=n;i++){
        ans = b + a*(i-1);
        a=b;
        b=ans;
    }
    return ans;
}


//leet 45
//memorization
int minJump(int idx,vector<int>&arr,vector<int>&dp){
    if(idx==arr.size()-1) return 0;

    // if(arr[idx]==0) return (int) 1e7;  handled down
    int minAns = (int) 1e7;
    
    if(dp[idx]!=0) return dp[idx];
    
    for(int jump = 1; jump<=arr[idx] && idx + jump<arr.size();jump++){
        int recAns = minJump(idx+jump,arr,dp);
        if(recAns!=(int)1e7 && recAns+1<minAns){
            minAns = recAns + 1;
        }
    }
    dp[idx] = minAns;
    return minAns;
}

//inn ques m bs pehli recur call tak ka answer socho aage ka recursion le ayega
//for above and below ques

//tabulation  from last as observed from dp array
int minJump_01(int idx,vector<int>&arr,vector<int>&dp){
    
    int n = arr.size();
    dp[n-1] = 0;

    for(int i=n-2;i>=0;i--){

        int minAns = (int) 1e7;
    
        //if(dp[idx]!=0) return dp[idx];
    
        for(int jump = 1; jump<=arr[i] && i + jump<arr.size();jump++){
            int recAns = dp[i+jump];
            if(recAns!=(int)1e7 && recAns+1<minAns){
                minAns = recAns + 1;
            }
        }
        dp[i] = minAns;
    }
    

    return dp[0];
}

int jump(vector<int>& nums) {
    vi dp(nums.size(),0);
    int ans = minJump_01(0,nums,dp);
    display(dp);
    return ans;

}


//partition a set into k subsets
int parti(int n,int k){
    if(n==k || k==1){
        return 1;
    }
    if(n<k){
        return 0;
    }

    int newGroup = parti(n-1,k-1);
    int oldGroup = k*parti(n-1,k);

    return newGroup+oldGroup; 
}
//memo
int parti_01(int n,int k,vii&dp){

    
    if(n==k||k==1){
        dp[n][k]=1;
        return 1;
    }
    if(n<k){
        dp[n][k] = 0;
        return 0;
    }
    int count=0;

    if(dp[n][k]!=0) return dp[n][k];

    count+=parti_01(n-1,k-1,dp);
    count+=k*parti_01(n-1,k,dp);

    dp[n][k] = count;

    return count; 
}
//tabu
int parti_02(int n,int k,vii&dp){
    
    for(int i=1;i<=n;i++){
        for(int j =1;j<=k;j++){
            if(i==j || j==1){
                dp[i][j]=1;
                continue;
            }
            if(i<k){
                dp[i][j]=0;
                continue;
            }
            int count=0;

            count+=dp[i-1][j-1];
            count+=j*dp[i-1][j];

            dp[i][j] = count;
        }
    }
    return dp[n][k]; 
}

//inn ques m bs pehli recur call tak ka answer socho aage ka recursion le ayega


//gold mine
vii dirArr = {{0, 1}, {-1, 1}, {1, 1}};
int goldMine_01(int x, int y, vii &arr, vii &dp)
{
    if (y == arr[0].size() - 1)
    {
        dp[x][y] = arr[x][y];
        return arr[x][y];   //last col m to vahi cell hoga ans
    }

    if (dp[x][y] != 0)
        return dp[x][y];

    int maxAns = -1e6;
    for (int d = 0; d < 3; d++)    //1st col se 3 call lgai or sbse apna max ans mangwa liya
    {                           //max ans mai apne 1st col ka add krkr return kr diya
        int r = x + dirArr[d][0]; 
        int c = y + dirArr[d][1];

        if (r >= 0 && c >= 0 && r < arr.size() && c < arr[0].size())
            maxAns = max(maxAns, goldMine_01(r, c, arr, dp));
    }

    dp[x][y] = maxAns + arr[x][y];
    return dp[x][y];
}

int goldMine_02(vii &arr, vii &dp)
{

    for (int y = arr[0].size() - 1; y >= 0; y--)
    {
        for (int x = arr.size() - 1; x >= 0; x--)
        {
            if (y == arr[0].size() - 1)
            {
                dp[x][y] = arr[x][y];
                continue;
            }

            int maxAns = -1e6;
            for (int d = 0; d < 3; d++)
            {
                int r = x + dirArr[d][0];
                int c = y + dirArr[d][1];

                if (r >= 0 && c >= 0 && r < arr.size() && c < arr[0].size())
                    maxAns = max(maxAns, dp[r][c]);
            }

            dp[x][y] = maxAns + arr[x][y];
        }
    }

    int maxAns = -1e6;
    for (int row = 0; row < arr.size(); row++)
    {
        maxAns = max(maxAns, dp[row][0]);
    }

    return maxAns;
}

void goldMine()
{
    vii arr = {{1, 3, 3},
               {2, 1, 4},
               {0, 6, 4}};
    vii dp(arr.size(), vi(arr[0].size(), 0));

    // int maxAns = -1e6;
    // for (int row = 0; row < arr.size(); row++)
    // {
    //     maxAns = max(maxAns, goldMine_01(row, 0, arr, dp));
    // }
    // cout << maxAns << endl;

    cout << goldMine_02(arr, dp) << endl;
    display2(dp);
}

//===========================================
//maximum size square submatrix with all 1's

//memo - this not fully right
int maxSquare=0;

int maxSubMat_01(int x,int y, vii &arr,vii&dp){
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


//tabu- dp sol is much better to understand of for loop
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


//tile floor n X m
//https://www.geeksforgeeks.org/count-number-ways-tile-floor-size-n-x-m-using-1-x-m-size-tiles/
//memo
int tileFloor(int n,int m,vi &dp){
    if(n<=m){
        dp[n] = ((n==m) ? 2:1);
        return dp[n];
    }

    if(dp[n]!=0) return dp[n];

    int horizontal = tileFloor(n-1,m,dp);
    int vertical = tileFloor(n-m,m,dp);

    dp[n] = horizontal + vertical;
    return dp[n];
}

//tabu
int tileFloor_01(int n,int m,vi &dp){
    
    for(int i=0;i<=n;i++){
    if(i<=m){
        dp[i] = ((i==m) ? 2:1);
        continue;
    }

    int horizontal = dp[i-1];
    int vertical = dp[i-m];

    dp[i] = horizontal + vertical;
    }
    

    return dp[n];
}

//======================================================
//coins to make target

int coinChangePermutation(vector<int> &arr, int tar, vector<int> &dp)
{
    if (tar == 0) return dp[tar] = 1;
    
    if (dp[tar] != 0) return dp[tar];

    int count = 0;
    for (int ele : arr)
        if (tar - ele >= 0)
            count += coinChangePermutation(arr, tar - ele, dp);

    return dp[tar] = count;
}

int coinChangePermutation_DP(vector<int> &arr, int tar, vector<int> &dp)
{
    dp[0] = 1;
    int Tar = tar;
    for (int tar = 0; tar <= Tar; tar++)
    {
        int count = 0;
        for (int ele : arr)
            if (tar - ele >= 0)
                count += dp[tar - ele];

        dp[tar] = count;
    }
}

int coinChangeCombination_DP(vector<int> &arr, int tar, vector<int> &dp)
{
    dp[0] = 1;
    int Tar = tar;
    for (int ele : arr)
        for (int tar = ele; tar <= Tar; tar++)
            dp[tar] += dp[tar - ele];
}

//leetcode 322  can be done by both combi/permu
//like leet 45, basically we need to find the height of tree which is minimum
    //using permu 
    int minCoins(vector<int>&arr,int tar,vector<int>&dp){
        if(tar==0){
            //dp[tar]=0;
            return 0;
        }
        if(dp[tar]!=1e8) return dp[tar];
        int minans = 1e8; 
        for(int i=0;i<arr.size();i++){
            if(tar-arr[i]>=0){
                int recAns = minCoins(arr,tar-arr[i],dp);
                if(recAns<minans){
                    minans = recAns+1;
                }
            }
        }
        dp[tar] = minans;
        return minans;

    }

    int minCoins_01(vector<int>arr,int tar,vector<int>dp){
        dp[0]=0;
        for(int t=1;t<=tar;t++){
            for(int i=0;i<arr.size();i++){
                if(t-arr[i]>=0){
                    dp[t]=min(dp[t],dp[t-arr[i]])+1;
                }
            }
        }
        return dp[tar];
    }

    int coinChange(vector<int>& coins, int amount) {
        if(coins.size()==0 || amount<=0) return 0;
        vector<int>dp(amount+1,1e8);
        int ans = minCoins_01(coins,amount,dp);
        return ans!=1e8?ans:-1;
    }


    //target sum: combination of coins using only unique coins
    
    int targetSum(int target,int idx,vi &arr,vii &dp){  //here dp for loop is started from top right corner which is not ideal so below sol is betr to convert to dp

        if(target==0 || idx==arr.size()){
            if(target==0)
                return dp[idx][target]=1;
            return dp[idx][target]=0;
        }
        int count=0;
        
        if(dp[idx][target]!=0) return dp[idx][target];

        if(target-arr[idx]>=0)
            count+=targetSum(target-arr[idx],idx+1,arr,dp); //coin use krne ki call
        
        count+=targetSum(target,idx+1,arr,dp); //coin na use krne ki call
        return dp[idx][target]= count;
    }


    //memo
    int targetSum_01(int target,int idx,vi &arr,vii &dp){  //easy for dp sol as started from back
                                                    //piche se chlane k liye n use kro as in knapsack used
        if(target==0 || idx==0){
            if(target==0)
                return dp[idx][target]=1;
            return dp[idx][target]=0;
        }
        int count=0;
        
        if(dp[idx][target]!=0) return dp[idx][target];

        if(target-arr[idx-1]>=0)
            count+=targetSum_01(target-arr[idx-1],idx-1,arr,dp);
        
        count+=targetSum_01(target,idx-1,arr,dp);
        return dp[idx][target]= count;
    }

    int printPathOfTargetSum(vector<int> &coins, int idx, int tar, string ans, vector<vector<bool>> &dp)
{
    if (tar == 0 || idx == 0)
    {
        if (tar == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    if (tar - coins[idx - 1] >= 0 && dp[idx - 1][tar - coins[idx - 1]])
        count += printPathOfTargetSum(coins, idx - 1, tar - coins[idx - 1], ans + to_string(coins[idx - 1]) + " ", dp);

    if (dp[idx - 1][tar])
        count += printPathOfTargetSum(coins, idx - 1, tar, ans, dp);

    return count;
}

    //tabu
    int targetSumDP(int target,vi &arr,vii &dp){
        
        dp[0][0]=1;
        for(int i=1;i<arr.size();i++){   //starting from 1 as 0 se koi call ni lagg paegi kyuki dono mai hm ek level upr jaa re hai
            for(int t=0;t<=target;t++){
                
                if(t==0){
                    dp[i][t]=1;
                    continue;
                } 

                if(t-arr[i]>=0){
                    dp[i][t] += dp[i-1][t-arr[i]]; 
                }
                dp[i][t] += dp[i-1][t];

            }
        }
        return dp[arr.size()-1][target];
    }

    //knapsack gfg
int knapSack_01(vi &weight, vi &cost, int n, int cap, vii &dp)
{
    if (cap == 0 || n == 0) 
    {
        return 0; //kyuki cost ki term m baat krre hai, price 0 hoga if cap 0 or no ele ie n =0;
    }

    if (dp[n][cap] != 0)
        return dp[n][cap];

    int picked = 0, unpicked = 0;
    if (cap - weight[n-1] >= 0)
        picked = knapSack_01(weight, cost, n - 1, cap - weight[n-1], dp) + cost[n-1];
    unpicked = knapSack_01(weight, cost, n - 1, cap, dp);

    return dp[n][cap] = max(picked, unpicked);
}

int knapSack_02(vi &weight, vi &cost, int capacity, vii &dp)
{

    for (int idx = 1; idx < dp.size(); idx++)
    {
        int weightIdx = idx - 1;
        for (int cap = 0; cap <= capacity; cap++)
        {
            int picked = 0, unpicked = 0;
            if (cap - weight[weightIdx] >= 0)
                picked = dp[idx - 1][cap - weight[weightIdx]] + cost[weightIdx];
            unpicked = dp[idx - 1][cap];

            dp[idx][cap] = max(picked, unpicked);
        }
    }

    return dp[dp.size() - 1][dp[0].size() - 1];
}

int unbounded(vector<int> &w, vector<int> &p, int weight)
{
    vector<int> dp(w.size() + 1, -1e8);
    dp[0] = 0;
    for (int i = 0; i < w.size(); i++)
        for (int tar = w[i]; tar <= weight; tar++)
            dp[tar] = max(dp[tar], dp[tar - w[i]] + p[i]);

    return dp[w.size()];
}

void knapsack()
{
    vector<int> p = {100, 280, 120};
    vector<int> w = {10, 40, 20};
    int weight = 60;
    int n = w.size();
    vector<vector<int>> dp(n + 1, vector<int>(weight + 1, 0));

    // cout << knapsack_01(w, p, weight, n, dp) << endl;
}

//Leetcode 416
bool canPartition_(vector<int> &nums, int n, int sum, vector<vector<int>> &dp)
{
    if (sum == 0 || n == 0)
    { 
        if (sum == 0)
            return dp[n][sum] = 1;
        return dp[n][sum] = 0;
    }

    if (dp[n][sum] != -1)
        return dp[n][sum];

    bool res = false;
    if (sum - nums[n - 1] >= 0)
        res = res || canPartition_(nums, n - 1, sum - nums[n - 1], dp) == 1;
    res = res || canPartition_(nums, n - 1, sum, dp) == 1;

    dp[n][sum] = res ? 1 : 0;
    return res;
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int ele : nums)
        sum += ele;
    if (sum % 2 != 0)
        return false;

    sum /= 2;
    vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, -1));

    return canPartition_(nums, nums.size(), sum, dp);
}



//===================================================================
//stringSet =========================================================

// public static boolean isPali(String str){
//         int i=0;
//         int j=str.length()-1;
//         while(i<=j){
//             char start = str.charAt(i);
//             char end = str.charAt(j);
//             if(start!=end){
//                 return false;
//             }
//             i++;
//             j--;
//         }
//         return true;
//     }

// 	public static void printAllSubstr(String str){
// 		//write your code here
		
// 		for(int i=0;i<str.length();i++ ){
// 		    for(int j=i+1;j<=str.length();j++){
// 		        String s = str.substring(i,j);
// 		        if(isPali(s)){ avoid this to simply print substrings
// 		            System.out.println(s);
// 		        }
// 		    }
// 		}
		
// 	}

// auto speedup = [](){
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//     return nullptr;
// }();


vector<vector<bool>> isPlaindromeSubstring(string str)
{
    int n = str.length();
    vector<vector<bool>> dp(n, vector<bool>(n, 0));
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
                dp[i][j] = true;
            else if (gap == 1 && str[i] == str[j])
                dp[i][j] = true;
            else
                dp[i][j] = str[i] == str[j] && dp[i + 1][j - 1];
        }
    }

    return dp;
}

//Leetcode 005.==================================================================
string longestPlaindromeSubstring(string str)
{
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    int maxLen = 0;
    int si = 0, ei = 0;
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
                dp[i][j] = 1;
            else if (gap == 1 && str[i] == str[j])
                dp[i][j] = 2;
            else if (str[i] == str[j] && dp[i + 1][j - 1] != 0)
                dp[i][j] = gap + 1;

            if (dp[i][j] > maxLen)
            {
                maxLen = dp[i][j];
                si = i;
                ei = j;
            }
        }
    }

    return str.substr(si, (ei - si + 1));
}

//Leetcode 647.=================================================================================
int countAllPlaindromicSubstring(string str)
{
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    int count = 0;
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            if (gap == 0)
                dp[i][j] = 1;
            else if (gap == 1 && str[i] == str[j])
                dp[i][j] = 2;
            else if (str[i] == str[j] && dp[i + 1][j - 1] != 0)
                dp[i][j] = gap + 1;

            count += dp[i][j] != 0 ? 1 : 0;
        }
    }
}

//leet 516===============================================================
int longestPlaindromeSubseq_Rec(string str, int si, int ei, vector<vector<int>> &dp)
{
    if (si > ei)
        return 0;
    if (si == ei)
        return dp[si][ei] = 1;
    if (dp[si][ei] != 0)
        return dp[si][ei];

    int len = 0;
    if (str[si] == str[ei])
        len = longestPlaindromeSubseq_Rec(str, si + 1, ei - 1, dp) + 2;
    else
        len = max(longestPlaindromeSubseq_Rec(str, si + 1, ei, dp), longestPlaindromeSubseq_Rec(str, si, ei - 1, dp));

    return dp[si][ei] = len;
}

int LongestPlaindromeSubsequence(string str,vii &dp){
    
    for(int gap=0;gap<str.length();gap++){
        for(int i=0,j=gap;j<str.length();i++,j++){
            if(gap==0) dp[i][j]=1;
            
            else if(str[i]==str[j]) dp[i][j]=dp[i+1][j-1] +2;
            else{
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
     
        }
    }
       return dp[0][str.length()-1];
}


//Geeks: https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1
int countPS(string &s, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
        return dp[i][j] = 1;
    if (dp[i][j] != 0)
        return dp[i][j];

    int middleString = countPS(s, i + 1, j - 1, dp);
    int excludingLast = countPS(s, i, j - 1, dp);
    int excludingFirst = countPS(s, i + 1, j, dp);

    int ans = excludingFirst + excludingLast;
    return dp[i][j] = (s[i] == s[j]) ? ans + 1 : ans - middleString;
}

int countPS_DP(string &s, int i, int j, vector<vector<int>> &dp)
{

    int n = s.length();
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, i++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
                continue;
            }

            int middleString = dp[i + 1][j - 1];
            int excludingLast = dp[i][j - 1];
            int excludingFirst = dp[i + 1][j];

            int ans = excludingFirst + excludingLast;
            dp[i][j] = (s[i] == s[j]) ? ans + 1 : ans - middleString;
        }
    }
    return dp[0][n - 1];
}





//Leetcode 115 : distinct-subsequences.=========================================================
int distinct_subsequences(string S, string T, int n, int m, vector<vector<int>> &dp)
{
    if (m == 0)
        return dp[n][m] = 1;
    if (m > n)
        return dp[n][m] = 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (S[n - 1] == T[m - 1])
        return dp[n][m] = distinct_subsequences(S, T, n - 1, m - 1, dp) + distinct_subsequences(S, T, n - 1, m, dp);

    return dp[n][m] = distinct_subsequences(S, T, n - 1, m, dp);
}

int distinct_subsequences_02(string S, string T, int i, int j, vector<vector<int>> &dp)
{
    if (T.length() - j == 0)
        return dp[i][j] = 1;
    if (S.length() - i > T.length() - j)
        return dp[i][j] = 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (S[i] == T[j])
        return dp[i][j] = distinct_subsequences_02(S, T, i + 1, j + 1, dp) + distinct_subsequences_02(S, T, i + 1, j, dp);

    return dp[i][j] = distinct_subsequences_02(S, T, i + 1, j, dp);
}

int distinct_subsequences_DP(string S, string T, int n, int m, vector<vector<int>> &dp)
{
    int N = n, M = m;
    for (n = 0; n <= N; n++)
    {
        for (m = 0; m <= M; m++)
        {
            if (m == 0)
            {
                dp[n][m] = 1;
                continue;
            }
            if (m > n)
            {
                dp[n][m] = 0;
                continue;
            }
            if (S[n - 1] == T[m - 1])
                dp[n][m] = dp[n - 1][m - 1] + dp[n - 1][m];
            else
                dp[n][m] = dp[n - 1][m];
        }
    }

    return dp[N][M];
}

int numDistinct(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // cout << distinct_subsequences(s, t, n, m, dp) << endl;
    cout << distinct_subsequences_DP(s, t, n, m, dp) << endl;

    display2(dp);
}



// Leetcode 1143.====================================================================
int longestCommonSubsequence(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
{
    if (i == text1.length() || j == text2.length())
        return dp[i][j] = 0;
    if (dp[i][j] != 0)
        return dp[i][j];

    int ans = 0;
    if (text1[i] == text2[j])
        ans = longestCommonSubsequence(text1, text2, i + 1, j + 1, dp) + 1;
    else
        ans = max(longestCommonSubsequence(text1, text2, i + 1, j, dp), longestCommonSubsequence(text1, text2, i, j + 1, dp));

    return dp[i][j] = ans;
}

int longestCommonSubsequence_DP(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
{
    for (i = text1.length(); i >= 0; i--)
    {
        for (j = text2.length(); j >= 0; j--)
        {
            if (i == text1.length() || j == text2.length())
                continue;

            int ans = 0;
            if (text1[i] == text2[j])
                ans = dp[i + 1][j + 1] + 1;
            else
                ans = max(dp[i + 1][j], dp[i][j + 1]);

            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

//subseq mai exc first,exc last calls se bhi answer ata h,substring m kewal tabhi ata hai jab char match hojae

int max_ = 0;
int longestCommonSubstring(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
{
    if (i == text1.length() || j == text2.length())
        return dp[i][j] = 0;
    if (dp[i][j] != 0)
        return dp[i][j];

    int a = longestCommonSubstring(text1, text2, i + 1, j, dp);
    int b = longestCommonSubstring(text1, text2, i, j + 1, dp);

    if (text1[i] == text2[j])
    {
        int a = longestCommonSubstring(text1, text2, i + 1, j + 1, dp) + 1;
        max_ = max(max_, a);
        return dp[i][j] = a;
    }

    return 0;
}

int longestCommonSubstring_DP(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
{
    int max_ = 0;
    for (i = text1.length(); i >= 0; i--)
    {
        for (j = text2.length(); j >= 0; j--)
        {
            if (i == text1.length() || j == text2.length())
                continue;

            int ans = 0;
            if (text1[i] == text2[j])
            {
                ans = dp[i + 1][j + 1] + 1;
                max_ = max(max_, ans);
            }
            int a = dp[i + 1][j];
            int b = dp[i][j + 1];

            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
    int ans = 0;
    // ans = longestCommonSubsequence(text1, text2, 0, 0, dp);
    ans = longestCommonSubsequence_DP(text1, text2, 0, 0, dp);
    display2(dp);
    return ans;
}


//leet 1035.===========================================
//based on longest common subseq

int maxUncrossedLines(vector<int> &A, vector<int> &B)
{
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = n; i >= 0; i--)
    {
        for (int j = m; j >= 0; j--)
        {
            if (i == n || m == j)
            {
                dp[i][j] = 0;
                continue;
            }
            if (A[i] == B[j])
                dp[i][j] = dp[i + 1][j + 1] + 1;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    return dp[0][0];
}

//leetcode 1458.
int maxDotProduct_(int i,int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>&dp) {
        if(i==nums1.size() || j==nums2.size()){
            return dp[i][j] = -1e8;
        }
        if(dp[i][j]!=0) return dp[i][j];
        
        int val=nums1[i]*nums2[j];   //vahi 2 value max h
        int a=maxDotProduct_(i+1,j+1,nums1,nums2,dp) + val;  //ye 2 sahi h or baki bache se kro
        int b=maxDotProduct_(i,j+1,nums1,nums2,dp); //inn dono ka nhi jamm raha,ek ko aage krkr fir compare kro
        int c=maxDotProduct_(i+1,j,nums1,nums2,dp);
        
        int ans=max(max(a,b),max(c,val));
        
        return dp[i][j]=ans;
    }

int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = n; i >= 0; i--)
    {
        for (int j = m; j >= 0; j--)
        {
            if (i == n || m == j)
            {
                dp[i][j] = -1e8;
                continue;
            }

            int val = nums1[i] * nums2[j];
            int a = dp[i + 1][j + 1] + val;
            int b = dp[i + 1][j];
            int c = dp[i][j + 1];

            dp[i][j] = max(max(a, b), max(c, val));
        }
    }

    return dp[0][0];
}

//Leetcode 72, edit distance.

int minDistance(string &word1, string &word2, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
    {
        return dp[n][m] = (n == 0 ? m : n);
    }

    if (dp[n][m] != 0)
        return dp[n][m];
    if (word1[n - 1] == word2[m - 1])
        return dp[n][m] = minDistance(word1, word2, n - 1, m - 1, dp);

    int insert_ = minDistance(word1, word2, n, m - 1, dp);
    int replace_ = minDistance(word1, word2, n - 1, m - 1, dp);
    int delete_ = minDistance(word1, word2, n - 1, m, dp);

    return dp[n][m] = min(min(insert_, replace_), delete_);
}





//LIS========================================================
//LIS: mai sbse bda hu mrse piche wale jo mrse chote h mre answer m contribute krenge

int LISmax_ = 0;
int LIS_Rec(vi &arr, int ei, vi &dp)
{
    if (ei == 0)
        return 1;

    int max_ = 1;
    for (int i = ei - 1; i >= 0; i--)
    {
        int recAns = LIS_Rec(arr, i, dp);
        if (arr[i] < arr[ei])
        {
            LISmax_ = max(LISmax_, recAns + 1);
            max_ = max(max_, recAns + 1);
        }
    }

    // dp[ei]=max_;
    return max_;
}



int LIS_leftToRight(vector<int> &arr, vector<int> &dp)
{
    int N = arr.size();
    int oMax = 0;
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        oMax = max(oMax, dp[i]);
    }
    return oMax;
}

//lds left to right = lis right to left
  //right se lis chla do  

int LIS_rightToLeft(vector<int> &arr, vector<int> &dp)
{
    int N = arr.size();
    int oMax = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        dp[i] = 1;
        for (int j = i + 1; j < N; j++)
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        oMax = max(oMax, dp[i]);
    }
    return oMax;
}

//https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/
//Longest bitonic subsequence
int LBS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> LIS(n, 0);
    vector<int> LDS(n, 0);

    LIS_leftToRight(arr, LIS);
    LIS_rightToLeft(arr, LDS);

    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int len = LIS[i] + LDS[i] - 1;
        maxLen = max(maxLen, len);
    }
    return maxLen;
}

// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0
int maximumIncreasingSumSubsequence(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);

    int oMax = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + arr[i]);
        }

        oMax = max(oMax, dp[i]);
    }
    return oMax;
}

// Minimum number of deletion to make sorted sequence.
// minimum no of deletion to make array in sorted order in increasing order.
int minDeletion(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);

    int oMax = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] <= arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }

        oMax = max(oMax, dp[i]);
    }

    return n - oMax; //main logic otherwise LIS
}

//Leetcode 354
int maxEnvelopes(vector<vector<int>> &arr)
{
    // for Java:
    // Arrays.sort(arr,(int[] a, int[] b)-> {
    //     if (a[0] == b[0])
    //         return b[1] - a[1]; // other - this
    //     return a[0] - b[0];     // this - other. default
    // });

    sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b) {
        if (a[0] == b[0])
            return b[1] < a[1]; // other - this
        return a[0] < b[0];     // this - other., for cpp replace '-' with '<' default
    });

//sorted to manage width

    int n = arr.size();
    vector<int> dp(n, 0);

    int oMax = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j][1] < arr[i][1]) //height compared here
                dp[i] = max(dp[i], dp[j] + 1);
        }

        oMax = max(oMax, dp[i]);
    }

    return oMax;
}

//--------------------------------------------------> // for you : 1027, 1235

int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    if (n <= 1)
        return n;

    vector<int> dp(n, 0);
    vector<int> count(n, 0);

    int maxLen = 0;
    int maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        count[i] = 1;

        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j]<arr[i])
            {
                if (dp[j] + 1 > dp[i]) //here subseq len is updated
                {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }
                else if (dp[j] + 1 == dp[i]) //here if len is same then count added
                    count[i] += count[j];
            }
        }

        if (dp[i] > maxLen)
        {
            maxLen = dp[i];
            maxCount = count[i];
        }
        else if (dp[i] == maxLen)
            maxCount += count[i];
    }

    return maxCount;
}

//==============================================================================================================

void LIS_Type()
{
    vector<int> arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    vector<int> dp(arr.size(), 0);

    cout << LIS_leftToRight(arr, dp) << endl;
}



//CutType.=============================================================

int MCM_rec(vector<int> &arr, int si, int ei, vector<vector<int>> &dp)
{
    if (si + 1 == ei)
        return dp[si][ei] = 0;

    if (dp[si][ei] != -1)
        return dp[si][ei];

    int ans = 1e8;
    for (int cut = si + 1; cut < ei; cut++)
    {
        int leftCost = MCM_rec(arr, si, cut, dp);
        int rightCost = MCM_rec(arr, cut, ei, dp);

        int myCost = leftCost + arr[si] * arr[cut] * arr[ei] + rightCost;
        if (myCost < ans)
            ans = myCost;
    }

    return dp[si][ei] = ans;
}

pair<int,string> MCM_memoString(vi &arr,int si,int ei,vector<vector<pair<int,string>>> &dp){
    if(si+1==ei){
        string str = string(1,(char)(si+'A'));  //here 1 denotes ki ek length ke char ko string m convert kardo
        dp[si][ei]={0,str};
        return dp[si][ei];
    }
if(dp[si][ei].first!=0) return dp[si][ei];

pair<int,string> minAns = {1e7,""};

for(int cut=si+1;cut<ei;cut++){
    pair<int,string> left=MCM_memoString(arr,si,cut,dp);
    pair<int,string> right = MCM_memoString(arr,cut,ei,dp);
    int ans = left.first+ arr[si]*arr[cut]*arr[ei] + right.first;
    
    if(ans<minAns.first){
        minAns.first=ans;
        minAns.second = "(" + left.second + right.second + ")";
    }
}
return dp[si][ei]=minAns;
}


int mcm_DP(vi &arr, vii &dp) //O(n^3)
{

    int n = arr.size();
    vector<vector<string>> sdp(n, vector<string>(n, ""));

    for (int gap = 1; gap < arr.size(); gap++)
    {
        for (int si = 0, ei = gap; ei < arr.size(); si++, ei++)
        {
            if (si + 1 == ei) //cost of multiplication of a single matrix is zero.
            {
                dp[si][ei]=0;
                sdp[si][ei] = char(si + 'A');
                continue;
            }

            int minAns = 1e7;
            string sans="";
            for (int cut = si + 1; cut < ei; cut++)
            {
                int left = dp[si][cut];
                int right = dp[cut][ei];

                int myCost = left + arr[si] * arr[cut] * arr[ei] + right;
                if (myCost < minAns)
                {
                    
                    minAns = myCost;
                    sans = "(" + sdp[si][cut] + sdp[cut][ei] + ")";
                }
            }
            dp[si][ei] = minAns;
            sdp[si][ei]=sans;
        }
    }

    cout << sdp[0][arr.size() - 1] << " -> " << dp[0][arr.size() - 1] << endl;
    return dp[0][arr.size() - 1];
}


//OBST : Optimal Binary Search Tree- mcm based

//use prefix sum to make this O(1)
int sumInRange(vi&freq,int si,int ei){
    int sum=0;
    for(int i=si;i<=ei;i++){
        sum+=freq[i];
    }
    return sum;
}

int OBST(vi&freq,vi&arr,int si,int ei,vii&dp){ // mcm: O(n^3) * sumInRange: O(n) = O(n^4)
    
    if(dp[si][ei]!=0) return dp[si][ei];
    int minAns= 1e7;

    for(int cut=si;cut<=ei;cut++){
        int left =(cut==si)?0:OBST(freq,arr,si,cut-1,dp);
        int right = (cut==ei)?0:OBST(freq,arr,cut+1,ei,dp);
        int myCost = left + sumInRange(freq,si,ei) + right;
        minAns=min(myCost,minAns);
    }
    return dp[si][ei] = minAns;
}

int OBST_DP(vector<int> &freq, int si, int ei, vector<vector<int>> &dp)
{
    vector<int> prefixSum(freq.size() + 1, 0);
    for (int i = 1; i < prefixSum.size(); i++)
        prefixSum[i] = prefixSum[i - 1] + freq[i - 1];

    for (int gap = 0; gap < freq.size(); gap++)
    {
        for (int si = 0, ei = gap; ei < freq.size(); si++, ei++)
        {
            int ans = 1e8;
            for (int cut = si; cut <= ei; cut++)
            {
                int leftTreeCost = (cut == si) ? 0 : dp[si][cut - 1];
                int rightTreeCost = (cut == ei) ? 0 : dp[cut + 1][ei];

                // int myCost = leftTreeCost + costOfSearching(freq, si, ei) + rightTreeCost;
                int myCost = leftTreeCost + (prefixSum[ei + 1] - prefixSum[si]) + rightTreeCost;
                if (myCost < ans)
                    ans = myCost;
            }

            dp[si][ei] = ans;
        }
    }

    return dp[0][freq.size() - 1];
}



int minimumPalindromicCut_rec(string str, int si, int ei, vii &dp, vbb &isPali)
{
    if (isPali[si][ei])
    {
        dp[si][ei] = 0;
        return 0;
    }
    if (dp[si][ei] != 0)
        return dp[si][ei];

    int min_ = 1e7;
    for (int cut = si; cut < ei; cut++)
    {
        int left = minimumPalindromicCut_rec(str, si, cut, dp, isPali);
        int right = minimumPalindromicCut_rec(str, cut + 1, ei, dp  , isPali);

        min_ = min(min_, left + 1 + right);
    }

    dp[si][ei] = min_;
    return min_;
}

int minimumPalindromicCut_DP(string str, vii &dp, vbb &isPali)
{

    for (int gap = 1; gap < str.length(); gap++)
    {
        for (int si = 0, ei = gap; ei < str.length(); si++, ei++)
        {
            if (isPali[si][ei])
            {
                dp[si][ei] = 0;
                continue;
            }

            int min_ = 1e7;
            for (int cut = si; cut < ei; cut++)
            {
                int left = dp[si][cut];
                int right = dp[cut + 1][ei];
                min_ = min(min_, left + 1 + right);
            }

            dp[si][ei] = min_;
        }
    }

    return dp[0][str.length() - 1];
}


//burst balloons

int burstBalloons(vi & arr,int si,int ei,vii&dp){
    if(dp[si][ei]!=0) return dp[si][ei];
    
    int l= (si-1==-1)?1:arr[si-1];
    int r=(ei+1==arr.size())?1:arr[ei+1];

    int maxAns=0;
    for(int cut=si;cut<=ei;cut++){
        int left = (cut==si)?0:burstBalloons(arr,si,cut-1,dp);
        int right = (cut==ei)?0:burstBalloons(arr,cut+1,ei,dp);

        int myCost = left + l*arr[cut]*r + right;

        maxAns=max(maxAns,myCost);
    }
    return dp[si][ei]=maxAns;
}

int burstBalloons_DP(vi & arr,int si,int ei,vii&dp){

    for (int gap = 0; gap < arr.size(); gap++)
    {
        for (int si = 0, ei = gap; ei < arr.size(); si++, ei++)
        {

    
    int l= (si-1==-1)?1:arr[si-1];
    int r=(ei+1==arr.size())?1:arr[ei+1];

    int maxAns=0;
    for(int cut=si;cut<=ei;cut++){
        int left = (cut==si)?0:dp[si][cut-1];
        int right = (cut==ei)?0:dp[cut+1][ei];

        int myCount = left + l*arr[cut]*r + right;

        maxAns=max(maxAns,myCount);
    }
    dp[si][ei]=maxAns;

        }
    }
    return dp[0][arr.size()-1];
}


//==================================================================================

//Leetcode :91. Decode Ways
int numDecodings_(string &s, int vidx, vector<int> &dp)
{
    if (vidx == s.length())
    {
        return dp[vidx] = 1;
    }
    if (dp[vidx] != -1)
        return dp[vidx];

    char ch = s[vidx];
    if (ch == '0')
        return dp[vidx] = 0;

    int count = 0;
    count += numDecodings_(s, vidx + 1, dp);
    if (vidx < s.size() - 1)
    {
        int num = (ch - '0') * 10 + (s[vidx + 1] - '0');
        if (num <= 26)
            count += numDecodings_(s, vidx + 2, dp);
    }

    return dp[vidx] = count;
}

//gfg
int AiBjCk(string str) //learn
{
    int Acount = 0;
    int Bcount = 0;
    int Ccount = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'a')
            Acount = Acount + (1 + Acount);
        else if (str[i] == 'b')
            Bcount = Bcount + (Acount + Bcount);
        else
            Ccount = Ccount + (Bcount + Ccount);
    }

    return Ccount;
}

void set2(){
    // int n=7;
    // int k=4;
    //vi dp(n+1,0);
    //vii dp(n+1,vi(k+1,0));

    // cout<<pairAndSingleUp_01(n,dp)<<endl;
    // cout<<pairAndSingleUp_02(n,dp)<<endl;
    // cout<<pairAndSingleUp_03(n)<<endl;
    //vi nums = {2,3,1,1,4};
    //cout<<jump(nums)<<endl;
    
   // cout<<parti_01(n,k,dp)<<endl;
    //display2(dp);

    //goldMine();

    // vii arr =      {{0, 1, 1, 0, 1},  
    //                 {1, 1, 0, 1, 0},  
    //                 {0, 1, 1, 1, 0},  
    //                 {1, 1, 1, 1, 0},  
    //                 {1, 1, 1, 1, 1},  
    //                 {0, 0, 0, 0, 0}}; 
    //  vii dp(arr.size(), vi(arr[0].size(), -1));

    //cout<<maxSubMat(0,0,arr,dp)<<endl;
    //cout<<maxSubMat_01(arr,dp)<<endl;
    //cout<<maxSquare<<endl;
    
    //cout<<tileFloor(n,k,dp)<<endl;
//     int tar=10;
//     vi arr = {2,3,5,7};
//     vi dp(tar+1,0);
//    cout<<coinChangePermu_01(arr,tar,dp)<<endl;
    //cout<<coinChangeCombi_01(arr,tar,dp)<<endl;
    

    // int tar=11;
    // vi arr = {1,2,5};
    // vi dp(tar+1,0);
    // cout<<minCoins(arr,tar,dp)<<endl;

    // int tar=10;
    // vi arr = {2,3,5,7};
    // vii dp(arr.size()+1,vi(tar+1,0));
    // cout<<targetSum(tar,0,arr,dp)<<endl;

    //     int tar=10;
    // vi arr = {2,3,5,7};
    // vii dp(arr.size()+1,vi(tar+1,0));
    // cout<<targetSum_01(tar,arr.size(),arr,dp)<<endl;


    // int tar=10;
    // vi arr = {0,2,3,5,7};
    // vii dp(arr.size(),vi(tar+1,0));
    // cout<<targetSum_01(tar,arr,dp)<<endl;


    vi weight = {2, 5, 1, 3, 4};
    vi cost = {15, 14, 10, 45, 30};
    int cap = 7;
    vii dp(weight.size() + 1, vi(cap + 1, 0));
    cout << knapSack_01(weight, cost, cost.size(), cap, dp) << endl;
    // cout << knapSack_02(weight, cost, cap, dp) << endl;

    //cout << unboundedKnapSack(weight, cost, cap) << endl;


    //display(dp);
    display2(dp);
}

void stringSet(){

    string str = "efabcbadd";
    int n = str.length();
    vii dp(n, vi(n, 0));

    // cout << LongestPlaindromeSubstring(str, dp) << endl;
    cout << LongestPlaindromeSubsequence(str, dp) << endl;


    display2(dp);
}


void cutType(){
    // vi arr = {10,20,30,40,30};
    // vii dp(arr.size(),vi(arr.size(),0));
    //cout<<MCM_memo(arr,0,arr.size()-1,dp)<<endl;
    
    // vector<vector<pair<int,string>>> dp(arr.size(),vector<pair<int,string>>(arr.size(),{0,""}));
    // pair<int,string> ans =MCM_memoString(arr,0,arr.size()-1,dp);
    // cout<<ans.second<<" -> "<<ans.first;


    // vii dp(arr.size(),vi(arr.size(),0));
    // mcm_DP(arr,dp);

    string str = "abcbddf";
    // int n = str.length();                                                                                                                                                                                                                                                                     

    // vii dp(n, vi(n, 0));

    // vbb isPali = isPlaindromeSubstring(str);
    // cout << minimumPalindromicCut_rec(str, 0, n - 1, dp, isPali) << endl;
    // cout << minimumPalindromicCut_DP(str, dp, isPali) << endl;


    vi arr = {3,1,5,8};
    int n = arr.size();
    vii dp(n, vi(n, 0));
    cout<<burstBalloons(arr,0,n-1,dp)<<endl;
    display2(dp);
}

int main(){
    set1();
    //set2();
    //stringSet();
    //LIS();
    //cutType();
    return 0;
}


//64,70,746 leet
//leet 45,55