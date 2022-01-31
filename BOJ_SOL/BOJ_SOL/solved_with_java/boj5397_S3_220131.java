package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.ListIterator;

public class boj5397_S3_220131 {
    public static void main(String[] args) throws IOException{
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            int testcase = Integer.parseInt(br.readLine());

            for(int i = 0; i < testcase; i++) {
                String input = br.readLine();
                LinkedList<Character> list = new LinkedList<>();
                ListIterator<Character> cursor = list.listIterator();

                for(int j = 0; j < input.length(); j++) {
                    // I wish Strings were Iterable
                    char c = input.charAt(j);
                    if (c != '<' && c != '>' && c != '-') {
                        cursor.add(c);
                    } else if (c == '<' && cursor.hasPrevious()) {
                        cursor.previous();
                    } else if (c == '>' && cursor.hasNext()) {
                        cursor.next();
                    } else if (c == '-' && cursor.hasPrevious()) {
                        cursor.previous();
                        cursor.remove();
                    }
                }

                for (char c : list) {
                    bw.write(c);
                }
                bw.write('\n');
            }
        }
    }
}
