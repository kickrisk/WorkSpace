package com.sw;

import java.util.Scanner;
// ING
public class Solution_D4_4530_극한의청소작업_오인호 {
	private static long[] stair;
	//							 	 1	 2		3	 4		5	  	6			7	   		8			9			10			11				112
	private static long[] pow =  { 1, 10, 100, 1000, 10000, 100000, 1000000, 	10000000, 100000000, 1000000000L, 10000000000L, 100000000000L, 1000000000000L };
	private static long temp = 0;
	static {
		stair = new long[13];
		for(int i=1; i<=12; i++) {
			if(i==1) {
				stair[i] = 1;
			} else {
				long temp = pow[i-1];
				temp += 9 * stair[i-1];
				stair[i] = temp;
			}
		}
		
	}
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int t=1; t<=T; t++) {
			long A = sc.nextLong();
			long B = sc. nextLong();
			temp = 0;
			if( A < 0 )	{
				if( (long)Math.abs(A) < 10)	{
					if( (long)Math.abs(A) >= 4){
						A = (long)Math.abs(A) - 2; 
					} else A = (long)Math.abs(A) -1;
				} else A = cal(String.valueOf(-1*A)) - 2;
				temp = 0;
				if( B < 10)	{
					if( B >= 4) B = B-2;
					else B = B-1;
				} else B = cal(String.valueOf(B)) - 2;
				System.out.println("#" + t + " " + (long)(A+B+1));
			}
			else {
				if( A < 10)	{
					if( A >= 4) A = A-1;
				} else A = cal(String.valueOf(A)) - 1;
				temp = 0;
				if( B < 10)	{
					if( B >= 4) B = B-1;
				} else B = cal(String.valueOf(B)) - 1;
				System.out.println("#" + t + " " + (long)(B-A));
			}
		}
	}
	private static long cal(String val) {
		int size = val.length() - 1;
		long cur = Long.parseLong(val);
		if(size == 0) {
			for(int i=0; i<= cur; i++) {
				if(i == 4) continue;
				else temp++;
			}
			return temp;
		}
		int cnt = (int)(cur / pow[size]);

		// 사이즈 만큼 더해주기
		for(int i = 0; i<cnt; i++) {
			if(i == 4) {
				continue;
			}
//			if(i == 0 || i == cnt-1) temp += pow[size] -1;
			else temp += pow[size];
			temp -= stair[size];
		}
		
		// 4자리수면 3자리수 까지는 더하고 뺐으니까 1000 ~ 들어온 수까지 값만 더 구해주면 됨
		if(cur / pow[size] != 4) return cal(String.valueOf(cur - cnt * pow[size]));
		return temp;
	}

}
