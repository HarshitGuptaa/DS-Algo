import java.util.Stack;
class histoMaxArea{

    

    public static void main(String[] args) {
        int [] height = {6,2,5,4,5,1,6};
         
        System.out.print(largestArea(height));
    }

    public static int largestArea(int[] height) {
        int maxArea = 0;
        Stack<Integer> st = new Stack<>();
        st.push(-1);

        for(int i=0;i<height.length;i++){
            
            while(st.peek()!=-1 && st.peek()>height[i]){
                int ht = height[st.pop()];
                int width = i - st.peek() -1;
                int area = ht*width;
                maxArea = (int) Math.max(area, maxArea);
            }

            st.push(i);
        }

        while(st.peek()!=-1){
            int ht = height[st.pop()];
            int width = i - st.peek() -1;
            int area = ht*width;
            maxArea = (int) Math.max(area, maxArea);
        }
        
        
        
        return maxArea;
    }

}