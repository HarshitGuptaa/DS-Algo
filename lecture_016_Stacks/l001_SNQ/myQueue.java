public class myQueue{
    private int [] arr;
    private int size=0;
    private int st=0;
    private int end=0;

    myQueue(){
        this.arr = new int[10];
    }

    myQueue(int size){
        this.arr = new int[size];
    }

    public void push(int data){
        if(this.size==arr.length){
            System.out.println("Queue is full");
            return;
        }
        this.arr[this.end]=data;
        this.end = (this.end+1)%arr.length;
        this.size++;
    }

    public int pop(){
        if(this.size==0){
            System.out.println("Queue is empty");
            return -1;
        }
        int rv=this.arr[st];
        this.size--;
        this.st = (this.st+1)%arr.length;
        return rv;
    }

    public boolean isEmpty(){
        return this.size==0;
    } 

    public int size(){
        return this.size;
    }
    public int top(){
        return idx;
    }
    public void print(){
        for(int i=0;i<arr.length;i++){
            int idx = (this.st+i)%arr.length;
            System.out.print(arr[idx]+" ");
        }
    }
    public int front(){
        if(this.size==0){
            System.out.println("Queue is empty");
            return -1;
        }
        return this.arr[st];
    }
}