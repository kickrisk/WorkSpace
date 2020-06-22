package com.sw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_D4_5604_구간합_오인호 {

	
	static long[] def = new long[16];
	public static void main(String[] args) throws IOException{
		def();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
		for(int t=1; t<=T; t++) {
			st = new StringTokenizer(br.readLine(), " ");
			String a = st.nextToken();
			String b = st.nextToken();
			long temp = Long.parseLong(a);
			if(temp != 0) temp--;
			a = String.valueOf(temp);
			System.out.println("#" + t + " " + (long)(get(b, 0) - get(a, 0)));
		}
	}
	private static long get(String x, long cnt) {
		int mod = x.length();  // ex) 1000 => 4
		if(mod == 1) {    // 1�ڸ� �� ��, 0~9�̸� �� �� x ��ŭ ���� ���鼭 �����ָ� ��
			long tt = Long.parseLong(x);
			for(int i=0; i<=tt; i++) {
				cnt+=i;
			}
			return cnt;
		}
		long basic = Long.parseLong(x);    // ��ǲ�� �ڸ����� �˱����� String ������ ������ long ������ ��ȯ
		int div = (int) (basic / (long)Math.pow(10, mod-1));   // ���� �� ���ڸ� ���� 7�̸� 6���� �Ϻ��Ѱ� �װ� �˱� ���� ���� => 766�̸� 699 ������ �Ϻ��� ��   �츮�� 700 ~ 766 ������ ���� �����ָ� ��
		long temp = (long)Math.pow(10, mod-1);       // �ϼ��� �ڸ� �� 6���� �Ϻ��ϸ� �� 6�� 60, 6000,600000 ������ ����
		// �ϼ��� �ڸ����� �ٷ� ������!
		for(int i=0; i<div; i++) {
			cnt += i*temp;
		}
		cnt += div*def[mod-1];
		long other = basic - div*temp;	//    7�� �Ϻ����� ������ 7�� �κ��� �ѱ����
		cnt += div * (other+1);   //  �ڸ����� ���ڸ� ���̱� ���� 7�� ������ �� �ִ� ��ŭ �����ֱ� ex) 745 ��  700~745 7 * 46 ���ָ� 00 ~ 45 ���� �����ϱ� 45�� �ٽ� get �Լ��� �ֱ�   
		cnt = get(String.valueOf(other), cnt);
		return cnt;
	}
	private static void def() {
		for(int i=0; i<16; i++) {
			if(i == 0) {
				def[i] = 0;
			} else if(i == 1) def[i] = 45;
			else def[i] = 10*def[i-1] + (45 * (long)Math.pow(10, i-1));
		}
	}
}
