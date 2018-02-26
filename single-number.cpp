class Solution {
public:
    int singleNumber(int A[], int n) {
        int t = A[0];
        for (int i = 1;i < n;i++) {
            A[0] ^= A[i];
        }
        return A[0];
    }
};