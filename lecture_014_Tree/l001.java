import java.util.*;

public class l001{
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
    static int idx=0;
    public static Node createTree(int []arr) {
        if(idx==arr.length || arr[idx]==-1){
            idx++;
            return null;
        }
        Node node = new Node(arr[idx]);
        idx++;
        node.left=createTree(arr);
        node.right=createTree(arr);
        return node;
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

    public static boolean findData(Node node,int data){
        if(node==null) return false;
        if(node.data==data) return true;

        boolean res = false;

        res= res || findData(node.left, data);
        res= res || findData(node.right, data);

        return res;
    }

    public static int height(Node node){ //return -1 for height in terms of edges, 0 in terms of node
        return node==null?-1: Math.max(height(node.left), height(node.right))+1;
    }

    public static int size(Node node){
        return node==null?0:size(node.left) + size(node.right) +1;
    }

    public static int maximum(Node node){  //max ele in tree
        if(node==null) return (int)-1e8;
        return Math.max( Math.max(maximum(node.left),maximum(node.right)) , node.data );
    }


    public static boolean nodeToRootPath_(Node root,int data,ArrayList<Node>path){
        if(root==null) return false;
        if(root.data==data){
            path.add(root);
            return true;
        }

        boolean res = nodeToRootPath_(root.left, data, path) || nodeToRootPath_(root.right, data, path);

        if(res) path.add(root);
        return res;
    }


    public static ArrayList<Node> nodeToRootPath(Node root,int data){
        if(root==null) return new ArrayList<>();
        
        if(root.data==data){
            ArrayList<Node>base = new ArrayList<>();
            base.add(root);
            return base;
        }

        ArrayList<Node> left = nodeToRootPath(root.left, data);
        if(left.size()!=0){
            left.add(root);
            return left;
        }
        ArrayList<Node> right = nodeToRootPath(root.right, data);
        if(right.size()!=0){
            right.add(root);
            return right;
        }
        return new ArrayList<>();
    }

    public static Node LCA_01(Node node, int data1,int data2){
        ArrayList<Node> list1 = nodeToRootPath(node, data1);
        ArrayList<Node> list2 = nodeToRootPath(node, data2);

        if(list1==null || list2==null) return null;

        int i=list1.size()-1;
        int j=list2.size()-1;

        Node prev = null;

        while(i>=0 && j>=0){
            if(list1.get(i).data!=list2.get(j).data){
                break;
            }
            prev = list1.get(i);
            i--;
            j--;
        }
        return prev;
    }

    static Node LCAnode = null; 
    public static boolean LCA_02(Node root,int p,int q){
        if(root==null) return false;

        boolean selfDone = false;
        if(root.data==p || root.data==q) selfDone = true;

        boolean leftDone = LCA_02(root.left,p,q);
        if(LCAnode!=null) return true;

        boolean rightDone = LCA_02(root.right,p,q);
        if(LCAnode!=null) return true;

        if(leftDone&&rightDone || selfDone&&leftDone || selfDone&&rightDone) LCAnode=root; //in post order

        return leftDone || rightDone ||selfDone;
    }

    public static int diameter_01(Node node) {  //O(n2)
        if(node==null) return 0;

        int ld = diameter_01(node.left);
        int rd = diameter_01(node.right);

        int lh = height(node.left);
        int rh = height(node.right);

        int myDia =  lh+rh+2;

        return Math.max(Math.max(ld,rd),myDia);

    }

    public static int [] diameter_02(Node node){ //O(n)
        if(node==null) return new int [] {0,-1};
        
        int [] lh = diameter_02(node.left);
        int [] rh = diameter_02(node.right);
        int [] ans = new int[2];

        ans[0] = Math.max(Math.max(lh[0],rh[0]), lh[1]+rh[1]+2);
        ans[1] = Math.max(lh[1], rh[1]) +1;

        return ans;
    }

    static int maxDia = 0;

    public static int diameter_03(Node node){ 
        if(node==null) return -1;
        
        int  lh = diameter_03(node.left);
        int  rh = diameter_03(node.right);
        
        maxDia = Math.max(maxDia, lh+rh+2);

        return Math.max(lh,rh)+1;
    }


    static int maxSum = (int)-1e7;
    public static int leaftoLeafMaxSum(Node node){
        if(node==null) return(int) -1e7;
        if(node.left==null && node.right==null) return node.data;

        int ls = leaftoLeafMaxSum(node.left);
        int rs = leaftoLeafMaxSum(node.right);

        if(node.left!=null && node.right!=null){
            maxSum= Math.max(maxSum, ls + rs + node.data);
        }
        return (node.left == null?rs:node.right==null?ls:Math.max(ls, rs))+node.data;
    }

    public static int leaftoLeafMaxSum_02(Node node){
        if(node==null) return 0;

        int leftnodeToLeafSum = leaftoLeafMaxSum_02(node.left);
        int rightnodeToLeafSum = leaftoLeafMaxSum_02(node.right);

        if(node.left!=null && node.right!=null){
            maxSum = Math.max(maxSum,leftnodeToLeafSum+rightnodeToLeafSum+node.data);
            return Math.max(leftnodeToLeafSum,rightnodeToLeafSum)+node.data;
        }
        return node.left==null?rightnodeToLeafSum:leftnodeToLeafSum + node.data;
    }

    public static int nodeToNodeMaxSum(Node node) {
        if (node == null)
            return 0;
        int leftsum = nodeToNodeMaxSum(node.left);
        int rightsum = nodeToNodeMaxSum(node.right);
        
        int sideMax = Math.max(leftsum, rightsum) + node.data;
        maxSum = Math.max(Math.max(maxSum, sideMax), Math.max(leftsum + rightsum + node.data, node.data));

        return Math.max(sideMax, node.data);
    }

//path sum to meet target
    static int ans=0;
    public static void pathSum(Node node, int target,int prefSum, HashMap<Integer,Integer>map){

        if(node==null){
            return ;
        }
        prefSum+=node.data;
        ans+=map.getOrDefault(prefSum-target,0); //only gives how many answers are there in tree

        map.put(prefSum,map.getOrDefault(prefSum, 0) +1);

        pathSum(node.left, target,prefSum,map);
        pathSum(node.right, target,prefSum,map);

        map.put(prefSum,map.getOrDefault(prefSum, 0) -1);

    } 

    //camera requirement
    // -1: need a camera
    //  0:  im a camera
    //  1:  no need of camera

    static int camCount = 0;
    public static int camera(Node node){
        if(node==null) return 1;

        int left = camera(node.left);
        int right = camera(node.right);

        if(left==-1 || right==-1){
            camCount++;
            return 0;
        }
        if(left==0 || right==0){
            return 1;
        }
        return -1;
    }

    public static Node removeLeafs(Node node) {
        if (node == null)
            return null;
        if (node.left == null && node.right == null)
            return null;

        node.left = removeLeafs(node.left);
        node.right = removeLeafs(node.right);
        return node;
    }


    //=============================================
    //BST

    public static Node createBST(int[]arr,int si,int ei){
        if(si>ei) return null;
        int mid = si+(ei-si)/2;
        Node node = new Node(arr[mid]);

        node.left = createBST(arr, si, mid-1);
        node.right = createBST(arr, mid+1, ei);
        
        return node;
    }

    public static boolean findInBST(Node root,int data){  //log(n) complexity as max logn hi niche ja skte h
        Node node = root; 
        while(node!=null){
            if(node.data==data) return true;
            else if(data<node.data) node=node.left;
            else node=node.right;
        }
        return false;
    }

    public static Node prev = new Node(-10000);

    public static boolean isBST(Node node) {
        if (node == null) return true;
    
        if (!isBST(node.left)) return false;
    
        if (prev.data > node.data) return false;
        prev = node;
    
        if (!isBST(node.right)) return false;
    
        return true;
    }

    public static Node maxEle(Node root){
        Node curr = root;
        while(curr.right!=null){
            curr = curr.right;
        }
        return curr;
    } 

    public static Node minEle(Node root){
        Node curr = root;
        while(curr.left!=null){
            curr = curr.left;
        }
        return curr;
    }

    //iterative:faster than rec. and o(1) space
    public static int LCAofBST(Node root,int p,int q){
        Node curr = root;
        while(curr!=null){
            if(p<curr.data && q<curr.data) curr=curr.left;
            else if(p>curr.data && q>curr.data) curr=curr.right;
            else return curr.data;
        }
        return -1;
    }

    //rec takes space and a little slower
    public static int LCAofBSTrec(Node node, int a, int b){
        if (node == null)
            return -1;

    if (b < node.data && a < node.data) return LCAofBSTrec(node.left, a, b);
    else if (a > node.data && b > node.data) return LCAofBSTrec(node.right, a, b);
    else return node.data; //LCA point.

    }

    //find all elts in range (a,b)
    //preorder
    public static void allNodesInRange_01(Node root,int a,int b,ArrayList<Integer>ans){
        if(root==null) return;
        
        if(root.data>=a && root.data<=b) ans.add(root.data);

        if(root.data>a && root.data>b) allNodesInRange_01(root.left, a, b, ans); 
        else if(root.data<a && root.data<b) allNodesInRange_01(root.right, a, b, ans);
        else{//LCA
            allNodesInRange_01(root.left, a, b, ans);
            allNodesInRange_01(root.right, a, b, ans);
        }
    }

    //inorder - better due to bst prop. that inorder gives sorted array
    public static void allNodesInRange_02(Node root,int a,int b,ArrayList<Integer>ans){
        if(root==null) return;
        
        allNodesInRange_02(root.left, a, b,ans);
        //inorder - gives in sorted order
        if(root.data>=a && root.data<=b) ans.add(root.data);
        
        allNodesInRange_02(root.right, a, b,ans);
    }

    public static class pair {  //class is on heap always,so changes will always be reflected same as static
        int size = 0;
        int height = 0;
        boolean find = false;

        int ceil = Integer.MAX_VALUE;
        int floor = Integer.MIN_VALUE;

        Node pred = null;  //just prev node in preorder trav, irrespective of value 
        Node succ = null;
        Node prev = null;
    }

    //for binary tree pred succ
    public static void allSolution(Node node, int level, int data, pair p) {
        if (node == null)
            return;

        p.height = Math.max(p.height, level);
        p.size++;
        p.find = p.find || node.data == data;

        //if you shift the corresponding 5 lines in bw calls then inorder or at end then postorder
        if (node.data < data) p.floor = Math.max(p.floor, node.data);
        if (data < node.data) p.ceil = Math.min(p.ceil, node.data);
        if (node.data == data && p.pred == null) p.pred = p.prev;
        if (p.prev != null && p.prev.data == data && p.succ == null) p.succ = node;

        p.prev = node;
        
        
        allSolution(node.left, level + 1, data, p);
        allSolution(node.right, level + 1, data, p);
    }


    //this is inorder pred succ
    //iterative for bst, rec works too but this is logn
    public static void BSTPredSucc(Node node, int data) {
        Node pred = null;
        Node succ = null;

        while (node != null) {
            if (node.data > data) {
                succ = node;
                node = node.left;
            } else if (node.data < data) {  //when going right we set pred 
                pred = node;
                node = node.right;
            } else {
                Node temp = node;
                if (node.right != null) {
                    node = node.right;
                    while (node.left != null) {
                        node = node.left;
                    }
                    succ = node;
                    System.out.println("Successor: "+succ);
                }

                node = temp;
                if (node.left != null) {
                    node = node.left;
                    while (node.right != null) {
                        node = node.right;
                    }
                    pred = node;
                    System.out.println("Predecessor: "+pred);
                }

                break;
            }
        }
    }


    static Node DLLhead=null;
    static Node DLLprev=null;
    
    public static void DLL(Node node){
         if(node==null) return;
         
         DLL(node.left);
         
         if(DLLhead==null){
            DLLhead=node;
         }else{
             DLLprev.right=node;
             node.left=DLLprev;
         }
          DLLprev=node;
    
         DLL(node.right);
         
        }


//bst construction from preorder array , only bst constr poss from 1 type of iteration 
    static int i = 0;
    public static Node constructTreeFromPreOrder(ArrayList<Integer> preOrder, int lb, int ele, int rb)
    {
        if (ele < lb || ele > rb || i == preOrder.size())
            return null;
    
        Node node = new Node(ele);
        i++;
    
        if (i < preOrder.size())
            node.left = constructTreeFromPreOrder(preOrder, lb, preOrder.get(i), ele);
        if (i < preOrder.size())
            node.right = constructTreeFromPreOrder(preOrder, ele, preOrder.get(i), rb);
    
        return node;
    }
    
    public static Node constructTreeFromPreOrder_02(ArrayList<Integer>preOrder, int lb, int rb)
    {
        if (i == preOrder.size() || preOrder.get(i) < lb || preOrder.get(i) > rb)
            return null;
    
        Node node = new Node(preOrder.get(i));
        i++;
    
        node.left = constructTreeFromPreOrder_02(preOrder, lb, node.data);
        node.right = constructTreeFromPreOrder_02(preOrder, node.data, rb);
        return node;
    }
    
    public static int heightOfBSTPreorder(ArrayList<Integer>preOrder, int lb, int rb)
    {
        if (idx == preOrder.size() || preOrder.get(i) < lb || preOrder.get(i) > rb)
            return -1;
    
        int ele = preOrder.get(i);
        i++;
    
        int lh = heightOfBSTPreorder(preOrder, lb, ele);
        int rh = heightOfBSTPreorder(preOrder, ele, rb);
        return Math.max(lh, rh) + 1;
    }
    
    public static Node constructTreeFromPreOrder_(ArrayList<Integer>preOrder)
    {
        return constructTreeFromPreOrder_02(preOrder,(int)-1e8 , (int)1e8);
    }
    
    public static Node addData(Node root, int data)
    {
        if (root == null)
            return new Node(data);
        if (data < root.data)
            root.left = addData(root.left, data);
        else
            root.right = addData(root.right, data);
    
        return root;
    }
    
    public static Node removeData(Node root, int data)
    {
        if (root == null)
            return null;  // never found data;
        
        if (data < root.data)
            root.left = removeData(root.left, data);
        else if(data > root.data)
            root.right = removeData(root.right, data);
        else{  // data found.
          
           if(root.left == null || root.right == null) 
           return root.left!=null?root.left:root.right;
           
           int maxInleft=maximumEle(root.left);
           root.data=maxInleft;
           root.left=removeData(root.left,maxInleft);
        
        }
        return root;
    }
    
    public static Node addDataItr(Node root, int data)
    {
        if(root==null) return new Node(data);
        Node curr = root;
        Node prev = null;
        while (curr != null)
        {
            prev = curr;
            if (data < curr.data)
                curr = curr.left;
            else
                curr = curr.right;
        }
    
        if(data < prev.data) prev.left=new Node(data);
        else prev.right=new Node(data);
        return root;
    }



//my method of addData iterative

    // public static void addNode(Node root,Node node){
                
    //     Node curr = root;
        
    //     while(node.data<curr.data && curr.left!=null){
    //         curr=curr.left;
    //     }
    //     while(node.data>curr.data && curr.right!=null){
    //         curr=curr.right;
    //     }
        
    //     if(node.data<curr.data) curr.left=node;
    //     else curr.right=node;

        
        
    // }    
    // //itrative
    // public static Node addData(Node root,int val){
    //     Node node = new Node(val);
    //     if(root==null) return node;

    //     addNode(root, node);
    //     return root;
    // }



    

    //bst end
    //======================================================================

    //K-Away in  a tree
    //easy method
    public static void kDown(Node node,Node avoid,int level){
        if(node==null ||node==avoid) return;
        if(level==0){
            System.out.println(node.data+" ");
            return;
        }
        kDown(node.left,avoid, level-1);
        kDown(node.right,avoid, level-1);
    }
    
    public static void kFar(Node node,int data,int k){
        ArrayList<Node> list = nodeToRootPath(node,data);
        Node avoid =null;
        for(int i=0; i<list.size();i++){
            kDown(list.get(i), avoid, k-i);
            avoid = list.get(i);
        }
    }
    
    //2. O(n) sol better
    
    public static int allNodeKAway_02_(Node root, int target, int K) {
        if(root==null) return -1;

        if(root.data == target){
           kDown(root,null,K);
           return 1;
        }

        int leftdistance=allNodeKAway_02_(root.left,target,K);
        if(leftdistance!=-1){
           if(K-leftdistance >= 0) kDown(root,root.left,K-leftdistance);
           return leftdistance+1;
        }
        
        int rightdistance=allNodeKAway_02_(root.right,target,K);
         if(rightdistance!=-1){
           if(K-rightdistance >= 0) kDown(root,root.right,K-rightdistance);
           return rightdistance+1;
       }

       return -1;
   
   }

    //3. 
    public static void kDown(Node root,int level){
        if(root==null) return;
 
        if(level==0){
          System.out.print(root.data + " ");
          return;  
        }
 
        kDown(root.left,level-1);
        kDown(root.right,level-1);
 
     }

    public static int allNodeKAway_03_(Node root, int target, int K) {
        if(root==null) return -1;

        if(root.data == target){
           kDown(root,K);
           return 1;
        }

        int leftdistance=allNodeKAway_03_(root.left,target,K);
        if(leftdistance!=-1){
           if(K-leftdistance == 0)  
              System.out.print(root.data + " ");
           else
              kDown(root.right,K-leftdistance-1);
           return leftdistance+1;
        }
        
        int rightdistance=allNodeKAway_03_(root.right,target,K);
        if(rightdistance!=-1){
            if(K-rightdistance == 0)
               System.out.print(root.data + " ");
            else
               kDown(root.left,K-rightdistance-1);
            return rightdistance+1;
         }

       return -1;
   
   }



    // view Set.==================================

    //2 que method
    public static void levelOrder_01(Node node){
        LinkedList<Node> pQue=new LinkedList<>(); // addLast and removeFirst.
        LinkedList<Node> cQue=new LinkedList<>(); // addLast and removeFirst.
    
        pQue.addLast(node);
        int count=0;
        System.out.print("Level: " + count + " -> ");
        
        while(pQue.size()!=0){
            Node rnode=pQue.removeFirst();
            System.out.print(rnode.data+ " ");
            if(rnode.left!=null) cQue.addLast(rnode.left);
            if(rnode.right!=null) cQue.addLast(rnode.right);
    
            if(pQue.size()==0){
              LinkedList<Node> temp=pQue;  //yaha bs naam chng hora h 
              pQue=cQue;
              cQue=temp;
              count++;      
             System.out.print("\nLevel: " + count + " -> ");
            }
        }
    }
    
    //delimiter method
    public static void levelOrder_02(Node node){
        LinkedList<Node> Que=new LinkedList<>(); // addLast and removeFirst.
    
        Que.addLast(node);
        Que.addLast(null);
        int count=0;
        System.out.print("Level: " + count + " -> ");
        
        while(Que.size()!=1){
            Node rnode=Que.removeFirst();
            System.out.print(rnode.data+ " ");
            if(rnode.left!=null) Que.addLast(rnode.left);
            if(rnode.right!=null) Que.addLast(rnode.right);
    
            if(Que.getFirst()==null){
                Que.removeFirst();
                Que.addLast(null);
                count++;      
                System.out.print("\nLevel: " + count + " -> ");
            }
        }
    }

    //best method
    public static void lineWiseLevelOrder(Node node) {
        LinkedList<Node> que = new LinkedList<>();
        que.addLast(node);

        int level = 0;
        while (que.size() != 0) {
            int size = que.size();
            System.out.print("Level: " + level + " -> ");

            while (size-- > 0) {
                Node rnode = que.removeFirst();
                System.out.print(rnode.data + ", ");
                if (rnode.left != null) que.addLast(rnode.left);
                if (rnode.right != null) que.addLast(rnode.right);
            }
            
            level++;
            System.out.println();
        }
        System.out.println();
    }

    public static void leftView(Node node) {
        LinkedList<Node> que = new LinkedList<>();
        que.addLast(node);

        while (que.size() != 0) {
            int size = que.size();
            System.out.print(que.getFirst().data + " ");
            while (size-- > 0) {
                Node rnode = que.removeFirst();

                if (rnode.left != null) {
                    que.addLast(rnode.left);
                }

                if (rnode.right != null) {
                    que.addLast(rnode.right);
                }
            }

        }
        System.out.println();
    }

    public static void rightView(Node node) {
        LinkedList<Node> que = new LinkedList<>();
        que.addLast(node);

        while (que.size() != 0) {
            int size = que.size();
            Node prev = null;
            while (size-- > 0) {
                Node rnode = que.removeFirst();
                prev = rnode;
                if (rnode.left != null) {
                    que.addLast(rnode.left);
                }

                if (rnode.right != null) {
                    que.addLast(rnode.right);
                }
            }

            System.out.print(prev.data + " ");

        }
        System.out.println();
    }


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
        int[] ans=new int[rightMaxValue - leftMinValue + 1];
    
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
    
        for(int e: ans)
           System.out.println(e);
        System.out.println();
    }

