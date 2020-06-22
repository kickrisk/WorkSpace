import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int[][] map;
	static int white, blue;
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		
		map = new int[N+1][N+1];
		
		for(int i=1; i<=N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j=1; j<=N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		solve(1,1,N);
		System.out.println(white);
		System.out.println(blue);
	}
	private static void solve(int x, int y, int n) {
		if(check(x,y,n)) {
			return;
		} else {
			int mid = n/2;
			solve(x, y, mid);
			solve(x, mid+y, mid);
			solve(mid+x, mid+y, mid);
			solve(mid+x, y, mid);
		}
	}

	private static boolean check(int x, int y, int n) {
		int sum = 0;
		for(int i=x; i<x+n; i++) {
			for(int j=y; j<y+n; j++) {
				sum+=map[i][j];
			}
		}
		if(sum == n*n) {
			blue++; return true;
		} else if(sum == 0) {
			white++; return true;
		}
		return false;
	}

}
