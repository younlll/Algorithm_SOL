package BOJ_SOL.BOJ_SOL.solved_with_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

public class boj10026_G5_220207 {

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

        int N;
        N = Integer.parseInt(br.readLine());
        char[][] map = new char[N][N];
        boolean[][] visited1 = new boolean[N][N];
        boolean[][] visited2 = new boolean[N][N];
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, 1, 0, -1};

        for(int i = 0; i < N; i++) {
            String line = br.readLine();
            for(int j = 0; j < line.length(); j++) {
                map[i][j] = line.charAt(j);
            }
        }

        int[] answer = new int[2];
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(!visited1[i][j]) {
                    Queue<Pair> queue = new LinkedList<>();
                    queue.offer(new Pair(i, j));
                    visited1[i][j] = true;

                    while(!queue.isEmpty()) {
                        int cx = queue.peek().getX();
                        int cy = queue.peek().getY();
                        queue.poll();

                        for(int d = 0; d < 4; d++) {
                            int nx = cx + dx[d];
                            int ny = cy + dy[d];

                            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            if(visited1[nx][ny]) continue;
                            if(map[cx][cy] != map[nx][ny]) continue;

                            queue.offer(new Pair(nx, ny));
                            visited1[nx][ny] = true;
                        }
                    }

                    answer[0]++;
                }

                if(!visited2[i][j]) {
                    Queue<Pair> queue = new LinkedList<>();
                    queue.offer(new Pair(i, j));
                    visited2[i][j] = true;

                    while(!queue.isEmpty()) {
                        int cx = queue.peek().getX();
                        int cy = queue.peek().getY();
                        queue.poll();

                        for(int d = 0; d < 4; d++) {
                            int nx = cx + dx[d];
                            int ny = cy + dy[d];

                            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                            if(visited2[nx][ny]) continue;
                            if(map[cx][cy] == 'B' && map[cx][cy] != map[nx][ny]) continue;
                            if(map[cx][cy] != 'B' && map[nx][ny] == 'B') continue;

                            queue.offer(new Pair(nx, ny));
                            visited2[nx][ny] = true;
                        }
                    }

                    answer[1]++;
                }
            }
        }

        bw.write(answer[0] + " " + answer[1] + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
