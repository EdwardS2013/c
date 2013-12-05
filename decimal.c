
char num_to_char(int num) {
    return num + '0';
}

// 00000000 ~ 11111111 (d. 0~255)
// 999 = 1000 - 1
// 11111111(d.255) = 100000000(d.256) - 1(d.1)
// MSD, LSD
// 4892
// |  |
/*
void print_decimal(int num) {
    int pos = 19;
    char str[20] = {0};
    while(num) {
        int lsd = num % 10;
        num = num / 10;

        pos -= 1;
        str[pos] = num_to_char(lsd);
    }
    printf("%s\n", str + pos);
}
*/

