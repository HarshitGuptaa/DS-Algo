#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define lli long long int

using namespace std;

class Edge{
    public:
    int v=0;
    int w=0;

    Edge(int v,int w){
        this->v=v;
        this->w=w;
    }
};

int n=7;
vector<vector<Edge*>>graph(n,vector<Edge*>());

void addEdge(vector<vector<Edge*>>&g,int u,int v,int w){
    g[u].push_back(new Edge(v,w));
    g[v].push_back(new Edge(u,w));
}

void constructGraph(){
    addEdge(graph,0,1,10);
    addEdge(graph,0,3,10);
    addEdge(graph,3,2,40);
    //addEdge(graph,3,0,40);
    addEdge(graph,3,4,2);
    addEdge(graph,1,2,10);
    addEdge(graph,4,5,2);
    addEdge(graph,4,6,3);
    addEdge(graph,5,6,8);
    //addEdge(graph,7,2,5);
    //addEdge(graph,2,5,5);
    //addEdge(graph,7,8,6);
}

int searchEdge(int u,int v){
    int vidx=-1;
    for(int i=0;i<graph[u].size();i++){
        Edge*e = graph[u][i];
        if(e->v==v){
            vidx=i;
            break;
        }
    }
    return vidx;
}

void removeEdge(int u,int v){
    int vidx = searchEdge(u,v);
    int uidx = searchEdge(v,u);

    graph[u].erase(graph[u].begin() + vidx);   //beginning se vidx duuri wali edge ko remove
    graph[v].erase(graph[v].begin() + uidx); 
}

void removeVtx(int u){
    for(int i=graph[u].size()-1;i>=0;i--){   //piche se isliye chla re h kyuki remove krne pe size bhi chota hora hai to increment krna sahi ni hoga
        Edge*e = graph[u][i];
        removeEdge(e->v,u);    //or removeEdge(u,e->v);
    }
}

bool hasPath(int src,int dest, vector<bool>& vis){
    if(src==dest){
        return true;
    }
    bool res = false;
    vis[src] = true;

    for(Edge* e:graph[src]){
        if(!vis[e->v])
        res=res||hasPath(e->v,dest,vis);
    }
    return res;
}

int allPaths(int src,int dest, vector<bool>& vis,string ans){
    if(src==dest){
        cout<<ans<<dest<<endl;
        return 1;
    }
    
    vis[src] = true;  //mark
    int count=0;

    for(Edge* e:graph[src]){
        if(!vis[e->v])
            count+=allPaths(e->v,dest,vis,ans + to_string(src));
    }

    vis[src] = false;  //unmark
    return count;
}

class pair1{
public:
    int minwt=1e7;
    int maxwt=-1e7;
    int ceil=1e7;
    int floor=-1e7;
};

void allSolution(int src, int dest, int wsf,int data,vector<bool>&vis,pair1 &pair){
    if(src==dest){
        pair.minwt=min(pair.minwt,wsf);
        pair.maxwt=max(pair.maxwt,wsf);
        return;
    }
    if(data<wsf){
        pair.ceil = min(pair.ceil,wsf);
    }
    if(data>wsf){
        pair.floor = max(pair.floor,wsf);
    }
    
    vis[src] = true;  //mark
    
    for(Edge* e:graph[src]){
        if(!vis[e->v])
            allSolution(e->v,dest,wsf + e->w,data,vis,pair);
    }

    vis[src] = false;

}


void preOrder(int src,int w,vector<bool>&vis,string ans){
    vis[src]=true;
    
    cout<<ans<<"@"<<w<<endl;
    for(Edge* e:graph[src]){
        if(!vis[e->v])
        preOrder(e->v,w+e->w,vis,ans+to_string(e->v));
    }

    vis[src]=false;
}


