#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, w;
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main() {
    int n, e;
    cin >> n >> e;

    vector<Edge> edge_list;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge_list.push_back(Edge(u, v, w));
    }

    vector<long long> dis(n + 1, 0); // সব নোডের ডিস্ট্যান্স 0 দিয়ে শুরু (ডিসকানেক্টেড গ্রাফের জন্যও কাজ করবে)
    vector<int> parent(n + 1, -1);

    int last_updated_node = -1;

    // ১. N-1 বার এজ রিল্যাক্সেশন
    for (int i = 1; i <= n; i++) {
        last_updated_node = -1;
        for (auto ed : edge_list) {
            if (dis[ed.u] + ed.w < dis[ed.v]) {
                dis[ed.v] = dis[ed.u] + ed.w;
                parent[ed.v] = ed.u;
                last_updated_node = ed.v; // N-তম বার পরিবর্তন পাওয়া নোড
            }
        }
    }

    // ২. নেগেটিভ সাইকেল চেক এবং প্রিন্ট
    if (last_updated_node == -1) {
        cout << "No Negative Cycle Found\n";
    } else {
        cout << "Negative Cycle Detected!\n";

        // ৩. N বার পেছনে গিয়ে নিশ্চিত করা যে আমরা সাইকেলের ভেতরের নোডেই আছি
        for (int i = 1; i <= n; i++) {
            last_updated_node = parent[last_updated_node];
        }

        // ৪. সাইকেলের নোডগুলো সংগ্রহ করা
        vector<int> cycle;
        int curr = last_updated_node;

        while (true) {
            cycle.push_back(curr);
            if (curr == last_updated_node && cycle.size() > 1) {
                break;
            }
            curr = parent[curr];
        }

        // সাইকেলটি উল্টো অর্ডারে পাওয়া গেছে, তাই রিভার্স করতে হবে
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle Path: ";
        for (int node : cycle) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}