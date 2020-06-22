package com.sw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_1953_탈주범검거_오인호 {
	static int[][] pipe;
	static int[][] map;
	static boolean[][] check;
	static int dx[] = { -1, 1, 0, 0};
	static int dy[] = { 0, 0, 1, -1};
	static {
		pipe = new int[7][];
		for(int i=0; i<7; i++) {
			switch(i) {
			case 0 : pipe[0] = new int[4]; pipe[0][0] = 0; pipe[0][1] = 1; pipe[0][2] = 2; pipe[0][3] = 3; break;
			case 1 : pipe[1] = new int[2]; pipe[1][0] = 0; pipe[1][1] = 1; break;
			case 2 : pipe[2] = new int[2]; pipe[2][0] = 2; pipe[2][1] = 3; break;
			case 3 : pipe[3] = new int[2]; pipe[3][0] = 0; pipe[3][1] = 2; break;
			case 4 : pipe[4] = new int[2]; pipe[4][0] = 1; pipe[4][1] = 2; break;
			case 5 : pipe[5] = new int[2]; pipe[5][0] = 1; pipe[5][1] = 3; break;
			default : pipe[6] = new int[2]; pipe[6][0] = 0; pipe[6][1] = 3; break;
			}
		}
	}
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
		for(int t=1; t<=T; t++) {
			st = new StringTokenizer(br.readLine(), " ");
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			int R = Integer.parseInt(st.nextToken());
			int C = Integer.parseInt(st.nextToken());
			int L = Integer.parseInt(st.nextToken());
			int ans = 0;
			map = new int[N][M];
			check = new boolean[N][M];
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(br.readLine(), " ");
				for(int j=0; j<M; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			int time = 1;
			Queue<Pair> q = new LinkedList<>();
			q.add(new Pair(R, C));
			check[R][C] = true; ans++;
			while(!q.isEmpty()) {
				if(time == L) break;
				int total = q.size();
				while(total-->0) {
					Pair tt = q.poll();
					int value = map[tt.x][tt.y] - 1;
					int size = pipe[value].length;
					for(int k=0; k<size; k++) {
						int dir = pipe[value][k];
						int nx = tt.x + dx[dir];
						int ny = tt.y + dy[dir];
						if(0<=nx && nx<N && 0<=ny && ny<M && map[nx][ny] != 0) {
							if(!check[nx][ny] && isOk(nx,ny,dir)) {
								q.add(new Pair(nx, ny));
								ans++;
								check[nx][ny] = true;
							}
						}
					}
				}
				time++;
			}
			System.out.println("#" + t + " " + ans);
		}
	}
	private static boolean isOk(int nx, int ny, int dir) {
		int value = map[nx][ny] - 1;
		int size = pipe[value].length;
		int correct = -1;
		switch(dir) {
		case 0 : correct = 1; break;
		case 1 : correct = 0; break;
		case 2 : correct = 3; break;
		case 3 : correct = 2; break;
		}
		for(int i=0; i<size; i++) {
			if(correct == pipe[value][i]) return true;
		}
		return false;
	}
	private static class Pair {
		int x, y;
		public Pair(int x, int y) {
			this.x = x; this.y = y;
		}
	}
}
