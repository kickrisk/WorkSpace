package com.sw;

import java.util.Arrays;

public class Solution_2115_벌꿀채취_오인호 {

	public static void main(String[] args) {
		boolean[][] visited = new boolean[2][2];
		visited[1][1] = true;
		
		for (boolean[] row : visited) {
			Arrays.fill(row, false);
		}
	}
}
