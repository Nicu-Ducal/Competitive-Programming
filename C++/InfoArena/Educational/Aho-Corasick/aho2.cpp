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
    //string word;
    unordered_map<char, TrieNode*> children;
    TrieNode* parent;
    TrieNode* suffix;


    TrieNode() : viz(0), ending(false)/*, word("$")*/, parent(nullptr), suffix(nullptr) {}
};

struct Trie {
    TrieNode* root;
    vector<TrieNode*> reverse_bfs;

    Trie() {
        root = new TrieNode();
        root->suffix = nullptr;
    }

    void insert(string& s) {
        TrieNode* curr = root;
        for (int i = 0; i < (int) s.length(); i++) {
            if (curr->children.find(s[i]) == curr->children.end()) {
                curr->children[s[i]] = new TrieNode();
                curr->children[s[i]]->parent = curr;
                //curr->children[s[i]]->word = curr->word + s[i];
            }
            curr = curr->children[s[i]];
        }

        curr->ending = true;
    }

    void remove(string s) {
        _remove(s, 0, root);
    }

    bool _remove(string s, int i, TrieNode* curr) {
        if (i == (int) s.length()) {
            curr->ending = 0;
            return (curr->ending == 0 and curr->children.size() == 0);
        }
        TrieNode* node = curr->children[s[i]];
        bool should_remove = _remove(s, i + 1, node);

        if (should_remove) {
            curr->children.erase(s[i]);
            return (curr->ending == 0 and curr->children.size() == 0 and curr != root);
        }
        return false;
    }

    int longest_prefix(string s) {
        TrieNode* curr = root;
        for (int i = 0; i < (int) s.length(); i++) {
            if (curr->children.find(s[i]) == curr->children.end())
                return i;
            curr = curr->children[s[i]];
        }

        return s.length();
    }

    /// For Aho-Corasick algorithm
    /// This builds the reverse BFS as well
    void build_suffix_links() {
        queue<TrieNode*> q;
        reverse_bfs.push_back(root);
        for (auto next: root->children) {
            TrieNode* node = next.second;
            q.push(node);
            node->suffix = root;
        }

        while (not q.empty()) {
            TrieNode* cur = q.front();
            q.pop();
            reverse_bfs.push_back(cur);

            for (auto next: cur->children) {
                char ch = next.first;
                TrieNode* node = next.second;
                TrieNode* par = cur->suffix;
                while (par != nullptr and par->children[ch] == nullptr)
                    par = par->suffix;
                if (par == nullptr)
                    node->suffix = root;
                else
                    node->suffix = par->children[ch];

                q.push(node);
            }

            //cout << cur->word << " " << cur->suffix->word << "\n";
        }
        reverse(reverse_bfs.begin(), reverse_bfs.end());
    }

    /// Counts the number of words
    void check_text(string& text) {
        TrieNode* cur = root;
        cur->viz++;
        for (int i = 0; i < (int) text.length(); i++) {
            //cout << i << " " << cur->word << " " << text[i] << " "; // to_del
            if (cur->children[text[i]] != nullptr) {
                cur = cur->children[text[i]];
            } else {
                cur = cur->suffix;
                while (cur != nullptr and cur->children[text[i]] == nullptr)
                    cur = cur->suffix;

                if (cur == nullptr)
                    cur = root;
                else
                    cur = cur->children[text[i]];
            }
            cur->viz++;
            //cout << cur->word << "\n"; // to del
        }

        // Now we should traverse a reverse BFS to count total vizits
        for (auto node: reverse_bfs) {
            if (node->parent != nullptr)
                node->suffix->viz += node->viz;
        }
    }

    /// Returns the number of word in text
    int count(string& s) {
        TrieNode* cur = root;
        for (int i = 0; i < (int) s.length(); i++) {
            cur = cur->children[s[i]];
        }

        if (cur->ending == true) {
            return cur->viz;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ifstream cin("ahocorasick.in");
    ofstream cout("ahocorasick.out");

    string text;
    cin >> text >> n;

    Trie trie;
    vector<string> dict(n);

    for (int i = 0; i < n; i++) {
        cin >> dict[i];
        trie.insert(dict[i]);
    }

    trie.build_suffix_links();
    trie.check_text(text);

    for (int i = 0; i < n; i++) {
        cout << trie.count(dict[i]) << "\n";
    }

    return 0;
}
