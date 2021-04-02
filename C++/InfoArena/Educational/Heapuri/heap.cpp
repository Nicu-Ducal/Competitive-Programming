#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
typedef unsigned long long ul;
typedef long long ll;
using namespace std;

const int MAX_HEAP_SIZE = 16384;
typedef int Heap[MAX_HEAP_SIZE];

ll n, op, x;
vector <ll> heap;

inline int father(int nod) {
    return nod / 2;
}

inline int left_son(int nod) {
    return nod * 2;
}

inline int right_son(int nod) {
    return nod * 2 + 1;
}

void sift(Heap H, int N, int K) {
    int son;
    do {
        son = 0;
        // Alege un fiu mai mare ca tatal.
        if (left_son(K) <= N) {
            son = left_son(K);
            if (right_son(K) <= N && H[right_son(K)] > H[left_son(K)])
                son = right_son(K);
            if (H[son] <= H[K])
                son = 0;
        }
        if (son) {
            swap(H[K], H[son]);
            K = son;
        }
    } while (son);
}


void percolate(Heap H, int N, int K) {
    int key = H[K];
    while ((K > 1) && (key > H[father(K)])) {
        H[K] = H[father(K)];
        K = father(K);
    }
    H[K] = key;
}

void build_heap(Heap H, int N) {
    for (int i = N / 2; i > 0; --i)
        sift(H, N, i);
}

void erase(Heap H, int& N, int K) {
    H[K] = H[N];
    --N;

    if ((K > 1) && (H[K] > H[father(K)]))
        percolate(H, N, K);
    else
        sift(H, N, K);
}

void insert(Heap H, int& N, int key) {
    H[++N] = key;
    percolate(H, N, N);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    ifstream cin("heapuri.in");
    //ofstream cout("heapuri.out");

    heap.pb(-1);
    cin >> n;
    while(n--){
        cin >> op;
        if (op == 1 || op == 2)
            cin >> x;

        if (op == 1){
            heap.pb(x);

        }
        else if (op == 2){

        }
        else
            cout << heap[1] << "\n";
    }

    return 0;
}
