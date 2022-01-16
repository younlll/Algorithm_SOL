package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Scanner;

public class boj2490_B4_220116 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num;
        int oneCnt = 0;
        // 배:0 등:1
        for(int i = 0; i < 3; i++) {
            oneCnt = 0;
            for(int j = 0; j < 4; j++) {
                num = sc.nextInt();
                if(num == 1) {
                    oneCnt++;
                }
            }

            if(oneCnt == 4) {
                System.out.println("E");
            } else if(oneCnt == 3) {
                System.out.println("A");
            } else if(oneCnt == 2) {
                System.out.println("B");
            } else if(oneCnt == 1) {
                System.out.println("C");
            } else {
                System.out.println("D");
            }
        }
    }
}
