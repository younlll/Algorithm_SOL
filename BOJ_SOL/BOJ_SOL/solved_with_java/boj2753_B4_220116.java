package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Scanner;

public class boj2753_B4_220116 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int year = sc.nextInt();
        int answer = 0;

        if(year % 4 == 0 && year % 100 != 0) {
            answer = 1;
        } else if(year % 400 == 0) {
            answer = 1;
        }

        System.out.println(answer);
    }
}