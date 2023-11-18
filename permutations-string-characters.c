#include <stdio.h>
#include <stdlib.h>

char s[11];
int n;
void swap(char *a, char *b) {
    char temep = *a;
    *a = *b;
    *b = temp;
}
void solve() {
    if (l==r) printf("%s\n", s);
    for (int ind = 1; ind <= r; ind++) {
        swap(&s[l], &s[ind]);
        solve(l+1, r, s);
        swap(&s[l], &s[ind]);
    }
}
int main() {
    scanf("%s", s);
    n = strlen(s);
    solve(0, n-1, s);
}
