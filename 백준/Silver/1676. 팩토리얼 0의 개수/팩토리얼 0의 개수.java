import java.util.*;
import java.io.*;

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        String str = new String();
        str = br.readLine();
        int N = Integer.parseInt(str);
        int[] arr = new int[N + 1];
        for (int i = 1; i < N + 1; i++) {
            arr[i] = i;
        }
        int five = 0;
        for (int i = 5; i < N + 1; i += 5) {
            while (arr[i] % 5 == 0) {
                arr[i] /= 5;
                five++;
            }
        }
        bw.write(String.valueOf(five));
        bw.flush();
        bw.close();
        br.close();
    }
}

 
