package com.acmicpc;

import java.util.Scanner;

public class Main_1699_제곱수의합_오인호 {
	private static int[] ans;
	private static final int MAX = 100001;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] ans = new int[MAX];
		
		for(int i=1; i<MAX; i++) {
			ans[i] = i;
			for(int j=1; j*j <= i; j++) {
				if(ans[i] > ans[i-j*j] + 1) {
					ans[i] = ans[i-j*j] + 1;
				}
			}
		}
		System.out.println(ans[N]);
	}

}
