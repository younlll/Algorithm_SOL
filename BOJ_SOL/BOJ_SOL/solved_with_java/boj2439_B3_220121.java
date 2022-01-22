package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Scanner;
//
public class boj2439_B3_220121 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        for(int i = 1; i <= num; i++) {
            for(int j = 0; j < num - i; j++) {
                System.out.print(" ");
            }
            for(int j = 0; j < i; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
