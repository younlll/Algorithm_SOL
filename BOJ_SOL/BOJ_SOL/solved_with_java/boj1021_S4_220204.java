package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class boj1021_S4_220204 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String inputOrder = br.readLine();
        String inputData = br.readLine();
        int N = Integer.parseInt(inputOrder.split(" ")[0]);
        int M = Integer.parseInt(inputOrder.split(" ")[1]);
        String[] dataArr = inputData.split(" ");
        int[] deque = new int[50*50+1];
        int head = 50*50/2;
        int tail = 50*50/2;
        int answer = 0;

        for(int i = 1; i <= N; i++) {
            deque[tail++] = i;
        }

        for(int i = 0; i < dataArr.length; i++) {
            if(deque[head] == Integer.parseInt(dataArr[i])) {
                head++;
            } else {
                int hcnt = 0;
                int tcnt = 0;
                for(int j = head; j < tail; j++) {
                    if(Integer.parseInt(dataArr[i]) == deque[j]) {
                        break;
                    }
                    hcnt++;
                }
                for(int j = tail - 1; j >= head; j--) {
                    if(Integer.parseInt(dataArr[i]) == deque[j]) {
                        tcnt++;
                        break;
                    }
                    tcnt++;
                }

                if(hcnt <= tcnt) {
                    answer += hcnt;
                    while(deque[head] != Integer.parseInt(dataArr[i])) {
                        deque[tail++] = deque[head++];
                    }
                    head++;
                } else {
                    answer += tcnt;
                    while(deque[head] != Integer.parseInt(dataArr[i])) {
                        deque[--head] = deque[--tail];
                    }
                    head++;
                }
            }
        }
        bw.write(answer + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
