package com.acmicpc;
/**
 * DFS
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main_2206_벽부수고이동하기_오인호2 {
	static int[] dx = { 1, -1, 0, 0};
	static int[] dy = { 0, 0, 1, -1};
	static int[][] map;
	static int N, M, ans;
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		for(int i=0; i<N; i++) {
			String temp = br.readLine();
			for (int j = 0; j < M; j++) {
				map[i][j] = temp.charAt(j) - '0';
			}
		}
		ans = -1;
		go(0,0,0,1);
		System.out.println(ans);
	}
	private static void go(int x, int y, int w, int c) {
		if(x == N-1 && y == M-1) {
			if(ans == -1 || ans > c) {
				ans = c;
			}
			return;
		}
		for(int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= N || ny >= M || nx < 0 || ny < 0) continue;
			if(map[nx][ny] == 1) {
				if(w == 1) continue;
				else go(nx,ny,w+1,c+1);
			} else go(nx,ny,w,c+1);
		}
	}

}
