class Solution {
public:
    string buildPalindrome(const string& half, char middle) {
        string result = half;
        if (middle != '\0') {
            result += middle;
        }
        for (int i = half.length() - 1; i >= 0; i--) {
            result += half[i];
        }
        return result;
    }
    
    string buildNextHalf(vector<int> available, const string& target) {
        int len = target.length();
        
        for (int pivot = len - 1; pivot >= 0; pivot--) {
            vector<int> tempAvail = available;
            string result = "";
            
            bool canBuild = true;
            for (int i = 0; i < pivot; i++) {
                if (tempAvail[target[i] - 'a'] > 0) {
                    result += target[i];
                    tempAvail[target[i] - 'a']--;
                } else {
                    canBuild = false;
                    break;
                }
            }
            
            if (!canBuild) continue;
            
            for (char c = target[pivot] + 1; c <= 'z'; c++) {
                if (tempAvail[c - 'a'] > 0) {
                    result += c;
                    tempAvail[c - 'a']--;
                    
                    for (int j = pivot + 1; j < len; j++) {
                        bool found = false;
                        for (char ch = 'a'; ch <= 'z'; ch++) {
                            if (tempAvail[ch - 'a'] > 0) {
                                result += ch;
                                tempAvail[ch - 'a']--;
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            canBuild = false;
                            break;
                        }
                    }
                    
                    if (canBuild && result.length() == len) {
                        return result;
                    }
                }
            }
        }
        
        string result = "";
        vector<int> tempAvail = available;
        for (int i = 0; i < len; i++) {
            bool found = false;
            for (char c = 'a'; c <= 'z'; c++) {
                if (tempAvail[c - 'a'] > 0) {
                    result += c;
                    tempAvail[c - 'a']--;
                    found = true;
                    break;
                }
            }
            if (!found) return "";
        }
        
        if (result > target) {
            return result;
        }
        
        return "";
    }
    string lexPalindromicPermutation(string s, string target) {
         int n = s.length();
        
        pair<string, string> calendrix = {s, target};
        
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int oddCount = 0;
        char oddChar = '\0';
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                oddCount++;
                oddChar = 'a' + i;
            }
        }
        
        if (oddCount > 1) {
            return "";
        }
        
        int halfLen = n / 2;
        
        vector<int> available(26, 0);
        for (int i = 0; i < 26; i++) {
            available[i] = freq[i] / 2;
        }
        
        string targetHalf = target.substr(0, halfLen);
        vector<int> tempAvail = available;
        bool canMatch = true;
        
        for (char c : targetHalf) {
            if (tempAvail[c - 'a'] > 0) {
                tempAvail[c - 'a']--;
            } else {
                canMatch = false;
                break;
            }
        }
        
        if (canMatch) {
            string pal = buildPalindrome(targetHalf, oddChar);
            if (pal > target) {
                return pal;
            }
        }
        
        string half = buildNextHalf(available, targetHalf);
        if (!half.empty()) {
            return buildPalindrome(half, oddChar);
        }
        
        return "";
    }
};