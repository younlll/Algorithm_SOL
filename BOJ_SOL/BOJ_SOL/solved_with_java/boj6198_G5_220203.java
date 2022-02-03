package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class boj6198_G5_220203 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int num = Integer.parseInt(br.readLine());
        Stack<Integer> buildingHeight = new Stack<>();
        Long result = 0L;
        for(int i = 0; i < num; i++) {
            int data = Integer.parseInt(br.readLine());

            while(!buildingHeight.isEmpty() && buildingHeight.peek() < data) {
                buildingHeight.pop();
            }

            result += buildingHeight.size();
            buildingHeight.push(data);
        }

        System.out.println(result);
        br.close();
        bw.close();
    }
}
