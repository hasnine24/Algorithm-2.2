#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> freq;
    for (int x : nums) {
        freq[x]++;
    }

    // Max-heap stores: {frequency, element}
    priority_queue<pair<int, int>> pq;
    for (auto it : freq) {
        pq.push({it.second, it.first});
    }

    vector<int> ans;
    while (k--) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);
    
    for (int x : result) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}