void display(vector<vector<Edge*>> &gp){
    for(int i=0;i<gp.size();i++){
        cout<<"vertex"<<i<<" -> ";

        // for(int j=0;j<graph[i].size();j++){
        //     cout<<"("<<graph[i][j]->v<<", "<<graph[i][j]->w<<") ";
        // }
        
        for(Edge* e: gp[i]){
            cout<<"("<<e->v<<", "<<e->w<<") ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void HamiltonianPath(int src,int osrc,vector<bool>&vis,int count,string ans){
    if(count==vis.size()-1){    //need to visit all
        int idx=searchEdge(src,osrc);
        if(idx!=-1){
            cout<<"Cycle: "<<ans+to_string(src)<<endl;
        }else{
            cout<<"Path: "<<ans+to_string(src)<<endl;
        }

        return;
    }

    vis[src]=true;
    for(Edge* e:graph[src]){
        if(!vis[e->v])
            HamiltonianPath(e->v,osrc,vis,count+1,ans+to_string(src)+" ");
    }
    vis[src]=false;  //backtrack always happen, false is marked only to get more paths 
}

//leetcode 130

void surroundedRegion_DFS(int r,int c,int n,int m,vector<vector<char>>&board){
    if(board[r][c]!='O') return;
    board[r][c]='#';
    if(r-1>=0) surroundedRegion_DFS(r-1,c,n,m,board);
    if(r+1<n) surroundedRegion_DFS(r+1,c,n,m,board);
    if(c-1>=0) surroundedRegion_DFS(r,c-1,n,m,board);
    if(c+1>m) surroundedRegion_DFS(r,c+1,n,m,board);
}

void surroundedRegion(vector<vector<char>>&board){
    if(board.size()==0) return;

    int n=board.size();
    int m=board[0].size();

    for(int i=0;i<n;i++){
        if(board[i][0]=='O') surroundedRegion_DFS(i,0,n,m,board);
        if(board[i][m-1]=='O') surroundedRegion_DFS(i,m-1,n,m,board);
    }

    for(int i=0;i<m;i++){
        if(board[0][i]=='O') surroundedRegion_DFS(0,i,n,m,board);
        if(board[n-1][i]=='O') surroundedRegion_DFS(n-1,i,n,m,board);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='#'){
                board[i][j]='O';
            }
            else if(board[i][j]=='O'){
                board[i][j]='X';
            }
        }
    }
}

int GCC_DFS(int src,vector<bool>&vis){
    int count=0;
    vis[src]=true;
    for(Edge* e:graph[src]){
        if(!vis[e->v])
            count+=GCC_DFS(e->v,vis);
    }
    return count+1;
}

int GCC(vector<bool>&vis){
    int count=0;
    int maxCount=0;

    for(int i=0;i<vis.size();i++){
        if(!vis[i]){
            count++;
            maxCount=max(maxCount,GCC_DFS(i,vis));
        }
    }

    cout<<maxCount<<endl;
    return count;
}

//leet 200: number of islands

void dfs_numOfIslands(int r,int c,int n,int m,vector<vector<char>>& board){
    if(board[r][c]!='1') return; 

    board[r][c]='0';
    if(r-1>=0) dfs_numOfIslands(r-1,c,n,m,board);
    if(r+1<n) dfs_numOfIslands(r+1,c,n,m,board);
    if(c-1>=0) dfs_numOfIslands(r,c-1,n,m,board);
    if(c+1<m) dfs_numOfIslands(r,c+1,n,m,board);
}

int numOfIslands(vector<vector<char>>& board){
    if(board.size()==0) return 0;
    int n=board.size();
    int m=board[0].size();
    
    int count=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='1'){
                count++;
                dfs_numOfIslands(i,j,n,m,board);
            }
        }
    }
    return count;
}

//leet 695: max area of island

int dfs_maxAreaOfIsland(int r,int c,int n,int m,vector<vector<int>>& board){
    if(board[r][c]!=1) return 0;
    int count=0;

    board[r][c]=0;
    if(r-1>=0) count+=dfs_maxAreaOfIsland(r-1,c,n,m,board);
    if(r+1<n) count+=dfs_maxAreaOfIsland(r+1,c,n,m,board);
    if(c-1>=0) count+=dfs_maxAreaOfIsland(r,c-1,n,m,board);
    if(c+1<m) count+=dfs_maxAreaOfIsland(r,c+1,n,m,board);

    return count+1;
}