    public static void BottomView(Node node) {
        width(node,0);
        int[] ans=new int[rightMaxValue - leftMinValue + 1];
    
        LinkedList<pairVO> que=new LinkedList<>();
        que.addLast(new pairVO(node,-leftMinValue));
    
        while(que.size()!=0){
            // int size=que.size();
            // while(size--> 0){
                pairVO rpair=que.removeFirst();
                ans[rpair.vl] = rpair.node.data;
                if(rpair.node.left!=null) que.addLast(new pairVO(rpair.node.left, rpair.vl - 1));
                if(rpair.node.right!=null) que.addLast(new pairVO(rpair.node.right,rpair.vl + 1));    
            // }
        }
    
        for(int e: ans)
           System.out.print(e+" ");
        // System.out.println();
    }

    public static void topView(Node node){
        width(node,0);
        int []ans = new int[rightMaxValue-leftMinValue+1];
        Arrays.fill(ans, (int)1e8);

        LinkedList<pairVO> que = new LinkedList<>();
        que.addLast(new pairVO(node, -leftMinValue));

        while(que.size()!=0){
            pairVO rpair = que.removeFirst();
            if(ans[rpair.vl]==(int)1e8) ans[rpair.vl]=rpair.node.data;
            if(rpair.node.left!=null) que.addLast(new pairVO(rpair.node.left, rpair.vl - 1));
            if(rpair.node.right!=null) que.addLast(new pairVO(rpair.node.right,rpair.vl + 1));
        }
        for(int e:ans)
            System.out.print(e+" ");
    }


static int leftDMinValue=0;
public static void widthDiagonal(Node node,int lev){
    if(node==null) return;

    leftMinValue=Math.min(leftMinValue,lev);

    width(node.left, lev - 1);
    width(node.right, lev + 0);
} 


public static void diagonalOrder(Node node){
    widthDiagonal(node,0);
    int n= -leftDMinValue + 1;
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
            if(rpair.node.right!=null) que.addLast(new pairVO(rpair.node.right,rpair.vl + 0));    
        }
    }

    for(ArrayList<Integer> ar: ans)
       System.out.println(ar);
    System.out.println();
}

