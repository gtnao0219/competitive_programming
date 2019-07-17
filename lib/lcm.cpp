// required
int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    int n = gcd(a, b);
    // 桁あふれを防ぐため先にgcdで割る
    return a / n * b;
}
