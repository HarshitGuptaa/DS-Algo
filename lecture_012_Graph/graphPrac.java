import java.util.*;

public class graphPrac {
    
    public static class Edge{
        int v;
        int w;
        Edge(int v,int w){
            this.v=v;
            this.w=w;
        }
    }

    static int N=7;
    static ArrayList<Edge> [] graph = new ArrayList[N];

    public static void addEdge(int u,int v,int w){
        graph[u].add(new Edge(v,w));
        graph[v].add(new Edge(u,w));
    }

    public static void constructGraph(){
        for (int i = 0; i < N; i++) {
            graph[i] = new ArrayList<Edge>();
        }

        addEdge(0,1,10);
        addEdge(0,3,10);
        addEdge(3,2,40);
        addEdge(3,4,2);
        addEdge(1,2,10);
        addEdge(4,5,2);
        addEdge(4,6,3);
        addEdge(5,6,8);
    }

    public static void display(){
        for(int i=0;i<N;i++){
            System.out.print(i + " -> ");
            for(Edge e:graph[i]){
                System.out.print(e.v + ", ");
            }
            System.out.println();
        }
    }

    public static int searchEdge(int u,int v){
        int idx=-1;
        for(int i=0;i<graph[u].size();i++){
            Edge e = graph[u].get(i);
            if(e.v==v) idx=i;
        }
        return idx;
    }

    public static void removeEdge(int u,int v){
        int uidx = searchEdge(u,v);
        int vidx = searchEdge(v,u);

        graph[u].remove(uidx);
        graph[v].remove(vidx);
    }

    public static void removeVtx(int u){
        for(int i=0;i<graph[u].size();i++){
            Edge e = graph[u].get(i);
            removeEdge(e.v,u);
        }
    }

    boolean hasPath(int src,int dest,boolean []vis){
        if(src==dest) return true;

        vis[src] = true;
        boolean res=false;
        for(Edge e:graph[src]){
            if(!vis[e.v]) res = res || hasPath(e.v,dest,vis);
        }
        return res;
    }

    public static int allPaths(int src,int dest,String ans,boolean []vis){
        if(src==dest) {
            System.out.println(ans + dest);
            return 1;
        }

        vis[src]=true;
        int count=0;
        for(Edge e:graph[src]){
            if(!vis[e.v]) count+= allPaths(e.v,dest,ans+src+" ",vis);
        }
        vis[src] = false;
        return count;
    }

    public static int hamiltonianPath(int src,int osrc,int edgeCount,String path,boolean []vis){
        if(edgeCount==N-1){
            int idx = searchEdge(src,osrc);
            if(idx==-1){
                System.out.println("Hamiltonian path: "+path+src);
            }else{
                System.out.println("Hamiltonian Cycle: "+path+src);
            }
            
            return 1;
        }
        
        int count=0;
        vis[src] = true;
        for(Edge e:graph[src])
        {
            if(!vis[e.v]) count+=hamiltonianPath(e.v,osrc,edgeCount+1,path+src+" ",vis);
        }
        vis[src]=false;

        return count;
    }

//leet 130

public static void dfs(char[][] board,int r,int c){
    board[r][c]="#";
    if(r-1>=0) dfs(board,r-1,c);
    if(r+1<board.length) dfs(board,r+1,c);
    if(c-1>=0) dfs(board,r,c-1);
    if(c+1<board[0].length) dfs(board,r,c+1);
}

public void solve(char[][] board) {
    int n=board.length;
    int m=board[0].length;

    for(int i=0;i<n;i++){
       if(board[i][0]=="O"){ dfs(board,i,0)};
        if(board[i][m-1]=="O"){dfs(board,i,m-1)};
    }

    for(int i=0;i<n;i++){
        if(board[0][i]=="O"){ dfs(board,0,i)};
         if(board[n-1][i]=="O"){dfs(board,n-1,i)};
     }

     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             if(board[i][j]=="O") board[i][j]="X";
         }
     }

     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=="#") board[i][j]="O";
        }
    }

}

//leet 200. Number of Islands
public void dfs(int r,int c,int n,int m,char[][] board){
    if(board[r][c]!='1') return;
    board[r][c]='0';
    if(r-1>=0) dfs(r-1,c,n,m,board);
    if(r+1<n) dfs(r+1,c,n,m,board);
    if(c-1>=0) dfs(r,c-1,n,m,board);
    if(c+1<m) dfs(r,c+1,n,m,board);
}

public int numIslands(char[][] grid) {
    if(grid.length==0) return 0;
    
    int n= grid.length;
    int m= grid[0].length;
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                count++;
                dfs(i,j,n,m,grid);
            }
        }
    }
    return count;
}


//bfs

public static class pair{
    int vtx;
    String psf;
    int level;

    pair(int vtx,String psf,int level){
        this.vtx=vtx;
        this.psf=psf;
        this.level=level;
    }
}

