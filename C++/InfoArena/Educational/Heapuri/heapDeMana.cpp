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

const int INF = INT_MAX;
ll t, n, q, num;
vector<pii> heap;
int order[2000005], curr = 1;


void heapifyUp(int idx){
    if (idx == 0)
        return;
    if (heap[idx].fi < heap[(idx - 1) / 2].fi){
        swap(order[heap[idx].se], order[heap[(idx - 1) / 2].se]);
        swap(heap[idx], heap[(idx - 1) / 2]);
        heapifyUp((idx - 1) / 2);
    }
}

void heapifyDown(int idx){
    int mi;
    if (2 * idx + 1 > (int) heap.size() - 1)
        return;
    else if (2 * idx + 2 > (int) heap.size() - 1)
        mi = heap[2 * idx + 1].fi;
    else
        mi = min(heap[2 * idx + 1].fi, heap[2 * idx + 2].fi);
    if (heap[idx].fi > mi){
        if (heap[2 * idx + 1].fi == mi){
            swap(order[heap[idx].se], order[heap[2 * idx + 1].se]);
            swap(heap[idx], heap[2 * idx + 1]);
            heapifyDown(2 * idx + 1);
        } else if (2 * idx + 2 < (int) heap.size() - 1 and mi == heap[2 * idx + 2].fi) {
            swap(order[heap[idx].se], order[heap[2 * idx + 2].se]);
            swap(heap[idx], heap[2 * idx + 2]);
            heapifyDown(2 * idx + 2);
        }
    }
}

void insert(int num){
    heap.emplace_back(num, curr);
    order[curr++] = (int) heap.size() - 1;
    heapifyUp((int) heap.size() - 1);
}

void pop(int idx){
    swap(order[heap[idx].se], order[heap[(int) heap.size() - 1].se]);
    swap(heap[idx], heap[(int) heap.size() - 1]);
    heap.pop_back();
    heapifyUp(idx);
    heapifyDown(idx);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("heapuri.in");
    ofstream cout("heapuri.out");

    cin >> n;
    while (n--){
        cin >> q;
        switch (q) {
            case 1:
                cin >> num;
                insert(num);
                break;
            case 2:
                cin >> num;
                pop(order[num]);
                break;
            case 3:
                cout << heap[0].fi << "\n";
                break;
        }
    }

    return 0;
}
