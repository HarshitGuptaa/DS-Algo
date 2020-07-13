public class client{
    public static void main(String[] args){
        solve();
    }
    public static void solve(){
        myStack obj1 = new myStack(); 
        for(int i=0;i<obj1.st.length;i++){
            obj1.push(i+10);
        }
        obj1.print();
    }

  

}