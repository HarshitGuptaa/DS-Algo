// 1 2 3 4 5 
//   2 3 4 5 
//     3 4 5
//       4 5
//         5
//       4 5
//     3 4 5
//   2 3 4 5
// 1 2 3 4 5

import java.util.Scanner;

public class l011 {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter rows: ");
        int rows = scn.nextInt();
        pattern(rows);
    }

    public static void pattern(int rows) {
        int nst = rows;
        int nsp = 0;
        int ele;
        for (int r = 1; r <= 2 * rows - 1; r++) {
            if (r <= rows) {
                ele = r;
            } else {
                ele = 2 * rows - r;
            }

            for (int csp = 1; csp <= nsp; csp++) {
                System.out.print(" ");
            }

            for (int cst = 1; cst <= nst; cst++) {
                System.out.print(ele);

                ele++;

            }

            if (r > rows - 1) {
                nst++;
                nsp--;
            } else {
                nst--;
                nsp++;
            }
            System.out.println();
        }

    }
}