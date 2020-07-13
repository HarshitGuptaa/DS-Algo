import java.util.*;

public class test{
    public static void HashmapOperation(String str){  //char -> indexes
        HashMap<Character,ArrayList<Integer>> map = new HashMap<>();

        for(int i=0;i<str.length();i++){
            char ch = str.charAt(i);
            
            if(!map.containsKey(ch)){
                map.put(ch,new ArrayList<>());
            } 
            map.get(ch).add(i);
        }

        System.out.println(map);

    }


    public static void HashmapOperation2(){
        HashMap<String,Integer> map = new HashMap<>();
        map.put("India", 100);
        map.put("Pak", -100);
        map.put("USA", 80);
        map.put("Italy", 75);

        System.out.println(map);
    }

    public static void HashmapOperation3(String str){   //freq map
        HashMap<Character,Integer> map = new HashMap<>();

        for(int i=0;i<str.length();i++){
            char ch = str.charAt(i);
            
           // if(!map.containsKey(ch)) map.put(ch,0);
           // map.put(ch,map.get(ch)+1);
            map.put(ch,map.getOrDefault(ch, 0)+1);
        }
        System.out.println(map);
    }

    //longest sequence
    public static void LongestSequence(int [] arr){
        HashMap<Integer,Boolean>map = new HashMap<>();
       
        int size=-1;
        int number=-1;
        
        for(int ele:arr){
            map.put(ele,true);
        }

        for(int ele:map.keySet()){
            if(map.containsKey(ele-1)){
                map.put(ele,false);
            }
        }

        for(int keys:map.keySet()){
            if(map.get(keys)){
                int num=keys+1;
                int smallsize=1;
                while(map.containsKey(num)){
                    num++;
                    smallsize++;
                }

                if(smallsize>size){
                    size = smallsize;
                    number = keys;
                }
            }
        }

        for(int i=0;i<size;i++){
            System.out.print(number+i +" ");
        }
    }


    public static void main(String[] args) {
       
        //HashmapOperation("aanbdd");
        //HashmapOperation2();
        //HashmapOperation3("abbcccdddd");
        int[]arr = {1,2,3,4,5,18,19,20,17,16,15};
        LongestSequence(arr);
    }



}