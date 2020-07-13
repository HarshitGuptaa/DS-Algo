import java.util.*;
class Questions{
    public class TreeNode {
            int val;
            TreeNode left;
            TreeNode right;
            TreeNode(int x) { val = x; }
        }

    //leet 863
    public ArrayList<TreeNode> nodeToRootPath(TreeNode root,int data){
        if(root==null) return new ArrayList<>();
        
        if(root.val==data){
            ArrayList<TreeNode>base = new ArrayList<>();
            base.add(root);
            return base;
        }

        ArrayList<TreeNode> left = nodeToRootPath(root.left, data);
        if(left.size()!=0){
            left.add(root);
            return left;
        }
        ArrayList<TreeNode> right = nodeToRootPath(root.right, data);
        if(right.size()!=0){
            right.add(root);
            return right;
        }
        return new ArrayList<>();
    }
    
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        List<Integer> res = kFar(root,target.val,K);
        return res;
    }
    
    public List<Integer> kFar(TreeNode root,int target,int k){
        ArrayList<TreeNode> li = nodeToRootPath(root,target);
        List<Integer> ans = new ArrayList<>();
        TreeNode avoid = null;
        for(int i=0;i<li.size();i++){
            kDown(li.get(i),k-i,avoid,ans);
            avoid=li.get(i);
        }
        return ans;
    }
    
    public void kDown(TreeNode root,int k,TreeNode avoid,List<Integer> ans){
        if(root==null || root==avoid) return;
        if(k==0){
            ans.add(root.val);
        }
        kDown(root.left,k-1,avoid,ans);
        kDown(root.right,k-1,avoid,ans);
    }

    //2. O(n) sol
    //3. 
    //both sol in main file


    //leet 112: path sum-1

    public boolean hasPathSum(TreeNode root, int sum) {
        if(root==null) return false;    
        
        if(root.left==null && root.right==null && sum-root.val==0) return true;
        
        boolean res = false;
        res = res || hasPathSum(root.left,sum-root.val);
        res = res || hasPathSum(root.right,sum-root.val);
        return res;
        
    }

    //leet 113: path sum-2
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> smallAns = new ArrayList<>();
        PathSum(root,sum,res,smallAns);
        return res;
    }
    
    public void PathSum(TreeNode root, int sum,List<List<Integer>>res,List<Integer>smallAns) {
        
        if(root==null) return;    
        
        if(root.left==null && root.right==null && sum-root.val==0){
            List<Integer>base = new ArrayList<>(smallAns); //deep copy- 2 AL bann jaengi with same data
            base.add(root.val);               //agar shallow copy hui hoti to dono mai changes reflect hote which we dont want
            res.add(base);
        }
        smallAns.add(root.val);
        PathSum(root.left,sum-root.val,res,smallAns);
        PathSum(root.right,sum-root.val,res,smallAns);
        smallAns.remove(smallAns.size()-1);       
    }

    //leaf to leaf max sum
    //https://practice.geeksforgeeks.org/problems/maximum-path-sum/1
        static int maxSum;
        public static int maxPathSum(Node root) {
            // your code here
            maxSum = (int)-1e8;
            leaftoLeafMaxSum_02(root);
            return maxSum;
        }
        public static int leaftoLeafMaxSum_02(Node node){
            if(node==null) return 0;
            if(node.left==null && node.right==null) return node.data;
    
            int leftnodeToLeafSum = leaftoLeafMaxSum_02(node.left);
            int rightnodeToLeafSum = leaftoLeafMaxSum_02(node.right);
    
            if(node.left!=null && node.right!=null){
                maxSum = Math.max(maxSum,leftnodeToLeafSum+rightnodeToLeafSum+node.data);
                return Math.max(leftnodeToLeafSum,rightnodeToLeafSum)+node.data;
            }
            return (node.left==null?rightnodeToLeafSum:leftnodeToLeafSum) + node.data;
        }
    }
    
//leet 124: node to node max sum
int maxSum = (int)-1e8;
    
public int maxPathSum(TreeNode node){
    maxPathSum_(node);
    return maxSum;
}