int maxAreaOfIsland(vector<vector<int>>& board) {
    if(board.size()==0) return 0;
    
    int n=board.size();
    int m=board[0].size();
    
    int maxArea=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==1){
                maxArea=max(maxArea,dfs_maxAreaOfIsland(i,j,n,m,board));
            }
        }
    }
    return maxArea; 
}

//leetcode 463======================================================

int islandPerimeter(vector<vector<int>> &board)
{
    int totalOnes = 0;
    int commonRegion = 0;

    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 1)
            {
                totalOnes++;
                if (j + 1 < m && board[i][j + 1] == 1)
                    commonRegion++;
                if (i + 1 < n && board[i + 1][j] == 1)
                    commonRegion++;
            }
        }
    }
    return (4 * totalOnes - 2 * commonRegion);
}




//==================================================================
//=========================BFS===============================

void bfs(int src,vector<bool>&vis){
    int desti=6;
    queue<pair<int,string>> que;
    que.push({src,to_string(src)});

    while(que.size()!=0){
        pair<int,string> vtx=que.front();
        que.pop();

        if(vis[vtx.first]){  //cycle
            cout<<"Cycle: "<<vtx.second<<endl;
            continue;
        }

        if(vtx.first==desti){
            cout<<"Destination: "<<vtx.second<<endl;
        }

        vis[vtx.first]=true;

        for(Edge*e:graph[vtx.first]){
            if(!vis[e->v]){
                que.push({e->v,vtx.second+to_string(e->v)});
            }
        }
    }
}

void bfs_2(int src,vector<bool>&vis){  //normal bfs but without pair class
    int desti=6;
    int level=0;
    int cycle=0;
    queue<int> que;
    
    que.push(src);
    

    while(que.size()!=0){
        int size=que.size();
        
        while(size-->0){
        
        int vtx=que.front();
        que.pop();

        if(vis[vtx]){  //cycle
            cout << "Cycle No. " + to_string(cycle) + ": " << vtx << endl;
            cycle++;
            continue;
        }

        if(vtx==desti){
            cout<<"Destination: "<<level<<endl;
        }


        vis[vtx]=true;

        for(Edge*e:graph[vtx]){
            if(!vis[e->v]){
                que.push(e->v);
            }
        }
        }
        level++;
    }
}

void BFS_3(int src, vector<bool> &vis)   //only for desti, cycle cannot be obtained
{
    queue<int> que;
    que.push(src);
    vis[src] = true;

    int level = 0;
    int desti = 6;

    while (que.size() != 0)
    {
        int size = que.size();

        while (size-- > 0)
        {
            int rvtx = que.front();
            que.pop();

            if (rvtx == desti)
                cout << "destination: " << level << endl;

            for (Edge* e : graph[rvtx])
            {
                if (!vis[e->v])
                {
                    que.push(e->v);
                    vis[e->v] = true;
                }
            }
        }
        level++;
    }
}



//bfs questions

//1091
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    if(n==0 || m==0) return -1;
    if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
    
    int level=0;
    int dirA[8][2] = {{-1, -1}, {-1, 0}, {0, -1}, {-1, 1}, {1, -1}, {0, 1}, {1, 0}, {1, 1}};
    queue<int>que;
    que.push(0);
    grid[0][0]=1;

    while(que.size()!=0){
        int size=que.size();
        while(size-->0){
            int vtx=que.front(); que.pop();
            
            int r=vtx/n;
            int c=vtx%m;

            if(r==n-1 && c==m-1) return level;
            
            for(int i=0;i<8;i++){
                int x=r+dirA[i][0];
                int y=c+dirA[i][1];
            
                 if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0){
                    que.push((x * m + y));
                    grid[x][y] = 1;
                }
            }
        }
        level++;
    }
    return -1;
}

