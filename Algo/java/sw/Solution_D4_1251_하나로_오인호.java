package com.sw;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Solution_D4_1251_하나로_오인호 { 

	static pair1[] island;
	static double E;
	static int N;
	static long ans;
	static int[] union;
	
	private static int find(int a) {
		if(union[a] == a) return a;
		else 
			return union[a] = find(union[a]);
	}
	
	private static boolean sum(int a, int b) {
 		int aa = find(a);
		int bb = find(b);
		if(aa == bb) return false;
		union[bb] = aa;
		return true;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int t=1; t<=T; t++) {
			N = sc.nextInt();
			island = new pair1[N];
			for(int i=0; i<N; i++) {
				int x = sc.nextInt();
				island[i] = new pair1(x,0,0);
			}
			for(int i=0; i<N; i++) {
				island[i].y = sc.nextInt();
			}
			E = sc.nextDouble();
			
			ArrayList<pair1> dis = new ArrayList<pair1>();
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					dis.add(new pair1(i,j,cal(island[i],island[j])));
				}
			}
			Collections.sort(dis, new Comparator<pair1>() {
				public int compare(pair1 o1, pair1 o2) {
					if(o1.weight > o2.weight) return 1;
					else if(o1.weight < o2.weight) return -1;
					else return 0;
				}
			});
			union = new int[N];
			for(int i=0; i<N; i++) {
				union[i] = i;
			}
			double ans = 0.0;
			for(int i=0; i<dis.size(); i++) {
				if(sum(dis.get(i).x,dis.get(i).y))
					ans += dis.get(i).weight;
			}
			System.out.println("#" + t + " " + (long)Math.round(ans));
		}
	}

	private static double cal(pair1 a, pair1 b) {
		return E * (Math.pow(a.x-b.x, 2) + Math.pow(a.y-b.y, 2));
	}
	

}
class pair1 {
	int x,y;
	double weight;
	public pair1() {
		this.x = 0; this.y = 0; this.weight = 0.0;
	}
	public pair1(int x, int y, double weight) {
		this.x = x; this.y = y; this.weight = weight;
	}
}