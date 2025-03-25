#include <bits/stdc++.h>

using namespace std;

vector<string> split(string a, string dec){
    vector<string> ret;
    int st = 0;
    int en = a.find(dec);
    while (en != string::npos){
        ret.push_back(a.substr(st, en));
        st = en + dec.length();
        en = a.find(dec,st);
    }
    ret.push_back(a.substr(st, en));
    return ret;
}

vector<pair<int,int>> makeInt(vector<vector<string>> book_time){
    vector<pair<int,int>> ret;
    for (auto a: book_time){
        int x = 0;
        int y = 0;
        vector<string> temp1 = split(a[0], ":");
        x += (stoi(temp1[0]) * 60);
        x += (stoi(temp1[1]));
        vector<string> temp2 = split(a[1], ":");
        y += (stoi(temp2[0]) * 60);
        y += (stoi(temp2[1]));

        ret.push_back({x,y});
    }
    return ret;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
   
    vector<pair<int,int>> book_time2 = makeInt(book_time);
    sort(book_time2.begin(), book_time2.end());
    
    
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for (auto a: book_time2){
        while (!pq.empty() && pq.top().first + 10  <= a.first)
            pq.pop();
        
        pq.push({a.second,a.first});
        answer = max(answer, (int)pq.size());
    }
    return answer;
}