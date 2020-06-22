package com.acmicpc;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_B6987_월드컵_오인호 {
	/**
	 * 6팀의 가능한 대진 표 
	 * 0 -> 1, 2, 3, 4, 5
	 * 1 -> 2, 3, 4, 5
	 * 2 -> 3, 4, 5
	 * 3 -> 4, 5
	 * 4 -> 5 
	 */
	static int d1[] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
	static int d2[] = { 1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5 };
	static int[][] result;
	static boolean flag;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();
		for(int t=0; t<4; t++) {
			result = new int[6][3];
			st = new StringTokenizer(br.readLine(), " ");
			int cnt = 0;
			for(int i=0; i<6; i++) {
				for(int j=0; j<3; j++) {
					int num = Integer.parseInt(st.nextToken());
					result[i][j] = num;
					cnt += num;
				}
			}
			flag = false;
			if(cnt == 30)
				go(0);
			sb.append(flag?1:0).append(" ");
		}
		System.out.println(sb.toString());
	}
	private static void go(int game) {
		if(game == 15) {
			int cnt = 0;
			for(int i=0; i<6; i++) {
				cnt = result[i][1] + result[i][1] + result[i][2]; 
			}
			if(cnt == 0) flag = true;
			return;                                                                                                       
		}
		int i = d1[game];
		int j = d2[game];
		if(result[i][0] > 0 && result[j][2] > 0) {
			result[i][0]--; result[j][2]--;
			go(game+1);
			result[i][0]++; result[j][2]++;
		}
		if(result[i][2] > 0 && result[j][0] > 0) {
			result[i][2]--; result[j][0]--;
			go(game+1);
			result[i][2]++; result[j][0]++;
		}
		if(result[i][1] > 0 && result[j][1] > 0) {
			result[i][1]--; result[j][1]--;
			go(game+1);
			result[i][1]++; result[j][1]++;
		}
	}
	
}
