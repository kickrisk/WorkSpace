package com.sw;
import java.util.Arrays;
import java.util.Scanner;
public class Solution_D4_5987_달리기_오인호 {
	
	static int[] runner; // �޸��� ����鰣�� ����											  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1 (2)������ => ��Ʈ����ŷ ����
	static long[] numbers; // �� ��Ȳ�� �迭���� �� ������ ����� �� ����  2^16�̹Ƿ� int ������ ���� ǥ�� ����    15/14/13/12/11/10/9 /8 /7 /6 /5 /4 /3 /2 /1 /0 
	static int N,M;
	
	private static long go(int per) { // per = permutation : ���� ����
		if(per == ((1<<N)-1)) { // ��� ����� �� ä������ �� ����� ���� �� 1����!!!  
			return 1;
		}
		
		if(numbers[per] != -1) return numbers[per]; // ���� ������ �޸��� ����Ǿ� �ִٸ� �׳� ����!
		
		long sum = 0;
		for(int i=0; i<N; i++) {
			if((per&(1<<i)) == 0) { // ���� �������� i-1��° ����� ���� ������ �������� �ʾ��� ��
				if((runner[i]&per) == 0) { // ���� �������� ������ ���� ���;� �ϴ� ����� �̹� �ִٸ� �װ� Ʋ�� ����� ��!
					sum += go(per|(1<<i)); // ���� ���� ���;��ϴ� ������� �� �ڽ��� ���� ä���.!
				}
			}
		}
		return numbers[per] = sum;  // ���� ������ ������ ����� �� �޸��ϱ�!
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		for(int t=1; t<=T; t++) {
			N=sc.nextInt();
			M=sc.nextInt();
			runner = new int[N]; // N���� ������� ����
			numbers = new long[1<<N]; // 0~2^N
			Arrays.fill(numbers, -1);
			for(int i=0; i<M; i++) {
				int x = sc.nextInt() - 1; // ��Ʈ����ŷ �� �� ������ ��!!! ��Ʈ����ŷ��
				int y = sc.nextInt() - 1; // 1���Ͱ� �ƴ϶� 0���� 2^N-1 ���� ǥ���� �� ���°�! ���� 1 �������
				runner[y]|=(1<<x); // y��° ����� ���� ������ x��° ����� ���� ���� ����
				// �ֳ��ϸ� x ���� �ʰ� ���Դµ� ���� �õ���� 1����� ä����̹Ƿ�,
				// �� ���� ä��� ������ ���� ���� �ʰ� ���� ����!!! �׷��� ���� �������� ���� �ȵ�!
			}
			System.out.println("#" + t + " " + go(0));  // �õ���� ä��� 
		}
		sc.close();
	}
}
