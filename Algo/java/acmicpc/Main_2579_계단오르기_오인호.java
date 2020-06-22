package com.acmicpc;
/**
 * Memory : 14616KB
 * Time : 120ms
 */
import java.util.Scanner;

public class Main_2579_계단오르기_오인호 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] stair = new int[N];
		int[][] ans = new int[N][2];
		for(int i=0; i<N; i++) {
			stair[i] = sc.nextInt();
		}
		for(int i=0; i<N; i++) {
			if(i==0) {
				ans[i][1] = stair[i];
			} else if(i==1) {
				ans[i][0] = stair[i];
				ans[i][1] = stair[i-1] + stair[i];
			} else {
				ans[i][0] = Math.max(ans[i-2][1],ans[i-2][0]) + stair[i];
				ans[i][1] = ans[i-1][0] + stair[i];
			}
		}
		System.out.println(Math.max(ans[N-1][0], ans[N-1][1]));
	}

}
