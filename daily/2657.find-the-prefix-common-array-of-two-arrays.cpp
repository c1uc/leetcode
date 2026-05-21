class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unsigned long long mask_a = 0;
        unsigned long long mask_b = 0;

        for(int i = 1;i <= A.size();i++) {
            mask_a |= 1ull << (A[i - 1] - 1);
            mask_b |= 1ull << (B[i - 1] - 1);
            A[i - 1] = popcount(mask_a & mask_b);
        }
        return A;
    }
};
