package com.acmicpc;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_B2468_안전영역_오인호 {
	static int[] dx = { 1, -1, 0, 0};
	static int[] dy = { 0, 0, 1, -1};
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		int N = Integer.parseInt(st.nextToken());
		int max = 0, ans = 0;
		int map[][] = new int[N][N];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j=0; j<N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				max = Math.max(max, map[i][j]);
			}
		}
		Queue<Pair> q = new LinkedList<>();
		for(int k=0; k<max; k++) {
			q.clear();
			int num = 0;
			boolean[][] c = new boolean[N][N];
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(map[i][j] > k && !c[i][j]) {
						q.add(new Pair(i, j));		
						c[i][j] = true;
						while(!q.isEmpty()) {
							Pair t = q.poll();
							for(int l=0; l<4; l++) {
								int nx = t.x + dx[l];
								int ny = t.y + dy[l];
								if(0<=nx&&nx<N && 0<=ny && ny<N) {
									if(map[nx][ny] > k && !c[nx][ny]) {
										c[nx][ny] = true;
										q.add(new Pair(nx, ny));
									}
								}
							}
						}
						num++;
					}
				}
			}
			ans = Math.max(ans, num);
		}
		System.out.println(ans);
	}
	private static class Pair {		
		int x, y;
		public Pair(int x, int y) {
			this.x = x; this.y = y;
		}
	}
}
