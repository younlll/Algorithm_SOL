package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class boj1874_S3_220203 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = Integer.parseInt(br.readLine());
        int idx = 1;
        Stack<Integer> stack = new Stack<>();
        StringBuilder sb = new StringBuilder();
        Boolean toggle = true;
        for(int i = 0; i < num; i++) {
            int data = Integer.parseInt(br.readLine());
            if(!toggle) continue;
            while(idx <= data) {
                stack.push(idx++);
                sb.append("+\n");
            }

            if(data == stack.peek()) {
                stack.pop();
                sb.append("-\n");
            } else {
                sb.setLength(0);
                sb.append("NO\n");
                toggle = false;
            }
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}
