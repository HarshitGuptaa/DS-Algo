// 1 2 3 4 5 6 7
// 1 2 3 4 5 6
// 1 2 3 4 5
// 1 2 3 4
// 1 2 3
// 1 2 
// 1 
// 1 2
// 1 2 3 
// 1 2 3 4 
// 1 2 3 4 5
// 1 2 3 4 5 6
// 1 2 3 4 5 6 7

import java.util.Scanner;

public class l010 {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter rows: ");
        int rows = scn.nextInt();
        pattern(rows);
    }

    public static void pattern(int rows) {
        int nst = rows;
        int nsp = 0;
        for (int r = 1; r <= 2*rows-1; r++) {
            int ele=1;
            for (int cst = 1; cst <= nst; cst++) {
                System.out.print(ele);
                ele++;

            }
            for (int csp = 1; csp <= nsp; csp++) {
                System.out.print(" ");
            }
            if(r>rows-1){
                nst++;
            }else{
                nst --;
            }
            System.out.println();

        }
    }
}