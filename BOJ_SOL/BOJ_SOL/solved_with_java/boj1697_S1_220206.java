package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj1697_S1_220206 {
    
    static int[] calc_result(int num) {
        int[] data = {num - 1, num + 1, num * 2};
        return data;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String nk = br.readLine();
        StringTokenizer st = new StringTokenizer(nk);
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        Queue<Integer> queue = new LinkedList<>();
        int[] visited = new int[100001];
        queue.offer(N);
        visited[N] = 0;
        while(!queue.isEmpty()) {
            int cpos = queue.poll();
            int[] calcData = calc_result(cpos);

            if(calcData[0] > K && calcData[1] > K && calcData[2] > K) continue;

            for(int i = 0; i < calcData.length; i++) {
                if(calcData[i] < 0 || calcData[i] > 100000) continue;
                if(visited[calcData[i]] == 0) {
                    queue.offer(calcData[i]);
                    visited[calcData[i]] = visited[cpos] + 1;
                } else if(visited[calcData[i]] > visited[cpos] + 1) {
                    queue.offer(calcData[i]);
                    visited[calcData[i]] = visited[cpos] + 1;
                }
            }
        }

        if(N > K) bw.write((N - K) + "\n");
        else if(N == K) bw.write("0\n");
        else bw.write(visited[K] + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
