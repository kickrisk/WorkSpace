package com.sw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution_D4_9760_PokerGame_오인호 {
	static String[] ans = {"Straight Flush", "Four of a Kind", "Full House", "Flush", "Straight", "Three of a Kind", "Two pair", "One pair", "High card"}; // 9개
	static int[] nums;
	public static void main(String[] args) throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
		for(int t=1; t<=T; t++) {
			String[] card = new String[5];
			char[] color = new char[5];
			int[] num = new int[5];
			int point = 8;
			nums = new int[14];
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<5;i++) {
				card[i] = st.nextToken();
				color[i] = card[i].charAt(0);
				char temp = card[i].charAt(1);
				if(Character.isDigit(temp)) {
					num[i] = temp - '0';
					nums[temp-'0']++;
				} else if(temp == 'A') {
					num[i] = 1;
					nums[1]++;
				} else if(temp == 'T') {
					num[i] = 10;
					nums[10]++;
				} else if(temp == 'J') {
					num[i] = 11;
					nums[11]++;
				} else if(temp == 'Q') {
					num[i] = 12;
					nums[12]++;
				} else if(temp == 'K'){
					num[i] = 13;
					nums[13]++;
				}
			}
			Arrays.sort(num);
			// 플러쉬 종류 체크
			boolean flag = true;
			for(int i=0; i<4; i++) {
				if(color[i] != color[i+1]) {
					flag = false; 
					break;
				}
			}
			// 플러쉬라면
			if(flag) {
				//스트레이트인가?
				if(straight(num) || ( num[0] == 1 && num[1] == 10 && num[2] == 11 && num[3] == 12 && num[4] == 13 ) ) point = 0;
				else point = 3;
			} else {
				if(fourcard()) point = 1;
				else if(full()) point = 2;
				else if(straight(num)) point = 4;
 				else {
 					point = 8 - pair();
 				}
			}
			System.out.println("#" + t + " " + ans[point]);
		}
	}

	private static int pair() {
		Arrays.sort(nums);
		int cnt = 0;
		for(int i=13; i>=1; i--) {
			if(nums[i] == 3) return nums[i];
			if(nums[i] == 2) cnt++;
		}
		return cnt;
	}

	private static boolean full() {
		boolean flag1 = false, flag2 = false;
		for(int i=1; i<14; i++) {
			if(nums[i] == 3) flag1 = true;
			if(nums[i] == 2) flag2 = true;
		}
		if(flag1 && flag2) return true;
		return false;
	}

	private static boolean fourcard() {
		for(int i=1; i<14; i++) {
			if(nums[i] == 4) return true;
		}
		return false;
	}

	private static boolean straight(int[] num) {
		int cnt = 0;
		int sum = 0;
		for(int i=0; i<4; i++) {
			if(num[i+1] - num[i] == 1) cnt++;
			sum += num[i+1];
		}
		if(cnt == 4 ) return true;
		return false;
	}
	
}