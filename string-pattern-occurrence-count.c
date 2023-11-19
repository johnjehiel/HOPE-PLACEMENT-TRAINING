#include <stdio.h>
#include <string.h>
// KMP ALGORITHM
int main() {
    char s[1000001], pat[1000001];
    scanf("%s%s", s, pat);
    int n = strlen(s), plen = strlen(pat);
    int lps[plen], streak = 0;
    lps[0] = 0;
    for (int i=1; i<plen; i++) {
        if (pat[i]==pat[streak]) {
            streak++;
            lps[i] =lps[i-1] + 1;
        } else {
            streak = 0;
            lps[i] = 0;
        }
    }
    int count = 0, lind = 0;
    for (int i=0; i<n;) {
        if (s[i]==pat[lind]) {
            i++;
            pat[lind]++;
            if (lind==plen) {
                count++;
                lind = 0;
            }
        } else {
            if (lind==0)
                i++;
            else
                lind = lps[lind-1];
        }
    } 

    return 0;
}
