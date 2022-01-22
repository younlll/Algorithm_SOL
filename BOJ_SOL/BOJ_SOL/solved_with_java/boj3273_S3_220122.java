package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Scanner;

public class boj3273_S3_220122 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int inputCnt = sc.nextInt();
        int[] arr = new int[10000101];
        int num;

        // 중복되지 않는 양의 정수들 입력 받으면서 입력받은 수의 인덱스를 배열에서 +1
        for(int i = 0; i < inputCnt; i++) {
            num = sc.nextInt();
            arr[num] += 1;
        }

        int matchNum = sc.nextInt();
        int answer = 0;
        /**
         * 검사할 배열의 숫자 최대값은 합을 구하고 싶은 숫자이다
         * 
         * 배열의 값이 0이 아닌 1이라면 해당 인덱스 숫자는 입력받은 숫자라는 것이다
         * 그 숫자가 합을 통해 x를 만들 수 있는 숫자는 x - 인덱스 하나이다
         * x - 인덱스 또한 1을 갖고 있다면 둘 다 입력받은 수이므로 한쌍을 추가한다
         * 그리고 i를 하나씩 증가시키며 검사하다보면 x - 인덱스가 나올것이고
         * 이런 경우 모두 한번씩 카운팅이 더 되었으므로 원하는 값보다 2배로 나올것이다
         * 따라서 구한 쌍의 수를 나누기 2를 통해 원하는 값을 구한다
         */
        for(int i = 1; i < 1000001; i++) {
            if(matchNum - i >= 1000000) continue;
            if(matchNum - i <= 0) continue;
            if(arr[i] == 1 && arr[matchNum - i] == 1) answer++;
        }

        System.out.println(answer/2);
    }
}
