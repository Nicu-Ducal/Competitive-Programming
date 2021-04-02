ans, test_cases = 0, []
with open("input.txt") as inp:
    test_cases = [tc.rstrip() for tc in inp.readlines()]

for tc in test_cases:
    tmp = tc.split()
    num_range = list(map(int, tmp[0].split("-")))
    char = tmp[1][0]
    if (num_range[0] <= tmp[2].count(char) <= num_range[1]):
        ans += 1

print(ans)
