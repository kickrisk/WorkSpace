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

public class Solution_D4_7701_염라대왕의이름정렬_오인호{
	
	static Map<String,Integer> map = new HashMap<String,Integer>();
	
	public static void main(String[] args) throws IOException{
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
		for(int t=1; t<=T; t++) {
//			sb = new StringBuilder();
			st = new StringTokenizer(br.readLine().trim());
			int N = Integer.parseInt(st.nextToken());
			String temp = null;
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(br.readLine().trim());
				temp = st.nextToken();
				map.put(temp, temp.length());
			}
			LinkedList<Map.Entry<String, Integer>> ll = new LinkedList<Map.Entry<String, Integer>>(map.entrySet());
			Collections.sort(ll, new Comparator<Map.Entry<String, Integer>>() {
				public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
					int d = o1.getValue() - o2.getValue();
					return d != 0 ? d : o1.getKey().compareTo(o2.getKey());
				}
			});
			for(int i=0; i<ll.size(); i++) {
 				sb.append(ll.get(i).getKey()).append('\n');
			}
			System.out.println("#" + t);
			System.out.print(sb.toString());
		}
	}

}
