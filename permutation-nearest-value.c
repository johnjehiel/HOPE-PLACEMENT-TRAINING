#include <stdio.h>
#include <stdlib.h>

int n, x, len = 0, ans;
int arr[9] = {0}, vis[9] = {0};
void solve(int i, int cur) {
    if (i==len) {
        if (abs(ans - x) > abs(cur - x))
            ans = cur;
        return ;
    }
    for (int ind = 0; ind < len; ind++) {
        if (!vis[ind]) {
            vis[ind] = 1;
            solve(i+1, cur*10, + arr[ind]);
            vis[ind] = 0;
        }
    }
}
int main() {
    scanf("%d %d", &n, &x);
    int temp = n;
    ans = n;
    while (temp>0) {
        temp/=10;
        len++;
    }
    for (int i = len - 1; i >= 0; i--) {
        arr[i] = n%10;
        n/=10;
    }
    solve(0, 0);
    printf("%d", ans);
}
