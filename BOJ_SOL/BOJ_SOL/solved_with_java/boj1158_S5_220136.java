package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj1158_S5_220136 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        Queue<Integer> queue = new LinkedList<>();
        for(int i = 1; i <= N; i++) {
            queue.offer(i);
        }

        int cnt = 1;
        StringBuilder sb = new StringBuilder();
        sb.append("<");
        while(!queue.isEmpty()) {
            if(cnt == K) {
                sb.append(queue.poll());
                if(!queue.isEmpty()) {
                    sb.append(", ");
                }
                cnt = 1;
                continue;
            }
            queue.offer(queue.poll());
            cnt++;
        }
        sb.append(">");

        bw.write(sb.toString() + '\n');
        bw.flush();
        bw.close();
        br.close();
    }
}
