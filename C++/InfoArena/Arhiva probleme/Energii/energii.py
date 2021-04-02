with open('energii.in') as f:
    g = int(f.readline())
    e = int(f.readline())
    gen = [(0,0)]
    for line in f:
        gen.append((int(line.split()[0]), int(line.split()[1])))

dp =