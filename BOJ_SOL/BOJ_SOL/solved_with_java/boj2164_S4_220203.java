package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

public class boj2164_S4_220203 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = Integer.parseInt(br.readLine());
        Queue<Integer> queue = new LinkedList<>();
        for(int i = 0; i < num; i++) {
            queue.offer(i + 1);
        }

        while(queue.size() != 1) {
            queue.poll(); // 맨 위 카드 버리기
            queue.offer(queue.poll());  // 맨 위 카드를 맨 아래로 옮기기
        }

        bw.write(queue.peek() + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
