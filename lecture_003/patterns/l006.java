// 1
// 11    <- nCr
// 121
// 1331
// 14641

import java.util.Scanner;

public class l006 {

    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter rows..");
        int rows = scn.nextInt();
        pattern(rows);
    }

    public static void pattern(int rows) {
        for (int n = 0; n <= rows; n++) {
            int val = 1;
            for (int r = 0; r <= n; r++) {
                System.out.print(val + " ");
                val = (val * (n - r)) / (r + 1);
            }
            System.out.println();
        }
    }

}