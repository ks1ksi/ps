# [Platinum III] Vještica - 13489 

[문제 링크](https://www.acmicpc.net/problem/13489) 

### 성능 요약

메모리: 3064 KB, 시간: 244 ms

### 분류

비트마스킹(bitmask), 다이나믹 프로그래밍(dp), 비트필드를 이용한 다이나믹 프로그래밍(dp_bitfield)

### 문제 설명

<p>Young hero, an adventurer Matej, has, after a long and strenuous journey, arrived to his final destination – the house of evil witch Marija. In order to complete his adventure, he must solve the final puzzle the witch gives him.</p>

<p>To even begin solving her puzzle, our hero needs to become familiar with the data structure called prefix tree (trie).</p>

<p>A prefix tree is a data structure that represents all prefixes of words from a certain set in the following way:</p>

<ul>
	<li>Each edge of the tree is denoted with a letter from the alphabet.</li>
	<li>The root of the tree represents an empty prefix.</li>
	<li>All other nodes in the tree represent a non-empty prefix in a way that each node represents a prefix obtained by concatenating letters written on the edges that lead from the root of the tree to that node (in that order).</li>
	<li>There will never be two edges labeled with the same letter coming out of a single node (this way we minimize the number of nodes necessary to represent all prefixes). </li>
</ul>

<p><img alt="" src="" style="height:356px; width:390px"></p>

<p>Prefix tree for words: “A”, “to”, “tea”, “ted”, “ten”, “i”, “in”, i “inn”.</p>

<p>Only after Matej learned what a prefix tree was does the real puzzle begin!</p>

<p>The witch, as you may have guessed, has N words that consist of lowercase letters of the English alphabet. The puzzle would be very simple if the witch wanted to know the number of nodes of the prefix tree for that set of words, but she is not interested in this. She wants to know the minimal number of nodes a prefix tree can have after permuting the letters of each word in an arbitrary manner​.</p>

<p>Help Matej find the answer to the puzzle! </p>

### 입력 

 <p>The first line of input contains the integer N ​(1 ≤ N ≤ 16).</p>

<p>Each of the following N lines contains a single word consisting of lowercase letter of the English alphabet.</p>

<p>The total length of all words will be less than 1 000 000. </p>

### 출력 

 <p>The first and only line of output must contain a number, the answer to witch Marija’s puzzle.</p>