public static void diagonalSum(Node node){
    widthDiagonal(node,0);
    int n= -leftDMinValue + 1;
    int[] ans=new int[n];

    LinkedList<pairVO> que=new LinkedList<>();
    que.addLast(new pairVO(node,-leftMinValue));

    while(que.size()!=0){
        int size=que.size();
        while(size--> 0){
            pairVO rpair=que.removeFirst();
            ans[rpair.vl] += rpair.node.data;
            if(rpair.node.left!=null) que.addLast(new pairVO(rpair.node.left, rpair.vl - 1));
            if(rpair.node.right!=null) que.addLast(new pairVO(rpair.node.right,rpair.vl + 0));    
        }
    }

    for(int ele: ans)
       System.out.println(ele);
    System.out.println();
}

  
    public static class LLNode {
        int data = 0;
        LLNode next = null;
        LLNode prev = null;

        LLNode(int data) {
            this.data = data;
        }
    }

    static LLNode head = null;
    static LLNode tail = null;

    public static void verticalSum_03(Node node, LLNode lnode) { //doubly ll method

        lnode.data += node.data;
        if (node.left != null) {
            if (lnode.prev == null) {
                lnode.prev = new LLNode(0);
                lnode.prev.next = lnode;
                head = lnode.prev;
            }
            verticalSum_03(node.left, lnode.prev);
        }

        if (node.right != null) {
            if (lnode.next == null) {
                lnode.next = new LLNode(0);
                lnode.next.prev = lnode;
                tail = lnode.next;
            }
            verticalSum_03(node.right, lnode.next);
        }
    }

    // public static void verticalSum_03(Node node) {
    //     LLNode lnode = new LLNode(0);
    //     head = lnode;
    //     tail = lnode;

    //     verticalSum_03(node, lnode);

    //     LLNode root = head;
    //     while (curr != null) {
    //         System.out.print(curr.data + " ");
    //         curr = curr.next;
    //     }
    //     System.out.println();

    // } 


