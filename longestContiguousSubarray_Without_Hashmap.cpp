class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        
       vector<int> pos(2*n+1, -2);
           
        int mx = 0, s = 0;
        pos[n] = -1;
                
        for(int i = 0; i < n; i++){
            s += (nums[i] == 0 ? -1 : 1);
            if(pos[s+n] == -2)pos[s+n] = i;
            else mx = max(mx, i - pos[s+n]);
        }
        
    
        return mx;
    }
};
