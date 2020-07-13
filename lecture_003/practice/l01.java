

//RIGHT PASCAL TRIANGLE
// *
// **
// ***
// ****
// *****
// ******
// *****
// ****
// ***
// **
// *

import java.util.Scanner;

public class l01 {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter rows..");
        int rows = scn.nextInt();
        triangle(rows);
    }

    public static void triangle(int rows) {
        int nsp=0;
        int nst =1;
        for(int r=1;r<=rows;r++){
            for (int cst = 1; cst <= nst; cst++) {
                System.out.print("*");
            }
            for (int csp = 1; csp <= nsp; csp++) {
                System.out.print(" ");
            }


            if(r<=rows/2){
            nst++;
            nsp--;
            }else{
                nst--;
                nsp++;
            }
            System.out.println();            
        }
    }

}