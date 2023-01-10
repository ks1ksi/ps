import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str = new String();
        str = br.readLine();
        int num = Integer.parseInt(str);
        int sum = 0, cnt = 0;
        do {
            if (str.length() == 1) {
                str = "0" + str;
            }
            sum = (str.charAt(0) - '0' + str.charAt(1) - '0');
            str = String.valueOf(str.charAt(1)) + String.valueOf(sum%10);
            cnt++;
        } while (Integer.parseInt(str) != num);
        bw.write(String.valueOf(cnt));
        bw.flush();
        bw.close();
        br.close();
    }
}