package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class boj17298_G4_220203 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = Integer.parseInt(br.readLine());
        String data = br.readLine();
        String[] dataArr = data.split(" ");
        Stack<Integer> stack = new Stack<>();
        Stack<Integer> result = new Stack<>();
        StringBuilder sb = new StringBuilder();
        for(int i = num - 1; i >= 0; i--) {
            while(!stack.isEmpty() && stack.peek() <= Integer.parseInt(dataArr[i])) {
                stack.pop();
            }

            if(stack.isEmpty()) {
                result.push(-1);
            } else {
                result.push(stack.peek());
            }

            stack.push(Integer.parseInt(dataArr[i]));
        }

        while(!result.isEmpty()) {
            sb.append(result.pop() + " ");
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}
