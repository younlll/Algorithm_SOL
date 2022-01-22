package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Scanner;

public class boj13300_B2_220122 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[][] studentArray = new int[7][2];   // row는 학년을 column은 성별을 나타낸다

        int grade;
        int gender;
        for(int i = 0; i < N; i++) {
            gender = sc.nextInt();
            grade = sc.nextInt();

            studentArray[grade][gender] += 1;
        }

        int answer = 0;
        for(int i = 1; i < 7; i++) {
            answer += studentArray[i][0] / K;
            answer += studentArray[i][1] / K;
            answer += studentArray[i][0] % K > 0 ? 1 : 0;
            answer += studentArray[i][1] % K > 0 ? 1 : 0;
        }

        System.out.println(answer);
    }
}
