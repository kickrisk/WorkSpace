package com.sw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Solution_4012_요리사_오인호 {

	static int map[][];
	static int N, ans;
	public static void main(String[] args) throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
	
		for(int t=1; t<=T; t++) {
			st = new StringTokenizer(br.readLine().trim());
			N = Integer.parseInt(st.nextToken());
			map = new int[N][N];
			ans = Integer.MAX_VALUE;
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(br.readLine(), " ");
				for(int j=0; j<N; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			LinkedList<Integer> a = new LinkedList<Integer>();
			LinkedList<Integer> b = new LinkedList<Integer>();
			getFind(0,a,b);
			System.out.println("#" + t + " " + ans);
		}
	}
	private static void getFind(int cnt, LinkedList<Integer> a, LinkedList<Integer> b) {

		if(cnt == N) {
			if(a.size() != N/2 || b.size() != N/2) return;
			int aSum = 0, bSum = 0;
			for(int i=0; i<N/2; i++) {
				for (int j = 0; j < N/2; j++) {
					if(i == j) continue;
					aSum += map[a.get(i)][a.get(j)];
					bSum += map[b.get(i)][b.get(j)];
				}
			}
			int result = aSum>bSum ? aSum-bSum : bSum-aSum;
			if(ans > result) ans = result;
		}
		if(a.size() > N/2 || b.size() > N/2) return;
		a.add(cnt);
		getFind(cnt+1, a, b);
		a.removeLast();
		b.add(cnt);
		getFind(cnt+1, a, b);
		b.removeLast();
	}

}
