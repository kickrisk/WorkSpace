import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int dx[] = {-1, 0, 1};
	static int dy[] = { 1, 1, 1};
	static char[][] map;
	static boolean[][] check;
	static int R, C;
	static int ans = 0;
	static boolean[] check2;
	public static void main(String[] args) throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		map = new char[R][C];
		check = new boolean[R][C];
		check2 = new boolean[R+1];
		for(int i=0; i<R; i++) {
			String str = br.readLine();
			for(int j=0; j<C; j++) {
				map[i][j] = str.charAt(j);
			}
		}
		for(int i = 1; i<=R; i++) {
			solve(i-1,0,i);
		}
		System.out.println(ans);
	}

	private static void solve(int x, int y, int type) {
		if(x < 0 || x >= R || y < 0 || y >= C) return;
		if(map[x][y] == 'x') return;
		if(check[x][y] == true  || check2[type] == true ) return;
		
 		check[x][y] = true;
 		
		if(y == C-1) {
			check2[type] = true;
			ans++;
			return;
		}
		
		for(int i=0; i<3; i++) {
			solve(x+dx[i], y+dy[i],type);
		}
		
//		check[x][y] = false;
	}
}
