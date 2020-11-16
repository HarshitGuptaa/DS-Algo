import java.util.*;
public class treePrac{
    
    public static class Node{
        int data;
        Node left;
        Node right;
    
        Node(){
    
        }
    
        Node(int data){
            this.data = data;
        }
    
        Node(int data,Node left,Node right){
            this.data = data;
            this.left = left;
            this.right = right;
    
        }        
    }

    public static void display(Node node) {
        if(node==null){
            return;
        }
        String ans="";
        ans+=node.left!=null?node.left.data:".";
        ans+="<-"+node.data+"->";
        ans+=node.right!=null?node.right.data:".";

        System.out.println(ans);
        display(node.left);
        display(node.right);
    }


    public static Node createBST(int []arr,int si,int ei){
        if(si>ei) return null;
        int mid = si+(ei-si)/2;
        Node node = new Node(arr[mid]);
        node.left = createBST(arr,si,mid-1);
        node.right = createBST(arr,mid+1,ei);
        return node;
    }

    //recursive
    public static boolean findInBST(Node node,int data){
        if(node==null) return false;
        if(node.data == data) return true;
        boolean res=false;
        if(data<node.data) res=res || findInBST(node.left,data);
        else res=res || findInBST(node.right,data);
        return res;
    }

    public static boolean findInBSTitr(Node node,int data){
        if(node==null) return false;
        Node temp = node;

        while(temp!=null){
            if(temp.data==data) return true;
            else if(data<temp.data) temp=temp.left;
            else temp=temp.right;
        }
        return false;
    }

    static int prev = (int)-1e7;
    public static boolean isBST(Node node){
        if(node==null) return true;
        boolean res = true;
        res = res && isBST(node.left);

        if(prev>node.data) return false;
        prev=node.data;

        res = res && isBST(node.right);
        return res;

    }

    public static int  maxEle(Node node){
        Node tmp=node;
        while(tmp.right!=null) tmp=tmp.right;
        return tmp.data;
    }
    public static int minEle(Node node){
        Node tmp=node;
        while(tmp.left!=null) tmp=tmp.left;
        return tmp.data;
    }
    
    public static int LCAofBST(Node node,int p,int q){
        Node temp = node;
        while(temp!=null){
            if(temp.data>p && temp.data>q) temp=temp.left;
            else if(temp.data<p && temp.data<q) temp=temp.right;
            else return temp.data;
        }
        return -1;
    }

    //kfar
    public static boolean nodetorootpath(Node node,int data,ArrayList<Node>list){
        if(node==null) return false;
        boolean res=false;
        if(node.data == data) {
            list.add(node);
            return true;
        }
        res=res || nodetorootpath(node.left,data,list);
        res=res || nodetorootpath(node.right,data,list);
        if(res) list.add(node);
        return res;
    }

    public static void kdown(Node node,int level,Node avoid){
        if(node==avoid || node==null) return;

        if(level==0) System.out.print(node.data+ " ");

        kdown(node.left,level-1,avoid);
        kdown(node.right,level-1,avoid);
    }

    public static void kfar(int data,Node node,int k){
        ArrayList<Node> list = new ArrayList<>();
        nodetorootpath(node,data,list);
        Node avoid=null; 
        for(int i=0;i<list.size();i++){
            kdown(list.get(i),k-i,avoid);
            avoid=list.get(i);
        }
    }

    //view set
    public static void lineWiseLevelOrder(Node node){
        LinkedList<Node> list = new LinkedList<>();
        list.add(node);
        int level=0;
        
        while(list.size()!=0){
            int size=list.size();
            System.out.print("Level " + level + " -> ");
            level++;
            while(size-->0){
                Node rn = list.removeFirst();
                System.out.print(rn.data+", ");
                if(rn.left!=null) list.addLast(rn.left);
                if(rn.right!=null) list.addLast(rn.right);
            }
            System.out.println(); 
        }
    }

    public static void leftView(Node node){
        LinkedList<Node> list = new LinkedList<>();
        list.add(node);
        int level=0;
        
        while(list.size()!=0){
            int size=list.size();
            System.out.print("Level " + level + " -> ");
            level++;
            Node l = list.getFirst();  //or peekfirst()
            System.out.print(l.data);
            while(size-->0){
                Node rn = list.removeFirst(); 
                //System.out.print(rn.data+", ");
                if(rn.left!=null) list.addLast(rn.left);
                if(rn.right!=null) list.addLast(rn.right);
            }
            System.out.println(); 
        }
    }

    public static void rightView(Node node){
        LinkedList<Node> list = new LinkedList<>();
        list.add(node);
        int level=0;
        
        while(list.size()!=0){
            int size=list.size();
            System.out.print("Level " + level + " -> ");
            level++;
            Node l = list.peekLast();  // or getLast()
            System.out.print(l.data);
            while(size-->0){
                Node rn = list.removeFirst();
                //System.out.print(rn.data+", ");
                if(rn.left!=null) list.addLast(rn.left);
                if(rn.right!=null) list.addLast(rn.right);
            }
            System.out.println(); 
        }
    }

//vertical order

    static int leftMinValue=0;
    static int rightMaxValue=0;

    public static void width(Node node,int lev){
        if(node==null) return;
 
        leftMinValue=Math.min(leftMinValue,lev);
        rightMaxValue=Math.max(rightMaxValue,lev);
        
        width(node.left, lev - 1);
        width(node.right, lev + 1);
    } 

