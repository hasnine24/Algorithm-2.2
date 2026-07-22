#include <bits/stdc++.h>
using namespace std;

// map<int, string> ব্যবহার করে
map<int, string> phone_map;
vector<string> ans;

void solve(int idx, string &digits, string current) {
    if (idx == digits.size()) {
        ans.push_back(current);
        return;
    }
    
    // char থেকে int-এ কনভার্ট ('2' -> 2)
    int digit = digits[idx] - '0';
    
    for (char ch : phone_map[digit]) {
        solve(idx + 1, digits, current + ch);
    }
}

vector<string> letterCombinations(string digits) {
    ans.clear();
    phone_map.clear();
    
    if (digits.empty()) return ans;

    // key হিসেবে integer বসানো
    phone_map[2] = "abc";
    phone_map[3] = "def";
    phone_map[4] = "ghi";
    phone_map[5] = "jkl";
    phone_map[6] = "mno";
    phone_map[7] = "pqrs";
    phone_map[8] = "tuv";
    phone_map[9] = "wxyz";

    solve(0, digits, "");
    return ans;
}

int main() {
    string digits = "23";
    vector<string> result = letterCombinations(digits);
    
    for (string s : result) {
        cout << s << " ";
    }
    cout << "\n";
    return 0;
}