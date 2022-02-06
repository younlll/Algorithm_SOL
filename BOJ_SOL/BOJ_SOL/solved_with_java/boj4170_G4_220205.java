package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj4170_G4_220205 {

    public static int R, C;
    public static int jx = 0, jy = 0;
    public static char[][] map;
    public static int[][] jvisited;
    public static int[][] fvisited;
    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, 1, 0, -1};

    static class Pair {
        private int x;
        private int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }
    }

    public static void solution(Queue<Pair> qf) {
        Queue<Pair> qj = new LinkedList<>();
        qj.offer(new Pair(jx, jy));

        while(!qf.isEmpty()) {
            // 불
            int cx, cy;
            cx = qf.peek().getX();
            cy = qf.peek().getY();
            qf.poll();

            for(int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if(fvisited[nx][ny] == -1) continue;
                if(fvisited[nx][ny] != 0 && fvisited[nx][ny] > fvisited[cx][cy] + 1) { 
                    qf.offer(new Pair(nx, ny));
                    fvisited[nx][ny] = fvisited[cx][cy] + 1;
                } else if(fvisited[nx][ny] == 0){
                    qf.offer(new Pair(nx, ny));
                    fvisited[nx][ny] = fvisited[cx][cy] + 1;
                }
            }
        }

        while(!qj.isEmpty()) {
            // 지훈
            int cx, cy;

            cx = qj.peek().getX();
            cy = qj.peek().getY();
            qj.poll();

            for(int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if(jvisited[nx][ny] != 0) continue;
                if(jvisited[cx][cy] + 1 > fvisited[nx][ny] && fvisited[nx][ny] != 0) continue;

                qj.offer(new Pair(nx, ny));
                jvisited[nx][ny] = jvisited[cx][cy] + 1;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String rc = br.readLine();
        StringTokenizer st = new StringTokenizer(rc);
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        map = new char[R][C];
        jvisited = new int[R][C];
        fvisited = new int[R][C];

        Queue<Pair> qf = new LinkedList<>();
        for(int i = 0; i < R; i++) {
            String line = br.readLine();
            for(int j = 0; j < C; j++) {
                map[i][j] = line.charAt(j);
                if(map[i][j] == 'J') {
                    jx = i;
                    jy = j;
                    jvisited[jx][jy] = 1;
                } else if(map[i][j] == 'F') {
                    qf.offer(new Pair(i, j));
                    fvisited[i][j] = 1;
                }

                if(map[i][j] == '#') {
                    jvisited[i][j] = -1;
                    fvisited[i][j] = -1;
                }
            }
        }

        solution(qf);

        int answer = Integer.MAX_VALUE;
        boolean escapeSucc = false;
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(i == 0 || i == R - 1 || j == 0 || j == C - 1) {
                    if(jvisited[i][j] <= 0) continue;
                    if(jvisited[i][j] < fvisited[i][j] || fvisited[i][j] == 0) {
                        escapeSucc = true;
                        answer = answer > jvisited[i][j] ? jvisited[i][j] : answer;
                    }
                }
            }
        }

        if(!escapeSucc) bw.write("IMPOSSIBLE\n");
        else bw.write(answer + "\n");

        bw.flush();
        bw.close();
        br.close();
    }
}
