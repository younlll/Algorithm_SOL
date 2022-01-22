package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Scanner;

public class boj2577_B2_220122 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A, B, C;
        int multi;
        int[] numberArray = new int[10];

        A = sc.nextInt();
        B = sc.nextInt();
        C = sc.nextInt();

        multi = A * B * C;
        while(multi/10 != 0) {
            numberArray[multi%10]++;
            multi = multi/10;
        }
        numberArray[multi%10]++;

        for(int i = 0; i < 10; i++) {
            System.out.println(numberArray[i]);
        }
    }
}
