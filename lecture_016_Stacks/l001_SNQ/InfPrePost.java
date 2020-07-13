import java.util.Stack;
import java.util.LinkedList;

//Infix Evaluation
public class InfPrePost{
    public static void main(String[] args) {
        System.out.println(infixEval("8+4*3-9/3^(2-1)"));
        System.out.println(infixToPostfix("8+4*3-9/3^(2-1)"));
    }

    public static boolean isOperator(char ch) {
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' ) return true;
        return false;
    }

    public static int priority(char ch) {
        if(ch=='+' || ch=='-') return 0;
        if(ch=='*' || ch=='/') return 1;
        if(ch=='^') return 2;

        return -1;
    }

    public static int performOperation(int val1,int val2,char ch) {
        if(ch=='+'){
            return val2+val1;
        }
        else if(ch=='-'){
            return val2-val1;
        }
        else if(ch=='*'){
            return val2*val1;
        }
        else if(ch=='/'){
            return val2/val1;
        }
        else if(ch=='^'){
            return (int) Math.pow(val2, val1);
        }
        return 0;
    }

    private static int infixEval(String str) {
        Stack<Integer> numSt = new Stack<>();
        Stack<Character> opSt = new Stack<>();

        for(int i=0;i<str.length();i++){
            char ch = str.charAt(i);

            if(ch>='0' && ch<='9'){        //a no. comes
                numSt.push(ch-'0');
            }

            else if(ch=='(') opSt.push(ch);    //opening bracket comes

            else if(isOperator(ch)){         //an opertator comes  
                while(opSt.size()!=0 && opSt.peek() != '(' && priority(opSt.peek()) > priority(ch)){
                    int val1= numSt.pop();
                    int val2= numSt.pop();
                    char c= opSt.pop();
                    int ans = performOperation(val1, val2, c);
                    numSt.push(ans);
                }
                opSt.push(ch);
            }else{       // closed bracket has come
                while(opSt.peek()!='('){
                    int val1= numSt.pop();
                    int val2= numSt.pop();
                    char c= opSt.pop();
                    int ans = performOperation(val1, val2, c);
                    numSt.push(ans);
                }
                opSt.pop();
            }
        }

            while(opSt.size()!=0){
                int val1= numSt.pop();
                int val2= numSt.pop();
                char c= opSt.pop();
                int ans = performOperation(val1, val2, c);
                numSt.push(ans);
            }
        
        return numSt.pop();
    }


    public static String infixToPostfix(String str){
        Stack<String> numSt = new Stack<>();
        Stack<Character> opSt = new Stack<>();
        for(int i=0;i<str.length();i++){
            char ch = str.charAt(i);

            if(ch>='0' && ch<='9'){
                numSt.push(Character.toString(ch));
            }else if(ch=='('){
                opSt.push(ch);
            }else if(isOperator(ch)){
                while(opSt.size()!=0 && opSt.peek()!='(' && priority(opSt.peek())>priority(ch)){
                    String val1 = numSt.pop();
                    String val2 = numSt.pop();
                    char c = opSt.pop();

                    String ans = val2 + val1 + c;
                    numSt.push(ans); 
                }
                opSt.push(ch);
            }else{
                while(opSt.peek()!='('){
                    String val1 = numSt.pop();
                    String val2 = numSt.pop();
                    char c = opSt.pop();

                    String ans = val2 + val1 + c;
                    numSt.push(ans);
                }
                opSt.pop();
            }
        }
        while(opSt.size()!=0){
            String val1 = numSt.pop();
            String val2 = numSt.pop();
            char c = opSt.pop();

            String ans = val2 + val1 + c;
            numSt.push(ans);
        }
        return numSt.pop();
    }
}