

// TRIANGLE

//   *   
//  * *
// *****
//    * 
//   * *  
//  *   *
// *******

import java.util.Scanner;

public class l02 {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter rows..");
        int rows = scn.nextInt();
        triangle(rows);
    }

    public static void triangle(int rows) {
        int nsp=rows-1;
        int nst =1;
        int betweenSpace = 1;

        for(int r=1;r<=rows;r++){

            for (int csp = 1; csp <= nsp; csp++) {
                System.out.print(" ");
            }

            for (int cst = 1; cst <= nst; cst++) {
                System.out.print("*");
                if(r>1&&r<rows){
                    for(int i=0;i<betweenSpace;i++){
                        System.out.print(" ");
                    }
                    betweenSpace+=2;
                    System.out.print("*");
                    
                }
            }

            if(r<rows-1){
            nst=1;
            nsp--;
            }else{
                nst=2*rows-1;
                nsp=0;
            }
            System.out.println();            
        }
    }

}