//leetcode 286.=============================================================

void wallsAndGates(vector<vector<int>> &grid)
{
    if (grid.size() == 0 || grid[0].size() == 0)
        return;

    int n = grid.size();
    int m = grid[0].size();

    int dirA[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    queue<int> que;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 0)
                que.push((i * m + j));

    int level = 1;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int rvtx = que.front();
            que.pop();

            int r = rvtx / m;
            int c = rvtx % m;

            for (int d = 0; d < 4; d++)
            {
                int x = r + dirA[d][0];
                int y = c + dirA[d][1];

                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 2147483647)
                {
                    que.push((x * m + y));
                    grid[x][y] = level;
                }
            }
        }
        level++;
    }
}

//leet 994: rotten oranges, amazon fav..........1:fresh, 2:rotten
int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size()==0 || grid[0].size()==0) return -1;
    int n=grid.size();
    int m=grid[0].size();
    
    
    int level=0;
    int dirA[4][2] = {{-1, 0}, {0, -1},{0, 1}, {1, 0}};
    queue<int>que;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==2){  
                    que.push(i*m +j);   
                }

    while(que.size()!=0){
        int size=que.size();
        while(size-->0){
            int vtx=que.front(); que.pop();
            
            int r=vtx/m;
            int c=vtx%m;
            
            for(int i=0;i<4;i++){
                int x=r+dirA[i][0];
                int y=c+dirA[i][1];
            
                 if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1){
                    que.push((x * m + y));
                    grid[x][y] = 2;
                }
            }
        }
        level++;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 1){
                return -1;
            }
                

    return level==0?0:level-1;
    
    }

bool isBipartiteBFS(int src, vector<int> &vis)
{
    queue<pair<int, int>> que;  //first is src and second is color.
    que.push({src, 0}); // src is red.
    int cycle=0;

    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            pair<int, int> rvtx = que.front();
            que.pop();

            if (vis[rvtx.first] != -1) // already visited(cycle).
            {   cycle++;
                if (vis[rvtx.first] != rvtx.second) // check for conflict.
                    return false;
            }

            vis[rvtx.first] = rvtx.second;
            for (Edge* e : graph[rvtx.first])
            {
                if (vis[e->v] == -1)
                    que.push({e->v, (rvtx.second + 1) % 2}); 
            }
        }
    }
    
    return true;
}

void isBipartite()
{
    vector<int> vis(n, -1); // -1 : unvisited, 0 : red, 1 : green
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == -1)
            cout << (boolalpha) << isBipartiteBFS(i, vis) << endl;
    }
}

//topological sort ques
//leetcode 207============================================

vector<int> kahnsAlgo(int n, vector<vector<int>> &graph, vector<vector<int>> &prerequisites)
{

    vector<int> indegree(n, 0);
    for (vector<int> ar : prerequisites)
        indegree[ar[1]]++;

    queue<int> que;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            que.push(i);
    }

    vector<int> ans;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size-- > 0)
        {
            int rvtx = que.front();
            que.pop();

            ans.push_back(rvtx);
            for (int e : graph[rvtx])
            {
                if (--indegree[e] == 0)
                {
                    que.push(e);
                }
            }
        }
    }

    return ans;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(numCourses, vector<int>());
    for (vector<int> ar : prerequisites)
        graph[ar[0]].push_back(ar[1]);

    vector<int> ans = kahnsAlgo(numCourses, graph, prerequisites);

    return ans.size() == numCourses;
}

//Leetcode 210.=========================================================

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(numCourses, vector<int>());
    for (vector<int> ar : prerequisites)
        graph[ar[0]].push_back(ar[1]);

    vector<int> ans = kahnsAlgo(numCourses, graph, prerequisites);

    if(ans.size() != numCourses) return {};
    return ans;
}

