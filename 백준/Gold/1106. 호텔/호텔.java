import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int MAX_COST = 100;
    static int C, N;
    static int[][] arr;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        C = sc.nextInt();
        N = sc.nextInt();
        arr = new int[N][2];

        for (int i = 0; i < N; i++) {
            int cost = sc.nextInt();
            int customer = sc.nextInt();
            arr[i] = new int[]{cost, customer};
        }

        // x명의 고객을 유치하기 위해 사용한 cost = dp[x]
        int[] dp = new int[C + MAX_COST];
        for (int i = 1; i < C + MAX_COST; i++) {
            dp[i] = 100000;
        }

        for (int i = 0; i < C + MAX_COST; i++) {
            for (int j = 0; j < N; j++) {
                int nc = arr[j][0];
                int nx = arr[j][1];

                if (i - nx >= 0) {
                    dp[i] = Math.min(dp[i], dp[i - nx] + nc);
                }
            }
        }

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < MAX_COST; i++) {
            ans = Math.min(ans, dp[C + i]);
        }

        System.out.println(ans);

    }

    static class FastScanner {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] readArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}