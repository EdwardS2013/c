
// 1, 1, 2, 3, 5, 8
// fib(0) == 1, fib(1) == 1
// fib(n) == fib(n-1) + fib(n-2)
int fib(int n) {
    int n2 = 1, n1 = 1, tmp;
    for(; n > 0; n--) {
        tmp = n1 + n2;
        n1 = n2;
        n2 = tmp;
    }

    return n2;
}