    public static class pairVO{
        Node node;  //actual Node
        int vl=0;  // vertical Level
        public pairVO(Node node,int vl){
            this.node=node;
            this.vl=vl;
        }
    }
 
    public static void verticalOrder(Node node){
        width(node,0);
        int n=rightMaxValue - leftMinValue + 1;
        ArrayList<ArrayList<Integer>> ans=new ArrayList<>(); // vector<vector<int>> (n,vector<int>());
        for(int i=0;i<n;i++)
          ans.add(new ArrayList<>());
       
 
        LinkedList<pairVO> que=new LinkedList<>();
        que.addLast(new pairVO(node,-leftMinValue));
 
        while(que.size()!=0){
            int size=que.size();
            while(size--> 0){
                pairVO rpair=que.removeFirst();
                ans.get(rpair.vl).add(rpair.node.data);
                if(rpair.node.left!=null) que.addLast(new pairVO(rpair.node.left, rpair.vl - 1));
                if(rpair.node.right!=null) que.addLast(new pairVO(rpair.node.right,rpair.vl + 1));    
            }
        }
 
        for(ArrayList<Integer> ar: ans)
           System.out.println(ar);
        System.out.println();
    }

    public static void verticalOrderSum(Node node){
        width(node,0);
        int n=rightMaxValue - leftMinValue + 1;
        int [] ans = new int[n];
 
        LinkedList<pairVO> que=new LinkedList<>();
        que.addLast(new pairVO(node,-leftMinValue));
 
        while(que.size()!=0){
            int size=que.size();
            while(size--> 0){
                pairVO rpair=que.removeFirst();
                ans[rpair.vl] += rpair.node.data;
                if(rpair.node.left!=null) que.addLast(new pairVO(rpair.node.left, rpair.vl - 1));
                if(rpair.node.right!=null) que.addLast(new pairVO(rpair.node.right,rpair.vl + 1));    
            }
        }
 
        for(int ele: ans)
           System.out.println(ele);
        System.out.println();
    }

    static int leftMinDiag = 0;
    public static void widthDiag(Node node,int level){
        if(node==null) return;
        leftMinDiag = Math.min(leftMinDiag,level);
        widthDiag(node.left,level-1);
        widthDiag(node.right,level+0);
    }

    public static void diagonalOrder(Node node){
        widthDiag(node,0);
        int n = -leftMinDiag + 1;
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        // for(ArrayList<Integer> ar:ans){
        //     ar=new ArrayList<>();
        // }
        for(int i=0;i<n;i++){
            ans.add(new ArrayList<>());
        }
        LinkedList<pairVO> que = new LinkedList<>();
        que.addLast(new pairVO(node,-leftMinDiag));
        while(que.size()!=0){
            int size=que.size();
            while(size-->0){
                pairVO rpair = que.removeFirst();
                ans.get(rpair.vl).add(rpair.node.data);
                if(rpair.node.left!=null) que.addLast(new pairVO(rpair.node.left,rpair.vl-1));
                if(rpair.node.right!=null) que.addLast(new pairVO(rpair.node.right,rpair.vl+0));

            }
        }
        for(ArrayList<Integer>ar:ans){
            System.out.println(ar);
        }

    }


//Traversal Set Iterative

public static class tpair{
    Node node=null;
    boolean selfdone = false;
    boolean leftdone = false;
    boolean rightdone = false;

    tpair(Node node,boolean selfdone,boolean leftdone,boolean rightdone){
        this.node=node;
        this.selfdone=selfdone;
        this.leftdone=leftdone;
        this.rightdone=rightdone;
    }
}

public static void preOrderItr(Node node){
    Stack<tpair> st = new Stack<>();
    st.push(new tpair(node,false,false,false));

    while(st.size()!=0){
        if(st.peek().selfdone==false){
            st.peek().selfdone=true;
            System.out.print(st.peek().node.data + " ");
        }
        else if(st.peek().leftdone==false){
            st.peek().leftdone=true;
            if(st.peek().node.left!=null){
                st.push(new tpair(st.peek().node.left,false,false,false));
            }
        }else if(st.peek().rightdone==false){
            st.peek().rightdone=true;
            if(st.peek().node.right!=null){
                st.push(new tpair(st.peek().node.right,false,false,false));
            }
        }else{
            st.pop();
        }
    }
}

//Tree Construction

//From Pre And In Order

public static Node ConstTreePreAndIn(int []pre,int psi,int pei,int []in,int isi,int iei){
    if(psi>pei || isi>iei) return null;

    Node node = new Node(pre[psi]);
    int idx = isi;
    while(in[idx]!=pre[psi]){
        idx++;
    }
    int tnel = idx - isi;

node.left = ConstTreePreAndIn(pre, psi+1 ,psi+tnel ,in, isi , idx-1);
node.right = ConstTreePreAndIn(pre, psi+tnel+1 , pei ,in, idx+1 , iei );

return node;
}


public static void main(String[] args) {
    int []arr = {10,20,30,40,50,60,70,80,90,100,110}; //sorted array required
    Node root = createBST(arr, 0, arr.length-1);
    display(root);
    System.out.println();
    // System.out.println(findInBST(root,0));
    // System.out.println(findInBSTitr(root,0));
    //System.out.println(isBST(root));
    //kfar(30,root,2);
    //lineWiseLevelOrder(root);
    // leftView(root);
    // rightView(root);
    // verticalOrder(root);
    // verticalOrderSum(root);
    diagonalOrder(root);
}


}
