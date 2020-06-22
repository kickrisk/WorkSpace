package com.sw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_5656_벽돌깨기_오인호 {

	static int[][] map;
	static int N, W, H, ans, total;
	static int[] dx = { 1, -1, 0, 0 };
	static int[] dy = { 0, 0, 1, -1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine(), " ");
			N = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			H = Integer.parseInt(st.nextToken());
			map = new int[H][W];
			int[][] memo = new int[H][W];
			total = 0;
			int[] how = new int[N + 1];
			for (int i = 0; i < H; i++) {
				st = new StringTokenizer(br.readLine(), " ");
				for (int j = 0; j < W; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
					if (map[i][j] != 0)
						total++;
				}
			}
			ans = -1;
			// ���� ������ �μŹ��� ��
			for (int k = 0; k < W; k++) {
				for (int i = 0; i < H; i++) {
					for (int j = 0; j < W; j++) {
						memo[i][j] = map[i][j];
					}
				}
				Queue<pair> q = new LinkedList<pair>();
				how[1] = k;
				go(0, k, memo, q, 0, how);
			}
			System.out.println("#" + t + " " + ans);
		}
	}

	private static void go(int x, int y, int[][] memo, Queue<pair> q, int n, int[] how) {
		if (ans == 0)
			return;
		if (n == N) {
			int cnt = 0;
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					if (memo[i][j] != 0) {
						cnt++;
					}
				}
			}
			if (ans == -1 || ans > cnt)
				ans = cnt;
			return;
		}
		int[][] memo2 = new int[H][W];
		getMap(memo, memo2);
		int i = 0;
		while (true) {
			if (i >= H)
				break;
			if (memo2[i][y] != 0) {
				q.add(new pair(i, y));
				break;
			}
			i++;
		}
		while (!q.isEmpty()) {
			pair p = q.poll();
			int size = memo2[p.x][p.y];
			memo2[p.x][p.y] = 0;
			while (size-- > 0) {
				for (int k = 0; k < 4; k++) {
					int nx = p.x + dx[k] * size;
					int ny = p.y + dy[k] * size;
					if (0 <= nx && nx < H && 0 <= ny && ny < W) {
						if (memo2[nx][ny] == 0)
							continue;
						if (memo2[nx][ny] > 1)
							q.add(new pair(nx, ny));
						else
							memo2[nx][ny] = 0;
					}
				}
			}
		}
		setMap(memo2);
		for (int j = 0; j < W; j++) {
			how[n + 1] = j;
			go(0, j, memo2, q, n + 1, how);
			how[n + 1] = 0;
		}
	}

	private static void getMap(int[][] memo, int[][] memo2) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				memo2[i][j] = memo[i][j];
			}
		}
	}

	private static void setMap(int[][] memo) {
		for (int j = 0; j < W; j++) {
			for (int i = H - 2; i >= 0; i--) {
				if (memo[i][j] != 0) {
					int temp = 1;
					while (i + temp < H && memo[i + temp][j] == 0) {
						memo[i + temp][j] = memo[i + temp - 1][j];
						memo[i + temp - 1][j] = 0;
						temp++;
					}
				}
			}
		}
	}
}

class pair {
	int x, y;

	public pair(int x, int y) {
		this.x = x;
		this.y = y;
	}
}