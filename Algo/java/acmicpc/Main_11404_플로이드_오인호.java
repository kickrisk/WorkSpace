package com.acmicpc;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_11404_플로이드_오인호 {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		int N = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine().trim());
		int M = Integer.parseInt(st.nextToken());
		int[][] map = new int[N][N];
		for(int i=0; i<N; i++) {
			for (int j = 0; j < N; j++) {
				if(i == j) continue;
				map[i][j] = 1000000000;
			}
		}
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int w= Integer.parseInt(st.nextToken());
			if(map[a-1][b-1] == 0) map[a-1][b-1] = w;
			else map[a-1][b-1] = (int)Math.min(map[a-1][b-1], w);
		}
		
		for(int k=0; k<N; k++) {
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(map[i][j] > map[i][k] + map[k][j]) {
						map[i][j] = map[i][k] + map[k][j];
					}
				}
			}
		}
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				System.out.print(map[i][j] + " ");
			}
			System.out.println();
		}

	}

}