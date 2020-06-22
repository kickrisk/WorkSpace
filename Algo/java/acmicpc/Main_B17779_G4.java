import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int[][] map = new int[21][21];
	static int[] vote = new int[5];
	static int sum = 0;
	static int ans = Integer.MAX_VALUE;
	static int N = 0;
	
	public static void main(String[] args) throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		for(int i = 1; i<=N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j = 1; j <= N ; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				sum += map[i][j];
			}
		}
		
		for(int i = 1; i <= N-2; i++) {
			for(int j = 2; j <= N-1; j++) {
				solve(i,j);
			}
		}
		System.out.println(ans);
	}
	private static void solve(int x, int y) {
		
		for(int i = 1; i<=N-2; i++) {
			for(int j = 1; j <= N-1-i; j++) {
				if( y - i < 1 || y + j > N || x + i + j > N)
					continue;
				get(x,y,i,j);
			}
		}
	}
	private static void get(int x, int y, int d1, int d2) {
		Arrays.fill(vote,  0);
		int temp = 0;
		for(int i = 1; i < x + d1; i++) {
			if(i<x) {
				for(int j=1; j <= y; j++) {
					vote[0] += map[i][j];
				}
				continue;
			}
			for(int j = 1; j < y-temp; j++) {
				vote[0] += map[i][j];
			}
			temp++;
		}
		
		temp = 0;
		for(int j = N; j > y; j--) {
			if(y+d2<j) {
				for(int i= x + d2; i > 0; i--) {
					vote[1] += map[i][j];
				}
				continue;
			}
			for(int i = x + d2 - 1 - temp; i > 0; i--) {
				vote[1] += map[i][j];
			}
			temp++;
		}
		
		temp = 0;
		for(int j = 1; j < y -d1 + d2; j++) {
			if(j < y-d1) {
				for(int i = x + d1; i <= N; i++) {
					vote[2] += map[i][j];
				}
				continue;
			}
			for(int i = x + d1 + temp + 1; i <= N; i++) {
				vote[2] += map[i][j];
			}
			temp++;
		}
		
		temp = 0;
		for(int i = N; i > x + d2; i--) {
			if(i > x + d1 + d2) {
				for(int j = y - d1 + d2; j <= N; j++) {
					vote[3] += map[i][j];
				}
				continue;
			}
			for(int j = y - d1 + d2 + 1 + temp; j <= N; j++) {
				vote[3] += map[i][j];
			}
			temp++;
		}
		
		vote[4] = sum - vote[1] - vote[2] - vote[3] - vote[0]; 
		Arrays.sort(vote);
		if( ans > vote[4] - vote[0]) {
			ans = vote[4] - vote[0];
		}
	}
	
}

