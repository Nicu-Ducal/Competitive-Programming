with open('maxsecv.in') as f:
    n = int(f.readline())
    l = sorted([len(x) for x in f.readline().replace(' ', '').split('0')])

with open('maxsecv.out', "w+") as f:
    f.write(str(l[-2] + l[-1]))
