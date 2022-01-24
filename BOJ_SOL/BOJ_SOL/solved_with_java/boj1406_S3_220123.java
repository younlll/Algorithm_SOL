package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class boj1406_S3_220123 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str = br.readLine();
        int num = Integer.parseInt(br.readLine());

        String[] dat = new String[600001];
        int[] pre = new int[600001];
        int[] nxt = new int[600001];
        
        dat[0] = "";
        pre[0] = -1;
        nxt[0] = -1;

        int pos = 0;
        int newPos = 1;
        for(int i = 0; i < str.length(); i++) {
            dat[newPos] = str.charAt(i) + "";
            pre[newPos] = pos;
            nxt[newPos] = nxt[pos];
            nxt[pos] = newPos;
            pos = newPos;
            newPos++;
        }

        String input = "";
        for(int i = 0; i < num; i++) {
            input = br.readLine();
            
            switch(input.charAt(0)) {
                case 'L':
                    if(pre[pos] != -1) pos = pre[pos];
                    break;
                case 'D':
                    if(nxt[pos] != -1) pos = nxt[pos];
                    break;
                case 'B':
                    if(nxt[pos] == -1 && pre[pos] != -1) {    // 커서 위치가 맨뒤인 경우
                        pos = pre[pos];
                        nxt[pos] = -1;
                    } else if(pre[pos] != -1) {    // 커서 위치가 맨앞을 제외한 경우
                        nxt[pre[pos]] = nxt[pos];
                        pre[nxt[pos]] = pre[pos];
                        pos = pre[pos];
                    }
                    break;
                case 'P':
                    if(nxt[pos] != -1) {
                        pre[nxt[pos]] = newPos;
                    }
                    dat[newPos] = input.charAt(2) + "";
                    pre[newPos] = pos;
                    nxt[newPos] = nxt[pos];
                    nxt[pos] = newPos;                    
                    pos = newPos;
                    newPos++;
                    break;
            }
        }

        int idx = 0;
        while(nxt[idx] != -1) {
            idx = nxt[idx];
            bw.write(dat[idx]);
        }
        bw.flush();
        bw.close();
    }
}