// traversalSet.==============================



//preorder: sd ld rd
//inorder: ld sd rd
//postorder: ld rd sd just change loops below and you get all 3 iterations

//rec stack has fixed size so this is betr

public static class tpair{  //traversalPair
    Node node=null;
    boolean selfDone=false;
    boolean leftDone=false;
    boolean rightDone=false;

    tpair(Node node,boolean selfDone,boolean leftDone,boolean rightdone){
        this.node=node;
        this.leftDone=leftDone;
        this.selfDone=selfDone; 
        this.rightDone=rightDone;
    }
}

public static void ItrTraversalOfTree(Node node){
    Stack<tpair> st=new Stack<>();
    st.push(new tpair(node,false,false,false));
    
    while(st.size()!=0){
        if(st.peek().selfDone==false){ //this is preorder as selfdone 1st
            st.peek().selfDone = true;
            System.out.print(st.peek().node.data+" ");
        }else if(st.peek().leftDone==false){
            st.peek().leftDone = true;
            if(st.peek().node.left!=null){
                st.push(new tpair(st.peek().node.left,false,false,false));
            }
        }else if(st.peek().rightDone==false){
            st.peek().rightDone = true;
            if(st.peek().node.right!=null){
                st.push(new tpair(st.peek().node.right,false,false,false));
            }
        }else {
            st.pop();
        }
    }
}

