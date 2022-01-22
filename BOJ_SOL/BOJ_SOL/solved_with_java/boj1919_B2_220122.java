package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Scanner;

public class boj1919_B2_220122 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str1 = sc.next();
        String str2 = sc.next();
        int[] alphaArray = new int[26];

        for(int i = 0; i < str1.length(); i++) {
            alphaArray[str1.charAt(i) - 97] += 1;
        }

        int sameAlphaCnt = 0;
        for(int i = 0; i < str2.length(); i++) {
            if(alphaArray[str2.charAt(i) - 97] != 0) {
                sameAlphaCnt++;
                alphaArray[str2.charAt(i) - 97] -= 1;
            }
        }

        int answer = str1.length() + str2.length() - (sameAlphaCnt * 2);
        System.out.println(answer);
    }
}
