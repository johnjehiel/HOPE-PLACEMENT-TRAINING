#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    int r, c, ans = 0;
    cin >> r >> c;
    vector<vector<int>> mat(r, vector<int> (c, 0));
    vector<vector<int>> dp(r, vector<int> (c, 0)); // tabulation
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> mat[i][j];
            if (i==0 || j==0) dp[i][j] = mat[i][j];
            ans = max(ans, mat[i][j]);
        }
    }
    for (int i=1; i<r; i++) {
        for (int j=1; j<c; j++) {
            if (mat[i][j]==1) {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}); // min(top, topleft, left)
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}
