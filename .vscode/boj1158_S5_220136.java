package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

public class boj1158_S5_220136 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str = br.readLine();
        int N = Integer.parseInt(str.charAt(0) + "");
        int K = Integer.parseInt(str.charAt(2) + "");

        Queue<Integer> queue = new LinkedList<>();
        for(int i = 1; i <= N; i++) {
            queue.offer(i);
        }

        int cnt = 1;
        bw.write('<');
        while(!queue.isEmpty()) {
            if(cnt == K) {
                System.out.println(queue.poll() + ", ");
                cnt = 1;
                continue;
            }
            queue.offer(queue.poll());
            cnt++;
        }
        // bw.write(">\n");
        // bw.flush();
        // bw.close();
    }
}
