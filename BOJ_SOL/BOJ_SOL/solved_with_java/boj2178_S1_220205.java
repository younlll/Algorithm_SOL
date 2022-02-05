package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

public class boj2178_S1_220205 {

    public static int n, m;
    public static int[][] map;
    public static boolean[][] visited;
    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, 1, 0, -1};

    public static int solution(int x, int y) {
        Queue<Integer> qx = new LinkedList<>();
        Queue<Integer> qy = new LinkedList<>();
        int[][] copyMap = new int[n][m];

        qx.offer(x);
        qy.offer(y);
        visited[x][y] = true;
        copyMap[x][y] = 1;

        while(!qx.isEmpty() && !qy.isEmpty()) {
            int cx = qx.poll();
            int cy = qy.poll();
            
            for(int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(visited[nx][ny]) continue;
                if(map[nx][ny] == 0) continue;

                qx.offer(nx);
                qy.offer(ny);
                visited[nx][ny] = true;
                copyMap[nx][ny] = copyMap[cx][cy] + 1;
            }
        }

        return copyMap[n - 1][m - 1];
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String nm = br.readLine();
        n = Integer.parseInt(nm.split(" ")[0]);
        m = Integer.parseInt(nm.split(" ")[1]);
        map = new int[n][m];
        visited = new boolean[n][m];
        for(int i = 0; i < n; i++) {
            String line = br.readLine();
            for(int j = 0; j < line.length(); j++) {
                map[i][j] = Integer.parseInt(line.charAt(j) + "");
            }
        }

        int answer = solution(0, 0);
        bw.write(answer + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
