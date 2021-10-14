

int numSquares(int n) {
    while (n % 4 == 0)              // Legendre's 3 square theorem, calculate 4^k, keep dividing n by 4, until remainder is not 0
        n /= 4;

    if (n % 8 == 7)                 // Legendre's 3 square theorem, if n mod 8 yeilds remainder 7, then n is of form 4^k(8*m + 7)
        return 4;                   // thus we definitely will have more than 3 perfect squares, return 4
    
    for (int a=0; a*a<=n; ++a) {    // iterate over n in brute force manner 
        int b = sqrt(n - a*a);      // check if number - perfect square yeilds a perfect square for us
        if (a*a + b*b == n)         
            return 1 + !!a;         // if a == 0, return 1, otherwise return 2
    }
    
    return 3;                       // we know a number cannot have 1,2 or 4 perfect squares, so it must be 3, just return it
}
