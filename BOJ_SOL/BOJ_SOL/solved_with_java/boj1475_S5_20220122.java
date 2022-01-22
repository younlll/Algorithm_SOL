package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Scanner;

public class boj1475_S5_20220122 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int inputData = sc.nextInt();
        int[] numberArray = new int[10];

        do {
            /**
             * 6과 9는 뒤집어서 사용할 수 있으므로
             * 최소한의 카드 셋트를 쓸 수 있도로고
             * 더 적은 카드를 사용한 쪽으로 숫자를 배치한다
             */
            if(inputData%10 == 6 || inputData%10 == 9) {
                int index = numberArray[6] > numberArray[9] ? 9 : 6;
                numberArray[index] += 1;
            } else {
                numberArray[inputData%10] += 1;
            }

            inputData /= 10;

        } while(inputData != 0);

        // 0~9 숫자중 최대 숫자가 필요한 카드뭉치의 수가 된다
        int answer = 0;
        for(int i = 0; i < 10; i++) {
            if(answer < numberArray[i]) {
                answer = numberArray[i];
            }
        }

        System.out.println(answer);
    }
}
