import java.util.*;

public class genericTree{
    

public static class Node{
    int data;
    ArrayList<Node> childs = new ArrayList<>();

    Node(int data){
        this.data = data;
    }
}

public static void display(Node node) {
    String ans="";
    ans+= node.data + "-> ";
    for(Node child:node.childs){
        ans+= child.data + ", ";
    }
    System.out.println(ans);
    for(Node child:node.childs){
        display(child);
    }
}

public static Node createTree(int []arr) {
    Stack<Node> st = new Stack<>();

    for(int i=0;i<arr.length-1;i++){
        if(arr[i]==-1){
            Node rn = st.pop();
            st.peek().childs.add(rn);
        }else{
            Node node = new Node(arr[i]);
            st.push(node);
        }
    }
    return st.pop();
}

public static int height(Node node){
    int h=-1;
    for(Node child:node.childs){ //apne har child se height mangao +1 meri height
        h=Math.max(h,height(child));
    }
    return h+1;
}

public static int size(Node node){
    int s=0;
    for(Node child:node.childs){
        s+=size(child);
    }
    return s+1;
}

public static boolean find(Node node,int data){
    if(node.data == data) return true;

    boolean res=false;
    for(Node child:node.childs){
        res = res || find(child,data);
    }
    return res;
}

public static boolean nodetorootPath(Node node,int data,ArrayList<Node> path){
    if(node.data==data){
        path.add(node);
        return true;  
    } 

    boolean res=false;
    for(Node child:node.childs){
        res = res || nodetorootPath(child,data,path);
    }

    if(res) path.add(node);

    return res;
}

//kfar kaway

public static void kaway(Node node,Node avoid,int level){
    if(node==avoid || node==null) return;
    if(level==0) {
        System.out.print(node.data+" ");
        return;
    }
    for(Node n:node.childs){
        kaway(n,avoid,level-1);
    }
}

public static void kfar(Node node,int data,int k){
    ArrayList<Node> list = new ArrayList<>();
    nodetorootPath(node,data,list);

    Node avoid = null;
    for(int i=0;i<list.size();i++){
        kaway(list.get(i),avoid,k-i);
        avoid = list.get(i);
    }
}

public static void linewiseLevelOrder(Node node){
    Queue<Node> que = new LinkedList<>();
    que.add(node);
    int level=0;
    while(que.size()!=0){
        int size=que.size();
        System.out.print("Level "+level+" -> ");
        while(size-->0){
            Node rn=que.remove();
            System.out.print(rn.data+" ");
            for(Node child:rn.childs){
                que.add(child);
            }
        }
        level++;
        System.out.println();
    }
}

public static Node linearize(Node node){
    if(node.childs.size()==0) return node;
    
    int n=node.childs.size();
    Node lastTail = linearize(node.childs.get(n-1));
    for(int i=n-2;i>=0;i--){
        Node secondLastTail = linearize(node.childs.get(i));
        secondLastTail.childs.add(node.childs.get(i+1));
        node.childs.remove(node.childs.size()-1);
    }
    return lastTail;
}

public static void main(String[] args) {
    int [] arr= {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,
        -1,-1,90,-1,-1,40,100,-1,-1,-1};
        Node node = createTree(arr);
        display(node);
        // ArrayList<Node> path = new ArrayList<>();
        // nodetorootPath(node,110,path);
        // for(Node n:path){
        //     System.out.print(n.data+", ");
        // }
        // kfar(node,30,2);
        
        // linewiseLevelOrder(node);
            Node n = linearize(node);
            display(node);

}











}