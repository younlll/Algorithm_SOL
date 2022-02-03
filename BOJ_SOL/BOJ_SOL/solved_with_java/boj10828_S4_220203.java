import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class boj10828_S4_220203 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int num = Integer.parseInt(br.readLine());

        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < num; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String orderStr = st.nextToken();
            if("push".equals(orderStr)) {
                int inputData = Integer.parseInt(st.nextToken());
                stack.push(inputData);
            } else if("top".equals(orderStr)) {
                if(stack.isEmpty()) {
                    System.out.println("-1");
                } else {
                    System.out.println(stack.peek());
                }
            } else if("size".equals(orderStr)) {
                System.out.println(stack.size());
            } else if("empty".equals(orderStr)) {
                if(stack.isEmpty()) {
                    System.out.println("1");
                } else {
                    System.out.println("0");
                }
            } else if("pop".equals(orderStr)) {
                if(stack.isEmpty()) {
                    System.out.println("-1");
                } else {
                    System.out.println(stack.peek());
                    stack.pop();
                }
            }
        }
    }
}