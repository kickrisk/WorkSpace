package com.sw;

import java.util.Arrays;
import java.util.Scanner;

public class Solution_D4_3234_준환이의양팔저울_오인호 {
	static int[] weight;
	static int N, ans;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int t=1; t<=T; t++) {
			N = sc.nextInt();
			weight = new int[N];
			for(int i=0; i<N; i++) {
				weight[i] = sc.nextInt();
			}
			ans = 0;
			Arrays.sort(weight);
			do {
				dfs(0,0,0);		
			} while(next_permutation());
			System.out.println("#" + t + " " + ans);
		}
	}
	private static boolean next_permutation() {
		int i = weight.length - 1;
		while(i > 0 && weight[i-1] >= weight[i]) i--;
		if(i <= 0) return false;
		int j = weight.length - 1;
		while(weight[i-1] >= weight[j]) j--;
		int temp = weight[i-1];
		weight[i-1] = weight[j];
		weight[j] = temp;
		int k = weight.length - 1;
		while(i < k) {
			temp = weight[i];
			weight[i] = weight[k];
			weight[k] = temp;
			i++; k--;
		}
		return true;
	}
	private static void dfs(int leftSum, int rightSum, int index) {
		if(index == N) {
		//오른쪽 위에 올라가있는 무게의 총합이 왼쪽에 올라가 있는 무게의 총합보다 커지지 않는 경우의 수
			if(rightSum <= leftSum) ans++; 
			return;
		}
		// 오른쪽이 왼쪽보다 커지면 안된다.
		if(rightSum + weight[index] <= leftSum) {
			dfs(leftSum, rightSum + weight[index], index + 1);
		}
		dfs(leftSum + weight[index], rightSum, index + 1);
		
	}

}
