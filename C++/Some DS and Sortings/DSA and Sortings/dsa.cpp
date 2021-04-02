/******** Ordered Set ********
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; */

#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << "\n"
#define all(x) (x).begin(),(x).end()
#define len length()
#define sz size()
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>

using ull = unsigned long long;
using ll = long long;
using namespace std;

template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

const int INF = INT_MAX, maxN = 1e4;
int t, n, m, a, b, c, d, k, ans, block_size;
vector<int> v, aux;
vector<int> blocks, seg, bit;

// Utils
int getMax(vector<int> &v) {
    int ans = -INF;
    for (int i = 0; i < n; i++)
        ans = max(ans, v[i]);
    return ans;
}

int getMaxLen(vector<int> &v, int b){
    int ans = 1;
    for (int i = 0; i < n; i++){
        int k = v[i], curr = 0, exp = b;
        while (k > 0){
            k /= exp;
            curr++;
        }
        ans = max(ans, curr);
    }
    return ans;
}

bool checkIfSorted(vector<int> &v, vector<int> &aux){
    for (int i = 0; i < n; i++)
        if (v[i] != aux[i])
            return false;
    return true;
}


/// 1. Countsort
/// Complexitate (Time: O(n + maxNum), Memory: O(maxNum + n))
void countsort(vector<int> &v) {
    int maxNum = getMax(v);
    vector<int> aux(maxNum + 1, 0);
    for (auto num : v){
        ++aux[num];
    }
    for (int i = 0, idx = 0; i <= maxNum; i++){
        while (aux[i] > 0){
            v[idx++] = i;
            aux[i]--;
        }
    }
}


