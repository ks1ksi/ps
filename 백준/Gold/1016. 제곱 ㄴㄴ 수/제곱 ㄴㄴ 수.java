import java.util.*;

public class Main {
    
    static boolean[] arr = new boolean[1000001];
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long max, min;
        int cnt = 0;
        min = sc.nextLong();
        max = sc.nextLong();
        for (long i = 2; i * i <= max; i++) {
            long currentNum = i*i;
            long idx = min; //min 빼면 0부터 시작 (나눠 떨어질때)
            if (min % currentNum != 0) {
                long tmp = min/currentNum + 1; //첫 번째 인덱스(나눠 떨어지면 0, 아니면 몫 + 1 하고 다시 곱해줌)
                idx = tmp * currentNum;
            }
            while (true) {
                if (idx > max) {break;}
                arr[(int)(idx - min)] = true; //배열 인덱스 무조건 int
                idx += currentNum; //제곱수만큼 건너뛰면서 배열 변경   
            }
        }
        for (int i = 0; i <= max - min; i++) {
            if (arr[i] == false) {
                cnt++;
            }
        }
        System.out.println(cnt);
        sc.close();
    }
}

 
