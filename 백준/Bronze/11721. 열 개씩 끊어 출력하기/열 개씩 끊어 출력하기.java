import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str = new String();
        str = br.readLine();
        while (str.length() > 10) {
            bw.write(str, 0, 10);
            bw.newLine();
            str = str.substring(10);
        }
        bw.write(str);
        bw.flush();
        bw.close();
        br.close();
    }
}