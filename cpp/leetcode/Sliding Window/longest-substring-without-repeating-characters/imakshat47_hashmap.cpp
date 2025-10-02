class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m; // Hash map to keep track of characters currently in the window
        int ans = 0;               // Stores the maximum length found so far
        int st = 0, en = 0;        // Two pointers: 'st' for start of window, 'en' for end
        int n = s.length();        // Length of the input string

        // Sliding window approach
        while(en < n){
            // If the current character already exists in the window,
            // move the start pointer forward and remove that character
            // until we get rid of the duplicate
            if(m.contains(s[en])){
                m.erase(s[st]);
                ++st;
            } 
            // Otherwise, add the new character to the window
            else {
                m[s[en++]];  // Insert the character and move 'en' forward
            }
            
            // Update the maximum length as difference between pointers
            ans = max(ans, en - st);
        }

        return ans; // Return the length of the longest substring without repeating characters
    }
};

/*
💡 Explanation (in simple words):
This program finds the length of the longest substring where no characters repeat.  
It uses a sliding window and a hash map:
- 'st' and 'en' represent the current window (substring).
- If a character repeats, we shrink the window from the left by erasing characters.
- If it's unique, we expand the window by adding the character.
- At each step, we calculate the window size (en - st) and keep track of the maximum.  
This way, we check all possible substrings in linear time.
*/
