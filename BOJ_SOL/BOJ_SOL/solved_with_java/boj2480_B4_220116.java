package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Scanner;

public class boj2480_B4_220116 {
    public static void main(String[] args) {
        int[] arr = new int[7];
        Scanner sc = new Scanner(System.in);

        int num;

        // 수를 입력받아 1~6이 나온 횟수를 배열을 통해 카운팅
        for(int i = 0; i < 3; i++) {
            num = sc.nextInt();
            arr[num]++;
        }

        int maxNum = 0;
        int answer = 0;
        for(int i = 1; i <= 6; i++) {
            if(arr[i] == 3) {   // 같은 눈이 3개가 나온 경우
                answer = 10000 + (i * 1000);
                break;
            } else if(arr[i] == 2) {    // 같은 눈이 2개가 나온 경우
                answer = 1000 + (i * 100);
                break;
            } else if(arr[i] == 1) {    // 같은 눈이 1개가 나온 경우
                // 가장 큰 눈을 찾아 계산 해준다
                if(maxNum < i) {
                    maxNum = i;
                    answer = i * 100;
                }
            }
        }

        System.out.println(answer);
    }
}
