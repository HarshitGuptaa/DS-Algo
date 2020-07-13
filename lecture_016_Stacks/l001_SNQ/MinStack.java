import java.util.Stack;

public class MinStack{
    Stack<Integer> st = new Stack<>();
    int minsf = 0; 
    MinStack(){

    }

    public void push(int val){
        
        if(st.size()==0){
            st.push(val);
            minsf=val;
        }

        else if(val<minsf){
            st.push(2*val-minsf);
            minsf=val;
        }else{
            st.push(val);
        }
    }

    public int pop(){
        if(st.size()==0){
            return -1;
        }
        if(st.peek()<minsf){
            int actualValue = minsf;
            int recoveredminsf = 2*minsf - st.pop();
            minsf = recoveredminsf;
            return actualValue;
        }
        return st.pop();
    }

    public int top(){
        if(st.size()==0){
            return -1;
        }
        if(st.peek()<minsf){
            return minsf;
        }
        return st.peek();
    }

    public int getMin(){
        if(st.size()==0){
            return -1;
        }
        return minsf;
    }
}