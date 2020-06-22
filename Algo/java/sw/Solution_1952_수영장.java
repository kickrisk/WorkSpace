package com.sw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_1952_수영장{
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int T = Integer.parseInt(st.nextToken());
		for (int t = 1; t <= T; t++) {
			
			int[] map = new int[13]; // 1�� ���� �ʱ�ȭ
			int[] pay = new int[4];
			int[] ans = new int[13]; // �޸������̼��� ���� �� ���ϱ�
			int[] month = new int[13]; // �ش� �޿� �����ϴ� ����
			
			st = new StringTokenizer(br.readLine(), " ");
			for(int i=0; i<4; i++) {
				pay[i] = Integer.parseInt(st.nextToken());
			}
			
			st = new StringTokenizer(br.readLine(), " ");
			for(int i=1; i<13; i++) {
				month[i] = Integer.parseInt(st.nextToken());
			}
			
			for(int i=1; i<=12; i++) {
				map[i] = Math.min(month[i]*pay[0], pay[1]);
			}
			
			for(int i=1; i<=12; i++) {
				ans[i] = ans[i-1] + map[i];
				if(i-3>=0) {
					if(ans[i] > ans[i-3] + pay[2]) {
						ans[i] = ans[i-3] + pay[2];
					}
				}
			}
			if(ans[12] > pay[3]) ans[12] = pay[3];
			System.out.println("#" + t + " " + ans[12]);
		}

	}
}
