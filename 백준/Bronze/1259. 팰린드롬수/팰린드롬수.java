import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str = new String();
        while (true) {
            str = br.readLine();
            if (str.equals("0")) {break;}
            boolean answer = true;
            for (int i = 0; i < str.length() / 2; i++) {
                if (str.charAt(i) != str.charAt(str.length() - i - 1)) {
                    answer = false;
                    break;
                }
            }
            if (answer) {bw.write("yes");}
            else {bw.write("no");}
            bw.newLine();
        }
        bw.flush();
        bw.close();
        br.close();
    }
}