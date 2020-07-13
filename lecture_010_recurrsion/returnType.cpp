#include <iostream>
#include <vector>

using namespace std;

//==============================================
string removeHi(string str)
{
    if (str.length() == 0)
    {
        return "";
    }

    char ch = str[0];
    if (str.size() > 1 && str.substr(0, 2) == "hi")
    {
        return removeHi(str.substr(2));
    }
    else
    {
        return ch + removeHi(str.substr(1));
    }
}

string removeHi2(string str)
{ //dont remove hi if it becomes hit
    if (str.length() == 0)
    {
        return "";
    }

    char ch = str[0];
    if (str.size() > 1 && str.substr(0, 2) == "hi" && str.substr(0, 3) != "hit")
    {
        return removeHi2(str.substr(2));
    }
    else
    {
        return ch + removeHi2(str.substr(1));
    }
}

//REMOVE DUPLICACY: aaaabccde7ghhha = abcde7gha
string removeDuplicate(string str)
{
    if (str.length() == 0)
    {
        return "";
    }

    char ch = str[0];
    if (str.length() > 1 && ch == str[1])
    {
        return removeDuplicate(str.substr(1));
    }
    else
    {
        return ch + removeDuplicate(str.substr(1));
    }
}

//Another method for c++ only to remove duplicate
void removeDupli0(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    if (ans[ans.length() - 1] != str[0])
        ans += str[0];

    removeDupli0(str.substr(1), ans);
}

//COMBINATIONS: abc= 2^3= 8, i.e,  - c b bc a ac ab abc
vector<string> subseq(string str)
{
    if (str.length() == 0)
    {
        vector<string> ar;
        ar.push_back("");
        return ar;
    }
    char ch = str[0];
    vector<string> smallAns = subseq(str.substr(1));

    vector<string> myAns(smallAns);

    for (string s : smallAns)
    {
        myAns.push_back(ch + s);
    }
    return myAns;
}

vector<string>permutation(string str){
    if(str.length()==1){
        vector<string>base;
        base.push_back(str);
        return base;
    }
    char ch = str[0];
    vector<string> smallAns = permutation(str.substr(1));

    vector<string> myAns;

    for (string s : smallAns)
    {
        for(int i=0;i<=s.length();i++){
            string st=s.substr(0,i) + ch + s.substr(i);
            myAns.push_back(st);
        }
        
    }
    return myAns;    

}


vector<string>permu(vector<int>&arr, int tar){
    if(tar==0){
        vector<string>base;
        base.push_back("");
        return base;
    }
    vector<string>myans;
    

    for(int i=0;i<arr.size();i++){
        vector<string>recans=permu(arr,tar-arr[i]);
        if(tar>=0){
            for(string s:recans){
                myans.push_back(to_string(arr[i])+s);
            }
        }
    }
    return myans;
}

// void mazePath(){
//     vector<string> ans=mazePathSimple(0,0,3,3);
//     for(string s:ans){
//         cout<<s<<" ";
//     }
// }

vector<string> mazePathSimple(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string> myAns;

    if (sc + 1 <= ec)
    {
        vector<string> horizontal = mazePathSimple(sr, sc + 1, er, ec);
        for (string s : horizontal)
            myAns.push_back("h" + s);
    }

    if (sr + 1 <= er)
    {
        vector<string> vertical = mazePathSimple(sr + 1, sc, er, ec);
        for (string s : vertical)
            myAns.push_back("v" + s);
    }

    return myAns;
}

vector<string> mazePath_D(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string> myAns;

    if (sc + 1 <= ec)
    {
        vector<string> horizontal = mazePath_D(sr, sc + 1, er, ec);
        for (string s : horizontal)
            myAns.push_back("H" + s);
    }

    if (sr + 1 <= er)
    {
        vector<string> vertical = mazePath_D(sr + 1, sc, er, ec);
        for (string s : vertical)
            myAns.push_back("V" + s);
    }

    if (sr + 1 <= er && sc + 1 <= ec)
    {
        vector<string> diagonal = mazePath_D(sr + 1, sc + 1, er, ec);
        for (string s : diagonal)
        {
            myAns.push_back("D" + s);
        }
    }

    return myAns;
}

int mazePath_D_height(int sr, int sc, int er, int ec)  //gives length of min path or put max for max height
{
    if (sr == er && sc == ec)
    {
        return 0;
    }

    int hori = 0, verti = 0, diag = 0;

    if (sc + 1 <= ec)
    {
        hori = mazePath_D_height(sr, sc + 1, er, ec);
    }

    if (sr + 1 <= er)
    {
        verti = mazePath_D_height(sr + 1, sc, er, ec);
    }

    if (sr + 1 <= er && sc + 1 <= ec)
    {
        diag = mazePath_D_height(sr + 1, sc + 1, er, ec);
    }

    return min(hori, min(verti, diag)) + 1;
}

