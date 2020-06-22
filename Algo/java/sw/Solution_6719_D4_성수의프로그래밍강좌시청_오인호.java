package com.sw;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Solution_6719_D4_성수의프로그래밍강좌시청_오인호 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int t=1; t<=T; t++) {
			double ans = 0.0;
			int N = sc.nextInt();
			int K = sc.nextInt();
			
			List<Integer> list = new ArrayList<Integer>();
			
			for(int i=0; i<N; i++) {
				list.add(sc.nextInt());
			}
			
			Collections.sort(list);
			
			int size = list.size();
			list = list.subList(size-K, size);
			int index = 0;
			while(index<K) {
				ans = (ans + list.get(index)) / 2;
				index++;
			}
			System.out.println("#" + t + " " + ans);
		}
		sc.close();
	}
}
