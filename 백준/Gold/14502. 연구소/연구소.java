import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;

class Pair<K, V> {

    public K first;
    public V second;

    public Pair(K first, V second) {
        this.first = first;
        this.second = second;
    }
}

public class Main {

    private static final BufferedReader reader =
            new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter writer =
            new BufferedWriter(new OutputStreamWriter(System.out));
    private static final int[] dx = {0, 0, 1, -1};
    private static final int[] dy = {1, -1, 0, 0};

    private static int[][] virus(int[][] arr, int n, int m) {
        int[][] ret = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret[i][j] = arr[i][j];
            }
        }

        ArrayDeque<Pair<Integer, Integer>> q = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ret[i][j] == 2) {
                    q.add(new Pair<>(i, j));
                }
            }
        }

        while (!q.isEmpty()) {
            Pair<Integer, Integer> p = q.remove();
            int x = p.first;
            int y = p.second;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }

                if (ret[nx][ny] == 0) {
                    ret[nx][ny] = 2;
                    q.add(new Pair<>(nx, ny));
                }
            }
        }

        return ret;
    }

    private static int solve(int[][] arr, int n, int m, int wall) {
        if (wall == 3) {
            int[][] temp = virus(arr, n, m);
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (temp[i][j] == 0) {
                        cnt++;
                    }
                }
            }
            return cnt;
        }

        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 0) {
                    arr[i][j] = 1;
                    ret = Math.max(ret, solve(arr, n, m, wall + 1));
                    arr[i][j] = 0;
                }
            }
        }

        return ret;
    }

    public static void main(String[] args) throws IOException {
        int n, m;
        String[] input = reader.readLine().split(" ");
        n = Integer.parseInt(input[0]);
        m = Integer.parseInt(input[1]);

        int[][] arr = new int[n][m];

        for (int i = 0; i < n; i++) {
            input = reader.readLine().split(" ");
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(input[j]);
            }
        }

        int ans = solve(arr, n, m, 0);
        writer.write(ans + "\n");

        writer.flush();
    }
}