package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Arrays;
import java.util.Scanner;

public class boj2309_B2_220116 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[9];
        int sum = 0;

        for(int i = 0; i < 9; i++) {
            arr[i] = sc.nextInt();
            sum += arr[i];
        }

        Arrays.sort(arr);

        for(int i = 0; i < 9; i++) {
            for(int j = i + 1; j < 9; j++) {
                if(sum - arr[i] - arr[j] == 100) {
                    arr[i] = -1;
                    arr[j] = -1;
                    i = 9;
                    j = 9;
                }
            }
        }

        for(int i = 0; i < 9; i++) {
            if(arr[i] == -1) continue;
            System.out.println(arr[i]);
        }
    }
}
