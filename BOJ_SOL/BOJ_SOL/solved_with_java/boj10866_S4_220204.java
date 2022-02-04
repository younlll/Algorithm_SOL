package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class boj10866_S4_220204 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        int[] deque = new int[2*10000+1];
        int head = 10000;
        int tail = 10000;
        for(int i = 0; i < num; i++) {
            String inputOrder = br.readLine();
            String[] orderArr = inputOrder.split(" ");

            switch(orderArr[0]) {
                case "push_front":
                    deque[--head] = Integer.parseInt(orderArr[1]);
                    break;
                case "push_back":
                    deque[tail++] = Integer.parseInt(orderArr[1]);
                    break;
                case "pop_front":
                    if(head == tail) sb.append("-1\n");
                    else sb.append(deque[head++] + "\n");
                    break;
                case "pop_back":
                    if(head == tail) sb.append("-1\n");
                    else sb.append(deque[--tail] + "\n");
                    break;
                case "size":
                    sb.append((tail - head) + "\n");
                    break;
                case "empty":
                    if(head == tail) sb.append("1\n");
                    else sb.append("0\n");
                    break;
                case "front":
                    if(head == tail) sb.append("-1\n");
                    else sb.append(deque[head] + "\n");
                    break;
                case "back":
                    if(head == tail) sb.append("-1\n");
                    else sb.append(deque[tail - 1] + "\n");
                    break;
            }
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}
