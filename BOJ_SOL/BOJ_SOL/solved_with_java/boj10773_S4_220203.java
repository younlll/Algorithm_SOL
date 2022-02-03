package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class boj10773_S4_220203 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = Integer.parseInt(br.readLine());
        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < num; i++) {
            int data = Integer.parseInt(br.readLine());
            if(data == 0) {
                stack.pop();
            } else {
                stack.push(data);
            }
        }

        int result = 0;
        while(!stack.isEmpty()) {
            result += stack.pop();
        }

        System.out.println(result);

        br.close();
    }
}