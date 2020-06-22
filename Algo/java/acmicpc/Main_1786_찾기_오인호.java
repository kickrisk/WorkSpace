package com.acmicpc;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;

public class Main_1786_찾기_오인호 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String parent = br.readLine();
		String pattern = br.readLine();
		int patternSize = pattern.length();
		int parentSize = parent.length();
		int[] pi = new int[patternSize];

		for (int i = 1, j = 0; i < pi.length; i++) {
			while (j > 0 && pattern.charAt(i) != pattern.charAt(j))
				j = pi[j - 1];
			if (pattern.charAt(i) == pattern.charAt(j)) pi[i] = ++j;
			else pi[i] = 0;
		}
		List<Integer> ans = new LinkedList<>();
		boolean flag = false;
		L:for (int i = 0, j = 0; i < parentSize; i++) {
			while (j > 0 && parent.charAt(i) != pattern.charAt(j))
				j = pi[j - 1];
			if (parent.charAt(i) == pattern.charAt(j)) {
				if (j == patternSize - 1) {
					flag = true;
					break L;
//					ans.add(i - patternSize + 2);
//					j = pi[j];
				} else
					j++;
			}
		}
		System.out.println(flag);
//		System.out.println(ans.size());
//		for (Integer a : ans)
//			System.out.print(a + " ");
	}
}