/// 2. Radixsord (baza 10) (Time: O(maxLen * n), Memory: O(baza + n));
void radixsort(vector<int> &v){
    int maxLen = getMaxLen(v, 10);
    for (int it = 1, exp = 1; it <= maxLen; it++, exp *= 10){
        vector<int> cnt(10, 0), aux(n, 0);
        for (int i = 0; i < n; i++){
            cnt[(v[i] / exp) % 10]++;
        }
        for (int i = 1; i < 10; i++){
            cnt[i] += cnt[i - 1];
        }
        for (int i = n - 1; i >= 0; i--){
            aux[cnt[(v[i] / exp) % 10] - 1] = v[i];
            cnt[(v[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++)
            v[i] = aux[i];
    }
}

void radixsord256(vector<int> &v){
    for (int k = 0; k < 32; k += 8){
        vector<int> bucket(256, 0), aux(n, 0);
        for (int i = 0; i < n; i++){
            bucket[(v[i] >> k) & 255]++;
        }
        for (int i = 1; i < 256; i++)
            bucket[i] += bucket[i - 1];
        for (int i = n - 1; i >= 0; i--){
            aux[bucket[(v[i] >> k) & 255] - 1] = v[i];
            bucket[(v[i] >> k) & 255]--;
        }
        for (int i = 0; i < n; i++)
            v[i] = aux[i];
    }
}


/// 3. Quicksort
int pivot(vector<int> &v, int a, int b, int c){
    if ((v[a] >= v[c]) != (v[a] >= v[b]))
        return a;
    else if ((v[b] >= v[a]) != (v[b] >= v[c]))
        return b;
    else
        return c;
}

void quicksort(vector<int> &v, int lo, int hi){
    if (lo < hi){
        int mid = lo + (hi - lo) / 2;
        int piv = v[pivot(v, lo, mid, hi)];
        int i = lo, j = hi;
        while (i <= j){
            while (i <= hi and v[i] < piv) ++i;
            while (j >= lo and v[j] > piv) --j;
            if (i <= hi and j >= lo and i <= j){
                swap(v[i], v[j]);
                ++i, --j;
            }
        }
        quicksort(v, lo, j);
        quicksort(v, i, hi);
    }
}


/// 4. Mergesort
void interclasare(vector<int> &v, int lo, int mid, int hi){
    int i = lo, j = mid + 1;
    vector<int> aux;

    while (i <= mid and j <= hi){
        if (v[i] <= v[j])
            aux.pb(v[i]), ++i;
        else
            aux.pb(v[j]), ++j;
    }
    while (i <= mid){
        aux.pb(v[i]), ++i;
    }
    while (j <= hi){
        aux.pb(v[j]), ++j;
    }
    for (int i = lo, idx = 0; i <= hi; i++, idx++){
        v[i] = aux[idx];
    }
}

void mergesort(vector<int> &v, int lo, int hi){
    if (lo < hi){
        int mid = lo + (hi - lo) / 2;
        mergesort(v, lo, mid);
        mergesort(v, mid + 1, hi);
        interclasare(v, lo, mid, hi);
    }
}


/// 5. Quickselect
int quickselect(vector<int> &v, int k, int lo, int hi){
    if (lo == hi)
        return v[lo];
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(lo, hi);
    // Partitionare
    int piv = distribution(rng);
    swap(v[piv], v[hi]);
    int i = lo - 1;
    for (int j = lo; j < hi; j++){
        if (v[j] <= v[hi]){
            ++i;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[hi]);
    int q = i + 1;
    int idx = q - lo + 1;
    if (k == idx)
        return v[q];
    else if (k < idx)
        return quickselect(v, k, lo, q - 1);
    else
        return quickselect(v, k - idx, q + 1, hi);
}

/// 6. Cautare binara
int binarysearch(vector<int> &v, int x){
    int lo = 0, hi = (int) v.size() - 1;
    while (lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if (v[mid] == x){
            return mid;
        } else if (v[mid] < x){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}


/// 16. Sqrt decomposition
void createBlocks(vector<int> &v){
    int n = (int) v.size();
    block_size = sqrt(n) + ((double)sqrt(n) != (int)sqrt(n));
    blocks.resize(block_size, 0);
    for (int i = 0; i < n; i++)
        blocks[i / block_size] += v[i];
}

int querySqrt(vector<int> &v, int l, int r){
    int ans = 0;
    int i = l;
    while (i <= r) {
        if (i % block_size == 0 and i + block_size - 1 <= r){
            ans += blocks[i / block_size];
            i += block_size;
        } else {
            ans += v[i];
            i++;
        }
    }
    return ans;
}

void updateSqrt(vector<int> &v, int i, int val){
    v[i] += val;
    blocks[i / block_size] += val;
}


/// 17. Segment tree
void buildSeg(vector<int> &v, int pos, int lo, int hi){
    if (lo == hi)
        seg[pos] = v[lo];
    else {
        int mid = lo + (hi - lo) / 2;
        buildSeg(v, 2 * pos + 1, lo, mid);
        buildSeg(v, 2 * pos + 2, mid + 1, hi);
        seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
    }
}

void updateSeg(int pos, int lo, int hi, int idx, int val){
    if (idx < lo or idx > hi)
        return;
    if (lo == hi and lo == idx){
        seg[pos] += val;
    } else {
        int mid = lo + (hi - lo) / 2;
        updateSeg(2 * pos + 1, lo, mid, idx, val);
        updateSeg(2 * pos + 2, mid + 1, hi, idx, val);
        seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
    }
}

int querySeg(int pos, int lo, int hi, int l, int r){
    if (r < lo or hi < l)
        return 0;
    if (l <= lo and hi <= r)
        return seg[pos];
    else {
        int mid = lo + (hi - lo) / 2;
        return querySeg(2 * pos + 1, lo, mid, l, r) +  querySeg(2 * pos + 2, mid + 1, hi, l, r);
    }
}


/// 18. Fenwick Tree
void updateBit(int idx, int val){
    idx++;
    while (idx <= n){
        bit[idx] += val;
        idx += (-idx & idx);
    }
}

int queryBit(int idx){
    idx++;
    int ans = 0;
    while (idx > 0){
        ans += bit[idx];
        idx -= (-idx & idx);
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    n = maxN;
    v.resize(n, 0);
    aux.resize(n, 0);
    uniform_int_distribution<int> distribution(1, n);
    for (int i = 0; i < n; i++){
        v[i] = distribution(rng);
        aux[i] = v[i];
        /// if (i < 50) cout << v[i] << " ";
    }

    /// Algoritmi de sortare/cautare
    /// 1. Countsort
    /// countsort(v);

    /// 2. Radixsort
    /// radixsort(v);
    /// radixsord256(v);

    /// 3. Quicksort
    /// quicksort(v, 0, n - 1);

    /// 4. Mergesort
    /// mergesort(v, 0, n - 1);

    /// sort(all(aux));
    /// cout << checkIfSorted(v, aux);

    /// 5. Quickselect
    /// vector<int> tm = {10,9,8,7,6,5,4,3,2,1};
    /// cout << quickselect(tm, 6, 0, 9);

    /// 6. Cautare binara
    /// sort(all(tm));
    /// cout << binarysearch(tm, 6);


    /// Structuri de date
    /// 7. Liste
    /// list<int> l;

    /// 8. Queue
    /// queue<int> q;

    /// 9. Stack
    /// stack<int> stk;

    /// 10. Deque
    /// deque<int> deq;

    /// 11. Heap, Binomial Heap, Fibonacci Heap
    /// priority_queue<int> pq;

    vector<int> forsum = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    /// 16. Sqrt decomposition
    /// createBlocks(forsum);
    /// cout << querySqrt(forsum, 1, 12) << "\n";
    /// updateSqrt(forsum, 3, 10);
    /// updateSqrt(forsum, 4, -5);
    /// cout << querySqrt(forsum, 1, 12) << "\n";
    /// cout << blocks << "\n";
    /// updateSqrt(forsum, 3, -10);
    /// updateSqrt(forsum, 4, 5);

    /// 17. Segment Tree
    /// n = (int) forsum.size();
    /// seg.resize(4 * n, 0);
    /// buildSeg(forsum, 0, 0, n - 1);
    /// cout << seg;
    /// updateSeg(0, 0, n - 1, 3, 10);
    /// updateSeg(0, 0, n - 1, 4, -5);
    /// cout << seg << "\n";
    /// cout << querySeg(0, 0, n - 1, 1, 12) << "\n";

    /// 18. Fenwick Tree
    /// bit.resize(n + 1, 0);
    /// for (int i = 0; i < n; i++)
    ///     updateBit(i, forsum[i]);
    /// cout << queryBit(12) - queryBit(0) << "\n";
    /// updateBit(3, 10);
    /// updateBit(4, -5);
    /// cout << queryBit(12) - queryBit(0);



    return 0;
}
