import java.util.Scanner;

public class isPrime {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter number: ");
        int n = scn.nextInt();
        boolean p = Prime(n);
        System.out.println(p);
    }

    public static boolean Prime(int n){
        int len=0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                len++;
            }
        }
        if(len>2){
            return false;
        }else{
            return true;
            
        }
    }
}