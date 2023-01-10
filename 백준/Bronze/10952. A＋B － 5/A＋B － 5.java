import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str = new String();
        int a, b;
        while (true) {
            str = br.readLine();
            StringTokenizer st = new StringTokenizer(str);
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            if (a == 0 && b == 0) {
                break;
            }
            bw.write(String.valueOf(a+b));
            bw.newLine();
        }
        bw.flush();
        bw.close();
        br.close();
    }
}