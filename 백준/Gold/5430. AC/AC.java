import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        String str = new String();
        str = br.readLine();
        int T = Integer.parseInt(str);
        while (T > 0) {
            boolean reversed = false; //뒤집지 않고 앞에서 뺄지 뒤에서 뺄지 결정
            boolean error = false; //empty인데 D
            str = br.readLine(); //command
            br.readLine();//cnt
            String numArr = br.readLine();
            StringTokenizer st = new StringTokenizer(numArr, ",[]");
            LinkedList<String> list = new LinkedList<String>();
            while (st.hasMoreTokens()) {
                list.add(st.nextToken());
            }
            
            for (int i = 0; i < str.length(); i++) {
                if (str.charAt(i) == 'R') {
                    reversed = !reversed;
                }
                if (str.charAt(i) == 'D') {
                    if (list.isEmpty()) {
                        error = true;
                        break;
                    }
                    if (reversed) {
                        list.removeLast();
                    }
                    else {
                        list.removeFirst();
                    }
                }
            }
            
            if (error) {
                bw.write("error");
            }
            else if (list.isEmpty()) {
                bw.write("[]");
            }
            else {
                bw.write("[");
                if (reversed) {
                    Collections.reverse(list);
                }
                for (String num: list) {
                    if (num != list.getLast()) {
                        bw.write(num + ",");
                    }
                    else {
                        bw.write(num);
                    }
                }
                bw.write("]");
            }
            bw.newLine();
            T--;
        }
        
        bw.flush();
        bw.close();
        br.close();
    }
}

 
