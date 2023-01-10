import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str = new String();
        str = br.readLine();
        int num = Integer.parseInt(str);
        
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < i + 1; j++) {bw.write("*");}
            if (i != num - 1) {bw.newLine();}
        }
        
        bw.flush();
        bw.close();
        br.close();
    }
}
