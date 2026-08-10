class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int total = tasks.size();
        vector<int> hash(26,0);
        int maxf = 0;
        int maxCount = 0;

        for(char task:tasks){
            hash[task - 'A']++;
            maxf = max(maxf, hash[task - 'A']);
        }

        for(int i=0; i < 26; i++){
            if(maxf == hash[i]){
                maxCount++;
            }
        }

        int ans = (maxf - 1)*(n+1) + maxCount; // (no of gaps - 1)*(n white spaces + 1 character) + maxCount
        return max(total, ans); // For edge case AAABBBCCCDDD min no of cycles is total no of tasks. 
    }
};