//
int longestIncreasingPath(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>>indegree(n,vector<int>(m,0));
    int dirA[4][2] = {{-1, 0}, {0, -1},{0, 1}, {1, 0}};
    queue<int>que;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int d=0;d<4;d++){
                int x=i+dirA[d][0];
                int y=j+dirA[d][1];
                if(x>=0 && y>=0 && x<n && y<m && matrix[x][y]>matrix[i][j]){
                    indegree[x][y]++;
                }
            }  
       }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            if(indegree[i][j]==0) que.push(i*m+j);
    }

    int length=0;    
    while(que.size()!=0){
        int size=que.size();
        while(size-->0){
            int vtx = que.front(); que.pop();

            int i=vtx/m;
            int j=vtx%m;
            for(int d=0;d<4;d++){
                int x=i+dirA[d][0];
                int y=j+dirA[d][1];
                if(x>=0 && y>=0 && x<n && y<m && matrix[x][y]>matrix[i][j] && --indegree[x][y]==0){
                    que.push(x*m +j);
                }
            }
        length++;
        }
    }
    return length;
}


//Kruskal Algo
vector<int> par;
vector<int> setSize;

int findPar(int vtx)
{
    if (par[vtx] == vtx)
        return vtx;
    return par[vtx] = findPar(par[vtx]);
}

void mergeSet(int p1, int p2)
{
    if (setSize[p1] < setSize[p2])
    {
        par[p1] = p2;
        setSize[p2] += setSize[p1];
    }
    else
    {
        par[p2] = p1;
        setSize[p1] += setSize[p2];
    }
}

void kruskalAlgo(vector<vector<int>> &arr)
{
    setSize.assign(arr.size()+1,1);
    for(int i=0;i<=arr.size();i++){
        par.push_back(i);
    }

    vector<vector<Edge*>> KruskalGraph(arr.size(), vector<Edge*>());
    sort(arr.begin(),arr.end(),[](vector<int>& a,vector<int>& b){
        return a[2] < b[2] ; // this - other,default is Increasing, '-' replace with '<'
    });
    
    for (vector<int> &ar : arr)
    {
        int u = ar[0];
        int v = ar[1];
        int p1 = findPar(u);
        int p2 = findPar(v);
        if (p1 != p2)
        {
            mergeSet(p1, p2);
            addEdge(KruskalGraph, u, v, ar[2]);
        }
    }

    display(KruskalGraph);
}

//leet 1168.=============================================

int minCosttoSupplyWater(int n,vector<int>&wells,vector<vector<int>>&pipes){
    for(int i=0;i<wells.size();i++){
        pipes.push_back({0,i+1,wells[i]});
        par.push_back(i);
    }
    par.push_back(wells.size());

    sort(pipes.begin(),pipes.end(),[](vector<int>&a,vector<int>&b){
        return a[2] < b[2];
    });

    int cost=0;
    for(vector<int>&p :pipes){
        int p1 = findPar(p[0]);
        int p2 = findPar(p[1]);

        if(p1!=p2){
            cost+=p[2];
            par[p1]=p2;
        }
    }
    return cost;
}

//hacker-earth: Mr. President

int mrPresident(){
    lli n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>graph,kruskalGraph;

    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        vector<int>ar = {u,v,w};
        graph.push_back(ar);
    }

    sort(graph.begin(),graph.end(),[](vector<int>&a,vector<int>&b){
        return a[2] < b[2];
    });

    for(int i=0;i<=n;i++){
        par.push_back(i);
    }

    lli MSTcost=0; 
    for(vector<int>g:graph){
        int p1=findPar(g[0]);
        int p2=findPar(g[1]);
        if(p1!=p2){
            par[p1]=p2;
            MSTcost+=g[2];
        }
    }

    int componentCount=0;
    for(int i=1;i<=n;i++){
        if(par[i]==i && ++componentCount>1) return -1;
    }

    int superRoad=0;
    for(int i=kruskalGraph.size()-1;i>=0;i--){
        if(MSTcost<=k) break;
        MSTcost = MSTcost - kruskalGraph[i][2] + 1;
        superRoad++; 
    }
    return MSTcost<=k?superRoad:-1;
}

