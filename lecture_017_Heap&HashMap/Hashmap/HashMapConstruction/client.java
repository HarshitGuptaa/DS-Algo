
public class client{
    public static void main(String[] args) {
        //myHashMap map = new myHashMap();
        myHashMap<Integer,Integer> map = new myHashMap<>();
        map.put(1,101);
        map.put(2,102);
        map.put(3,103);
        map.put(4,104);
        for(Integer ele:map.keySet()){
            System.out.println(ele);
        }
    }
}