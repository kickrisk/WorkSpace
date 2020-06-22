package com.sw;

import java.util.Scanner;
//dfs 2 개 
public class Solution_D4_5643_키순서_오인호 {
	static int N, M, cnt, result;
	static int[][] map;
	static boolean[] v;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int t=1; t<=T; t++) {
			result = 0;
			N = sc.nextInt();
			M = sc.nextInt();
			map = new int[N+1][N+1];
			for(int i=0; i<M; i++) {
				int x = sc.nextInt();
				int y = sc.nextInt();
				map[x][y] = 1;
			}
			for(int i=1; i<=N; i++) {
				cnt = 0;
				v = new boolean[N+1];
				dfs(i);

				v = new boolean[N+1];
				dfs1(i);
				if(cnt == N-1) result++;
			}
			System.out.println("#" + t + " "  + result);
		}
	}
	private static void dfs1(int idx) {
		v[idx] = true;
		for(int i=1; i<=N; i++) {
			if(v[i]) continue;
			if(map[i][idx] == 1) {
				cnt++;
				dfs1(i);
			}
		}
	}
	private static void dfs(int idx) {
		v[idx] = true;
		for(int i=1; i<=N; i++) {
			if(v[i]) continue;
			if(map[idx][i] == 1) {
				cnt++;
				dfs(i);
			}
		}
	}

}
