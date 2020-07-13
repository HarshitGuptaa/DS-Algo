//REQUIRED PATTERN

//     *
//    **
//   ***
//  ****
// *****

import java.util.Scanner;

public class l001 {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter rows..");
        int rows = scn.nextInt();
        pattern(rows);
    }

    public static void pattern(int rows) {
        int nsp = rows - 1;
        int nst = 1;
        for (int r = 1; r <= rows; r++) {
            for (int csp = 1; csp <= nsp; csp++) {
                System.out.print(" ");
            }
            for (int cst = 1; cst <= nst; cst++) {
                System.out.print("*");
            }
            nsp--;
            nst++;
            System.out.println();
        }
    }

}