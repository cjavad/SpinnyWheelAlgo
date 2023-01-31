#include <vector>
#include <iostream>

using namespace std;

int peakpoint_alg1(int* A, int n) {
    if (A[0] > A[1]) return 0;
    for (int i = 1; i < n - 2; i++) {
        if (A[i-1] <= A[i] && A[i] >= A[i+1]) return i;
    }
    if (A[n-2] <= A[n-1]) return n - 1;
    return -1;
}

int main() {
    int n;
    cin >> n;

    // Read next line as array 
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    // Find peak point
    int peak = peakpoint_alg1(A.data(), n);
    cout << peak << endl;
    flush(cout);
    
    return 0;
}