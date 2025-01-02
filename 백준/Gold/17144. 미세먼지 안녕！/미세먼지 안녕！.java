import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

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

class Solver {

    private final int[] dx = {0, 0, 1, -1};
    private final int[] dy = {1, -1, 0, 0};

    private int[][] spread(int[][] board) {
        int r = board.length;
        int c = board[0].length;
        int[][] newBoard = new int[r][c];

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == -1) {
                    newBoard[i][j] = -1;
                    continue;
                }

                newBoard[i][j] += board[i][j];
                int spreadValue = board[i][j] / 5;

                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                        continue;
                    }

                    if (board[nx][ny] == -1) {
                        continue;
                    }

                    newBoard[nx][ny] += spreadValue;
                    newBoard[i][j] -= spreadValue;
                }
            }
        }
        return newBoard;
    }

    private int[][] circulate(int[][] board) {
        int r = board.length;
        int c = board[0].length;
        int[][] newBoard = new int[r][c];

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                newBoard[i][j] = board[i][j];
            }
        }

        // column: 0
        int upperCirculatorRow = 0;
        for (int i = 0; i < r; i++) {
            if (board[i][0] == -1) {
                upperCirculatorRow = i;
                break;
            }
        }
        int lowerCirculatorRow = upperCirculatorRow + 1;

        // upper circulator
        for (int row = 0; row < upperCirculatorRow - 1; row++) {
            newBoard[row + 1][0] = board[row][0];
        }
        for (int col = 0; col < c - 1; col++) {
            newBoard[upperCirculatorRow][col + 1] = board[upperCirculatorRow][col];
        }
        for (int row = upperCirculatorRow; row > 0; row--) {
            newBoard[row - 1][c - 1] = board[row][c - 1];
        }
        for (int col = c - 1; col > 0; col--) {
            newBoard[0][col - 1] = board[0][col];
        }

        // lower circulator
        for (int row = r - 1; row > lowerCirculatorRow + 1; row--) {
            newBoard[row - 1][0] = board[row][0];
        }
        for (int col = 0; col < c - 1; col++) {
            newBoard[lowerCirculatorRow][col + 1] = board[lowerCirculatorRow][col];
        }
        for (int row = lowerCirculatorRow; row < r - 1; row++) {
            newBoard[row + 1][c - 1] = board[row][c - 1];
        }
        for (int col = c - 1; col > 0; col--) {
            newBoard[r - 1][col - 1] = board[r - 1][col];
        }

        newBoard[upperCirculatorRow][1] = 0;
        newBoard[lowerCirculatorRow][1] = 0;

        return newBoard;
    }

    public void solve() {
        int r, c, t;
        String[] line = IO.readLine().split(" ");
        r = Integer.parseInt(line[0]);
        c = Integer.parseInt(line[1]);
        t = Integer.parseInt(line[2]);

        int[][] board = new int[r][c];

        for (int i = 0; i < r; i++) {
            String[] row = IO.readLine().split(" ");
            for (int j = 0; j < c; j++) {
                board[i][j] = Integer.parseInt(row[j]);
            }
        }

        for (int i = 0; i < t; i++) {
            board = spread(board);
            board = circulate(board);
        }

        int sum = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == -1) {
                    continue;
                }
                sum += board[i][j];
            }
        }

        IO.writeLine(String.valueOf(sum));
    }
}


public class Main {

    public static void main(String[] args) {
        Solver solver = new Solver();
        solver.solve();
        IO.flush();
    }
}