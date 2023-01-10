# [Platinum II] Unique Activities - 21218 

[문제 링크](https://www.acmicpc.net/problem/21218) 

### 성능 요약

메모리: 36212 KB, 시간: 2800 ms

### 분류

이분 탐색(binary_search), 해싱(hashing), 매개 변수 탐색(parametric_search), 라빈–카프(rabin_karp), 문자열(string), 접미사 배열과 LCP 배열(suffix_array)

### 문제 설명

<p>Emily is tired of having studied at home throughout 2020. She has noticed the same tasks occur over and over: she has to cook and wash the dishes. Then it's time for her class; afterwards she resumes washing the dishes, has to attend another class, washes some more dishes before cooking and washing the dishes for the last time of the day.</p>

<p>There is a part of her day she loves, though: it's when the sequence of activities she is currently carrying out happens only once during her day. She rejoices the most when that activity sequence is unique and really short.</p>

<p>Each activity is represented by an uppercase letter. Given the list of activities Emily has to carry out today, help Emily find the best moment of her day by finding the shortest substring that only occurs once in the input.</p>

<p>If Cooking is C, Dishes is D, and Studying is S, the list of activities in the example above are C D S D S D C D, and the shortest substring that occurs only once is D C. (All the one-letter substrings and the other two-letter substrings occur at least twice).</p>

### 입력 

 <p>The input consists of a single line, with a sequence of $N$ uppercase letters (from 'A' to 'Z'). The line is terminated by a newline character which is not considered to be part of the input string.</p>

### 출력 

 <p>The output should contain a single line with the shortest substring that happens only once in the input string. If there are multiple shortest substrings (with the same length), output the one that occurs first.</p>

