#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:

    vector<int> process_lot(vector<int>& sol, vector<int>& nums1, vector<int>& nums2, int index1, int index2)
    {
        int val1 = nums1[index1]; int val2 = nums2[index2];
        if (val1 < val2)
        {   
            int last = index1;
            sol.push_back(val1);
            for (int i=index1+1; nums1[i] < val2; i++){
                sol.push_back(nums1[i]);
                last = i;
            }
            sol.push_back(val2);
            return {last+1, index2+1};
        }
        else if (val1 > val2)
        {   
            int last = index2;
            sol.push_back(val2);
            for (int i=index2+1; nums1[i] < val1; i++){
                sol.push_back(nums1[i]);
                last = i;
            }
            sol.push_back(val1);
            return {last+1, index1+1};
        }
        else
            return {index1, index2};
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sol = {};
        vector<int> next_cords = process_lot(sol, nums1, nums2, 0, 0);

        cout << next_cords[0] << next_cords[1] << endl;
        return 0.0;
    }

    Solution()
    {
        return;
    }

};

int main(){
    vector<int> var1 = {1,2};
    vector<int> var2 = {3,4};

    Solution* s = new Solution();

    s->findMedianSortedArrays(var1, var2);
};