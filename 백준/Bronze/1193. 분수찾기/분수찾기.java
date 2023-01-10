import java.util.*;

public class Main {    
    public static void main(String[] args){
        int cnt, sum, mo, ja;
        Scanner sc = new Scanner(System.in);
        cnt = sc.nextInt();
        sum = 1;
        mo = 1;
        ja = 0;
        for (int i = 0; i < cnt; i++) {
            if (sum % 2 == 1) { //분모 분자 합 홀수일 때 -> 분자 증가, 분모 감소
                                // 분모가 1일때 change
                if (mo == 1) {
                    sum += 1;
                    ja +=  1;
                }
                else {
                    ja += 1;
                    mo -= 1;
                }
            }
            else { //분모 분자 합 짝수일 때 -> 분자 감소, 분모 증가, 분자가 1일때 change
                if (ja == 1) {
                    sum += 1;
                    mo += 1;
                }
                else {
                    ja -= 1;
                    mo += 1;
                }
            }
        }
        System.out.println(ja + "/" + mo);
        sc.close();
    }
}
