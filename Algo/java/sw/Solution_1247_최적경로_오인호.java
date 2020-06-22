package com.sw;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_1247_최적경로_오인호 {
	

	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new  StringTokenizer(br.readLine());
		int T = Integer.parseInt(st.nextToken());
		
		for(int t=1; t<=T; t++) {
			st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			
			Point com = new Point(0,0) , home = new Point(0,0);;
			st = new StringTokenizer(br.readLine(), " ");
			for(int i=0; i<2; i++) {
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				if(i==0) com = new Point(x,y);
				else home = new Point(x,y);
			}
			
			Point[] cus = new Point[N];
			for(int i=0; i<N; i++) {
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				cus[i] = new Point(x,y);
			}
			
			// ������ ������ ���� �迭 ����
			int[] per = new int[N];
			for(int i=0; i<N; i++) {
				per[i] = i;
			}
			
			int ans = Integer.MAX_VALUE;
			
			// 10! = 300������ => ������ �̿��ؼ� �� ��!
			
			do {
				int temp = 0;
				temp += (abs(com.x-cus[per[0]].x) + abs(com.y-cus[per[0]].y));
				for(int i=0; i<N; i++) {
					if(i==N-1) {
						temp += abs(cus[per[i]].x-home.x) + abs(cus[per[i]].y-home.y); continue;
					}
					temp += abs(cus[per[i]].x-cus[per[i+1]].x) + abs(cus[per[i]].y-cus[per[i+1]].y);
				}
				if(ans > temp) ans = temp;
			}while(next_permutaion(per));
							
			System.out.println("#"+t+" "+ ans);
		}
		
	}
	private static boolean next_permutaion(int[] per) {
		int size = per.length;
		
		int j = -1;
		for(int i=size-1; i>0; i--) {
			if(per[i] > per[i-1]) {
				j = i-1;
				break;
			}
		}
		
		if(j==-1) return false;
		
		for(int i=size-1; i>=j+1; i--) {
			if(per[i] > per[j]) {
				int temp = per[i];
				per[i] = per[j];
				per[j] = temp;
				break;
			}
		}
		
		int i = size-1; j++;
		while(j<i) {
			int temp = per[i];
			per[i] = per[j];
			per[j] = temp;
			i--; j++;
		}

		return true;
	}
	static int abs(int x) {
		if(x>=0) return x;
		return -1*x;
	}

}
