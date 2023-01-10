import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str = new String();
        str = br.readLine();
        int cnt = Integer.parseInt(str);
        str = br.readLine();
        StringTokenizer st = new StringTokenizer(str);
        List<Integer> list = new ArrayList<Integer>();
        while (st.hasMoreTokens()) {
            list.add(Integer.parseInt(st.nextToken()));
        }
        
        list.sort(null);
        
        bw.write(String.valueOf(list.get(0)) + " " + String.valueOf(list.get(list.size() - 1)));
        
        bw.flush();
        bw.close();
        br.close();
    }
}