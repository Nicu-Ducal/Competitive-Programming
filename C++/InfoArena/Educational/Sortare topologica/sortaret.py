from queue import Queue

with open('sortaret.in') as f:
    n, m = map(int, f.readline().split())
    g = {x: [] for x in range(1, n + 1)}
    pred = [0] * (n + 1)
    for i in range(m):
        x, y = map(int, f.readline().split())
        g[x].append(y)
        pred[y] += 1

zero = [x for x in range(1, n + 1) if pred[x] == 0]

st = []
q = Queue()
for x in zero:
    q.put(x)
    st.append(x)
    while not q.empty():
        curr = q.get()
        for succ in g[curr]:
            pred[succ] -= 1
            if pred[succ] == 0:
                st.append(succ)
                q.put(succ)

with open("sortaret.out", "w") as f:
    for x in st:
        print(x, end=" ", file=f)
