class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // Step 1: Input digits ki frequency count store karein
        int freq[10] = {0};
        for (int d : digits) {
            freq[d]++;
        }

        int count = 0;

        // Step 2: 100 se 998 tak sirf EVEN numbers check karein
        for (int i = 100; i < 1000; i += 2) {
            int d1 = i / 100;       // Hundreds digit
            int d2 = (i / 10) % 10; // Tens digit
            int d3 = i % 10;        // Units digit (Even)

            // Current number ki digits ka count nikalein
            int numFreq[10] = {0};
            numFreq[d1]++;
            numFreq[d2]++;
            numFreq[d3]++;

            // Step 3: Check karein ki kya ye number humare paas majood digits se ban sakta hai
            if (numFreq[d1] <= freq[d1] && 
                numFreq[d2] <= freq[d2] && 
                numFreq[d3] <= freq[d3]) {
                count++;
            }
        }

        return count;
    }
};