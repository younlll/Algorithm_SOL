package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class boj18258_S4_220203 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int inputNum = Integer.parseInt(br.readLine());
        int[] queue = new int[2000001];
        int head = 0;
        int tail = 0;
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < inputNum; i++) {
            String inputOrder = br.readLine();
            String[] orderArr = inputOrder.split(" ");

            switch(orderArr[0]) {
                case "push":
                    queue[tail++] = Integer.parseInt(orderArr[1]);
                    break;
                case "pop":
                    if(head == tail) sb.append("-1\n");
                    else sb.append(queue[head++] + "\n");
                    break;
                case "size":
                    sb.append(tail - head + "\n");
                    break;
                case "empty":
                    if(head == tail) sb.append("1\n");
                    else sb.append("0\n");
                    break;
                case "front":
                    if(head == tail) sb.append("-1\n");
                    else sb.append(queue[head] + "\n");
                    break;
                case "back":
                    if(head == tail) sb.append("-1\n");
                    else sb.append(queue[tail - 1] + "\n");
                    break;
            }
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}
