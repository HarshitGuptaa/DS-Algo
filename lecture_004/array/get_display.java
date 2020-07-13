import java.util.Scanner;
public class get_display{
    public static Scanner scn=new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("Enter size of array");
        int n=scn.nextInt();
        int[]arr=new int[n];
        get(arr);
        display(arr);
    }
    public static void get(int[] arr) {
        System.out.println("Enter data..");
        for(int i=0;i<arr.length;i++){
            arr[i]=scn.nextInt();
        }
    }       
    public static void display(int[] arr) {
        System.out.println("Inserted array is..");
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
    }
}