package com.sw;

import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Solution_D4_1868_파핑파핑지뢰찾기_오인호 {

	static char[][] map;
	static int[][] map2;
	static boolean[][] check;
	static int[] dx = { 1, -1, 0, 0, 1, 1, -1, -1 };
	static int[] dy = { 0, 0, 1, -1, 1, -1, 1, -1 };

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			int N = sc.nextInt();
			map = new char[N][N];
			map2 = new int[N][N];
			check = new boolean[N][N];
			int ans = 0;
			for (int i = 0; i < N; i++) {
				String temp = sc.next();
				for (int j = 0; j < N; j++) {
					map[i][j] = temp.charAt(j);
				}
			}
			LinkedList<pair2> ll = new LinkedList<pair2>();
			PriorityQueue<pair2> q = new PriorityQueue<pair2>();
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (map[i][j] == '.') {
						int cnt = 0;
						for (int k = 0; k < 8; k++) {
							int ni = i + dx[k];
							int nj = j + dy[k];
							if (0 <= ni && ni < N && 0 <= nj && nj < N) {
								if (map[ni][nj] == '*') {
									cnt++;
								}
							}
						}
						map2[i][j] = cnt;
						if (cnt == 0)
							ll.add(new pair2(i, j, cnt));
					} else {
						map2[i][j] = -1;
					}
				}
			}
			for (int i = 0; i < ll.size(); i++) {
				pair2 temp = ll.get(i);
				if (check[temp.x][temp.y])
					continue;
				check[temp.x][temp.y] = true;
				q.add(temp);
				while (!q.isEmpty()) {
					pair2 p = q.poll();
					for (int k = 0; k < 8; k++) {
						int nx = p.x + dx[k];
						int ny = p.y + dy[k];
						if (0 <= nx && nx < N && 0 <= ny && ny < N) {
							if (map2[nx][ny] == 0 && !check[nx][ny]) {
								check[nx][ny] = true;
								q.add(new pair2(nx, ny, 0));
								continue;
							}
							if (map2[nx][ny] != -1 && !check[nx][ny]) {
								check[nx][ny] = true;
							}
						}
					}
				}

				ans++;
			}
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					if (check[j][k] == false && map2[j][k] != -1)
						ans++;
				}
			}
			System.out.println("#" + t + " " + ans);
		}

	}

}

class pair2 implements Comparable<pair2> {
	int x, y, cnt;

	public pair2(int x, int y, int cnt) {
		this.x = x;
		this.y = y;
		this.cnt = cnt;
	}

	@Override
	public int compareTo(pair2 o) {
		return o.cnt - this.cnt;
	}

}