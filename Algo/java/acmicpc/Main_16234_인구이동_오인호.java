package com.acmicpc;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main_16234_인구이동_오인호 {
	static int[] dx = { 1, -1, 0, 0};
	static int[] dy = { 0, 0, 1, -1};
	static int N,L,R,p,ans;
	static int[][] map, copy;
	static boolean[][] check;
	static Queue<Pair16234> q = new LinkedList<>();
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		L = sc.nextInt();
		R = sc.nextInt();
		map = new int[N][N];
		copy = new int[N][N];
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		ans = 0;
		while(true) {
			check = new boolean[N][N];
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					copy[i][j] = -1;
				}
			}
			p = 0;
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(copy[i][j] == -1) {
						q.add(new Pair16234(i, j));
						bfs();
					}
				}
			}
			if(p == 0) break;
			else ans++;
		}
		System.out.println(ans);
	}
	private static void bfs() {
		Pair16234 t = q.peek();
		long sum = map[t.x][t.y];
		boolean ok = false;
		int cnt = 1;
		while(!q.isEmpty()) {
			t = q.poll();
			for(int k=0; k<4; k++) {
				int nx = t.x + dx[k]; int ny = t.y + dy[k];
				if( 0<=nx && nx < N && 0<= ny && ny < N) {
					if(Math.abs(map[t.x][t.y] - map[nx][ny]) <= R && Math.abs(map[t.x][t.y] - map[nx][ny]) >= L && copy[nx][ny] == -1 ) {
						q.add(new Pair16234(nx, ny));
						copy[nx][ny] = copy[t.x][t.y] = 1;
						cnt++;
						sum+=map[nx][ny];
						ok = true;
					}
				}
			}
		}
		if(ok) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if(copy[i][j] != -1 && !check[i][j]) {
						map[i][j] = (int) (sum/cnt);
						check[i][j] = true;
					}
					
				}
			}
			p+=1;
		}
	}
}
class Pair16234 {
	int x , y;
	public Pair16234(int x, int y) {
		this.x = x; this.y = y;
	}
}