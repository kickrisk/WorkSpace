package com.acmicpc;

import java.util.Scanner;

public class Main_B18225_당구공을넣자_오인호 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int X = sc.nextInt();
		int Y = sc.nextInt();
		int P = sc.nextInt();
		int Q = sc.nextInt();
		boolean[][] check = new boolean[B+1][A+1];
		int tX = X;
		int tY = Y;
		int ans = 0;
		boolean flag = false;
		while(true) {
			// 무한이다 => 기존위치로 돌아왔다.
			System.out.println("X : " + tX + "\t" + "Y : " + tY);
			if(check[tY][tX])  {
				break;
			}
			check[tY][tX] = true;
			if(tX == 0 && tY == 0 || tX == 0 && tY == B || tX == A && tY == 0 || tX == A && tY == B) {
				ans++;
				flag = true;
				break;
			}
			
			int min = Math.min((Math.abs(A) - Math.abs(tX)) % P, (Math.abs(B) - Math.abs(tY)) % Q);
			if(A - min < 0) tX = Math.abs(A - min);
			else tX = A - min;
			if(B - min < 0) tY = Math.abs(B - min);
			else tY = B - min;
			System.out.println(min);
			ans++;
		}
		System.out.println(flag ? ans : -1);
	}

}
