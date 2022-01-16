package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Arrays;
import java.util.Scanner;

public class boj2587_B2_220116 {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[5];
        int sum = 0;

        for(int i = 0; i < 5; i++) {
            arr[i] = sc.nextInt();
            sum += arr[i];
        }

        Arrays.sort(arr);   // 중앙값을 찾기 위한 정렬

        System.out.println(sum/5);
        System.out.println(arr[2]);
    }
}
