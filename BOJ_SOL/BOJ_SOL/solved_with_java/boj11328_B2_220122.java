package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Scanner;

public class boj11328_B2_220122 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testcase = sc.nextInt();

        for(int i = 0; i < testcase; i++) {
            int[] alphaArray = new int[26];
            String answer = "Possible";

            String frontStr = sc.next();
            String backStr = sc.next();

            if(frontStr.length() != backStr.length()) {
                System.out.println("Impossible");
                continue;
            }

            for(int j = 0; j < frontStr.length(); j++) {
                alphaArray[frontStr.charAt(j) - 97] += 1;
            }

            for(int j = 0; j < backStr.length(); j++) {
                if(alphaArray[backStr.charAt(j) - 97] == 0) answer = "Impossible";
                else alphaArray[backStr.charAt(j) - 97] -= 1;
            }
            System.out.println(answer);
        }
    }
}
