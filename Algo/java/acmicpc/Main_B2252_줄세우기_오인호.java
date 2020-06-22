package com.acmicpc;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_B2252_줄세우기_오인호 {
	static int[] data;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int N = Integer.parseInt(st.nextToken());
		data = new int[N+1];
		int M = Integer.parseInt(st.nextToken());
		List<ArrayList<Integer>> list = new ArrayList<>();
		for(int i=0; i<N+1; i++) {
			list.add(new ArrayList<>());
		}
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int A = Integer.parseInt(st.nextToken());
			int B = Integer.parseInt(st.nextToken());
			list.get(A).add(B);
			data[B]++;
		}
		StringBuilder sb = new StringBuilder();
		Queue<Integer> q = new LinkedList<>();
		for(int i=1; i<N+1; i++) {
			if(data[i] == 0) q.add(i);
		}
		while(!q.isEmpty()) {
			int t = q.poll();
			sb.append(t + " ");
			for (Integer next : list.get(t)) {
				data[next]--;
				if(data[next] == 0) q.add(next);
			}
		}
		System.out.println(sb.toString());
	}
}
