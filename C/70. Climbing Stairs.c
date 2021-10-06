

int climbStairs(int n)
{
    int ans, one=1, two=2;
    
    if (n < 4)
        return n;
    
    while (3 <= n--)
    {
        ans = one + two;
        one = two;
        two = ans;
    }

    return ans;
}