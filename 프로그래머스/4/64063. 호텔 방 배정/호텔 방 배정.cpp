#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
unordered_map<long long, long long> um;
long long find(long long x){
    if (um[x] == 0)
        return x;
    return um[x] = find(um[x]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for (auto a: room_number){
        long long idx = find(a);
        answer.push_back(idx);
        um[idx] = find(idx + 1);
    }
    return answer;
}