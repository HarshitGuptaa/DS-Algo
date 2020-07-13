public class myStack{
    private int  idx=-1;
    protected int [] st;

    myStack(){
        this.st = new int[10];
    }

    myStack(int size){
        this.st = new int[size];
    }

    public void push(int data){
        if(idx==st.length){
            System.out.println("StackOverflow");
            return;
        }
        idx++;
        this.st[idx]=data;
    }

    public int pop(){
        if(idx==-1){
            System.out.println("StackUnderflow");
            return -1;
        }
        int rv = this.st[idx];
        this.st[idx]=0;
        idx--;
        return rv;
    }

    public boolean isEmpty(){
        if(this.idx==-1){
            return true;
        }
        return false;
    } 

    public int size(){
        return idx+1;
    }
    public int top(){
        return st[idx];
    }
    public void print(){
        System.out.print("[");
        for(int i=idx;i>0;i--){
            System.out.print(st[i]+", ");
        }
        System.out.print(st[0]+"]");
    }
}