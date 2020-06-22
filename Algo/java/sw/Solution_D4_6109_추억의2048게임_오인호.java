package com.sw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_D4_6109_추억의2048게임_오인호 {
	static int dx[] = { 1, -1, 0, 0};
	static int dy[] = { 0, 0, 1, -1};
	static int[][] map;
	static boolean[][] check;
	static int N, S;
	static boolean ok;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
		for(int t=1; t<=T; t++) {
			st = new StringTokenizer(br.readLine(), " ");
			N = Integer.parseInt(st.nextToken());
			S = sw(st.nextToken());
			map = new int[N][N];
			check = new boolean[N][N];
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(br.readLine(), " ");
				for (int j = 0; j < N; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			while(true) {
				ok = false;
				go();
				if(!ok) break;
			}
			System.out.println("#" + t);
			for(int i=0; i<N; i++) {
				for (int j = 0; j < N; j++) {
					System.out.print(map[i][j] + " ");
				}
				System.out.println();
			}
		}
	}
	private static void go() {
		switch(S) {
		case 0 :
			for(int i=N-2; i>=0; i--) {
				for(int j=0; j<N; j++) {
					if(map[i][j] == 0) continue;
					if(map[i+1][j] == 0) {
						map[i+1][j] = map[i][j];
						check[i+1][j] = check[i][j];
						check[i][j] = false;
						map[i][j] = 0;
						ok = true;
					} else if(!check[i+1][j] && !check[i][j] && map[i+1][j] == map[i][j]) {
						map[i+1][j] *= 2;
						map[i][j] = 0;
						check[i+1][j] = true;
						ok = true;
					}
				}
			}
			break;
		case 1 :
			for(int i=1; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(map[i][j] == 0) continue;
					if(map[i-1][j] == 0) {
						map[i-1][j] = map[i][j];
						check[i-1][j] = check[i][j];
						check[i][j] = false;
						map[i][j] = 0;
						ok = true;
					} else if(!check[i-1][j] && !check[i][j] && map[i-1][j] == map[i][j]) {
						map[i-1][j] *= 2;
						map[i][j] = 0;
						check[i-1][j] = true;
						ok = true;
					}
				}
			}
			break;
		case 2 :
			for(int i=0; i<N; i++) {
				for(int j=N-2; j>=0; j--) {
					if(map[i][j] == 0) continue;
					if(map[i][j+1] == 0) {
						map[i][j+1] = map[i][j];
						check[i][j+1] = check[i][j];
						check[i][j] = false;
						map[i][j] = 0;
						ok = true;
					} else if(!check[i][j+1] && !check[i][j] && map[i][j+1] == map[i][j]) {
						map[i][j+1] *= 2;
						map[i][j] = 0;
						check[i][j+1] = true;
						ok = true;
					}
				}
			}
			break;
		case 3 :
			for(int i=0; i<N; i++) {
				for(int j=1; j<N; j++) {
					if(map[i][j] == 0) continue;
					if(map[i][j-1] == 0) {
						map[i][j-1] = map[i][j];
						check[i][j-1] = check[i][j];
						check[i][j] = false;
						map[i][j] = 0;
						ok = true;
					} else if(!check[i][j-1] && !check[i][j] && map[i][j-1] == map[i][j]) {
						map[i][j-1] *= 2;
						map[i][j] = 0;
						check[i][j-1] = true;
						ok = true;
					}
				}
			}
			break;
		}
		
	}
	private static int sw(String nextToken) {
		switch(nextToken) {
			case "left" : return 3;
			case "right" : return 2;
			case "up" : return 1;
			case "down" : return 0;
		}
		return 0;
	}

}