//height only in post order
public static class tpair_{  //traversalPair
    Node node=null;
    boolean selfDone=false;
    boolean leftDone=false;
    boolean rightDone=false;
    
    int ld = -1;
    int rd = -1;
    int sd = -1;
    boolean isleft=false;

    tpair_(Node node,boolean selfDone,boolean leftDone,boolean rightDone,boolean isleft){
        this.node=node;
        this.leftDone=leftDone;
        this.selfDone=selfDone; 
        this.rightDone=rightDone;
        this.isleft=isleft;
    }
}

public static void ItrHeightOfTree(Node node){
    Stack<tpair_> st=new Stack<>();
    st.push(new tpair_(node,false,false,false,false));
    
    tpair_ rpair=null;
    while(st.size()!=0){
        if(st.peek().leftDone==false){
            st.peek().leftDone = true;
            if(st.peek().node.left!=null){
                st.push(new tpair_(st.peek().node.left,false,false,false,true));
            }
        }else if(st.peek().rightDone==false){
            st.peek().rightDone = true;
            if(st.peek().node.right!=null){
                st.push(new tpair_(st.peek().node.right,false,false,false,false));
            }
        }else if(st.peek().selfDone==false){
            st.peek().selfDone = true;
            st.peek().sd=Math.max(st.peek().ld,st.peek().rd)+1;
        }else {
            rpair=st.pop();
            if(st.size()!=0){
                if(st.peek().isleft)
                    st.peek().ld=rpair.sd;
                else 
                   st.peek().rd=rpair.sd;
            }
        }
    }

    System.out.println(rpair.sd);
}


