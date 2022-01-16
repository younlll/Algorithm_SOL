package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Arrays;
import java.util.Scanner;

public class boj2752_B4_220116 {
    public static void main(String[] args) {
        int[] arr = new int[3];
        Scanner sc = new Scanner(System.in);

        for(int i = 0; i < 3; i++) {
            arr[i] = sc.nextInt();
        }

        Arrays.sort(arr);

        for(int i = 0; i < 3; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
