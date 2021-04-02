f = open("algsort.in", 'r')
g = open("algsort.out", 'w')

n = f.readline()
l = [int(x) for x in (f.readline()).split()]
l.sort()

ls = " ".join([str(x) for x in l])
g.write(ls + "\n")

f.close()
g.close()
