import java.util.*;
import java.io.*;

public class Main {
    
    static int[] arr = new int[41];
    
    static int fibo(int n) {
        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return 1;
        }
        else if (arr[n] != 0) {
            return arr[n];
        }
        else {
            return arr[n] = fibo(n-1) + fibo(n-2);
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        String str = new String();
        str = br.readLine();
        int T = Integer.parseInt(str);
        while (T > 0) {
            str = br.readLine();
            int n = Integer.parseInt(str);
            Arrays.fill(arr, 0);
            int zero, one;
            if (n == 0) {
                zero = 1;
                one = 0;
            }
            else {
                zero = fibo(n-1);
                one = fibo(n);
            }
            bw.write(String.valueOf(zero) + " " + String.valueOf(one));
            bw.newLine();
            T--;
        }
        
        bw.flush();
        bw.close();
        br.close();
    }
}

 
