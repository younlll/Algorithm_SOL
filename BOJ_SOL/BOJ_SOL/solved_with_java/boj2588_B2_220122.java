package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Scanner;

public class boj2588_B2_220122 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A, B, C;
        int multi;
        int[] numberArray = new int[10];

        A = sc.nextInt();
        B = sc.nextInt();
        C = sc.nextInt();

        multi = A * B * C;

        /**
         * multi를 10으로 나눈 나머지는 1의 자리부터 시작해서 숫자를 얻을 수 있다
         * 얻은 숫자를 0~9의 인덱스를 갖는 배열에 각 인덱스에 맞게 +1을 해서 카운팅을 해준다
         * while문의 조건을 multi/10 != 0을 함으로써 마지막 숫자는 카운팅이 되지 않으므로
         * 반복문 밖에서 마지막 연산을 수행해준다
         */
        while(multi/10 != 0) {
            numberArray[multi%10]++;
            multi = multi/10;
        }
        numberArray[multi%10]++;

        for(int i = 0; i < 10; i++) {
            System.out.println(numberArray[i]);
        }
    }
}
