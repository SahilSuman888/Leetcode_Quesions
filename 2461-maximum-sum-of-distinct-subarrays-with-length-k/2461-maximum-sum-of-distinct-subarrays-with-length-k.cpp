class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq;
        
        long long sum = 0;
        long long ans = 0;
        
        int left = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            
            // Add current element
            sum += nums[right];
            freq[nums[right]]++;
            
            // Window size > k
            if (right - left + 1 > k) {
                
                sum -= nums[left];
                
                freq[nums[left]]--;
                
                // If frequency becomes 0, remove it
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                
                left++;
            }
            
            // Window size == k
            if (right - left + 1 == k) {
                
                // Number of distinct elements == k
                if (freq.size() == k) {
                    ans = max(ans, sum);
                }
            }
        }
        
        return ans;
    }
};