//Morris Traversal
public static Node rightMost_of_LeftNode(Node lnode,Node curr){
    while(lnode.right!=null && lnode.right!=curr){
        lnode=lnode.right;
    }
    return lnode;
}


public static void morrisInOrder(Node node){
    Node curr=node;
    while(curr!=null){
        if(curr.left==null){
            System.out.print(curr.data+" ");
            curr=curr.right;
        }else{
            Node leftNode=curr.left;
            Node rightMost=rightMost_of_LeftNode(leftNode,curr);
            if(rightMost.right==null){ // thread create
               rightMost.right=curr;
               curr=curr.left;
            }else{ // thread break
                rightMost.right=null;
                System.out.print(curr.data+" ");
                curr=curr.right;
            }
        }
    }
    System.out.println();
}

public static void morrisPreOrder(Node node){
    Node curr=node;
    while(curr!=null){
        if(curr.left==null){
            System.out.print(curr.data+" ");
            curr=curr.right;
        }else{
            Node leftNode=curr.left;
            Node rightMost=rightMost_of_LeftNode(leftNode,curr);
            if(rightMost.right==null){ // thread create
               rightMost.right=curr;
               System.out.print(curr.data+" ");
               curr=curr.left;
            }else{ // thread break
                rightMost.right=null;
                curr=curr.right;
            }
        }
    }
    System.out.println();
}


