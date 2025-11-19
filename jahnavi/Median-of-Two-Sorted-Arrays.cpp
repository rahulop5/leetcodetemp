class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int m = nums1.size();
        int n = nums2.size();
        int mn = m + n;
        int idx2 = mn/2;
        int idx1 = idx2 - 1;
        int idx1el = -1;
        int idx2el = -1;
        int count = 0;

        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                if(count == idx1) idx1el = nums1[i];
                if(count == idx2) idx2el = nums1[i];
                count++;
                i++;
            } else {
                if(count == idx1) idx1el = nums2[j];
                if(count == idx2) idx2el = nums2[j];
                count++;
                j++;
            }
        }

        while(i < m){
            if(count == idx1) idx1el = nums1[i];
            if(count == idx2) idx2el = nums1[i];
            count++;
            i++;
        }

        while(j < n){
            if(count == idx1) idx1el = nums2[j];
            if(count == idx2) idx2el = nums2[j];
            count++;
            j++; 
        }

        if(mn % 2 == 1) return idx2el;
        return (idx1el + idx2el) / 2.0;
    }
};