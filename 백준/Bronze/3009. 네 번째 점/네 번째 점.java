import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        
        int[] xc = new int[1001];
        int[] yc = new int[1001];
        
        for (int i = 0; i < 3; i++ ){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            xc[x]++;
            yc[y]++;
        }

        int ax = 0, yx = 0;

        for (int i = 0; i < 1001; i++) {
            if (xc[i] == 1) ax = i;
            if (yc[i] == 1) yx = i;
        }

        System.out.printf("%d %d", ax, yx);
    }
}
