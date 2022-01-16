package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Scanner;

public class boj10804_B2_220116 {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[21];
        
        for(int i = 0; i < 21; i++) {
            arr[i] = i;
        }

        int inputStart;
        int inputEnd;
        for(int i = 0; i < 10; i++) {
            inputStart = sc.nextInt();
            inputEnd = sc.nextInt();

            while(inputStart <= inputEnd) {
                int tmp = arr[inputStart];
                arr[inputStart] = arr[inputEnd];
                arr[inputEnd] = tmp;
                inputStart++;
                inputEnd--;
            }
        }

        for(int i = 1; i <= 20; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