//bt/bst const when 2 iterations are given like pre,inorder    

// psi = preStartIndex, pei=preEndIndex, isi=inStartIndex, iei=inEndIndex
public static Node ConstructFromPreAndIn(int[] pre,int psi,int pei,int[] in,int isi,int iei){
    if(psi>pei || isi>iei) return null;

    Node node=new Node(pre[psi]);
    
    int idx=isi;
    while(in[idx]!=pre[psi]){
      idx++;
    }
    int tnel=idx-isi;  // total no of elements between isi and idx

    node.left=ConstructFromPreAndIn(pre,psi+1,psi+tnel,in,isi,idx-1);
    node.right=ConstructFromPreAndIn(pre,psi+tnel+1,pei,in,idx+1,iei);
    
    return  node;
  }

public static Node ConstructFromPreAndIn(int[] pre, int[] in) {
    return ConstructFromPreAndIn(pre,0,pre.length-1,in,0,in.length-1);
}


// psi = postStartIndex, pei=postEndIndex, isi=inStartIndex, iei=inEndIndex
public static Node ConstructFromPostAndIn(int[] post,int psi,int pei,int[] in,int isi,int iei){
    if(psi>pei || isi>iei) return null;

    Node node=new Node(pre[pei]);
    
    int idx=isi;
    while(in[idx]!=pre[psi]){
      idx++;
    }
    int tnel=idx-isi;  // total no of elements between isi and idx

    node.left=ConstructFromPostAndIn(post,psi,psi+tnel-1,in,isi,idx-1);
    node.right=ConstructFromPostAndIn(post,psi+tnel,pei-1,in,idx+1,iei);
    
    return  node;
}

