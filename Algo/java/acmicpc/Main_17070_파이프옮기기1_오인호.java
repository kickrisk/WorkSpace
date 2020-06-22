package com.acmicpc;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_17070_파이프옮기기1_오인호 {
	/**
	 * 1 : 가로 => 가로, 대각선 2 : 세로 => 세로, 대각선 3 : 대각선 => 가로, 세로, 대각선
	 */
	private static int[][] map;
	private static int N, ans;
	private static long[][][] count;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		N = Integer.parseInt(st.nextToken());
		map = new int[N + 1][N + 1];
		count = new long[N + 1][N + 1][4];
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 1; j <= N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		ans = 0;
		map[1][1] = map[1][2] = 1;
		count[1][1][1] = count[1][2][1] = 1;
		dfs(1, 2, 1, 1);
		System.out.println(ans);
		System.out.println(count[N][N][1]);
		System.out.println(count[N][N][2]);
		System.out.println(count[N][N][3]);
	}

	private static long dfs(int x, int y, int t, int cnt) {
		if (x == N && y == N) {
			return cnt;
		}
		if (t == 1) {
			// 가로방향일때
			// 1. 가로로 놓는법
			if ( y + 1 <= N && map[x][y + 1] == 0) {
				if(count[x][y+1][1] != 0) return count[x][y+1][1];
				else if(count[x][y+1][1] == 0) count[x][y+1][1] = dfs(x, y + 1, t, cnt + 1);
			}
			// 2. 대각선으로 놓는법
			if (x + 1 <= N && y + 1 <= N && map[x][y + 1] + map[x + 1][y + 1] + map[x + 1][y] == 0) {
				if(count[x + 1][y + 1][3] != 0) return count[x + 1][y + 1][3];
				else if(count[x+1][y+1][3] == 0) count[x + 1][y + 1][3] = dfs(x + 1, y + 1, 3, cnt + 1);
			}
		} else if (t == 2) {
			// 세로방향일때
			// 1. 세로로
			if (x + 1 <= N && map[x + 1][y] == 0 ) {
				if(count[x + 1][y][2] != 0) return count[x + 1][y][2];
				else if(count[x+1][y][2] == 0) count[x + 1][y][2] = dfs(x + 1, y, t, cnt + 1);
			}
			// 2. 대각선으로 놓는법
			if (x + 1 <= N && y + 1 <= N && map[x][y + 1] + map[x + 1][y + 1] + map[x + 1][y] == 0) {
				if(count[x + 1][y + 1][3] != 0) return count[x + 1][y + 1][3];
				else if(count[x+1][y+1][3] == 0) count[x + 1][y + 1][3] = dfs(x + 1, y + 1, 3, cnt + 1);
			}
		} else {
			// 대각선
			// 1. 가로로 놓는법
			if ( y + 1 <= N && map[x][y + 1] == 0) {
				if(count[x][y+1][1] != 0) return count[x][y+1][1];
				else if(count[x][y+1][1] == 0) count[x][y+1][1] = dfs(x, y + 1, 1, cnt + 1);
			}
			// 2. 대각선으로 놓는법
			if (x + 1 <= N && y + 1 <= N && map[x][y + 1] + map[x + 1][y + 1] + map[x + 1][y] == 0) {
				if(count[x + 1][y + 1][3] != 0) return count[x + 1][y + 1][3];
				else if(count[x+1][y+1][3] == 0) count[x + 1][y + 1][3] = dfs(x + 1, y + 1, t, cnt + 1);
			}
			// 3. 세로로
			if (x + 1 <= N && map[x + 1][y] == 0 ) {
				if(count[x + 1][y][2] != 0) return count[x + 1][y][2];
				else if(count[x+1][y][2] == 0) count[x + 1][y][2] = dfs(x + 1, y, 2, cnt + 1);
			}

		}
		return -1;
	}

}
