import java.io.*;

public class Main {
    
    static int makeOne(int N, int count)
    {
        if (N < 2) {return count;}
        return Math.min(makeOne(N / 2, count + 1 + (N % 2)),
                        makeOne(N / 3, count + 1 + (N % 3)));
    }
    
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        String str = new String();
        str = br.readLine();
        int N = Integer.parseInt(str);
        
        int ans = makeOne(N, 0);
        bw.write(String.valueOf(ans));
        
        bw.flush();
        bw.close();
        br.close();
    }
}
