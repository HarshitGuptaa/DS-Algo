import java.util.Stack;

public class histogramMaxArea{

    public static void main(String[] args){
        //int [] height = {6,2,5,4,5,1,6};
        //System.out.println(largestArea(height));
        
        int [] [] arr = {{1,0,1,0,0},
                        {1,0,1,1,1},
                        {1,0,1,1,1},
                        {1,0,1,0,1}};
                        
        System.out.println(maxAreaInMatrix(arr));
    }



    public static int largestArea(int[] height) {
    int maxArea = 0;
    int n=height.length;

    Stack<Integer> st = new Stack<>();
    st.push(-1);     //  -1 lgane se hm left side reference ke bhi access kr paate hai,vrna ni ho skte

    for (int i = 0; i < n; i++) {
        while(st.peek()!=-1 && height[st.peek()] >= height[i]){  //resolve for this   = lgane se optimize hota hai sath sath resolve hote hai

            int ht = height[st.pop()];
            int width = i - st.peek() - 1 ;
            int area = ht*width;
            maxArea = (int) Math.max(area,maxArea);
        }
        st.push(i);
    }

    while(st.peek()!=-1 ){  //leftover elts are resolved 
        int ht = height[st.pop()];
        int width = n - st.peek() - 1 ;
        int area = ht*width;
        maxArea = (int) Math.max(area,maxArea);
    }
    return maxArea;
}

//chota ele aye to vo hmari right boundary hai and piche tak area resolve krae aao left boundary tak
//resolve krate time hm pop krte h apni left bounday tak pohch jaate h uss ele se choti hai jo
//and inke beech jo ele the vo bde rhe honge tabhi chota aane pe pop hogye the 

//bda hai ele to vo right boundary ni h to bs push krado

public static int maxAreaInMatrix(int [][] arr) {
    if(arr.length==0) return 0;
    int [] ar = new int[arr[0].length];
    int max_=0;
    for(int i=0;i<arr.length;i++){
        for(int j=0;j<arr[0].length;j++){
            ar[j] = (arr[i][j] == 0)? 0 : arr[i][j]+1;

        }
        max_= Math.max(max_,largestArea(ar));
    }
    return max_;
}

}