class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        // optimised: BFS/Sliding Window     T/C: O(N) S/C: O(N)
        // create rechable array for n indexes
        // keep a variable farthest, which tells how far have checked, (remembers Till which index have I already processed jumps?)
        // start next search within start as max(farthest, i+minJump) & end as max(i+maxJump, n-1)
        // this will eliminate the rechaking of indexes within range [i+minJump <-> farthest]
        // make 0's rechable which are in range [start <-> end]
        // if current index is not rechable then skip that iteration
        // at last return rechable[n-1]

        int n = s.size();

        if(s[0] != '0' || s[n-1] != '0')
            return false;

        vector<bool> rechable(n, false);
        rechable[0] = true;

        int farthest = -1;      // use it as starting point for nexxt search, rather  than i+minJump to reduce iterations

        for(int i = 0; i < n; i++) {
            if(!rechable[i])     continue;

            int start = max(i+minJump, farthest);
            int end = min(i+maxJump, n-1);

            for(int j = start; j <= end; j++) {
                if(s[j] == '0')
                    rechable[j] = true;
            }

            farthest = end;
        }

        return rechable[n-1];
    }
};