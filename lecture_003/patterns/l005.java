import java.util.Scanner;

public class l005 {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {

        System.out.println("Enter number of rows..");
        int rows = scn.nextInt();
        fullDiamondNumber(rows);
    }

    public static void fullDiamondNumber(int rows) {
        int nsp = rows / 2; // 3 spaces in 1st line when 7 rows
        int nst = 1;
        for (int r = 1; r <= rows; r++) {
            for (int csp = 1; csp <= nsp; csp++) {
                System.out.print(" ");
            }
            int ele = r;
            if(r>(rows+1)/2){
                ele = rows-r+1;
            }
            for (int cst = 1; cst <= nst; cst++) {
                System.out.print(ele);
                if(cst<=nst/2){
                    ele++;
                }else{
                    ele--;
                }
            }
            if (r <= rows / 2) {
                nst += 2;
                nsp--;
                
            } else {
                nst -= 2;
                nsp++;
                
            }
            System.out.println();
        }
    }
}