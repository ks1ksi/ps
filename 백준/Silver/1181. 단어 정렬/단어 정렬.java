import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str = new String();
        str = br.readLine();
        int num = Integer.parseInt(str);
        List<String> list = new ArrayList<String>();
        for (int i = 0; i < num; i++) {
            str = br.readLine();
            if (!list.contains(str)) {list.add(str);}
        }
        
        Collections.sort(list, new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                if (s1.length() == s2.length()) {
                    return s1.compareTo(s2);
                }
                else {
                    return s1.length() - s2.length();
                }
            }
        });
        
        for (String word: list) {
            bw.write(word);
            bw.newLine();
        }
        
        bw.flush();
        bw.close();
        br.close();
    }
}