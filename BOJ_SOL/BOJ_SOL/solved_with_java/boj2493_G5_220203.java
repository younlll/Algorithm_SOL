package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class boj2493_G5_220203 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = Integer.parseInt(br.readLine());
        String str = br.readLine();
        String[] strArr = str.split(" ");
        Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();
        StringBuilder sb = new StringBuilder();
        for(int i = 1; i <= strArr.length; i++) {
            int data = Integer.parseInt(strArr[i - 1]);
            
            while(!stack1.isEmpty() && stack1.peek() < data) {
                stack1.pop();
                stack2.pop();
            }
            
            if(stack1.isEmpty()) {
                sb.append("0 ");
            } else {
                sb.append(stack2.peek() + " ");
            }

            stack1.push(data);
            stack2.push(i);
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}
