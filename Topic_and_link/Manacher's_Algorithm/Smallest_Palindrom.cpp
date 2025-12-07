class Solution {
public:
    string preprocess(const string &s) {
        string t = "#";
        for (char c : s) {
            t += c;
            t += "#";
        }
        return t;
    }

    string shortestPalindromicSubstring(string s) {
        if (s.empty()) return "";

        string t = preprocess(s);
        int n = t.size();
        vector<int> P(n, 0);
        int center = 0, right = 0;

        int minLength = INT_MAX;
        int resultCenter = -1;

        for (int i = 0; i < n; ++i) {
            int mirror = 2 * center - i;

            if (i < right)
                P[i] = min(right - i, P[mirror]);

            while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 &&
                   t[i + P[i] + 1] == t[i - P[i] - 1])
                ++P[i];

            if (i + P[i] > right) {
                center = i;
                right = i + P[i];
            }

            // Only consider palindromes of length >= 2 in real characters
            int realLen = 0;
            for (int j = i - P[i]; j <= i + P[i]; ++j)
                if (t[j] != '#') ++realLen;

            if (realLen >= 2 && realLen < minLength) {
                minLength = realLen;
                resultCenter = i;
            }
        }

        // Reconstruct the substring from resultCenter
        int start = (resultCenter - P[resultCenter]) / 2;
        return s.substr(start, minLength);
    }
};
