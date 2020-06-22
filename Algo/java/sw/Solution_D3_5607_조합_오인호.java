package com.sw;

import java.util.Scanner;

public class Solution_D3_5607_조합_오인호 {

	static final long pVal = 1234567891;
	static long fac[]; // fac(n)
	static long invFac[]; // 1/fac(n)
	static {
		// 전처리 단계
		fac = new long[1000001];
		invFac = new long[1000001];

		// factorial
		fac[0] = 1;
		for (int i = 1; i <= 1000000; i++) {
			fac[i] = (fac[i - 1] * i) % pVal;
		}

		/*
		 * invFac 구하기 페르마 소정리 => a^(p-1) = 1 단, a는 정수 p는 소수 (즉, a와 p는 서로수) 일때 성립, 따라서,
		 * a^(p-2) = 1/a 1/fac[1000000] = fac[1000000]^p-2 => 페르마 소정리, 이때는 fac[1000000]
		 * = a (왜냐 fac[1000000]또한 어떠한 정수가 될것이며 pVal 1234567891이 소수이므로 성립)
		 */
		invFac[1000000] = power(fac[1000000], pVal - 2);

		// inverse_factorial => 1/n! * n = 1/n-1!
		for (int i = 1000000 - 1; i >= 0; i--) {
			invFac[i] = (invFac[i + 1] * (i + 1)) % pVal;
		}

	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int t = 1; t <= T; t++) {
			int N = sc.nextInt();
			int R = sc.nextInt();
			long ans = 0;
			ans = (fac[N] * invFac[N - R]) % pVal;
			ans = (ans * invFac[R]) % pVal;
			System.out.println("#" + t + " " + ans);
		}
	}

	private static long power(long l, long m) {
		if(m == 1) return l;
		else {
			if(m % 2 == 0) {
				return power(l*l%pVal,m/2);
			} else {
				return (power(l*l%pVal,m/2) * l) % pVal;
			}
		}
	}
	
	
//	private static long power(long x, long y) {
//		long ret = 1;
//		while (y > 0) {
//			// 홀수면 2번 곱해야하므로 한 번 더 추가
//			if (y % 2 != 0) {
//				ret *= x;
//				ret %= pVal;
//			}
//			x *= x;
//			x %= pVal;
//			y /= 2;
//		}
//		return ret;
//	}

}
