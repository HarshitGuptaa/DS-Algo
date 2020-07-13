// import java.util.Scanner;

// public class rotateNumber {
//     public static Scanner scn = new Scanner(System.in);

//     public static void main(String[] args) {
//         System.out.println("Enter : ");
//         int n = scn.nextInt();
//         int r = scn.nextInt();
//         System.out.println(rotate(n, r));

//     }

//     public static int digit(int n) {
//         int len = 0;
//         while (n != 0) {
//             len++;
//             n = n / 10;
//         }

//         return len;
//     }

//     public static int rotate(int n, int r) {
//         int d = digit(n);
//         r %= 10;
//         r = (r < 0) ? (r + d) : r;
//         int mul = 1;
//         int divd = 1;
//         for (int i = 1; i <= d; i++) {
//             if (i <= r) {
//                 mul *= 10;
//             } else {
//                 divd *= 10;
//             }
//         }
//         int fdigits = n % divd;
//         int sdigits = n / divd;

//         return ((fdigits * mul) + sdigits);
//     }
// }

//AT HOME

import java.util.Scanner;

public class rotateNumber {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter number to rotate..");
        int num = scn.nextInt();
        System.out.println("Rotate by how much..?");
        int r = scn.nextInt();
        System.out.println("Rotated number is..");
        int rotated=rotate(num, r);
        System.out.println(rotated);

    }

    public static int digits(int n) {
        int dig = 0;
        while (n != 0) {
            dig++;
            n /= 10;
        }
        return dig;
    }

    public static int rotate(int n, int r) {
        int digit = digits(n);
        r %=digit;
        r = (r < 0) ? (r + digit) : r;
        int mul = 1;
        int divd = 1;
        for (int i = 1; i <= digit; i++) {
            if (i <= r) {
                mul *= 10;
            }
            else {
                divd *= 10;
            }
        }
            int leftdigits = n / divd; // in 12345 to rotate by 2, 12:leftdigits, 345:rightdigits
            int rightdigits = n % divd;
            return ((rightdigits * mul) + leftdigits);

        
    }

}