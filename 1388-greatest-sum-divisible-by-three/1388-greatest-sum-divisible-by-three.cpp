class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int maxSumDivThree(VI& A) {
        int N = A.size();
        VVI buckets(N + 1, VI(3));
        for (auto i{ 1 }; i <= N; ++i) {
            buckets[i] = buckets[i - 1]; // create current from previous \U0001f914
            for (auto j: VI{ 0, 1, 2 }) {
                auto sum = A[i - 1] + buckets[i - 1][j]; // add A[i] onto each previous bucket (A[i - 1] for A[i] because buckets is offset by 1)
                buckets[i][sum % 3] = max(buckets[i][sum % 3], sum); // update each (current sum % 3) bucket to max of itself and the current sum
            }
        }
        return buckets[N][0]; // max sum of all N items of A which is evenly divisible by 3 \U0001f3af
    }
};