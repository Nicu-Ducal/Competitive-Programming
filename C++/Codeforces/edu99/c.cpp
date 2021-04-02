/*
i64 x;
cin >> x;
double delta = sqrt(1 + 8 * x);
i64 sum = (-1 + i64(delta)) / 2 + (double(delta) != i64(delta));
i64 ans = sum + i64(sum * (sum + 1) / 2) - x;
if (x == 1) cout << "1\n";
else if (x == 2) cout << "3\n";
else cout << min(x - 1, ans) << "\n";*/
