package com.acmicpc;

import java.util.Scanner;

// floyd-warthal
public class Main_B2458_키순서_오인호 {
	static int N, M, cnt, result;
	static int[][] map;
	static int INF = 123456789;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		result = 0;
		N = sc.nextInt();
		M = sc.nextInt();
		map = new int[N + 1][N + 1];
		for (int i = 0; i < N + 1; i++) {
			for (int j = 0; j < N + 1; j++) {
				map[i][j] = INF;
			}
		}
		for (int i = 0; i < M; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			map[x][y] = 1;
		}
		for (int k = 1; k < N + 1; k++) {
			for (int i = 1; i < N + 1; i++) {
				for (int j = 1; j < N + 1; j++) {
					map[i][j] = Math.min(map[i][j], map[i][k] + map[k][j]);
				}
			}
		}
		for (int i = 1; i < N + 1; i++) {
			cnt = 0;
			for (int j = 1; j < N + 1; j++) {
				if (i == j)
					continue;
				if (map[i][j] < INF)
					cnt++;
				if (map[j][i] < INF)
					cnt++;
			}
			if (cnt == N - 1)
				result++;
		}
		System.out.println(result);
	}

}
