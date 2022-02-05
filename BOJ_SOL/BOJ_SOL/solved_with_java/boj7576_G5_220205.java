package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj7576_G5_220205 {

    public static int n, m;
    public static int[][] map;
    public static boolean[][] visited;
    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, 1, 0, -1};
    public static int zeroCnt = 0;
    public static int depth = 1;

    public static void solution(Queue<Integer> startX, Queue<Integer> startY) {
        Queue<Integer> qx = new LinkedList<>();
        Queue<Integer> qy = new LinkedList<>();
        
        while(!startX.isEmpty() && !startY.isEmpty()) {
            int x = startX.poll();
            int y = startY.poll();
            qx.offer(x);
            qy.offer(y);
            visited[x][y] = true;
        }

        while(!qx.isEmpty() && !qy.isEmpty()) {
            int cx = qx.poll();
            int cy = qy.poll();

            for(int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(map[nx][ny] == -1 || map[nx][ny] == 1) continue;
                if(visited[nx][ny]) continue;

                map[nx][ny] = map[cx][cy] + 1;
                zeroCnt--;
                qx.offer(nx);
                qy.offer(ny);
                visited[nx][ny] = true;

                if(depth < map[nx][ny]) depth = map[nx][ny];
            }
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String nm = br.readLine();
        StringTokenizer st = new StringTokenizer(nm);
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        visited = new boolean[n][m];

        Queue<Integer> startX = new LinkedList<>();
        Queue<Integer> startY = new LinkedList<>();
        for(int i = 0; i < n; i++) {
            String line = br.readLine();
            st = new StringTokenizer(line);
            int j = 0;
            while(st.hasMoreTokens()) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] == 1) {
                    startX.offer(i);
                    startY.offer(j);
                } else if(map[i][j] == 0) {
                    zeroCnt++;
                }
                j++;
            }
        }

        solution(startX, startY);

        if(zeroCnt == 0) {
            bw.write((depth - 1)  + "\n");
        } else {
            bw.write("-1\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
