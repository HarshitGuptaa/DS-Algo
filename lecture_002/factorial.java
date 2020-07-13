// import java.util.Scanner;

// public class factorial{
//     public static Scanner scn = new Scanner(System.in);
//     public static void main(String[] args){
//         System.out.println("Enter number for factorial: ");
//         int n = scn.nextInt();
//         System.out.println("factorial: ");
//         System.out.println(facto(n));
//     }



// public static int facto(int n){
//     int ans =1;
//     for(int i=1;i<=n;i++){
//         ans*=i;
//     }
//     return ans;
// }

// }

//AT HOME

import java.util.Scanner;

public class factorial{
    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args){
        System.out.println("Enter number for factorial..");
        int n= scn.nextInt();
        facto(n);
    }

    public static int facto(int n) {
        int fact = 1;
        for(int i=1;i<=n;i++){
            fact*=i;
        }
        System.out.println("factorial is : " + fact);
        
        return 0 ;
    }
}