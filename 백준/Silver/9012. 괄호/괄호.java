import java.util.*;
import java.io.*;

public class Main {
    
    static boolean checkP(String PS)
    {
        Stack<Character> stack = new Stack<Character>();
        for (int i = 0; i < PS.length(); i++) {
            if (PS.charAt(i) == '(') {
                stack.push('(');
            }
            else if (PS.charAt(i) == ')') {
                if (stack.isEmpty()) {
                    return false;
                }
                stack.pop();
            }
        }
        if (stack.isEmpty()) {
            return true;
        }
        else {
            return false;
        }
    }
    
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        String str = new String();
        str = br.readLine();
        int N = Integer.parseInt(str);
        while (N > 0) {
            str = br.readLine();
            if (checkP(str)) {
                bw.write("YES");
            }
            else {
                bw.write("NO");
            }
            bw.newLine();
            N--;
        }

        
        bw.flush();
        bw.close();
        br.close();
    }
}