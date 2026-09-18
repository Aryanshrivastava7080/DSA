class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        vector<int> first(26, -1);
        vector<int> last(26, -1);

        // Find first and last occurrence
        for (int i = 0; i < s.size(); i++) {

            int c = s[i] - 'a';

            if (first[c] == -1)
                first[c] = i;

            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Try to create a valid interval for every character
        for (int c = 0; c < 26; c++) {

            if (first[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];

            bool valid = true;

            for (int i = l; i <= r; i++) {

                int x = s[i] - 'a';

                // This character started before our interval
                if (first[x] < l) {
                    valid = false;
                    break;
                }

                // Need to include all occurrences of this character
                r = max(r, last[x]);
            }

            if (valid) {
                intervals.push_back({l, r});
            }
        }

        // Choose maximum number of non-overlapping intervals
        // Greedy: sort by ending position
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;

        int prevEnd = -1;

        for (auto &[l, r] : intervals) {

            if (l > prevEnd) {

                ans.push_back(s.substr(l, r - l + 1));

                prevEnd = r;
            }
        }

        return ans;
    }
};