import java.util.*;
import java.io.*;

public class Main {
    
    static int maxConference(List<int[]> list) {
        int cnt = 1;
        int tmp = list.get(0)[1];
        int idx = 1;
        while (idx < list.size()) {
            if (list.get(idx)[0] >= tmp) { //시작시점 >= 이전 회의 종료시점 (종료시점 순 정렬상태)
                cnt++;
                tmp = list.get(idx)[1];
            }
            idx++;
        }
        return cnt;
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        String str = new String();
        str = br.readLine();
        int N = Integer.parseInt(str);
        List<int[]> list = new ArrayList<int[]>();
        
        while (N > 0) {
            int[] arr = new int[2];
            str = br.readLine();
            StringTokenizer st = new StringTokenizer(str);
            arr[0] = Integer.parseInt(st.nextToken());
            arr[1] = Integer.parseInt(st.nextToken());
            list.add(arr);
            N--;
        }
        
        Collections.sort(list, new Comparator<int[]>() {
            @Override
            public int compare(int[] arr1, int[] arr2) {
                if (arr1[1] > arr2[1]) {
                    return 1;
                }
                else if (arr1[1] == arr2[1]) {
                    return arr1[0] - arr2[0]; //종료시점 동일할시 시작 먼저하는걸로! (그래야 4 8, 8 8 둘다 가능)
                }
                else {
                    return -1;
                }
            }
        });
        
        /*
        for (int[] nextArr: list){
            bw.write(String.valueOf(nextArr[0]) + " " + String.valueOf(nextArr[1]));
            bw.newLine();
        }
        */
        
        bw.write(String.valueOf(maxConference(list)));
        
        bw.flush();
        bw.close();
        br.close();
    }
}

 
