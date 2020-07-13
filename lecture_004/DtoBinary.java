import java.util.Scanner;
public class DtoBinary{
    public static Scanner scn=new Scanner(System.in);
    public static void main(String[] args) {
        System.out.println("Enter number");
        int n=scn.nextInt();
        int b= DtoB(n);
        BtoD(b);
    }
    public static int DtoB(int n){
        int res=0,pow=1;
        while(n!=0){
            int rem=n%2;
            n=n/2;
            res=(rem*pow)+res;
            pow*=10;
        }
        System.out.println(res);
        return res;
    }

    public static void BtoD(int b) {
        int mul=1;
        int dig=0;
        while(b!=0){

        dig += b%10 * mul;
        mul*=2;
        b/=10;
        }
        System.out.println(dig);

    }
}