package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Scanner;

public class boj2576_B3_220116 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int inputNum = 0;
        int answer = 0;
        int minNum = Integer.MAX_VALUE;
        for(int i = 0; i < 7; i++) {
            inputNum = sc.nextInt();
            
            if(inputNum % 2 != 0) { // 홀수인 경우를 찾는다
                answer += inputNum;
                if(minNum > inputNum) { // 홀수인 경우 중에서 최솟값을 찾는다
                    minNum = inputNum;
                }
            }
        }

        if(answer == 0) {
            System.out.println(-1);
        } else {
            System.out.println(answer);
            System.out.println(minNum);
        }
    }
}
