package com.acmicpc;

import java.util.Scanner;

public class Main_11727_2xN타일링2_오인호 {

	static int[] memo = new int[1001];
	static int N;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		memo[1] = 1; memo[2] = 3; memo[3] = 5;
		System.out.println(go(N)%10007);
	}
	private static int go(int n) {
		if(n == 1) return 1;
		if(n == 2) return 3;
		if(n == 3) return 5;
		if( memo[n] != 0) return memo[n];
		else return memo[n] = (go(n-1) + 2 * go(n-2)) % 10007;
	}
	

}
