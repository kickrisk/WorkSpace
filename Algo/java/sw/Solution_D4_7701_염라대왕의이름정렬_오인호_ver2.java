package com.sw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.StringTokenizer;

public class Solution_D4_7701_염라대왕의이름정렬_오인호_ver2 {
	
	static String[] map;
	public static void main(String[] args) throws IOException{
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
		for(int t=1; t<=T; t++) {
			sb = new StringBuilder();
			map = new String[33151];
			st = new StringTokenizer(br.readLine().trim());
			int N = Integer.parseInt(st.nextToken());
			String temp = null;
			int size = 0, cnt = 0; 
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(br.readLine().trim());
				temp = st.nextToken();
				size = temp.length();
				cnt = 0;
				for(int j=0; j<size; j++) {
					cnt += (j * 26 + (temp.charAt(j) - 'a')); 
				}
				map[cnt] = temp;
				System.out.println(cnt);
			}
			for(int i=0; i<33151; i++) {
				if(map[i] != null) 
					sb.append(map[i]).append('\n');
			}
			System.out.println("#" + t);
			System.out.print(sb.toString());
		}
	}

}