//VOID TYPE
#include<iostream>
#include<vector>
#include<unordered_set>

#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;


void display2D(vvi &board){
    for(vi arr:board){
        for(int ele:arr){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


//SUBSEQ
int subseq(string str, string ans){
    if(str.length()==0){
        cout<<ans<<endl;
        return 1;
    }

    int count =0;

    count+=subseq(str.substr(1),ans);
    count+=subseq(str.substr(1),ans+str[0]);

    return count;
}

//KEYPAD

vector<string>words={"_","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
                    ,"+-/","*()%","#@$"};

int keyPad(string ques, string ans){
    if(ques.length()==0){
        cout<<ans<<endl;
        return 1;
    }
    int count =0;

    int idx1=ques[0]-'0';
    string word=words[idx1];
    for(int i=0;i<word.length();i++){
        count +=keyPad(ques.substr(1),ans+word[i]);
    }
    
    if(ques.length()>=2){
        int idx2=(ques[0]-'0')*10 + (ques[1]-'0');
        if(idx2==10||idx2==11){
            word=words[idx2];
            for(int i=0;i<word.length();i++){
                count +=keyPad(ques.substr(2),ans+word[i]);
            }
        }
    }
    return count;
}

//PERMUTATION
int permu(string str, string ans){
    if(str.length()==0){
        cout<<ans<<endl;
        return 1;
    }

    int count =0;

    for(int i=0;i<str.length();i++){
       string str2=str.substr(0,i)+str.substr(i+1);
        count+=permu(str2,ans+str[i]);
    }
    return count;
}

//PERMU WITH REMOVING DUPLICACY
int permu2(string str, string ans){
    
    if(str.length()==0){
        cout<<ans<<endl;
        return 1;
    }

    int count =0;

    vector<bool> vis(26,false);
    for(int i=0;i<str.length();i++){
       if(!(vis[str[i]-'a'])){
            vis[str[i]-'a']=true;
            string str2=str.substr(0,i)+str.substr(i+1);
            count+=permu2(str2,ans+str[i]);
       }
    }
    return count;
}

//PERMU WITH BIT
int permu3(string str, string ans){
    
    if(str.length()==0){
        cout<<ans<<endl;
        return 1;
    }

    int count =0;

    int vis=0;

    for(int i=0;i<str.length();i++){
        int mask=1<<(str[i]-'a');
       if((vis&mask)==0){
            vis|=mask;
            string str2=str.substr(0,i)+str.substr(i+1);
            count+=permu3(str2,ans+str[i]);
       }
    }
    return count;
}



//***********************************************************
//PERMU & COMBI WITH COINS TO MAKE A TARGET

//PERMU WITH INFINITE USABLE COINS
int permuInfi(vector<int>& arr, int target, string ans){
    if(target==0){
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i=0;i<arr.size();i++){
        if(target-arr[i]>=0){
            count+=permuInfi(arr,target-arr[i],ans+to_string(arr[i])+" ");
        }
    }
    return count;
}

//COMBINATIONS WITH INFINITE USABLE COINS
int combiInfi(vector<int>& arr,int idx, int target, string ans){
    if(target==0){
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i=idx;i<arr.size();i++){
        if(target-arr[i]>=0){
            count+=combiInfi(arr,i,target-arr[i],ans+to_string(arr[i])+" ");
        }
    }
    return count;
}


//COMBINATIONS WITHOUT REPITATION OF COINS
int combiWthoutRepe(vector<int>& arr,int idx, int target, string ans){
    if(target==0){
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int i=idx;i<arr.size();i++){
        if(target-arr[i]>=0){
            count+=combiWthoutRepe(arr,i+1,target-arr[i],ans+to_string(arr[i])+" ");
        }
    }
    return count;
}

//PERMU WITHOUT REPITATION OF COINS
int permuWithoutRepe(vector<int>& arr,vector<bool>&vis, int target, string ans){
    if(target==0){
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;

    for(int i=0;i<arr.size();i++){
        if(!vis[i]&&target-arr[i]>=0){
            vis[i]=true;
            count+=permuWithoutRepe(arr,vis,target-arr[i],ans+to_string(arr[i])+" ");
            vis[i]=false;
        }
    }
    return count;
}

//***********************************************************
//PERMU & COMBI WITH COINS TO MAKE A TARGET - USING SUBSEQ

//COMBINATIONS WITH INFINITE USABLE COINS
int combiInfisubseq(vector<int>& arr,int idx, int target, string ans){
    if(idx==arr.size()||target==0){
        if(target==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    
        if(target-arr[idx]>=0){
            count+=combiInfisubseq(arr,idx,target-arr[idx],ans+to_string(arr[idx])+" ");
            count+=combiInfisubseq(arr,idx+1,target,ans);
        }
    
    return count;
}

//COMBINATIONS WITHOUT REPITATION OF COINS
int combiWithoutrepesubseq(vector<int>& arr,int idx, int target, string ans){
    if(idx==arr.size()||target==0){
        if(target==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    
        if(target-arr[idx]>=0)
            count+=combiWithoutrepesubseq(arr,idx+1,target-arr[idx],ans+to_string(arr[idx])+" ");
        count+=combiWithoutrepesubseq(arr,idx+1,target,ans);
        
    
    return count;
}

//PERMUTATION WITH INFINITE USABLE COINS
int permuInfiSubseq(vector<int>& arr,int idx, int target, string ans){
    if(idx==arr.size()||target==0){
        if(target==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    
        if(target-arr[idx]>=0)
            count+=permuInfiSubseq(arr,0,target-arr[idx],ans+to_string(arr[idx])+" ");
        count+=permuInfiSubseq(arr,idx+1,target,ans);
        
    
    return count;
}

int permuNoRepeSubseq(vector<int> &arr,vector<bool>&vis,int idx,int target,string ans){
    if(idx==arr.size() || target==0){
        if(target==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;

    if(!vis[idx]&&target-arr[idx]>=0){
        vis[idx]=true;
        count+=permuNoRepeSubseq(arr,vis,0,target-arr[idx],ans+to_string(arr[idx])+" ");
        vis[idx]=false;
    }
    count+=permuNoRepeSubseq(arr,vis,idx+1,target,ans);
    return count;
}


//===================================================================================
//QUEEN

//1-D
int queenCombi(vector<int>&box,int idx,int qpsf, int tnq, string ans){
    if(qpsf==tnq){
        cout<<ans<<endl;            //qpsf:queens placed so far
        return 1;                   //tnq: total no. of queens
    }
    int count=0;
    for(int i=idx;i<box.size();i++){
        count+=queenCombi(box,i+1,qpsf+1,tnq,ans+"b"+to_string(i)+"q"+to_string(qpsf)+" ");
    }
    return count;
}
int queenPermu(vector<int>&box,vector<bool>&vis,int qpsf, int tnq, string ans){
    if(qpsf==tnq){
        cout<<ans<<endl;            //qpsf:queens placed so far
        return 1;                   //tnq: total no. of queens
    }
    int count =0;
    for(int i=0;i<box.size();i++){
        if(!vis[i]){
            vis[i]=true;
            count+=queenPermu(box,vis,qpsf+1,tnq,ans+"b"+to_string(i)+"q"+to_string(qpsf));
            vis[i]=false;
        }
    }
    return count;
}

//QUEEN BY SUBSEQ
int queenCombisubseq(vector<int>&box,int idx,int qpsf, int tnq, string ans){
    if(idx==box.size()||qpsf==tnq){
        if(qpsf==tnq){
        cout<<ans<<endl;            //qpsf:queens placed so far
        return 1;     
        }
        return 0;              
    }
    int count =0;
            
    count+=queenCombisubseq(box,idx+1,qpsf+1,tnq,ans+"b"+to_string(idx)+"q"+to_string(qpsf));
    count+=queenCombisubseq(box,idx+1,qpsf,tnq,ans);

    return count;
}
int queenPermusubseq(vector<int>&box,vector<bool>&vis,int idx,int qpsf, int tnq, string ans){
    if(idx==box.size()||qpsf==tnq){
        if(qpsf==tnq){
        cout<<ans<<endl;            //qpsf:queens placed so far
        return 1;     
        }
        return 0;              
    }
    int count =0;
    if(!vis[idx]){
        vis[idx]=true;
        count+=queenPermusubseq(box,vis,0,qpsf+1,tnq,ans+"b"+to_string(idx)+"q"+to_string(qpsf));
        vis[idx]=false;    
        }
    count+=queenPermusubseq(box,vis,idx+1,qpsf,tnq,ans);

    return count;
}




//2D BOARD QUEEN
int queen2DPermu(vector<vector<bool>>&board,int qpsf, int tnq, string ans){
    if(qpsf==tnq){
        cout<<ans<<endl;            //qpsf:queens placed so far
        return 1;                   //tnq: total no. of queens
    }
    int count =0;
    for(int i=0;i<board.size()*board[0].size();i++){
        int x=i/board[0].size();
        int y=i%board[0].size();
        if(!board[x][y]){
            board[x][y]=true;
            count+=queen2DPermu(board,qpsf+1,tnq,ans+"("+to_string(x)+", "+to_string(y)+")");
            board[x][y]=false;
        }
    }
    return count;
}
int queen2DCombi(vector<vector<bool>>&board,int idx,int qpsf, int tnq, string ans){
    if(qpsf==tnq){
        cout<<ans<<endl;            //qpsf:queens placed so far
        return 1;                   //tnq: total no. of queens
    }
    int count =0;
    for(int i=idx;i<board.size()*board[0].size();i++){
        int x=i/board[0].size();
        int y=i%board[0].size();
        count+=queen2DCombi(board,i+1,qpsf+1,tnq,ans+"("+to_string(x)+", "+to_string(y)+")");
    }
    return count;
}

//===================================
//N-QUEEN - queen must be placed in such a way that other does not kill it

vector<vector<int>>dir={{0,-1},{-1,-1},{-1,0},{-1,1}};
vector<vector<int>>dir2={{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};

bool isSafeToPlaceQueenC(vector<vector<bool>>&board,int r, int c){  //like floodfill
    for(int i=0;i<dir.size();i++){
        for(int rad=1;rad<=max(board.size(),board[0].size());rad++){
            int x=r+rad*dir[i][0];
            int y=c+rad*dir[i][1];
            if(x<0||y<0||x>=board.size()||y>=board[0].size()){
                break;
            }
            if(board[x][y]){
                return false;
            }
        }
    }
    return true;
}

int nQueenCombi(vector<vector<bool>>&board,int idx, int qpsf, int tnq, string ans){
    if(qpsf==tnq){
        cout<<ans<<endl;
        return 1;
    }
    int count =0;

    for(int i=idx;i<board.size()*board[0].size();i++){
        int x=i/board[0].size();
        int y=i%board[0].size();
        if(isSafeToPlaceQueenC(board,x,y)){
            board[x][y]=true;
            count+=nQueenCombi(board,i+1,qpsf+1,tnq,ans+"("+to_string(x)+", "+to_string(y)+")");
            board[x][y]=false;
        }
    }
    return count;
}

bool isSafeToPlaceQueenP(vector<vector<bool>>&board,int r, int c){  //like floodfill
    for(int i=0;i<8;i++){
        for(int rad=1;rad<=max(board.size(),board[0].size());rad++){
            int x=r+rad*dir2[i][0];
            int y=c+rad*dir2[i][1];
            if(x<0||y<0||x>=board.size()||y>=board[0].size()){
                break;
            }
            if(board[x][y]){     //this 8 direction isSafe can also be used for combination
                return false;    //as aage ke false hi hai
            }
        }
    }
    return true;
}

int nQueenPermu(vector<vector<bool>>&board, int qpsf, int tnq, string ans){
    if(qpsf==tnq){
        //cout<<ans<<endl;
        return 1;
    }
    int count =0;

    for(int i=0;i<board.size()*board[0].size();i++){
        int x=i/board[0].size();
        int y=i%board[0].size();
        if(!board[x][y]&&isSafeToPlaceQueenP(board,x,y)){
            board[x][y]=true;
            count+=nQueenPermu(board,qpsf+1,tnq,ans+"("+to_string(x)+", "+to_string(y)+")");
            board[x][y]=false;
        }
    }
    return count;
}


//=======================================================
//NQUEEN BY O(1)

int nqueen(int r,int tnq, vb&col, vb&diag, vb&adiag, string ans){
    int n=col.size();
    if(r==n||tnq==0){
       if(tnq==0){
            cout<<ans<<endl;
            return 1;
       }
       return 0;
    }

    int count=0;

    for(int c=0;c<n;c++){
        if(!col[c] && !diag[r+c] && !adiag[r-c+n-1]){
            col[c]=true;
            diag[r+c]=true;
            adiag[r-c+n-1]=true;
            count+=nqueen(r+1,tnq-1,col,diag,adiag,ans+"("+to_string(r)+","+to_string(c)+") ");
            col[c]=false;
            diag[r+c]=false;
            adiag[r-c+n-1]=false;
        }
    }
    return count;
}

int nqueen2(int n,int r,int tnq, int &col, int &diag, int &adiag, string ans){
    
    if(r==n||tnq==0){
       if(tnq==0){
            cout<<ans<<endl;
            return 1;
       }
       return 0;
    }

    int count=0;

    for(int c=0;c<n;c++){
        int w=1<<c;
        int x=1<<(r+c);
        int y=1<<(r-c+n-1);
        if(!(col&w) && !(diag&x) && !(adiag&y)){
            col^=w;
            diag^=x;
            adiag^=y;
            count+=nqueen2(n,r+1,tnq-1,col,diag,adiag,ans+"("+to_string(r)+","+to_string(c)+") ");
            col^=w;
            diag^=x;
            adiag^=y;
        }
    }
    return count;
}

void queen(){
    vector<int>box(5,0);
    cout<<queenCombi(box,0,0,3,""); 
    vector<bool>vis(5,false);
    cout<<queenPermu(box,vis,0,3,"");

    //cout<<queenCombisubseq(box,0,0,3,"");
    //cout<<queenPermusubseq(box,vis,0,0,3,"");


    vector<vector<bool>>board(4,vector<bool>(4,false));
    //cout<<queen2DPermu(board,0,4,"");
   // cout<<queen2DCombi(board,0,0,4,"");
    //cout<<nQueenCombi(board,0,0,4,"");
  //  cout<<nQueenPermu(board,0,4,"");


int r=4,c=4;
// vb col(c,false);
// vb diag(r+c-1,false);
// vb adiag(r+c-1,false);
//cout<<nqueen(0,r,col,diag,adiag,"");


int col=0,diag=0,adiag=0;
//cout<<nqueen2(r,0,r,col,diag,adiag,"");

}

//================================================================//
//SUDOKU

vi row(9,0);
vi col(9,0);
vvi mat(3,vi(3,0));

//===============levelup====================================
bool isSafeSudoku(vvi &board,int r,int c,int num){
    
    //for col
    for(int i=0;i<9;i++){
        if(board[r][i]==num) return false;
    }
    
    //for row
    for(int j=0;j<9;j++){
        if(board[j][c]==num) return false;
    }

    int x=(r/3)*3;
    int y=(c/3)*3;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[x+i][y+j]==num) return false;
        }
    }
    return true;
}

int sudoku01(vvi &board,int idx){
    if(idx==81){
        display2D(board);
        return 1;
    }

    int r=idx/9;
    int c=idx%9;
    int count=0;

    if(board[r][c]==0){
        for(int num=1;num<=9;num++){
            if(isSafeSudoku(board,r,c,num)){
            board[r][c]=num;
            count+=sudoku01(board,idx+1);
            board[r][c]=0;
            }
        }
    }else 
        count+=sudoku01(board,idx+1);

    return count;

}

int sudoku02(vvi &board,vi &calls,int idx){
    if(idx==calls.size()){
        display2D(board);
        return 1;
    }

    int r=calls[idx]/9;
    int c=calls[idx]%9;
    int count=0;

        for(int num=1;num<=9;num++){
            if(isSafeSudoku(board,r,c,num)){
            board[r][c]=num;
            count+=sudoku02(board,calls,idx+1);
            board[r][c]=0;
            }
        }
        //the calls where num!=0 are saved

    return count;

}

int sudoku03(vvi &board,vi &calls,int idx){
    if(idx==calls.size()){
        display2D(board);
        return 1;
    }

    int r=calls[idx]/9;
    int c=calls[idx]%9;
    int count=0;

        for(int num=1;num<=9;num++){
            int mask=1<<num;
            if((row[r]&mask)==0 && (col[c]&mask)==0 && (mat[r/3][c/3]&mask)==0){
            
            board[r][c]=num;
            row[r]^=mask;
            col[c]^=mask;
            mat[r/3][c/3]^=mask;
            
            count+=sudoku03(board,calls,idx+1);
            
            board[r][c]=0;
            row[r]^=mask;
            col[c]^=mask;
            mat[r/3][c/3]^=mask;
            }
        }

    return count;

}








//===============foundation================================
void display(vvi&board){
    for(vi arr:board){
        for(int ele:arr){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}



int sudoku_01(vvi & board,vi &calls, int idx){
    if(idx==calls.size()){
        display(board);
        return 1;
    }
    int x=calls[idx]/9;
    int y=calls[idx]%9;
    int count=0;

    
        for(int num=1;num<=9;num++){
            int mask=1<<num;
            if(!(row[x]&mask) && !(col[y]&mask) && !(mat[x/3][y/3]&mask)){
                board[x][y]=num;
                row[x]^=mask;
                col[y]^=mask;
                mat[x/3][y/3]^=mask;

                count+=sudoku_01(board,calls,idx+1);
                
                board[x][y]=0;
                row[x]^=mask;
                col[y]^=mask;
                mat[x/3][y/3]^=mask;
            }
        }

    return count;
}


void sudoku(){
    vvi board=  {{0, 0, 6, 0, 0, 8, 0, 0, 0},
                {5, 2, 0, 0, 0, 0, 0, 0, 0},
                {0, 8, 7, 0, 0, 0, 0, 3, 1},
                {0, 0, 3, 0, 1, 0, 0, 8, 0},
                {9, 0, 0, 8, 6, 3, 0, 0, 5},
                {0, 5, 0, 0, 9, 0, 6, 0, 0},
                {1, 3, 0, 0, 0, 0, 2, 5, 0},
                {0, 0, 0, 0, 0, 0, 0, 7, 4},
                {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    // vi calls;

    // for(int i=0;i<9;i++){
    //     for(int j=0;j<9;j++){
    //         if(board[i][j]==0){
    //             calls.push_back(i*9+j);
    //         }else{
    //             int mask=1<<board[i][j];
    //             row[i]|=mask;
    //             col[j]|=mask;
    //             mat[i/3][j/3]|=mask;
    //         }
    //     }
    // }
    //cout<<sudoku_01(board,calls,0);


    //levelup
    //cout<<sudoku01(board,0);

    vi calls;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                calls.push_back(i*9+j);
            }else{
                int mask=1<<board[i][j];
                row[i] ^= mask;
                col[j] ^= mask;
                mat[i/3][j/3] ^=  mask;
            }
        }
    }
    cout<<sudoku03(board,calls,0);
}



//================================================================//
//CROSSWORD

vector<vector<char>> board = {
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},
    {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
    {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
    {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
    {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};

bool isSafePWH(int x,int y,string word){

    //calls save krne ke liye kuch ifs, vrna handle to ho jaega fir bhi backtrack wagerah se
    //pr ye lgane se vo call hi ni lgegi direct false chla jaega

    
    for(int i=0;i<word.size();i++){
        if((y+i)<board[0].size() && board[x][y+i] != '-' && board[x][y+i]!=word[i]){
            return false;
        } 
    }
    return true;
}
bool isSafePWV(int x,int y,string word){
    for(int i=0;i<word.size();i++){
        if((x+i)<board.size() && board[x+i][y] != '-' && board[x+i][y]!=word[i]){
            return false;
        } 
    }
    return true;
}

vb PWH(int x,int y,string word){
    vb loc(word.length(),false);
    for(int i=0;i<word.length();i++){
        if(board[x][y+i]=='-'){
            loc[i]=true;    //this is imp as we mark only those which we place & later only those are removed that are placed by me
            board[x][y+i]=word[i];
        }
    }
    return loc;
}
vb PWV(int x,int y,string word){
    vb loc(word.size(),false);
    for(int i=0;i<word.size();i++){
        if(board[x+i][y]=='-'){
            loc[i]=true;
            board[x+i][y]=word[i];
        }
    }
    return loc;
}

void UnPWH(int x, int y, vb &loc)
{
    for (int i = 0; i < loc.size(); i++)
    {
        if (loc[i])
        {
            board[x][y + i] = '-';
        }
    }
}
void UnPWV(int x, int y, vb &loc)
{
    for (int i = 0; i < loc.size(); i++)
    {
        if (loc[i])
        {
            board[x+i][y] = '-';
        }
    }
}

int crossword(vector<string>&arr,int idx){
    if(idx==arr.size()){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return 1;
    }

    int count=0;
    string word=arr[idx];

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='-'||board[i][j]==word[0]){
                if(isSafePWH(i,j,word)){
                    vb loc = PWH(i,j,word);
                    count+=crossword(arr,idx+1);
                    UnPWH(i,j,loc);
                }
                if(isSafePWV(i,j,word)){
                    vb loc = PWV(i,j,word);
                    count+=crossword(arr,idx+1);
                    UnPWV(i,j,loc);
                }
            }
        }
    }
    return count;
}

void crossW()
{
    vector<string> words = {"agra", "norway", "england", "gwalior"};
    cout << crossword(words, 0) << endl;
}
//=================================================================//
//=============================wordBreak==========================
unordered_set<string> map;
int wordBreak_(string str,string ans){
    if(str.length()==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;

    for(int i=1;i<=str.length();i++){
        string smallStr=str.substr(0,i);
        if(map.find(smallStr)!=map.end()){    //map.contains(smallstr)  java Hashset
            count+=wordBreak_(str.substr(i),ans+smallStr+" ");
        }
    }
    return count;
}


void wordBreak(){
    vector<string> words={"i","like","ilike","sam","sung","samsung"};
    for(string s:words){
        map.insert(s);               //map.add() java
    }
    cout<<wordBreak_("ilikesamsung","");
}
//===========================================================================
//===========================crypto=======================================
//
string str1;
string str2;
string str3;
int numUsed=0;
vi mapping;

int stringToNumber(string str){

}

int crypto_(string str,int idx){
    if(idx==str.length()){
        int a= stringToNumber(str1);
        int b= stringToNumber(str2);
        int c= stringToNumber(str3);

        if(a+b==c){



            return 1;
        }
        return 0;
    }

    int count=0;

    for(int num=0;num<=9;num++){
        int mask=1<<num;
        if(numUsed&mask==0)
        {
            numUsed^=mask;
            mapping[str[idx]-'a'] = num;
            count+=crypto_(str,idx+1);
            numUsed^=mask;
            mapping[str[idx]-'a'] = 0;
        }
    }
    return count;
}

void crypto(){
    string str=str1 + str2 + str3;
    int freq=0;
    for(int i=0;i<str.length();i++){
        int idx = 1 << (str[i]-'a');
        freq|=idx;
    }

    str="";
    for(int i=0;i<26;i++){
        int mask=1<<i;
        if((mask&freq)!=0){
            str+=(char)(i+'a');
        }
    }
    cout<<crypto_(str,0);
}




//=========================================================================
void combiPermu(){
    vector<int>arr={2,3,5,7};
    //cout<<permuInfi(arr,10,"");
    //cout<<combiInfi(arr,0,10,"");
   // cout<<combiWthoutRepe(arr,0,10,"");

    vector<bool>vis(4,false);
    //cout<<permuWithoutRepe(arr,vis,10,"");

    //subseq
   // cout<<combiInfisubseq(arr,0,10,"");

//    cout<<permuInfiSubseq(arr,0,10,"");
    cout<<permuNoRepeSubseq(arr,vis,0,10,"");

}

void basicQues(){
    
    //cout<<subseq("abc","");
    //cout<<keyPad("1011","");
    //cout<<permu("abc","");
    //cout<<permu3("aba","");
    combiPermu();
}

void solve(){
    //basicQues();
    //queen();
    //crossW();
    //sudoku();
    wordBreak();
}

int main(int args, char**argv){
    solve();
}