package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class boj2493_G5_220129 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = Integer.parseInt(br.readLine());

        Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();
        for(int i = 0; i < num; i++) {
            int data = Integer.parseInt(br.readLine());
            stack1.push(data);
        }

        int num2 = stack1.peek();
        stack1.pop();
        while(!stack1.isEmpty()) {
            if(num2 < stack1.peek()) {
                stack2.push(stack1.size());
                num2 = stack1.peek();
                stack1.pop();
            } else if (num2 > stack1.peek()) {
                
            }
        }
    }
}
