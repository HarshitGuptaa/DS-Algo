import java.util.*;
public class l01{
    public static class Node{
        int data;
        Node right;
        Node left;
        
        Node(){

        }

        Node(int data){
            this.data=data;
        }
        Node(int data,Node left,Node right){
            this.data=data;
            this.left=left;
            this.right=right;
        }
    }
    static int idx=0;
    public static Node createTree(int []arr){
        if(arr[idx]==-1 || idx==arr.length) {
            idx++; 
            return null;
        }
        Node node = new Node(arr[idx]);
        idx++;
        node.left=createTree(arr);
        node.right=createTree(arr);

        return node;
    }
    

    public static void display(Node node){
        if(node==null) return;
        String ans="";
        
        ans+=node.left!=null?node.left.data:".";
        ans+="->"+node.data+"<-";
        ans+=node.right!=null?node.right.data:".";
        
        System.out.println(ans);
        display(node.left);
        display(node.right);
    }

    public static void linewiselevelorder(Node node,int level){
        LinkedList<Node>que = new LinkedList<>();
        que.add(node);

    while(que.size()!=0){
        System.out.print(level + "->");
        int size = que.size();

        while(size-->0){
            Node rNode = que.removeFirst();
            System.out.print(rNode.data+" ");
            if(rNode.left!=null){
                que.addLast(rNode.left);
                
            }
            if(rNode.right!=null){
                que.addLast(rNode.right);
                
            }
        }
        level++;
        System.out.println();
    }
        
    }

    public static void leftview(Node node,int level){
        LinkedList<Node>que = new LinkedList<>();
        que.add(node);

    while(que.size()!=0){
       // System.out.print(level + "->");
        int size = que.size();
        System.out.print(que.getFirst().data);
        while(size-->0){
            Node rNode = que.removeFirst();
            
            if(rNode.left!=null){
                que.addLast(rNode.left);
                
            }
            if(rNode.right!=null){
                que.addLast(rNode.right);
                
            }
        }
        //level++;
        System.out.println();
    }
        
    }

    public static void main(String[] args) {
        int []arr ={10,20,40,60,-1,-1,70,-1,-1,50,80,
             -1,-1,-1,30,90,-1,110,150,-1,-1,-1,100,120,-1,-1,-1};
        Node node = createTree(arr);
        //display(node);
        linewiselevelorder(node, 0);
        leftview(node, 0);

    }
}