//hacker-rank: journey to the moon
int journeyToTheMoon_UnionFind(){
    int n,p;
    int ans=0;
    cin>>n>>p;
    for(int i=0;i<=n;i++){
        par.push_back(i);
    }
    while(p-->0){
        int u,v;
        cin>>u>>v;  //pair of astro belonging to same country

        int p1=findPar(u);
        int p2=findPar(v);
        par[p1]=min(p1,p2);
        par[p2]=min(p1,p2);
    }
    int worldPopulation=n;
    
    vector<int>countrySize(n,0);
    for(int i=0;i<n;i++){
        countrySize[findPar(i)]++;
    }

    for(int i=0;i<n;i++){
        if(par[i]==i){                                             //S=A+B+C
            ans+=countrySize[i]*(worldPopulation-countrySize[i]);  //combi=A*(S-A) + B*(S-A-B) +C*(S-A-B-C)
            worldPopulation-=countrySize[i];
        }
    }
    return ans;
}



//topic

class pair_
{
public:
    int src;
    int par;
    int w;
    int wsf;

    pair_(int src, int par, int w, int wsf)
    {
        this->src = src;
        this->par = par;
        this->w = w;
        this->wsf = wsf;
    }

    // bool operator<(pair_ &o)    //method of comparator inside class
    // {
    //     return this.wsf > o.wsf; // default min PQ.
    //     //   return o.wsf > this.wsf   // max PQ.
    // }
    
};

struct dijikstraComp            //best comparator method as class always not present
{
public:
    bool operator()(pair_ &p1, pair_ &p2)
    {
        return p1.wsf > p2.wsf; // default min PQ.
        //   return p2.wsf > p1.wsf   // max PQ.
    }
};

void dijikstraAlgo(int src)
{
    vector<vector<Edge*>> dijikstraGraph(n, vector<Edge*>());
    priority_queue<pair_, vector<pair_>, dijikstraComp> pq; // by default min PQ.

    vector<bool> vis(n, false);
    pq.push(pair_(src, -1, 0, 0));
    while (pq.size() != 0)
    {
        int size = pq.size();
        while (size-- > 0)
        {
            pair_ rvtx = pq.top();
            pq.pop();

            if (vis[rvtx.src])
                continue; // for cycle.

            if (rvtx.par != -1)
                addEdge(dijikstraGraph, rvtx.src, rvtx.par, rvtx.w);

            vis[rvtx.src] = true;
            for (Edge *e : graph[rvtx.src])
            {
                if (!vis[e->v])
                    pq.push(pair_(e->v, rvtx.src, e->w, rvtx.wsf + e->w));
            }
        }
    }

    display(dijikstraGraph);
}

struct primsComp
{
public:
    bool operator()(pair_ &p1, pair_ &p2)
    {
        return p1.w > p2.w; // default min PQ.
        //   return p2.w > p1.w   // max PQ.
    }
};

void primsAlgo(int src)
{
    vector<vector<Edge*>> primsGraph(n, vector<Edge*>());
    priority_queue<pair_, vector<pair_>, primsComp> pq; // by default min PQ.

    vector<bool> vis(n, false);
    pq.push(pair_(src, -1, 0, 0));
    while (pq.size() != 0)
    {
        int size = pq.size();
        while (size-- > 0)
        {
            pair_ rvtx = pq.top();
            pq.pop();

            if (vis[rvtx.src])
                continue; // for cycle.

            if (rvtx.par != -1)
                addEdge(primsGraph, rvtx.src, rvtx.par, rvtx.w);

            vis[rvtx.src] = true;
            for (Edge* e : graph[rvtx.src])
            {
                if (!vis[e->v])
                    pq.push(pair_(e->v, rvtx.src, e->w, rvtx.wsf + e->w));
            }
        }
    }

    display(primsGraph);
}

