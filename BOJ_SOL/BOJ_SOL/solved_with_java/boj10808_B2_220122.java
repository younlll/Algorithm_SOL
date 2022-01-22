package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Scanner;

public class boj10808_B2_220122 {
    public static void main(String[] args) {
        int[] alphaArray = new int[26];
        Scanner sc = new Scanner(System.in);
        String inputStr = sc.nextLine();

        for(int i = 0; i < inputStr.length(); i++) {
            alphaArray[(int)inputStr.charAt(i) - 97]++;
        }

        for(int i = 0; i < 26; i++) {
            System.out.print(alphaArray[i] + " ");
        }
    }
}
