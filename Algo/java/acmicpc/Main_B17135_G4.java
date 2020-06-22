import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static int[] archer;
	static int N,M,D;
	static int[][] map;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		archer = new int[M];
		archer[M-1] = archer[M-2] = archer[M-3] = 1;
		map = new int[N][M];
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j=0; j<M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		Shoot archers[] = new Shoot[3];
		int ans = 0;
		do {
			int temp = 0;
			for(int i=0; i<M; i++) {
				if(temp == 3) break;
				if(archer[i] == 1) {
					archers[temp++] = new Shoot(N, i);
				}
			}
			temp = 0;
			PriorityQueue<Shoot> pq = new PriorityQueue<Shoot>();

			int[][] map2 = new int[N][M];
			for(int i=0; i<N; i++) {
				for(int j=0; j<M; j++) {
					map2[i][j] = map[i][j];
				}
			}
			
			while(true) {
				pq.clear();
				boolean flag[] = new boolean[3];
				// 활을 쏜다
				int enemy = 0;
				for(int i=0; i<N; i++) {
					for(int j=0; j<M; j++) {
						if(map2[i][j] != 0) {
							enemy++;
							int d1 = (Math.abs(i-archers[0].x) + Math.abs(j-archers[0].y));
							int d2 = (Math.abs(i-archers[1].x) + Math.abs(j-archers[1].y));
							int d3 = (Math.abs(i-archers[2].x) + Math.abs(j-archers[2].y));
							if(d1 <= D) pq.add(new Shoot(i,j,d1,0));
							if(d2 <= D) pq.add(new Shoot(i,j,d2,1));
							if(d3 <= D) pq.add(new Shoot(i,j,d3,2));
						}
					}
				}
				// 제거할 적이 없다면
				if(pq.isEmpty() && enemy == 0) break;
				// 적 제거
				int cnt = 0;
				while(!pq.isEmpty()) {
					if(cnt == 3) break;
					Shoot tmp = pq.poll();
					if(!flag[tmp.a]) {
						cnt++;
						flag[tmp.a] = true;
						if(map2[tmp.x][tmp.y] != 0) {
							temp++;
							map2[tmp.x][tmp.y] = 0; 
						}
					}
				}
				// 적이 움직인다
				for(int i=N-1; i>0; i--) {
					for(int j=0; j<M; j++) {
						map2[i][j] = map2[i-1][j];
					}
				}
				Arrays.fill(map2[0], 0);
			}
			if(ans < temp) ans = temp;
		}while(next_permutation());
		System.out.println(ans);
	}
	
	private static boolean next_permutation() {
		int i = archer.length-1;
		while(i > 0 && archer[i-1] >= archer[i]) --i;
		if(i==0) return false;
		
		int j = archer.length-1;
		while(archer[i-1] >= archer[j]) --j;
		
		int temp = archer[i-1];
		archer[i-1] = archer[j];
		archer[j] = temp;
		
		int k = archer.length-1;
		while(i<k) {
			temp = archer[i];
			archer[i] = archer[k];
			archer[k] = temp;
			i++; k--;
		}
		return true;
	}

}
class Shoot implements Comparable<Shoot>{
	int x,y,d,a;
	public Shoot(int x, int y) {
		this.x = x; this.y = y; this.d = 0;
	}
	public Shoot(int x, int y, int d, int a) {
		this.x = x; this.y = y; this.d = d; this.a = a;
	}
	@Override
	public int compareTo(Shoot o) {
		int cnt = this.d - o.d;
		if(cnt == 0) return this.y - o.y;
		return cnt;
	}
	
}
