package com.sw;

import java.util.Scanner;
//����ư �Ÿ� �˰��� ����!
public class Solution_D4_8382_방향전환_오인호 {

	static int X, Y, XX, YY;

	public static void main(String[] args) {

			Scanner sc = new Scanner(System.in);
		
			int T = sc.nextInt();
			for(int t=1; t<=T; t++) {
				
				X = sc.nextInt(); 
				Y = sc.nextInt();
				XX = sc.nextInt();
				YY = sc.nextInt();
				int x = abs(X-XX);
				int y = abs(Y-YY);
				int ans = 0;
	            if((x + y)%2 == 0) {
	             	   ans = 2 * (x > y ? x : y);
	            } else {
	            	ans = 2 * (x > y ? x : y) - 1;
	            }
				System.out.println("#" + t + " " + ans);
			
			}
		}

	private static int abs(int i) {
		if (i < 0)
			return -1 * i;
		return i;
	}
}