import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.stream.Stream;

public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());

        int ans = 0;

        if (x <= w && y <= h) {
            ans = Stream.of(x, y, w - x, h - y).min(Integer::compareTo).orElse(x);
        } else if (x <= w && y > h) {
            ans = y - h;
        } else if (x > w && y <= h) {
            ans = x - w;
        } else {
            ans = (x - w) + (y - h);
        }

        System.out.println(ans);
    }
}