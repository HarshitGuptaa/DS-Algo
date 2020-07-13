import java.util.Scanner;

public class fibonacci {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter n");
        int n = scn.nextInt();
        fibo(n);
    }

    public static void fibo(int n) {
        int first = 0;
        int second = 1;
        // System.out.print("1 ");
        for (int i = 0; i < n; i++) {
            int next = first + second;
            System.out.print(second + " ");
            first = second;
            second = next;
        }
    }

}