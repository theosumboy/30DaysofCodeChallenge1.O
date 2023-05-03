class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mpp1;
        map<int,int>mpp2;
        for(auto it : nums1){
            mpp1[it]++;
        }
        for(auto it : nums2){
            mpp2[it]++;
        }
        set<int>st1;
        set<int>st2;
        for(auto it : nums1){
            if(mpp2[it] == 0){
                st1.insert(it);
            }
        }
        for(auto it : nums2){
            if(mpp1[it] == 0){
                st2.insert(it);
            }
        }
        vector<int>ans1;
        vector<int>ans2;
        vector<vector<int>>ans;
        for(auto it : st1){
            ans1.push_back(it);
        }
        for(auto it : st2){
            ans2.push_back(it);
        }
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};
