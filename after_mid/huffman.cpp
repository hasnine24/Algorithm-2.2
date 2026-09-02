#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char ch;
    int freq;

    Node *left, *right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

void printCode(Node *root, string code)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->ch << " : " << code << endl;
        return;
    }

    printCode(root->left, code + "0");
    printCode(root->right, code + "1");
}

int main()
{
    char ch[] = {'A', 'B', 'C', 'D', 'E'};
    int freq[] = {5, 9, 12, 13, 16};

    int n = 5;

    priority_queue<
        pair<int, Node *>,
        vector<pair<int, Node *>>,
        greater<pair<int, Node *>>>
        pq;

    // Insert all nodes
    for (int i = 0; i < n; i++)
    {
        pq.push({freq[i], new Node(ch[i], freq[i])});
    }

    // Build Huffman Tree
    while (pq.size() > 1)
    {
        Node *left = pq.top().second;
        pq.pop();

        Node *right = pq.top().second;
        pq.pop();

        int sum = left->freq + right->freq;

        Node *parent = new Node('$', sum);

        parent->left = left;
        parent->right = right;

        pq.push({sum, parent});
    }

    Node *root = pq.top().second;

    printCode(root, "");

    return 0;
}