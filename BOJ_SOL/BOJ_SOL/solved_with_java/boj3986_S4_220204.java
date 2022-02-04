package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class boj3986_S4_220204 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int answer = 0;
        for(int i = 0; i < N; i++) {
            String inputData = br.readLine();
            Stack<Character> stack = new Stack<>();
            for(int j = 0; j < inputData.length(); j++) {
                char c = inputData.charAt(j);

                if(stack.isEmpty()) {
                    stack.push(c);
                } else {
                    if(stack.peek() == c) {
                        stack.pop();
                    } else {
                        stack.push(c);
                    }
                }
            }

            if(stack.isEmpty()) answer++;
        }

        bw.write(answer + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
