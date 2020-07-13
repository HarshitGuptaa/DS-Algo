// 1
// 1 2 1
// 1 2 3 2 1
// 1 2 3 4 3 2 1
// 1 2 3 4 5 4 3 2 1
// 1 2 3 4 5 6 5 4 3 2 1
// 1 2 3 4 5 6 7 6 5 4 3 2 1

import java.util.Scanner;

public class l09 {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter rows: ");
        int rows = scn.nextInt();
        pattern(rows);
    }

    public static void pattern(int rows) {
        int nst = 1;
        int nsp = 0;
        for (int r = 1; r <= rows; r++) {
            int ele = 1;
            for (int cst = 1; cst <= nst; cst++) {
                System.out.print(ele + " ");

                if (cst > nst / 2) {
                    ele--;
                } else {
                    ele++;
                }

            }
            for (int csp = 1; csp <= nsp; csp++) {
                System.out.print(" ");
            }
            nst += 2;
            System.out.println();

        }
    }
}