package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Scanner;

public class boj10807_B2_220122 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int inputCnt = sc.nextInt();
        int[] numberArray = new int[201];

        int inputNum;
        /**
         * 찾고자 하는 숫자의 범위가 -100 ~ 100이다
         * 음수를 배열에 쉽게 찾을수 있도록 표현하기 위해 + 100을 해주었다
         * -100 -> -100 + 100 = 0이 되는 것이다
         */
        for(int i = 0; i < inputCnt; i++) {
            inputNum = sc.nextInt();
            numberArray[inputNum + 100] += 1;
        }

        // 입력값 + 100을 해서 저장하고 있으므로 찾고 싶은 숫자도 +100을 한 위치에서 찾는다
        int findNum = sc.nextInt();
        System.out.println(numberArray[findNum + 100]);
    }
}
