package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class boj4949_S4_220204 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringBuilder sb = new StringBuilder();
        StringBuilder answer = new StringBuilder();
        while(!".".equals(sb.append(br.readLine()).toString())) {
            Stack<Character> openStack = new Stack<>();
            for(int i = 0; i < sb.toString().length(); i++) {
                char c = sb.toString().charAt(i);

                if(c == '(' || c == '[') {
                    openStack.push(c);
                } else if (c == ')') {
                    if(openStack.isEmpty()) {
                        openStack.push(c);
                        break;
                    } else if('(' == openStack.peek()) {
                        openStack.pop();
                    } else {
                        openStack.push(c);
                    }
                } else if (c == ']') {
                    if(openStack.isEmpty()) {
                        openStack.push(c);
                        break;
                    } else if('[' == openStack.peek()) {
                        openStack.pop();
                    } else {
                        openStack.push(c);
                    }
                }
            }

            if(openStack.size() == 0) answer.append("yes\n");
            else answer.append("no\n");

            sb.setLength(0);
        }
        bw.write(answer.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}