public static Node ConstructFromPostAndIn(int[] post, int[] in) {
    return ConstructFromPostAndIn(post,0,post.length-1,in,0,in.length-1);
}

// psi = preStartIndex, pei=preEndIndex, ppsi=postStartIndex, ppei=postEndIndex
public static Node ConstructFromPreAndPost(int[] post,int psi,int pei,int[] in,int ppsi,int ppei){
    if(psi>pei || ppsi>ppei) return null;

    Node node=new Node(pre[psi]);
        
    int idx=ppsi;
    while(post[idx]!=pre[psi+1]){
        idx++;
    }
    
    int tnel=idx-isi+1;  // total no of elements between isi and idx

    node.left=ConstructFromPreAndPost(post,psi+1,psi+tnel,in,ppsi,idx);
    node.right=ConstructFromPreAndPost(post,psi+tnel+1,pei,in,idx+1,iei-1);
        
    return  node;
}

public static Node ConstructFromPreAndPost(int[] pre, int[] post) {
    return ConstructFromPreAndPost(pre,0,pre.length-1,post,0,post.length-1);
}

     
    
    public static void viewSet(Node node) {
        lineWiseLevelOrder(node);
        // leftView(node);
        // rightView(node);
        // topView(node);

    }

    public static void BST(){
        int []arr = {10,20,30,40,50,60,70,80,90,100,110}; //sorted array required
        Node root = createBST(arr, 0, arr.length-1);
        display(root);
        System.out.println();
        root = addData(root, 120);

        display(root);

        // System.out.println(maxEle(root).data);
        // System.out.println(minEle(root).data); 

        // System.out.println(LCAofBST(root, 70, 100)); 
    
        // int []arr = {50,17,9,14,12,23,19,76,54,72,67}; //sorted array required
        // Node root = constructBST(arr);
        // display(root);
    }

    public static void set1(){
        int []arr ={10,20,40,60,-1,-1,70,-1,-1,50,80,
           -1,-1,-1,30,90,-1,110,150,-1,-1,-1,100,120,-1,-1,-1};
        Node node = createTree(arr);
        // ArrayList<Node>path=new ArrayList<>();
        // nodeToRootPath_(node, 80, path);
        // for(Node n:path){
        //     System.out.println(n.data);
        // }
        // LCA_02(node, 50, 80);
        // System.out.println(LCAnode.data);
            
           // kFar(node,10,2);
            
            // allNodeKAway_02(node, 10, 2);
        
            //verticalOrder(node);
            BottomView(node);
            topView(node);
        //display(node);
    }

    public static void main(String[] args) {
        //set1();
        BST();
    //   System.out.println(LCA_01(node, 60, 80).data);
        //int d=diameter_03(node);
        //System.out.println(maxDia);
        //System.out.println(diameter_01(node));
    //     //System.out.println(findData(node,200)) ;
    //     //System.out.println(leaftoLeafMaxSum(node));
    //     //System.out.println(maxSum);

    //int [] arr = {2,6,10,25,36,37,39,40,52,68,72};
    // int [] arr = {3,7,9,15,20};
    // Node node = createBST(arr, 0, arr.length-1);
    //  display(node);
    //  System.out.println(isBST(node));
    // //System.out.println(findData(node, 16));
    // pair p = new pair();
    // allSolution(node, 0, 39, p);
    // System.out.println(p.pred.data);
    // System.out.println(p.succ.data);
    // System.out.println(p.prev.data);
    // viewSet(node);


    }
}