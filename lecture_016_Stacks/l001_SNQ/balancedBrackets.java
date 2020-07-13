import java.util.Stack;

public class balancedBrackets{
    public static void main(String[] args){
        System.out.println(balbra("{[(((())"));
    }

    public static boolean balbra(String str){
        Stack<Character> st = new Stack<>();

        for(int i = 0;i<str.length();i++){
            char ch = str.charAt(i);


            if(ch=='(' || ch=='[' || ch=='{'){
                st.push(ch);
            }
            else if(ch==')' || ch=='}' || ch==']'){
                if(st.size()==0){
                    return false;
                }

                if(ch==')' && st.peek()=='('){
                    st.pop();
                }
                else if(ch=='}' && st.peek()=='{'){
                    st.pop();
                }
                else if(ch==']' && st.peek()=='['){
                    st.pop();
                }else{
                    return false;
                }
            }

        }
        return st.size()==0;
    }
}