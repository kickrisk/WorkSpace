package com.acmicpc;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main_1753_최단경로_오인호 {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int V = Integer.parseInt(st.nextToken());
		int E = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine().trim());
		int S = Integer.parseInt(st.nextToken()) - 1;
		List<ArrayList<Pair1753>> l = new ArrayList<ArrayList<Pair1753>>();
		for(int i=0; i<V; i++) {
			l.add(new ArrayList<>());
		}
		for(int i=0; i<E; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			l.get(a-1).add(new Pair1753(b-1, w));
		}
		
		int[] dist = new int[V];
		boolean[] check = new boolean[V];
		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[S] = 0;
		PriorityQueue<Pair1753> pq = new PriorityQueue<>();
		pq.add(new Pair1753(S, 0));
		while(!pq.isEmpty()) {
			Pair1753 t = pq.poll();
			if(check[t.d]) continue; 
			check[t.d] = true; 
			for(int i=0, size = l.get(t.d).size(); i<size; i++) {
				int d = l.get(t.d).get(i).d;
				int w = l.get(t.d).get(i).w;
				dist[d] = Math.min(dist[d], dist[t.d] + w);
				pq.add(new Pair1753(d, dist[d]));
			}
		}
		for (int d : dist) {
			System.out.println(d == Integer.MAX_VALUE ? "INF" : d);
		}
	}

}
class Pair1753 implements Comparable<Pair1753> {
	int d, w;
	public Pair1753(int d, int w) {
		this.d = d; this.w = w;
	}
	@Override
	public int compareTo(Pair1753 o) {
		return this.w - o.w;
	}
	
}