package com.sw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution_D5_4534_트리흑백색칠_오인호 {

	private static int MOD = 1000000007;

	public static void main(String args[]) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringTokenizer st = null;
		for (int t = 1; t <= T; t++) {
			int N = Integer.parseInt(br.readLine());
			// ��������Ʈ ������ ���� Ǯ��!
			ArrayList<ArrayList<Integer>> list = new ArrayList<>();
			for (int i = 0; i <= N; i++) {
				list.add(new ArrayList<>());
			}

			for (int i = 1; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				list.get(a).add(b);
				list.get(b).add(a);
			}

			boolean visited[] = new boolean[N + 1];
			long map[][] = new long[N + 1][2];
			visited[1] = true;
			long ans = (recur(visited, list, map, 1, 0) + recur(visited, list, map, 1, 1)) % MOD;
			System.out.println("#" + t + " " + ans);
		}
	}

	static long recur(boolean[] visited, ArrayList<ArrayList<Integer>> list, long[][] map, int cur, int status) {

		if (map[cur][status] != 0)
			return map[cur][status];

		long val = 1;

		for (int prev : list.get(cur)) {
			if (visited[prev])
				continue;
			visited[prev] = true;
			if (status == 0) {
				val = (val * ((recur(visited, list, map, prev, 0) + recur(visited, list, map, prev, 1)) % MOD)) % MOD;
			} else {
				val = (val * recur(visited, list, map, prev, 0)) % MOD;
			}
			visited[prev] = false;
		}
		return map[cur][status] = val;

	}
}

