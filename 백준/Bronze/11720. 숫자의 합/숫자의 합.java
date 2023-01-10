import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str = new String();
        int sum = 0, cnt;
        cnt = Integer.parseInt(br.readLine());
        str = br.readLine();
        for (int i = 0; i < cnt; i++) {
            sum += (str.charAt(i) - '0');
        }
        bw.write(String.valueOf(sum));
        bw.flush();
        bw.close();
        br.close();
    }
}