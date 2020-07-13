import java.util.Scanner;

public class octalAdd {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter n1..");
        int n1 = scn.nextInt();
        System.out.println("Enter n2..");
        int n2 = scn.nextInt();
        int r = oAdd(n1, n2);
        System.out.println(r);
    }

    public static int oAdd(int n1, int n2) {
        int carry = 0, res = 0, pow = 1;
        while (n1 != 0 || n2 != 0 || carry != 0) {
            int r1 = n1 % 10;
            int r2 = n2 % 10;
            int rem = r1 + r2 + carry;

            n1 /= 10;
            n2 /= 10;
            carry = rem / 8;

            rem %= 8;
            res += rem * pow;
            pow *= 10;

        }

        return res;
    }

}