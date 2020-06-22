package com.sw;

import java.util.Scanner;

public class Solution_D4_4366_정식이의은행업무 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			String str = sc.next();
			long sum2 = 0, sum3 = 0;
			int size2 = str.length();
			int[] two = new int[size2];
			for (int i = 0; i < size2; i++) {
				two[size2 - 1 - i] = str.charAt(i) - '0';
				sum2 |= (str.charAt(i) - '0') << (size2 - 1 - i);
			}
			str = sc.next();
			int size3 = str.length();
			int[] three = new int[str.length()];
			for (int i = 0; i < size3; i++) {
				three[size3 - 1 - i] = str.charAt(i) - '0';
				sum3 += (long) Math.pow(3, size3 - 1 - i) * (str.charAt(i) - '0');
			}
			long dis = sum3 - sum2;
			long ans = 0;
			if (dis >= 0) {
				long temp = 0;
				L: for (int i = 0; i < size3; i++) {
					for (int j = 0; j < 3; j++) {
						if (three[i] != j) {
							temp = sum3 - (long) Math.pow(3, i) * (three[i]) + (long) Math.pow(3, i) * (j);
							for (int k = 0; k < size2; k++) {
								long tt = sum2 ^ 1 << k;
								if (tt == temp) {
									ans = tt;
									break L;
								}
							}
						}
					}
				}
			} else {
				long temp = 0;
				L: for (int i = 0; i < size2; i++) {
					long tt = sum2 ^ 1 << i;
					for (int k = 0; k < size3; k++) {
						for (int l = 0; l < 3; l++) {
							if (three[k] != l) {
								temp = sum3 - (long) Math.pow(3, k) * (three[k]) + (long) Math.pow(3, k) * (l);
								if (temp == tt) {
									ans = temp;
									break L;
								}
							}
						}
					}
				}
			}
			System.out.println("#" + t + " " + ans);
		}
	}

}
