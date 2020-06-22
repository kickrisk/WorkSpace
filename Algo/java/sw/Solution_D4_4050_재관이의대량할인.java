package com.sw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Solution_D4_4050_재관이의대량할인 {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
		for(int t=1; t<=T; t++) {
			st = new StringTokenizer(br.readLine().trim());
			int N = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine(), " ");
			List<Integer> list = new ArrayList<>();	
			int sum = 0;
			for(int i=0; i<N; i++) {
				int cost = Integer.parseInt(st.nextToken());
				sum += cost;
				list.add(cost);
			}
			Collections.sort(list, new Comparator<Integer>() {
				@Override
				public int compare(Integer o1, Integer o2) {
					return o2-o1;
				}
			});
			int size = list.size();
			for(int i=2; i<size; i+=3) {
				if(i >= size) break;
				sum -= list.get(i);
			}
			System.out.println("#" + t + " " + sum);
		}
	}

}
