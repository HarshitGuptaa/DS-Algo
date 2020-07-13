import java.util.Scanner;
public class b1tob2{
    public static Scanner scn=new Scanner(System.in);
    
    
    public static void main(String[] args) {
        System.out.println("Enter number..");
        int num=scn.nextInt();
        System.out.println("Enter b1..");
        int b1=scn.nextInt();
        System.out.println("Enter b2..");
        int b2=scn.nextInt();
        int ans=b1toD(num,b1);
        Dtob2(ans,b2);
    }
    
    
    public static int b1toD(int num,int b1) {
        int res=0,pow=1;
        while(num!=0){
            int rem=num%10;
            res=rem*pow+res;
            pow*=b1;
            num/=10;
        }
        System.out.println("In decimal: "+res);
        return res;
    }

    
    public static void Dtob2(int num,int b2) {
        int res=0,pow=1;
        while(num!=0){
            int rem=num%b2;
            res=rem*pow+res;
            pow*=10;
            num/=b2;
        }
        System.out.println("In b2: "+res);      
    }

}