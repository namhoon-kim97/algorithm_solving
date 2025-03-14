#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
long long res;

bool isSolved(vector<int> diffs, vector<int> times, long long x, long long limit){
    long long sumTime = 0;
    for (int i = 0; i < diffs.size(); i++){
        if (diffs[i] <= x){
            sumTime += times[i];
        } else{
            sumTime += ((diffs[i] - x) * (times[i] + times[i - 1]) + times[i]);
        }
    }
    return sumTime <= limit;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    // 퍼즐을 모두 해결할 수 있는 숙련도의 최솟값은?
    // -> 숙련도가 x일때, 퍼즐을 모두 해결할 수 있나?
    long long st = 1;
    long long en = limit;
    long long res = limit;
    while (st < en){
        long long mid = (st + en) / 2;
        if (isSolved(diffs, times, mid, limit)){
            res = min(res, mid);
            en = mid ;
        } else st = mid + 1;
    }
    return res;
}