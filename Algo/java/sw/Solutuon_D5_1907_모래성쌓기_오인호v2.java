package com.sw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solutuon_D5_1907_모래성쌓기_오인호v2 {

	static int[] dx = { 1, -1, 0, 0, 1, 1, -1, -1 };
	static int[] dy = { 0, 0, 1, -1, 1, -1, 1, -1 };
	static int[][] map;
	static int[][] map2;
	static Queue<Sand> q;

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
	    StringTokenizer st;
	        
		for (int t = 1; t <= T; t++) {
			int ans = 0;
			st = new StringTokenizer(br.readLine());
			int H = Integer.parseInt(st.nextToken());
			int W = Integer.parseInt(st.nextToken());

			map = new int[H][W];
			map2 = new int[H][W];

			q = new LinkedList<Sand>();

			for (int i = 0; i < H; i++) {
				st = new StringTokenizer(br.readLine());
                String str = st.nextToken();
				for (int j = 0; j < W; j++) {
					char temp = str.charAt(j);
					if (temp != '.') {
						map[i][j] = temp - '0';
					} 
				}
			}
			
			for (int i = 1; i < H-1; i++) {
				for (int j = 1; j < W-1; j++) {
					for (int k = 0; k < 8; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (0 <= nx && nx < H && 0 <= ny && ny < W) {
							if(map[nx][ny] == 0) map2[i][j]++;
						}
					}
					if(map[i][j] != 0 && map[i][j] <= map2[i][j])
						q.add(new Sand(i,j));
				}
			}

			while (!q.isEmpty()) {
				ans++;
				int size = q.size();
				while (size-- > 0) {
					Sand p = q.poll();
					for (int k = 0; k < 8; k++) {
						int nx = p.x + dx[k];
						int ny = p.y + dy[k];
						if (0 <= nx && nx < H && 0 <= ny && ny < W) {
							if (map[nx][ny] > map2[nx][ny]) {
								map2[nx][ny]++;
							} else
								continue;

							if (map[nx][ny] != 0 && map[nx][ny] <= map2[nx][ny]) {
								q.add(new Sand(nx, ny));
							}
						}
					}
				}
			}
			System.out.println("#" + t + " " + ans);
		}
	}

}

class Sand {
	int x, y;

	public Sand(int x, int y) {
		this.x = x;
		this.y = y;
	}
}