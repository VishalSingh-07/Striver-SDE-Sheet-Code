/*

3. Longest Substring withour repeating characters

Given a string s, find the length of the longest  substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.


Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.


Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/


#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0)
        {
            return 0;
        }
        int longestStreak=0;
        for(int i=0;i<n;i++)
        {
            unordered_set<int> st;
            for(int j=i;j<n;j++)
            {
                if(st.find(s[j])!=st.end())
                {
                    break;
                }
                st.insert(s[j]);
                longestStreak=max(longestStreak,j-i+1);
            }
            
        }
        return longestStreak;
    }

};


// Better Approach
// Time complexity -> O(2n) and Space -> O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0 || n==1)
        {
            return n;
        }
        int left=0;
        int right=0;
        int len=INT_MIN;
        unordered_set<char> st;
        while(right<n)
        {
            if(st.find(s[right])!=st.end()) //if duplicate element is found
            {
                while (left < right && st.find(s[right]) != st.end()) 
                {
                    st.erase(s[left]);
                    left++;
                }
            }
            st.insert(s[right]);
            len = max(len, right - left + 1);
            right++;
        }
        return len;

    }

};


// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0 || n==1)
        {
            return n;
        }
        int left=0;
        int right=0;
        int len=INT_MIN;
        vector<int> mpp(256,-1);
        while(right<n)
        {
            if(mpp[s[right]]!=-1)
            {
                left=max(mpp[s[right]]+1,left);
            }
            mpp[s[right]]=right;
            len=max(len,right-left+1);
            right++;
        }
        return len;

    }

};

/*
1. Question link -- https://leetcode.com/problems/longest-substring-without-repeating-characters/

2. Solution link -- https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/3847862/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/

3. Video link -- https://youtu.be/qtVh-XEpsJo
*/


