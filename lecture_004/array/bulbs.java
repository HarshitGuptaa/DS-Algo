
//this is by n^2 complexity, do by root n
import java.util.Scanner;
public class bulbs{
    public static Scanner scn=new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("Enter size of array");
        int n=scn.nextInt();
        int[]arr=new int[n];
        initialize(arr);
        on_off(arr);
     
    }
    public static void initialize(int[] arr) {
        for(int i=0;i<arr.length;i++){
            arr[i]=0;
        }
    }       
    public static void on_off(int[] arr){
        for(int pos=1;pos<=arr.length;pos++){
        for(int i=0;i<arr.length;i++){
            if((i+1)%pos==0){
                if(arr[i]==0){
                    arr[i]=1;
                }else{
                    arr[i]=0;
                }
            }
        }
    }
        System.out.println("Bulbs on are..");
        for(int i=1;i<arr.length;i++){
            if(arr[i]==1){
                int j=i+1;
                System.out.println("bulb: "+j);
            }
        }
    }


}