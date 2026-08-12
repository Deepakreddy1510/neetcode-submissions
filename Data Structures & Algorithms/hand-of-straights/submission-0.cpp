class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0){
            return false;
        }

        // We use map instead of unordered map to store the sorted numbers
        map<int,int> freq;

        // Store the freq of each number in map
        for(int num:hand){
            freq[num]++;
        }

        while(!freq.empty()){
            //Smallest remaining number
            int start = freq.begin()->first;

            for(int x=start; x < start + groupSize; x++){
                if(freq[x] == 0){
                    return false;
                }

                freq[x]--;
                if(freq[x] == 0){
                    freq.erase(x);
                }
            }
        }

        return true;

    }
};