package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

public class boj1926_S1_220205 {
    public static int n;
    public static int m;
    public static int[][] map;
    public static boolean[][] visited;
    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, 1, 0, -1};

    public static int solution(int x, int y) {
        Queue<Integer> qx = new LinkedList<>();
        Queue<Integer> qy = new LinkedList<>();
        qx.offer(x);
        qy.offer(y);
        visited[x][y] = true;   // 방문표시
        int cnt = 1;

        while(!qx.isEmpty() && !qy.isEmpty()) {
            int cx = qx.poll();
            int cy = qy.poll();

            for(int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                // 벽 처리
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                // 방문한 곳인지 확인 후, 방문한 곳이라면 continue
                if(visited[nx][ny]) continue;
                // 그림이 있는 공간인지 확인 (x, y) == 1
                if(map[nx][ny] != 1) continue;

                qx.offer(nx);
                qy.offer(ny);
                visited[nx][ny] = true; // 방문표시
                cnt++;                  // 그림의 칸 수 세기
            }
       }

       return cnt;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int drawCnt = 0;
        int wideDrawMax = 0;
        String nm = br.readLine();
        n = Integer.parseInt(nm.split(" ")[0]);
        m = Integer.parseInt(nm.split(" ")[1]);
        map = new int[n][m];
        visited = new boolean[n][m];
        for(int i = 0; i < n; i++) {
            String line = br.readLine();
            int idx = 0;
            for(String s : line.split(" ")) {
                map[i][idx++] = Integer.parseInt(s);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(map[i][j] == 1 && !visited[i][j]) {
                    drawCnt++;
                    int wideDraw = solution(i, j);
                    if(wideDraw > wideDrawMax) wideDrawMax = wideDraw;
                }
            }
        }

        bw.write(drawCnt + "\n" + wideDrawMax + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}