f = open('int.in')
n = int(f.readline())
l = []
for i in range(n):
    a,b = map(int, f.readline().split())
    l.append((a,b))
f.close()

l.sort(key = lambda x: x[1])

rsp = []
rsp.append(l[0])
for tup in l[1:]:
    if tup[0] >= rsp[-1][1]:
        rsp.append(tup)

f = open('int.out',"w")
#for tup in rsp:
   # f.write(str(tup[0]) + " " + str(tup[1]) + "\n")
f.write(str(len(rsp)))
f.close()