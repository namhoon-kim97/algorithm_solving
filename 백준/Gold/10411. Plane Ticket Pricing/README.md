# [Gold III] Plane Ticket Pricing - 10411 

[문제 링크](https://www.acmicpc.net/problem/10411) 

### 성능 요약

메모리: 2220 KB, 시간: 4 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 4월 9일 20:55:53

### 문제 설명

<p>Plane ticket prices fluctuate wildly from one week to the next, and their unpredictability is a major source of frustration for travellers. Some travellers regret buying tickets too early when the prices drop right after they purchase the tickets, and some travellers regret buying tickets too late when prices rise right before they are about to make the purchase. At the end, no one is happy, except the airlines, of course.</p>

<p>Surely there is some reason to this madness. It turns out that airlines price their tickets dynamically, based on how many seats are still available and how close the flight is. For example, if there are very few seats left on a flight then the tickets may be expensive until the last few weeks before the flight, at which point the prices may decrease to fill the empty seats. Ultimately, the airlines wish to maximize revenue from each flight.</p>

<p>You have been hired by the International Contrived Pricing Corporation (ICPC) to set ticket prices each week for airlines. The airlines have collected and analyzed historical data, and have good estimates on the number of seats that will be sold at a particular ticket price with a particular number of weeks before the flight. Given the number of seats left on a flight as well as the number of weeks left before the flight, your job is to set the ticket price for the current week, in order to maximize the total revenue obtained from ticket sales from the current week to the time of the flight. You may assume that the number of tickets sold is exactly the same as the estimates, unless there are not enough remaining seats. In that case, all remaining seats will be sold. You may also assume that the optimal ticket prices will be chosen for the remaining weeks before the flight.</p>

<p>Note that higher prices do not necessarily mean fewer tickets will be sold. In fact, higher prices can sometimes increase sales as travellers may be worried that the prices will rise even higher later.</p>

### 입력 

 <p>The input consists of one case. The first line contains two integers, N and W, the number of seats left and the number of weeks left before the flight (0 < N ≤ 300, 0 ≤ W ≤ 52). The next W + 1 lines give the estimates for W weeks, W − 1 weeks, . . . , and down to 0 weeks (i.e. last week) before the flight. Each of these lines starts with an integer K (0 < K ≤ 100), the number of different prices to consider that week. This is followed by K integers 0 < p<sub>1</sub> < · · · < p<sub>K</sub> < 1000 giving the prices in dollars. Finally, this is followed by K additional integers s<sub>1</sub>, . . . , s<sub>K</sub> (0 ≤ s<sub>i</sub> ≤ N) indicating the number of tickets that will be sold for the corresponding prices.</p>

### 출력 

 <p>On the first line, print the maximum total revenue the airline can obtain from ticket sales from the current week to the time of the flight. On the second line, print the ticket price to set for the current week (W weeks before the flight) to achieve this maximum.</p>

<p>If there are multiple sets of ticket prices achieving this maximum, choose the smallest ticket price for week W.</p>

