package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class boj5430_G5_220204 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for(int t = 0; t < T; t++) {
            String funcP = br.readLine();
            int dataCnt = Integer.parseInt(br.readLine());
            String inputData = br.readLine();
            inputData = inputData.substring(1, inputData.length() - 1);
            String[] dataArr = inputData.split(",");
            var deque = new int[1400000*2+1];
            int head = 1400000;
            int tail = 1400000;
            StringBuilder sb = new StringBuilder();
            boolean toggle = true;
            boolean reverseToggle = true;
            for(int i = 0; i < dataCnt; i++) {
                deque[tail++] = Integer.parseInt(dataArr[i]);
            }

            for(int i = 0; i < funcP.length(); i++) {
                char c = funcP.charAt(i);

                if(c == 'R') {
                    int tmp = head;
                    if(reverseToggle) {
                        head = tail - 1;
                        tail = tmp - 1;
                    } else {
                        head = tail + 1;
                        tail = tmp + 1;
                    }
                    reverseToggle = !reverseToggle;
                    
                } else if (c == 'D') {
                    if(tail - head == 0) {
                        sb.append("error\n");
                        toggle = false;
                        break;
                    } else{
                        if(reverseToggle) head++;
                        else head--;
                    }
                }
            }

            if(toggle) {
                sb.append("[");
                if(head != tail) {
                    if(reverseToggle) {
                        while(head != tail - 1) {
                            sb.append(deque[head++] + ",");
                        }
                    } else {
                        while(head != tail + 1) {
                            sb.append(deque[head--] + ",");
                        }
                    }
                    sb.append(deque[head++] + "]\n");
                } else{
                    sb.append("]\n");
                }
                
            }
            bw.write(sb.toString());
            bw.flush();
        }
        
        bw.close();
        br.close();
    }
}
