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

/**
 *  Author: Neeecu
 *  Data structure: Trie
 *  Algorithm: Aho-Corasick
 */
struct TrieNode {
    int viz;
    bool ending;
    vector<TrieNode*> children;
    TrieNode* parent;
    TrieNode* suffix;

    TrieNode() : viz(0), ending(false), parent(nullptr), suffix(nullptr) {
        children.resize(26, 0);
    }
};

struct Trie {
    TrieNode* root;
    vector<TrieNode*> reverse_bfs, words;

    Trie() {
        root = new TrieNode();
    }

    void insert(string& s) {
        TrieNode* cur = root;
        for (char c : s) {
            int ch = c - 'a';
            if (not cur->children[ch]) {
                cur->children[ch] = new TrieNode();
                cur->children[ch]->parent = cur;
            }
            cur = cur->children[ch];
        }

        cur->ending = true;
        words.push_back(cur);
    }

    /// For Aho-Corasick algorithm
    /// This builds the reverse BFS as well
    void build_suffix_links() {
        queue<TrieNode*> q;
        q.push(root);

        while (not q.empty()) {
            TrieNode* cur = q.front();
            q.pop();
            reverse_bfs.push_back(cur);

            for (int ch = 0; ch < 26; ch++) {
                if (cur->children[ch]) {
                    TrieNode* node = cur->children[ch];
                    TrieNode* par = cur->suffix;
                    while (par != nullptr and par->children[ch] == nullptr)
                        par = par->suffix;
                    if (par == nullptr)
                        node->suffix = root;
                    else
                        node->suffix = par->children[ch];

                    q.push(node);
                }
            }
        }
    }

    /// Counts the number of words
    vector<int> check_text(string& text) {
        TrieNode* cur = root;
        cur->viz++;
        for (char c : text) {
            int ch = c - 'a';
            while (cur->children[ch] == nullptr and cur != root)
                cur = cur->suffix;
            if (cur->children[ch])
                cur = cur->children[ch];
            cur->viz++;
        }

        /// Now we should traverse a reverse BFS to count total vizits
        for (int i = (int) reverse_bfs.size() - 1; i > 0; i--) {
            if (reverse_bfs[i]->parent != nullptr)
                reverse_bfs[i]->suffix->viz += reverse_bfs[i]->viz;
        }

        vector<int> cnt(words.size());
        for (int i = 0; i < (int) cnt.size(); i++) {
            cnt[i] = words[i]->viz;
        }
        return cnt;
    }
};

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); // cout.tie(0);
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("ahocorasick.in");
    ofstream cout("ahocorasick.out");

    string text, pattern;
    cin >> text >> n;

    Trie trie;

    for (int i = 0; i < n; i++) {
        cin >> pattern;
        trie.insert(pattern);
    }

    trie.build_suffix_links();
    vector<int> ans = trie.check_text(text);

    for (auto i : ans) {
        cout << i << "\n";
    }

    return 0;
}
