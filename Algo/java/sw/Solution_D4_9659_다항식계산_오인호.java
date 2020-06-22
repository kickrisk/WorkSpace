package com.sw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_D4_9659_다항식계산_오인호 {
	private static int[] t = new int[51];
	private static int[] a = new int[51];
	private static int[] b = new int[51];
	private static long[] func;
	private static final long div = 998244353L;
	
	public static void main(String[] args) throws IOException {

		BufferedReader  br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
		for(int tc=1; tc<=T; tc++) {
			st = new StringTokenizer(br.readLine().trim());
			int N = Integer.parseInt(st.nextToken());
			
			func = new long[51];
			StringBuilder sb = new StringBuilder();
			
			for(int i=2; i <= N; i++) {
				st = new StringTokenizer(br.readLine(), " ");
				t[i] = Integer.parseInt(st.nextToken());
				a[i] = Integer.parseInt(st.nextToken());
				b[i] = Integer.parseInt(st.nextToken());
			}
			
			st = new StringTokenizer(br.readLine().trim());
			int M = Integer.parseInt(st.nextToken());
			sb.append("#" + tc + " ");
			st = new StringTokenizer(br.readLine(), " ");
			for(int i = 0; i<M; i++) {
				int x = Integer.parseInt(st.nextToken());
				func[0] = 1; func[1] = x;
				for(int j=2; j<=N; j++) {
					switch(t[j]) {
						case 1 :
							func[j] = (func[a[j]] + func[b[j]]) % div; 
							break;
								
						case 2 :
							func[j] = (a[j] * func[b[j]]) % div;
							break;

						case 3 :
							func[j] = (func[a[j]] * func[b[j]]) % div;
							break;
					}
				}
				sb.append(func[N]).append(" ");
			}
			System.out.println(sb);
		}
	}

}
