//  FULL DIAMOND 
//   *
//  ***
// *****
//  ***
//   *

import java.util.Scanner;

public class l004 {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter rows..");
        int rows = scn.nextInt();
        fullDiamond(rows);
    }

    public static void fullDiamond(int rows) {
        int nsp=rows/2;
        int nst =1;
        for(int r=1;r<=rows;r++){
            for (int csp = 1; csp <= nsp; csp++) {
                System.out.print(" ");
            }
            for (int cst = 1; cst <= nst; cst++) {
                System.out.print("*");
            }

            if(r<=rows/2){
            nst+=2;
            nsp--;
            }else{
                nst-=2;
                nsp++;
            }
            System.out.println();            
        }
    }

}