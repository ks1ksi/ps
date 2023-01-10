# [Platinum I] Flip - 23339 

[문제 링크](https://www.acmicpc.net/problem/23339) 

### 성능 요약

메모리: 34252 KB, 시간: 316 ms

### 분류

자료 구조(data_structures), 느리게 갱신되는 세그먼트 트리(lazyprop), 세그먼트 트리(segtree)

### 문제 설명

<p>Suppose you are given an array of n entries where each array entry is either 0 or 1. For any pair (ℓ, r) such that 1 ≤ ℓ ≤ r ≤ n, [a[ℓ], a[ℓ + 1], ..., a[r]] is a subarray of the array [a[1], a[2], ..., a[n]]. An alternating subarray [a[ℓ], a[ℓ + 1], ..., a[r]] of [a[1], a[2], ..., a[n]] if a[ℓ] ≠ a[ℓ + 1] ≠ ··· ≠ a[r]. I.e., every entry in the subarray is different from its neighbors in the subarray. Since the definition of alternating subarrays only considers the entries in the subarrays, [1, 0, 1] is still an alterating subarray of [1, 1, 0, 1, 1].</p>

<p>In this problem, two types of operations will be applied to the given array.</p>

<ul>
	<li>1 ℓ r: for every i ∈ [ℓ, r], change a[i] into 1 − a[i].</li>
	<li>2 ℓ r: report the total number of pairs (x, y) such that ℓ ≤ x ≤ y ≤ r and subarray [a[x], a[x + 1], ..., a[y]] is an alternating subarray.</li>
</ul>

<p>Please write a program to maintain the given array. Your program must report the numbers efficiently.</p>

### 입력 

 <p>The first line contains two integers n and q, indicating the length of the given array and the number of operations. The second line contain n space separated numbers a[1], a[2], ..., a[n] representing the given array [a[1], a[2], ..., a[n]]. Then q lines follow, and the i-th of them contains 3 integers t<sub>i</sub>, ℓ<sub>i</sub>, r<sub>i</sub> where the i-th operation is t<sub>i</sub> ℓ<sub>i</sub> r<sub>i</sub> .</p>

### 출력 

 <p>For each operation of the second type, output the reported number on one line.</p>

