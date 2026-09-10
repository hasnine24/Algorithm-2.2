#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first == b.first) {
            return a.second > b.second; // Lexicographically smaller string first
        }
        return a.first < b.first; // Higher frequency first
    }
};

vector<string> topKFrequentWords(vector<string>& words, int k) {
    map<string, int> freq;
    for (const string& w : words) {
        freq[w]++;
    }

    priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
    for (auto it : freq) {
        pq.push({it.second, it.first});
    }

    vector<string> ans;
    while (k--) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main() {
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    vector<string> result = topKFrequentWords(words, k);

    for (string s : result) {
        cout << s << " ";
    }
    cout << "\n";
    return 0;
}