vector<string> mazePath_multimove(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string> myAns;

    for (int i = 1; sc + i <= ec; i++)
    {
        vector<string> horizontal = mazePath_multimove(sr, sc + i, er, ec);
        for (string s : horizontal)
            myAns.push_back("H" + to_string(i) + s);
    }

    for (int i = 1; sr + i <= er; i++)
    {
        vector<string> vertical = mazePath_multimove(sr + i, sc, er, ec);
        for (string s : vertical)
            myAns.push_back("V" + to_string(i) + s);
    }

    for (int i = 1; sr + i <= er && sc + i <= ec; i++)
    {
        vector<string> diagonal = mazePath_multimove(sr + i, sc + i, er, ec);
        for (string s : diagonal)
        {
            myAns.push_back("D" + to_string(i) + s);
        }
    }

    return myAns;
}

//can move in 8 directions
//FLOODFILL : void type sol here
bool isSafe(int x,int y, int er,int ec,vector<vector<bool>>&board){
    if(x<0 || y<0 || x>er || y>ec || board[x][y] ) return false;
    return true;
}

vector<vector<int>>dirVal={{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};
vector<string>dir={"R","1","U","2","L","3","D","4"};

int floodFill(int sr,int sc,int er,int ec,vector<vector<bool>>&board,string ans){
    if(sr==er&&sc==ec){
        cout<<ans<<endl;
        return 1;
    }

    int count =0;
    board[sr][sc]=true; //mark
    for(int d=0;d<8;d++){
        int x=sr+dirVal[d][0];
        int y=sc+dirVal[d][1];

        if(isSafe(x,y,er,ec,board)){
            count += floodFill(x,y,er,ec,board,ans+dir[d]); //call for unvisited
        }
    }
    board[sr][sc]=false;   //unmarking again as we wont be able to reach destination after 1 path as it will become true
    return count;
}



//multimove floodFill
int multiMoveFloodFill(int sr,int sc,int er,int ec,vector<vector<bool>>&board,int rad,string ans){
    if(sr==er&&sc==ec){
        cout<<ans<<endl;
        return 1;
    }

    int count =0;
    board[sr][sc]=true; //mark
    for(int d=0;d<8;d++){
        for(int mag=1;mag<=rad;mag++){
            int x=sr+ mag*dirVal[d][0];
            int y=sc+ mag*dirVal[d][1];

            if(isSafe(x,y,er,ec,board))
                count += multiMoveFloodFill(x,y,er,ec,board,rad,ans+dir[d]+to_string(mag)); //call for unvisited
        }

    }
    board[sr][sc]=false;   //unmarking again as we wont be able to reach destination after 1 path as it will become true
    return count;
}

//connected islands  0:water,1:land ie free to move, 2:marked that ive moved here
//application ques of floodfill    
bool isSafe(int x,int y,vector<vector<char>>&board){
    if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y]=='0' || board[x][y]=='2'){
      return false;  
    } 
    return true;
}

// vector<vector<int>>dirVal={{0,1},{-1,0},{0,-1},{1,0}};
// vector<string>dir={"R","U","L","D"};

int floodFillIslands(int sr,int sc,vector<vector<char>>&board){
  

    int count =0;
    board[sr][sc]='2'; //mark
    for(int d=0;d<4;d++){
        int x=sr+dirVal[d][0];
        int y=sc+dirVal[d][1];

        if(isSafe(x,y,board)){
            count += floodFillIslands(x,y,board); 
        }
    }
    return count;
}
    
        
    int numIslands(vector<vector<char>>& grid) {
       int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    floodFillIslands(i,j,grid);
                }
            }
        }
        return count;
    }

//=============================================================================
//height in flood fill
int floodFillHeight(int sr,int sc,int er,int ec,vector<vector<int>>&board,string ans){      
    if(sr==er&&sc==ec){
        return 0;
    }

    board[sr][sc]=2; //mark
    int maxH=0;
    for(int d=0;d<8;d++){
        int x=sr+dirVal[d][0];
        int y=sc+dirVal[d][1];

        if(x>=0 && y>=0 && x<board.size() && y<board[0].size() && board[x][y]==1){
            int recAns = floodFillHeight(x,y,er,ec,board,ans+dir[d]); //call for unvisited
            maxH=max(recAns,maxH);
        }
    }
    board[sr][sc]=1;   //unmarking again as we wont be able to reach destination after 1 path as it will become true
    return maxH+1;
}
//for java need to make pair class as pair<> c++ exclusive
//longest path
pair<int,string> floodFillLongestPath(int sr,int sc,int er,int ec,vector<vector<int>>&board){      
    if(sr==er&&sc==ec){
        return {0,""};
    }

    board[sr][sc]=2; //mark
    pair<int,string> maxH={0,""};

    for(int d=0;d<8;d++){
        int x=sr+dirVal[d][0];
        int y=sc+dirVal[d][1];

        if(x>=0 && y>=0 && x<board.size() && y<board[0].size() && board[x][y]==1){
            pair<int,string> recAns = floodFillLongestPath(x,y,er,ec,board); //call for unvisited
            if(recAns.first+1>maxH.first){
                maxH.first=recAns.first+1;
                maxH.second=recAns.second+dir[d];
            }
        }
    }
    board[sr][sc]=1;   //unmarking again as we wont be able to reach destination after 1 path as it will become true
    return maxH;
}

