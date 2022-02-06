package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj1012_S2_220206 {
    static class Pair {
        int x;
        int y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        int getX() {
            return x;
        }

        int getY() {
            return y;
        }
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, 1, 0, -1};
        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t < T; t++) {
            String mnk = br.readLine();
            StringTokenizer st = new StringTokenizer(mnk);
            int m = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            int[][] map = new int[m][n];
            Queue<Pair> queue = new LinkedList<>();
            boolean[][] visited = new boolean[m][n];
            int answer = 0;

            for(int i = 0; i < k; i++) {
                String xy = br.readLine();
                st = new StringTokenizer(xy);
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                map[x][y] = 1;
                queue.offer(new Pair(x, y));
            }

            while(!queue.isEmpty()) {
                if(visited[queue.peek().getX()][queue.peek().getY()]) {
                    queue.poll();
                    continue;
                }

                Queue<Pair> q = new LinkedList<>();
                q.offer(new Pair(queue.peek().getX(), queue.peek().getY()));
                visited[queue.peek().getX()][queue.peek().getY()] = true;
                queue.poll();
                while(!q.isEmpty()) {
                    int cx = q.peek().getX();
                    int cy = q.peek().getY();
                    q.poll();
                    for(int i = 0; i < 4; i++) {
                        int nx = cx + dx[i];
                        int ny = cy + dy[i];

                        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if(visited[nx][ny]) continue;
                        if(map[nx][ny] == 0) continue;

                        q.offer(new Pair(nx, ny));
                        visited[nx][ny] = true;
                    }
                }
                answer++;
            }
            bw.write(answer + "\n");
            bw.flush();
        }
        bw.close();
        br.close();
    }
}
