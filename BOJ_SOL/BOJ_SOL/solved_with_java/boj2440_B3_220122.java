package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Scanner;

public class boj2440_B3_220122 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        for(int i = num; i > 0; i--) {
            for(int j = 0; j < i; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