public int maxPathSum_(TreeNode node) {
    if (node == null) return (int)-1e8;
    
    int leftsum = maxPathSum_(node.left);
    int rightsum = maxPathSum_(node.right);
    
    int sideMax = Math.max(leftsum, rightsum) + node.val;
    maxSum = Math.max(Math.max(maxSum, sideMax), Math.max(leftsum + rightsum +              node.val, node.val));

    return Math.max(sideMax, node.val);
}

    //Leetcode 987.====================================================


    static int leftMinValue=0;
    static int rightMaxValue=0;
    
    public static void width(TreeNode node,int lev){
        if(node==null) return;
    
        leftMinValue=Math.min(leftMinValue,lev);
        rightMaxValue=Math.max(rightMaxValue,lev);
        
        width(node.left, lev - 1);
        width(node.right, lev + 1);
    } 
    
    public static class pairVO implements Comparable<pairVO>{
        TreeNode node;  //actual Node
        int vl=0;  // vertical Level
        public pairVO(TreeNode node,int vl){
            this.node=node;
            this.vl=vl;
        }
    
        @Override
        public int compareTo(pairVO o){  // for c++: bool opeartor < ( pairvo const & o) const{
           if(this.vl==o.vl) return this.node.val-o.node.val; // in c++: replace '-' with '>'
           return this.vl-o.vl;  // default behaviour of que // in c++: replace '-' with '>'
        }
    }
    
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>> ans=new ArrayList<>();
        if(root==null) return ans;
    
        width(root,0);
        int n=rightMaxValue - leftMinValue + 1;
        for(int i=0;i<n;i++)
            ans.add(new ArrayList<>());
    
        PriorityQueue<pairVO> pque=new PriorityQueue<>();
        PriorityQueue<pairVO> cque=new PriorityQueue<>();
    
        pque.add(new pairVO(root,-leftMinValue));
    
        while(pque.size()!=0){
            int size=pque.size();
            while(size--> 0){
                pairVO rpair=pque.poll();
                ans.get(rpair.vl).add(rpair.node.val);
    
                if(rpair.node.left!=null) cque.add(new pairVO(rpair.node.left,rpair.vl-1));
                if(rpair.node.right!=null) cque.add(new pairVO(rpair.node.right,rpair.vl+1));
            }
    
            PriorityQueue<pairVO> temp=pque;
            pque=cque;
            cque=temp;
        }
        //jo empty hai vo list na print krwana
        for(int i=n-1;i>=0;i--){
            if(ans.get(i).size()==0)
                ans.remove(i);
        }
        return ans;
    }

//leet 173.============================================================
class BSTIterator {
    Stack < TreeNode > st;

    public BSTIterator(TreeNode root) {
        st = new Stack <>();
        pushAll_Left_Of_Right(root);
    }

    public void pushAll_Left_Of_Right(TreeNode node) {
        while (node != null) {
            st.push(node);
            node = node.left;
        }
    }

    public int next() {
        TreeNode rn = st.pop();
        pushAll_Left_Of_Right(rn.right);
        return rn.val;
    }

    public boolean hasNext() {
        return st.size() != 0;
    }
}

//Leetcode 105: construct-binary-tree-from-preorder-and-inorder-traversal.========================

    // psi = preStartIndex, pei=preEndIndex, isi=inStartIndex, iei=inEndIndex
    public TreeNode ConstructFromPreAndIn(int[] pre, int psi, int pei, int[] in , int isi, int iei) {
        if (psi > pei || isi > iei) return null;

        TreeNode node = new TreeNode(pre[psi]);

        int idx = isi;
        while ( in [idx] != pre[psi]) {
            idx++;
        }
        int tnel = idx - isi; // total no of elements between isi and idx

        node.left = ConstructFromPreAndIn(pre, psi + 1, psi + tnel, in , isi, idx - 1);
        node.right = ConstructFromPreAndIn(pre, psi + tnel + 1, pei, in , idx + 1, iei);

        return node;
    }

    public TreeNode buildTree(int[] pre, int[] in ) {
        return ConstructFromPreAndIn(pre, 0, pre.length - 1, in , 0, in .length - 1);
    }

    //Leetcode 106 : construct-binary-tree-from-inorder-and-postorder-traversal.
    // psi = postStartIndex, pei=postEndIndex, isi=inStartIndex, iei=inEndIndex
    public TreeNode ConstructFromPostAndIn(int[] post, int psi, int pei, int[] in , int isi, int iei) {
        if (psi > pei || isi > iei) return null;

        TreeNode node = new TreeNode(post[pei]);

        int idx = isi;
        while ( in [idx] != post[pei]) {
            idx++;
        }
        int tnel = idx - isi; // total no of elements between isi and idx

        node.left = ConstructFromPostAndIn(post, psi, psi + tnel - 1, in , isi, idx - 1);
        node.right = ConstructFromPostAndIn(post, psi + tnel, pei - 1, in , idx + 1, iei);

        return node;
    }

    public TreeNode buildTree(int[] in , int[] post) {
        return ConstructFromPostAndIn(post, 0, post.length - 1, in , 0, in .length - 1);
    }

    // Leetcode 889: construct-binary-tree-from-preorder-and-postorder-traversal
    // psi = preStartIndex, pei=preEndIndex, ppsi=postStartIndex, ppei=postEndIndex
    public TreeNode ConstructFromPreAndPost(int[] pre, int psi, int pei, int[] post, int ppsi, int ppei) {
        if (psi > pei || ppsi > ppei) return null;

        if (ppsi == ppei) {
            return new TreeNode(post[ppsi]);
        }

        TreeNode node = new TreeNode(pre[psi]);

        int idx = ppsi;
        while (post[idx] != pre[psi + 1]) {
            idx++;
        }

        int tnel = idx - ppsi + 1; // total no of elements between isi and idx

        node.left = ConstructFromPreAndPost(pre, psi + 1, psi + tnel, post, ppsi, idx);
        node.right = ConstructFromPreAndPost(pre, psi + tnel + 1, pei, post, idx + 1, ppei - 1);

        return node;
    }

    public TreeNode constructFromPrePost(int[] pre, int[] post) {
        return ConstructFromPreAndPost(pre, 0, pre.length - 1, post, 0, post.length - 1);
    }







}


