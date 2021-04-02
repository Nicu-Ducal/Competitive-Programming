#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len(x) (x).length()
#define sqr(x) (x) * (x)

using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template <typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

const int INF = INT_MAX;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);

ll t, n;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int wordCnt;

    TrieNode() : wordCnt(0) {}
};

struct Trie {
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string s) {
        TrieNode* curr = root;
        for (int i = 0; i < s.length(); i++) {
            if (curr->children.find(s[i]) == curr->children.end()) {
                curr->children[s[i]] = new TrieNode();
            }
            curr = curr->children[s[i]];
        }

        curr->wordCnt++;
    }

    void remove(string s) {
        _remove(s, 0, root);
    }

    bool _remove(string s, int i, TrieNode* curr) {
        if (i == s.length()) {
            curr->wordCnt--;
            return (curr->wordCnt == 0 and curr->children.size() == 0);
        }
        TrieNode* node = curr->children[s[i]];
        bool should_remove = _remove(s, i + 1, node);

        if (should_remove) {
            curr->children.erase(s[i]);
            return (curr->wordCnt == 0 and curr->children.size() == 0 and curr != root);
        }
        return false;
    }

    int count(string s) {
        TrieNode* curr = root;
        for (int i = 0; i < s.length(); i++) {
            if (curr->children.find(s[i]) == curr->children.end()) {
                return 0;
            }
            curr = curr->children[s[i]];
        }

        return curr->wordCnt;
    }

    int longest_prefix(string s) {
        TrieNode* curr = root;
        for (int i = 0; i < s.length(); i++) {
            if (curr->children.find(s[i]) == curr->children.end())
                return i;
            curr = curr->children[s[i]];
        }

        return s.length();
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("trie.in");
    ofstream cout("trie.out");

    Trie trie;
    int q, i = 1;
    string s;
    while (cin >> q) {
        cin >> s;
        if (q == 0) {
            trie.insert(s);
        } else if (q == 1) {
            trie.remove(s);
        } else if (q == 2)
            cout << trie.count(s) << "\n";
        else
            cout << trie.longest_prefix(s) << "\n";
    }


    return 0;
}
