package com.sw;

import java.util.Scanner;

public class Solution_D4_7699_수지의수지맞는여행_오인호 {

	static int R, C, ans = -1;
	static char[][] map;
	static int[] dx = { 1, -1, 0, 0};
	static int[] dy = { 0, 0, 1, -1};
	static boolean[] check;
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int t=1; t<=T; t++) {
			
			ans = -1;
			R = sc.nextInt();
			C = sc.nextInt();
			map = new char[R][C];
			check = new boolean[26];
			
			for(int i=0; i<R; i++) {
				String str = sc.next();
				for(int j=0; j<C;j++) {
					map[i][j] = str.charAt(j);
				}
			}
			check[map[0][0]-'A'] = true;
			dfs(0,0,1);
			System.out.println("#" + t + " " + ans);
		}
	}

	private static void dfs(int r, int c, int cnt) {

		for(int k=0; k<4; k++) {
			int nr = r + dx[k]; 
			int nc = c + dy[k];
			if(0 <= nr && nr < R && 0 <= nc && nc < C) {
				if(check[map[nr][nc]-'A'] == false) {
					check[map[nr][nc]-'A'] = true;
					dfs(nr,nc,cnt+1);
					check[map[nr][nc]-'A'] = false;
				}
			}
		}
		if(ans<cnt) ans = cnt;
		return;
	}

}
