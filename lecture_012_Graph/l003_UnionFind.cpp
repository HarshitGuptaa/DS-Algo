#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Edge
{
public:
    int v = 0;
    int w = 0;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

int N = 7;
vector<vector<Edge>> graph(N, vector<Edge>());

void addEdge(vector<vector<Edge>> &gp, int u, int v, int w)
{
    gp[u].push_back(Edge(v, w));
    gp[v].push_back(Edge(u, w));
}

//unionFind.==============================================

vector<int> par;
vector<int> setSize;

int findPar(int vtx)
{
    if(par[vtx]==vtx) return vtx;
    return par[vtx]=findPar(par[vtx]);
}

void mergeSet(int l1, int l2)
{
    if (setSize[l1] < setSize[l2])
    {
        par[l1] = l2;
        setSize[l2] += setSize[l1];
    }
    else
    {
        par[l2] = l1;
        setSize[l1] += setSize[l2];
    }
}

void unionFind(){

}


//leetcode 684.=====================================================
vector<int> findRedundantConnection(vector<vector<int>> &edges){
    for (int i = 0; i <= edges.size(); i++)
    {
        par.push_back(i);
        setSize.push_back(1);
    }

    for (vector<int> ar : edges)
    {
        int u = ar[0];
        int v = ar[1];
        int p1 = findPar(u);
        int p2 = findPar(v);

        if (p1 != p2)
        {
            mergeSet(p1, p2);
        }
        else
        {
            return ar;
        }
    }

    return {};
}

//leetcode : 547 ===================================================

int findCircleNum(vector<vector<int>> &arr)
{

    int n = arr.size();
    //declare se;f as parent.
    for (int i = 0; i < n; i++)
    {
        par.push_back(i);
        setSize.push_back(1);
    }
    int count = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0 && i != j) // if direct friendship.
            {
                int p1 = findPar(i);
                int p2 = findPar(j);
                if (p1 != p2)
                {
                    count--;
                    mergeSet(p1, p2);
                }
            }
        }
    }

    return count;
}

//leet 1061.====================================================
//lexicographic smallest equivalent string
string smallestEquivalentString(string A,string B,string S){
    for(int i=0;i<26;i++){
        par.push_back(i);
    }
    for(int i=0;i<A.length();i++){
        int p1=findPar(A[i]-'a');
        int p2=findPar(B[i]-'a');
        par[p1]=min(p1,p2);   //chota char parent bnega
        par[p2]=min(p1,p2);   //
    }
    string ans="";
    for(int i=0;i<S.length();i++){
        ans+=(char)(findPar(S[i]-'a')+'a');
    }
    return ans;
}

//leet 200.==================================================================
//num of islands with unionFind.......only 2 directions needed here whereas in dfs we require 4
 int numIslands(vector<vector<char>>& arr) {
    if(arr.size()==0) return 0;
        
    int n=arr.size();
    int m=arr[0].size();
    int noOfOnes=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            par.push_back(i*m+j);  //sab initially khud ke parents hai
            if(arr[i][j]=='1'){
               noOfOnes++;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='1'){
                
                if(j+1<m && arr[i][j+1]=='1'){  //checking for right
                    int p1=findPar(i*m+j);
                    int p2=findPar(i*m+j+1);
                    if(p1!=p2){
                       par[p1]=p2;
                       noOfOnes--;
                    }
                }

                if(i+1<n && arr[i+1][j]=='1'){ //checking for down
                    int p1=findPar(i*m+j);
                    int p2=findPar((i+1)*m+j);
                    if(p1!=p2){
                        par[p1]=p2;
                        noOfOnes--;
                    }       
                }

            }
        }
    }
    return noOfOnes;
}


//leet 839.=========================================
//Similar String Groups

bool isSimilar(string &p,string &q){
        int n=p.length();
        int count=0;
        for(int i=0;i<n;i++){
            if(p[i]!=q[i] && ++count>2)
                return false;
        }
        return true;
    }
    
    int numSimilarGroups(vector<string>& A) {
        int n=A.size();
        for(int i=0;i<n;i++){
            par.push_back(i);
        }
        int groups=n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(A[i],A[j])){
                    int p1=findPar(i);
                    int p2=findPar(j);
                    if(p1!=p2){
                    par[p1]=p2;
                    groups--;                        
                    }

                }
            }
        }
        return groups;
    }



void constructGraph()
{
    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 3, 10);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 40);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 2);
    addEdge(graph, 4, 6, 3);
    addEdge(graph, 5, 6, 8);

    // addEdge(graph, 2, 5, 2);

    cout << endl;
}

void solve()
{
    constructGraph();
}

int main()
{
    solve();
    return 0;
}