//shortest path
pair<int,string> floodFillShortestPath(int sr,int sc,int er,int ec,vector<vector<int>>&board){      
    if(sr==er&&sc==ec){
        return {0,""};
    }

    board[sr][sc]=2; //mark
    pair<int,string> minH={1e7,""};

    for(int d=0;d<8;d++){
        int x=sr+dirVal[d][0];
        int y=sc+dirVal[d][1];

        if(x>=0 && y>=0 && x<board.size() && y<board[0].size() && board[x][y]==1){
            pair<int,string> recAns = floodFillShortestPath(x,y,er,ec,board); //call for unvisited
            if(recAns.first+1<minH.first){
                minH.first=recAns.first+1;
                minH.second=recAns.second+dir[d];
            }
        }
    }
    board[sr][sc]=1;   //unmarking again as we wont be able to reach destination after 1 path as it will become true
    return minH;
}

void floodFill(){
    int er=3;
    int ec=3;
    // vector<vector<bool>>board(er+1,vector<bool>(ec+1,false));
    // cout<<floodFill(0,0,2,2,board,"");

    // int rad=max(er,ec)+1;
    // cout<<multiMoveFloodFill(0,0,er,ec,board,rad,"");

    vector<vector<int>>board(er+1,vector<int>(ec+1,1));
    // cout<<floodFillHeight(0,0,er,ec,board,"");

    // pair<int,string> ans = floodFillLongestPath(0,0,er,ec,board);
    pair<int,string> ans = floodFillShortestPath(0,0,er,ec,board);

    cout<<ans.first<<" -> "<<ans.second;
}

void mazePAth()
{
    //vector<string> ans = mazePathSimple(0, 0, 3, 3);
    // vector<string> ans = mazePath_D(0, 0, 3, 3);
    // vector<string> ans = mazePath_multimove(0, 0, 3, 3);
    // for (string s : ans)
    //     cout << s << endl;

    //cout<<mazePath_D_height(0,0,2,2);
}


//NOKIA KEYPAD
vector<string>words = {"_","+-/","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz","*()%","#@$"};

vector<string> keypad(vector<string>&words,string str){
    if(str.length()==0){
        vector<string>base;
        base.push_back("");
        return base;
    }

    char ch = str[0]; 
    string word=words[ch-'0'];
    vector<string>myAns;
    vector<string>firstRes=keypad(words,str.substr(1));
    for(string s:firstRes){
        for(int i=0;i<word.length();i++){
            myAns.push_back(word[i]+s);
        }
    }

    if(str.length()>1&&ch!='0'){
        int num =(ch-'0')*10+(str[1]-'0');
        word=words[num];
        if(num<12){
            vector<string>secondRes=keypad(words,str.substr(2));
            for(string s:secondRes){
                for(int i=0;i<word.length();i++){
                    myAns.push_back(word[i]+s);
                }
            }
        }
    }
    return myAns;
}

//ABCD COMBINATINS FROM NUMBER
//ENCODING
vector<string> encoding(string str){
    if(str.length()==0){ 
        vector<string>base;
        base.push_back("");
        return base; 
    }

    char ch = str[0];
    
    if(ch=='0'){
        return encoding(str.substr(1));
    }

    char ch_ = (char)(ch - '1' + 'a');
    vector<string>myAns;
    vector<string>firstRes=encoding(str.substr(1));
    for(string s:firstRes){
        myAns.push_back(ch_+s);
    }

    if(str.length()>1){
        int num =(ch-'0')*10+(str[1]-'0');
        if(num<=26){
            ch_=(char)(num -1 +'a');        
            vector<string>secondRes=encoding(str.substr(2));
            for(string s:secondRes){
                myAns.push_back(ch_+s);
            }
        }
    }
    return myAns;
}


void basic()
{

    //mazePAth();
    floodFill();
    //cout<<removeHi("hihii");
    //    cout<<removeHi2("ih");
    //   cout<<removeDuplicate("aaabbccd");
        //  vector<string>ans=subseq("cba");
        //  for(string s: ans){
        //      cout<<s<<" ";
        //  }
    //    vector<string>ans=permutation("abc");

        // for(string s: keypad(words,"10811")){
        //     cout<<s<<endl;
        // }
        
        // for(string s: encoding("1124")){
        //     cout<<s<<endl;
        // }
}

void solve()
{
    basic();
}

int main(int args, char **argv)
{
    solve();
    return 0;
}