public static void bfs_01(int src,boolean []vis){
    int dest = 6;
    LinkedList<pair> que = new LinkedList<>();
    que.addLast(new pair(src,src+"",0));
    
    while(que.size()!=0){
        int size=que.size();
        while(size-->0){
            pair rvtx = que.removeFirst();

            if(vis[rvtx.vtx]){
				System.out.println("Cycle: " + rvtx.psf);
				continue;
			}

			if(rvtx.vtx==desti){
				System.out.println("destinantion: " + rvtx.psf + " -> " + rvtx.level);
			}

            vis[rvtx.vtx]=true;
            for(Edge e:graph[rvtx.vtx]){
                if(!vis[e.v]) que.addLast(new pair(e.v,rvtx.psf+e.v,rvtx.level+1));
            }
        }

    }

}


//leet 1091

public static int shortestPathBinaryMatrix(int [][]grid){
    int n=grid.length;
    int m=grid[0].length;
    int dir[][] = {{-1, -1}, {-1, 0}, {0, -1}, {-1, 1}, {1, -1}, {0, 1}, {1, 0}, {1, 1}};

    if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
    
    int level=1;
    int ans=-1;    
        
    LinkedList<Integer> que = new LinkedList<>();
    que.addLast(0);
    grid[0][0]=1;

    while(que.size()!=0){
        int size=que.size();
        while(size-->0){
            int rvtx = que.removeFirst();
            int r=rvtx/m;
            int c=rvtx%m;

            if(r==n-1 && c==m-1) ans=level;

            for(int i=0;i<8;i++){
                int x=r+dir[i][0];
                int y=c+dir[i][1];

                if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==0) {
                    grid[x][y]=1;
                    que.addLast(x*m +y);
                }
                
            }

        }
        level++;
    }

    return ans;
}


//Rotten Oranges
public int orangesRotting(int[][] grid) {
    if(grid.length==0) return -1;
    int n=grid.length;
    int m=grid[0].length;
    
    int dir[][] = {{0,1},{0,-1},{1,0},{-1,0}};
    LinkedList<Integer> que = new LinkedList<>();        
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                que.addLast(i*m+j);
            }
        }    
    }

    int level=0;

    while(que.size()!=0){
        int size=que.size();
        while(size-->0){
            int rvtx = que.removeFirst();
            int r = rvtx/m;
            int c = rvtx%m;

            for(int i=0;i<dir.length;i++){
                int x=r+dir[i][0];
                int y=c+dir[i][1];

                if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1){
                    grid[x][y]=2;
                    que.addLast(x*m + y);
                }
            }
        }
        level++;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1) return -1;
        }
    }
    
    
    return level==0?0:level-1;
}





    public static void main(String[] args) {
        constructGraph();
        display();
        //System.out.println(searchEdge(0,1));
        // removeEdge(0,1);
        // display();
        System.out.println();
        boolean []vis = new boolean[N];
        System.out.println("Paths: "+allPaths(0,3,"",vis));
    }






}



import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static class Edge{
        int v;
        Edge(int v){
            this.v=v;
        }
    }

    public static ArrayList<Edge> [] graph ;

    public static class pair{
    int vtx;
    String psf;
    int level;

    pair(int vtx,String psf,int level){
        this.vtx=vtx;
        this.psf=psf;
        this.level=level;
    }
}

    public static int bfs_01(int src,boolean []vis,int desti){
    LinkedList<pair> que = new LinkedList<>();
    que.addLast(new pair(src,src+"",0));
    
    while(que.size()!=0){
        int size=que.size();
        while(size-->0){
            pair rvtx = que.removeFirst();

            if(vis[rvtx.vtx]){
				// System.out.println("Cycle: " + rvtx.psf);
				continue;
			}

			if(rvtx.vtx==desti){
				// System.out.println("destinantion: " + rvtx.psf + " -> " + rvtx.level);
                return rvtx.level;
            }

            vis[rvtx.vtx]=true;
            for(Edge e:graph[rvtx.vtx]){
                if(!vis[e.v]) que.addLast(new pair(e.v,rvtx.psf+e.v,rvtx.level+1));
            }
        }

    }
    return -1;
}

    public static int ans(int level, int c, int t){
        if(c>t){
            return level*c + ((level-1)*(t-(c-t)));
        }else if(c<t){
            int val = t/c;
            val++;
            t=t%c;
            int rem = level%val;
            if(rem==0) level = level/val;
            else level = (level/val) + 1; 

            return level*c + ((level-1)*(t-(c-t)));
        }
        return level*c;
    } 

    public static void main(String[] args) {
        
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();
        int t = scn.nextInt();
        int c = scn.nextInt();
        graph = new ArrayList[n];

        for(int i=0;i<n;i++){
            graph[i] = new ArrayList<Edge>();
        }
    
        for(int i=0;i<m;i++){
            int u = scn.nextInt();
            int v = scn.nextInt();
            graph[u-1].add(new Edge(v-1));
            graph[v-1].add(new Edge(u-1));
        }

        int level = bfs_01(0,new boolean[n],n-1);
        int a = ans(level,c,t);
        System.out.println(a);
    }
}