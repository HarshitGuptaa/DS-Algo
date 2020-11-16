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