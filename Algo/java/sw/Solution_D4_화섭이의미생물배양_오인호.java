package com.sw;

import java.util.Scanner;

public class Solution_D4_화섭이의미생물배양_오인호 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int t=1; t<=T; t++) {
			int S = sc.nextInt();     // start 
			int D = sc.nextInt();	  // end
			int A = sc.nextInt();	  // add +
			int B = sc.nextInt();	  // mul *
			
			if(B == 1) {
				if((D-S)%A == 0) {
					System.out.println("#" + t + " " + (D-S)%A);
				} else {
					System.out.println("#" + t + " " + -1);
				}
			} else {
				int ans = 0;
				while(S!=D) {
					if(D%B == 0) {
						if(D/B < S) {
							ans++;
							D-=A;
						} else {
							ans++;
							D/=B;
						}
					} else {
						ans++;
						D-=A;
					}
					if(S > D) {
						ans = -1;
						break;
					}
				}
				System.out.println("#" + t + " " + ans);
			}
		}
	}

}