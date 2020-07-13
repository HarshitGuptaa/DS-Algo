// REQUIRED
// 54321
// 4321
// 321
// 21
// 1

import java.util.Scanner;

public class l07 {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter rows: ");
        int rows = scn.nextInt();
        pattern(rows);
    }

    public static void pattern(int rows) {
        int nst = rows;
        int nsp = 0;
        for (int r = 1; r <= rows; r++) {
            int ele=nst;

            for (int cst = 1; cst <= nst; cst++) {
                System.out.print(ele);
                ele--;
            }
            for (int csp = 1; csp <= nsp; csp++) {
                System.out.print(" ");
            }
            nst--;
            System.out.println();

        }
    }
}