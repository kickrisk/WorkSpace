package com.sw;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Solution_D5_7793_오나의여신님_오인호 {

	static int[] dx = { 1, -1, 0, 0};
	static int[] dy = { 0, 0, 1, -1};
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int t=1; t<=T; t++) {
			
			int N = sc.nextInt();
			int M = sc.nextInt();
			char[][] map = new char[N][M];
			
			char temp = '0';
			Queue<point> sq = new LinkedList<point>();
			Queue<point> dq = new LinkedList<point>();
			
			for(int i=0; i<N; i++) {
				String str = sc.next();
				for(int j=0; j<M; j++) {
					temp = str.charAt(j);
					map[i][j] = temp;
					if(temp == '*') { 
						dq.add(new point(i,j));
					} else if(temp == 'S') {
						sq.add(new point(i,j));
					}
				}
			}
			
			int ans = -1;
			int time = 0;
			L:while(!sq.isEmpty()) {
				time++;
				int sizeD = dq.size();
				int sizeS = sq.size();
				
				while(sizeD-->0) {
                    point d = dq.poll();
					for(int k=0; k<4; k++) {
						int nx = d.x + dx[k];
						int ny = d.y + dy[k];
						if(0<=nx && nx<N && 0<=ny && ny<M) {
							if(map[nx][ny] == '.' || map[nx][ny] =='S') {
								map[nx][ny] = '*';
								dq.add(new point(nx,ny));
							}
						}
					}
				}
				while(sizeS-->0) {
                    		point s = sq.poll();
					for(int k=0; k<4; k++) {
						int nx = s.x + dx[k];
						int ny = s.y + dy[k];
						if(0<=nx && nx<N && 0<=ny && ny<M) {
							if(map[nx][ny] =='.') {
								map[nx][ny] = 'S';
								sq.add(new point(nx,ny));
							} else if(map[nx][ny] == 'D') {
								ans = time;
								break L;
							}
						}
					}
				}
			}
			if(ans == -1) 
				System.out.println("#" + t + ' ' + "GAME OVER");
			else System.out.println("#" + t + ' ' + ans);

		}
	}

}
class point {
	int x, y;
	public point(int x, int y) {
		this.x = x; this.y = y;
	}
}