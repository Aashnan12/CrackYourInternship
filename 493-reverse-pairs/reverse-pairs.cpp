#include <vector>
using namespace std;

class Solution {
public:
    int count;

    void Merge(vector<int> &arr, int s, int mid, int e, int n) {
        vector<int> sorted(e - s + 1);
        int idx = 0;
        int i = s;
        int j = mid + 1;

        // Counting the reverse pairs
        int l = s, r = mid + 1;
        while (l <= mid && r <= e) {
            if (arr[l] > 2LL * arr[r]) {
                count += (mid - l + 1); // All elements from l to mid will satisfy the condition
                r++;
            } else {
                l++;
            }
        }

        // Merging the two halves
        while (i <= mid && j <= e) {
            if (arr[i] <= arr[j]) {
                sorted[idx++] = arr[i++];
            } else {
                sorted[idx++] = arr[j++];
            }
        }
        while (i <= mid) {
            sorted[idx++] = arr[i++];
        }
        while (j <= e) {
            sorted[idx++] = arr[j++];
        }
        for (int k = s; k <= e; k++) {
            arr[k] = sorted[k - s];
        }
    }

    void MergeSort(vector<int>& nums, int s, int e, int n) {
        if (s >= e) {
            return;
        }
        int mid = (s + e) / 2;
        MergeSort(nums, s, mid, n);
        MergeSort(nums, mid + 1, e, n);
        Merge(nums, s, mid, e, n);
    }

    int reversePairs(vector<int>& nums) {
        count = 0;
        MergeSort(nums, 0, nums.size() - 1, nums.size());
        return count;
    }
};