//dijikstra ques===========================================================

//leet-743
int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int,int>>>graph(N+1,vector<pair<int,int>>());
        vector<int>dist(N+1,-1);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>  >pq;
        
        for(int u=0;u<times.size();u++){
            graph[times[u][0]].push_back({times[u][1],times[u][2]});
        }

        pq.push({0,K});
        while(pq.size()!=0){
                pair<int,int> rvtx = pq.top(); pq.pop();
                
                if(dist[rvtx.second]!=-1) continue;
                
                dist[rvtx.second]=rvtx.first;
                for(pair<int,int> e:graph[rvtx.second]){
                    if(dist[e.first]==-1){
                        pq.push({rvtx.first+e.second,e.first});
                    }
                }
        }
        
        int ans=0;
        for(int i=1;i<=N;i++){
            if(dist[i]==-1) return -1;
            else ans=max(ans,dist[i]);
        }
        
        return ans;
    }
    
//leet-787
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>>graph(n+1);
        for(vector<int>ar:flights){
            graph[ar[0]].push_back({ar[1],ar[2]});
        }
        
        priority_queue< vector<int>,vector<vector<int>>,greater<vector<int>> >pq;
       
        
        pq.push({0,src,K+1});
        while(pq.size()!=0){
            
            vector<int> rvtx = pq.top(); pq.pop();
            
            if(rvtx[1]==dst) return rvtx[0];

            if(rvtx[2]==0) continue;
            
            
            for(pair<int,int> e:graph[rvtx[1]]){
                     
                    pq.push({rvtx[0]+e.second,e.first,rvtx[2]-1});
               
            }
        }
        return -1;
    }


//Bellman-Ford Algo
void bellmanFord(vector<vector<int>> graph, int src)
{
    int INF = 1e8;
    vector<vector<int>> dp(graph.size(), vector<int>(graph.size() + 1), INF);
    dp[src][0] = 0;
    bool isNegativeCycle = false;

    for (int i = 1; i <= graph.size(); i++)
    {
        for (int j = 0; j < graph.size(); j++)
            dp[j][i] = dp[j][i - 1];

        for (vector<int> &e : graph)
        {
            int u = e[0], v = e[1], w = e[2];
            if (dp[u][i - 1] == INF)
                continue;
            int temp = dp[v][i];
            dp[v][i] = min(dp[v][i], dp[u][i - 1] + w);

            if (i == graph.size() && dp[v][i] != temp)
                isNegativeCycle = true;
        }
    }
}

void bellmanFord_1D(vector<vector<int>> &graph, int src)
{
    int INF = 1e8;
    int n=graph.size();
    vector<int> dp(n, INF);
    dp[src] = 0;
    bool isNegativeCycle = false;

    for (int i = 1; i <= n; i++)
    {
        for (vector<int> &e : graph)
        {
            int u = e[0], v = e[1], w = e[2];
            if (dp[u][i - 1] == INF)
                continue;
            int temp = dp[v][i];
            dp[v] = min(dp[v], dp[u] + w);
            if (i == graph.size() && dp[v][i] != temp)
                isNegativeCycle = true;
        }
    }
}


void solve(){
    constructGraph();
    //removeVtx(2);
    
    
    vector<bool>vis(n,false);
   // cout<<boolalpha<<hasPath(0,6,vis);
    // allPaths(0,6,vis,"");

    // pair1 p;
    // allSolution(1,6,0,55,vis,p);
    // cout<<p.ceil<<endl;
    //preOrder(0,0,vis,to_string(0)+"");
    // display();

    //HamiltonianPath(2,2,vis,0,"");

    //cout<<GCC(vis);

    // bfs(0,vis);
    // bfs_2(0,vis);
    //BFS_3(0,vis);

    vector<vector<int>>arr = {{0,1,2},{0,2,2},{1,2,2}};
    kruskalAlgo(arr);

}

int main(){
    solve();
}