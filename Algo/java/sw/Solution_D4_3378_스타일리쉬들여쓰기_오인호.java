package com.sw;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_D4_3378_스타일리쉬들여쓰기_오인호 {
	
	static int[][] dis; // 0 : ( , 1 : ) , 2 : { , 3 : } , 4 : [ , 5 : ]
	static int[] space; // �� �� �鿩���� ���� �����ϴ� �迭
	static int[][] matrix = new int[3][3];
	static int[][] map;		// ���� ��
	static int[][] map1;    // �� �� 
	static int[] isSelected = new int[3];  // �� �� ���� ������?
	static int R, C, S; // ( ) , { } , [ ] �� ��
	static boolean flag;
	public static void main(String[] args) throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine().trim());
		int T = Integer.parseInt(st.nextToken());
		for(int t=1; t<=T; t++) {
			st = new StringTokenizer(br.readLine());
			int p = Integer.parseInt(st.nextToken());
			int q = Integer.parseInt(st.nextToken());
			dis = new int[2][6];
			String strTemp = null;
			int size = 0;
			space = new int[p];
			map = new int[p][6];
			map1 = new int[q][6];
			// �Է� ���� ���ڿ� ��ȣ �����ϱ�
			for(int i=0; i<p; i++) {
				strTemp = br.readLine();
				size = strTemp.length();
				flag = true;
				for(int j=0; j<size; j++) {
					check(i,strTemp.charAt(j),0);
				}
				for(int k=0; k<6; k++) 
					map[i][k] = dis[0][k];
			}
			
			for(int i=0; i<q; i++) {
				strTemp = br.readLine();
				size = strTemp.length();
				flag = true;
				for(int j=0; j<size; j++) {
					check(i,strTemp.charAt(j),1);
				}
				for(int k=0; k<6; k++) 
					map1[i][k] = dis[1][k];
			}
			
			// �Է� ���� ���ڿ��� R C S ���ϱ�
			setMatrix(p);
			
			// ������� �̿��� �ظ� ���ϱ�
			if(inverseMatrix()) {
				System.out.print("#" + t + " ");
				for(int i=0; i<q; i++) {
					if(i==0) System.out.print("0 ");
					else {
						System.out.print( (int)Math.abs(map1[i-1][0] - map1[i-1][1])*R
								+ (int)Math.abs(map1[i-1][2] - map1[i-1][3])*C
									+ (int)Math.abs(map1[i-1][4] - map1[i-1][5])*S + " ");
					}
				}
				System.out.println();
			} else System.out.println("#" + t + " " + -1);
		}
	}

	private static boolean inverseMatrix() {
		int a = matrix[0][0], b = matrix[0][1], c = matrix[0][2];
		int d = matrix[1][0], e = matrix[1][1], f = matrix[1][2];
		int g = matrix[2][0], h = matrix[2][1], i = matrix[2][2];
		int det = a*(e*i-f*h) - b*(d*i-f*g) + c*(d*h - e*g); // Determinant
		int l = space[isSelected[0]], m = space[isSelected[1]], n = space[isSelected[2]];
		if(det == 0) {
			if(a == d && d == g && b == e) {
				R = l; C = m; S = n;
				return true;
			}
			return false;
		}
		R = ((e*i - f*h)*l + (c*h - b*i)*m + (b*f - c*e)*n)/det;
		C = ((f*g - d*i)*l + (a*i - c*g)*m + (c*d - a*f)*n)/det;
		S = ((d*h - e*g)*l + (b*g - a*h)*m + (a*e - b*d)*n)/det;
		return true;
	}

	private static void setMatrix(int p) {
		// 3�� ���� ������ �����
		int cnt = 0;
		for(int i=1; i<p; i++) {
			if(cnt == 3) break;
			if(space[i] != 0) {
				for(int j=0; j<3; j++) {
					matrix[cnt][j] = (int)Math.abs(map[i-1][2*j] - map[i-1][2*j+1]);
				}
				// ����� ������ �Ұ�!!
				if(cnt != 0) {
					double a = 0.0, b = 0.0, c = 0.0;
					a = matrix[cnt-1][0] / (double) matrix[cnt][0];
					b = matrix[cnt-1][1] / (double) matrix[cnt][1];
					c = matrix[cnt-1][2] / (double) matrix[cnt][2];
					if(a == b && b == c) continue;
				}
				isSelected[cnt] = i;
				cnt++;
			}
		}
	}

	private static void check(int line, char c, int i) {
		switch(c) {
			case '(' :
				dis[i][0]++; flag = false; break;
			case ')' : 
				dis[i][1]++; flag = false; break;
			case '{' :
				dis[i][2]++; flag = false; break;
			case '}' : 
				dis[i][3]++; flag = false; break;
			case '[' :
				dis[i][4]++; flag = false; break;
			case ']' : 
				dis[i][5]++; flag = false; break;
			case '.' :
				if(flag)
					space[line]++; break;
			default :
				flag = false;
				return;
		}
		
	}

}
