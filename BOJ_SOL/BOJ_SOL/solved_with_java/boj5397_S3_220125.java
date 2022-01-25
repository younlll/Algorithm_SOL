package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Stack;

public class boj5397_S3_220125 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int testcase = Integer.parseInt(br.readLine());

        for(int i = 0; i < testcase; i++) {
            String input = br.readLine();
            Stack<Character> front = new Stack<>();
            Stack<Character> back = new Stack<>();

            for(int j = 0; j < input.length(); j++) {
                if(input.charAt(j) == '<') {
                    if(front.size() != 0) {
                        back.push(front.pop());
                    }
                } else if(input.charAt(j) == '>') {
                    if(back.size() != 0) {
                        front.push(back.pop());
                    }
                } else if(input.charAt(j) == '-') {
                    if(front.size() != 0) {
                        front.pop();
                    }
                } else {
                    front.push(input.charAt(j));
                }
            }


            while(!front.empty()) {
                back.push(front.pop());
            }
            
            while(!back.empty()) {
                bw.write(back.pop());
            }
            bw.write('\n');
        }
        bw.flush();
        bw.close();
    }
}
