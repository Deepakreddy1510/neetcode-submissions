class Solution {
public:
    int maxElement(vector<int>& v){
        int n = v.size();
        int maxi = INT_MIN;
        for(int i=0; i < n; i++){
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    int func(vector<int>& piles, int hourly){
        int totalHrs = 0;
        for(int pile:piles){
            totalHrs += ceil((double)(pile) / (double)(hourly));
        }
        return totalHrs;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = maxElement(piles);
        int ans = INT_MAX;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            int totalHrs = func(piles, mid);

            if(totalHrs <= h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};
