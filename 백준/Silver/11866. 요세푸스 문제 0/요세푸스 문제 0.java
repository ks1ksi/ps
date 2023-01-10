import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        String str = new String();
        str = br.readLine();
        StringTokenizer st = new StringTokenizer(str);
        int num = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        
        List<Integer> answer = new LinkedList<Integer>();
        List<Integer> list = new LinkedList<Integer>();
        
        for (int i = 1; i <= num; i++) {
            list.add(i);
        }
        
        int idx = k - 1;
        answer.add(list.remove(idx));
        
        while (list.size() > 1) {
            if (idx >= list.size()) {
                idx = 0;
            }
            int cnt = k - 1;
            while (cnt > 0) {
                idx++;
                if (idx >= list.size()) {
                    idx = 0;
                }
                cnt--;
            }
            answer.add(list.remove(idx));
        }
        bw.write("<");
        
        if (list.size() == 0) {
            bw.write("1>");
        }
        
        else {
            for(int i: answer) {
                bw.write(String.valueOf(i) + ", ");
            }
            bw.write(String.valueOf(list.get(0)) + ">");
        }
        
        bw.flush();
        bw.close();
        br.close();
    }
}