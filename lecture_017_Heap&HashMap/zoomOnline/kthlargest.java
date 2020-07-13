import java.util.*;
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int n=nums.length;
        for(int i=0;i<n;i++){
            pq.add(nums[i]);
        }
        for(int i=0;i<k;i++){
            int ans = pq.peek();
            pq.remove();
        }
        return ans;
    }

   
    public class pair{
        int ele,i,j;
        pair(int ele,int i,int j){
            this.ele=ele;
            this.i=i;
            this.j=j;
        }
    }
    
    
    
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<pair> pq = new PriorityQueue<>((pair a,pair b)->{
            return a.ele - b.ele;  //min PQ
            //return b.ele - a.ele   max PQ
        });
        
        int n= matrix.length;
        int m=matrix[0].length;
        
        for(int i=0;i<n;i++){
            pq.add(new pair(matrix[i][0],i,0));  //1st col entered
        }
        
        while(--k>0){
            pair p = pq.poll();
            int x=p.i;
            int y=p.j;
            
            if(++y>m) pq.add(new pair(matrix[x][y],x,y));
        }
        return pq.poll().ele;
    }
}