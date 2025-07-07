#include <iostream>
#include <vector>
#include <climits>
#include <cctype>
using namespace std;

int maxSumSubarray(vector<int>& arr, int m);
int maxSumSubmatrix(vector<vector<int>>& mat, int n, int m);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n) {
        cin >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        cout << maxSumSubmatrix(mat, n, m) << '\n';
    }
    cout.flush();
    return 0;
}

int maxSumSubmatrix(vector<vector<int>>& mat, int n, int m) {
    int max_val = INT_MIN;
    for (int i = 0; i < n; i++) {
        vector<int> arr(m, 0);
        for (int j = i; j < n; j++) {
            for (int k = 0; k < m; k++) {
                arr[k] += mat[j][k];
            }
            max_val = max(max_val, maxSumSubarray(arr, m));
        }
    }
    return max_val;
}

int maxSumSubarray(vector<int>& arr, int m) {
    int max_val = INT_MIN;
    int cur = 0;
    for (int i = 0; i < m; i++) {
        cur += arr[i];
        max_val = max(max_val, cur);
        cur = cur < 0 ? 0 : cur;
    }
    return max_val;
}
