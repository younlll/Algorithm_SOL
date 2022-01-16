package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.util.Scanner;

public class boj1267_B3_220116 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int callTime = 0;
        int yBill = 0;
        int mBill = 0;

        for(int i = 0; i < num; i++) {
            callTime = sc.nextInt();
            yBill += (callTime/30) * 10;
            if(callTime%30 >= 0) yBill += 10;

            mBill += (callTime/60) * 15;
            if(callTime%60 >= 0) mBill += 15;
        }

        if(yBill < mBill) {
            System.out.println("Y " + yBill);
        } else if(yBill > mBill) {
            System.out.println("M " + mBill);
        } else {
            System.out.println("Y M " + yBill);
        }
    }
}
