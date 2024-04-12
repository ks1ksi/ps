import java.util.*;
import java.util.stream.*;

class Solution {
    public String solution(int[] numbers) {
        List<String> v = Arrays.stream(numbers)
            .mapToObj(String::valueOf)
            .sorted((a, b) -> (b + a).compareTo(a + b))
            .collect(Collectors.toList());
        
        if (v.get(0).equals("0")) {
            return "0";
        }
        
        return v.stream().collect(Collectors.joining());   
    }
}