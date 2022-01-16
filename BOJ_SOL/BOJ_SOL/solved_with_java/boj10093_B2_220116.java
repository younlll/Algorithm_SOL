package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Scanner;

public class boj10093_B2_220116 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextLong();
        long B = sc.nextLong();
        
        long start = A > B ? B : A;
        long end = A > B ? A : B;

        if(start == end) {
            // ex) A = 2, B = 2인 경우, 
            // 예외처리를 하지 않는 경우 2 - 2 -1 = -1이 되어 올바른 답이 나오지 않는다
            System.out.println(0);
        } else {
            System.out.println(end - start - 1);
        }
        
        for(long i = start + 1; i < end; i++) {
            System.out.print(i + " ");
        }
    }
}
