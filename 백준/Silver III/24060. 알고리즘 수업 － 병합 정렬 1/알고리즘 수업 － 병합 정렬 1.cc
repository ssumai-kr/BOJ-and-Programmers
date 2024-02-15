#include <iostream>
#include <vector>
using namespace std;

class MergeSort {
public:
    vector<int> record;
    void mergeSort(vector<int>& A, int p, int r) {
        if (p < r) {
            int q = (p + r) / 2;
            mergeSort(A, p, q);
            mergeSort(A, q + 1, r);
            merge(A, p, q, r);
        }
    }

    void merge(vector<int>& A, int p, int q, int r) {
        int i = p;
        int j = q + 1;
        int t = 0;
        vector<int> tmp(r - p + 1);

        while (i <= q && j <= r) {
            if (A[i] <= A[j])
                tmp[t++] = A[i++];
            else
                tmp[t++] = A[j++];
        }

        while (i <= q)
            tmp[t++] = A[i++];

        while (j <= r)
            tmp[t++] = A[j++];

        i = p; t = 0;
        while (i <= r) {
            A[i++] = tmp[t++];
            record.push_back(tmp[t - 1]);
        }
    }

    void solution() {
        int n, k; cin >> n >> k;
        vector<int> A(n);

        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            A[i] = a;
        }
        mergeSort(A, 0, n - 1);
        if (k > record.size()) cout << -1;
        else cout << record[k - 1];
    }
};

int main() {
    MergeSort run;
    run.solution();
    return 0;
}