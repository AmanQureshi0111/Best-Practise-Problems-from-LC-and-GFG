class Solution {
public:
    void addRemaining(string &res, vector<int> &mp) {
        for (int i = 0; i < 26; i++) {
            while (mp[i] > 0) {
                res += char('a' + i);
                mp[i]--;
            }
        }
    }

    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> mp(26, 0);

        for (char c : s) mp[c - 'a']++;

        string g = "";
        for (int i = 0; i < n; i++) {
            int ch = target[i] - 'a';
            bool found=false;
            // Try placing the same char as target[i]
            if (mp[ch] > 0) {
                mp[ch]--;
                g += target[i];
            } else {
                // Need to find next possible greater char
                for (int j = ch + 1; j < 26; j++) {
                    if (mp[j] > 0) {
                        g += char('a' + j);
                        mp[j]--;
                        addRemaining(g, mp);
                        found=true;
                        return g; // strictly greater found
                    }
                }
                while(!g.empty()){
                    ch=g.back()-'a'; g.pop_back();
                    mp[ch]++;
                    for (int j = ch + 1; j < 26; j++) {
                        if (mp[j] > 0) {
                            g += char('a' + j);
                            mp[j]--;
                            addRemaining(g, mp);
                            return g; // strictly greater found
                        }
                    }
                }
                break;
            }
        }

        next_permutation(g.begin(),g.end());
        if(g>target) return g;
        return "";
    }
};
