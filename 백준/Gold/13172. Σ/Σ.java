import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


class Solver {

    private final long MOD = 1000000007;

    private long pow(long a, long b) {
        long res = 1;
        while (b > 0) {
            if (b % 2 == 1) {
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            b /= 2;
        }
        return res;
    }

    public void solve() {
        int m = Integer.parseInt(IO.readLine());
        long ans = 0;
        for (int i = 0; i < m; i++) {
            String[] line = IO.readLine().split(" ");
            long a = Long.parseLong(line[0]);
            long b = Long.parseLong(line[1]);

            long inv = pow(a, MOD - 2);
            long res = (b * inv) % MOD;
            ans = (ans + res) % MOD;
        }
        IO.writeLine(String.valueOf(ans));
    }
}


class IO {

    private static final BufferedReader reader =
            new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter writer =
            new BufferedWriter(new OutputStreamWriter(System.out));

    public static String readLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    public static void writeLine(String line) {
        try {
            writer.write(line);
            writer.newLine();
        } catch (IOException e) {
            // do nothing
        }
    }

    public static void flush() {
        try {
            writer.flush();
        } catch (IOException e) {
            // do nothing
        }
    }
}

public class Main {

    public static void main(String[] args) {
        Solver solver = new Solver();
        solver.solve();
        IO.flush();
    }
}