/*
Longest Subarray with sum k [Positive]

Problem statement
You are given an array 'a' of size 'n' and an integer 'k'.



Find the length of the longest subarray of 'a' whose sum is equal to 'k'.



Example :
Input: ‘n’ = 7 ‘k’ = 3
‘a’ = [1, 2, 3, 1, 1, 1, 1]

Output: 3

Explanation: Subarrays whose sum = ‘3’ are:

[1, 2], [3], [1, 1, 1] and [1, 1, 1]

Here, the length of the longest subarray is 3, which is our final answer.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
7 3
1 2 3 1 1 1 1


Sample Output 1 :
3


Explanation Of Sample Input 1 :
Subarrays whose sum = ‘3’ are:
[1, 2], [3], [1, 1, 1] and [1, 1, 1]
Here, the length of the longest subarray is 3, which is our final answer.


Sample Input 2 :
4 2
1 2 1 3


Sample Output 2 :
1


Sample Input 3 :
5 2
2 2 4 1 2 


Sample Output 3 :
1


Expected time complexity :
The expected time complexity is O(n).


Constraints :
1 <= 'n' <= 5 * 10 ^ 6
1 <= 'k' <= 10^18
0 <= 'a[i]' <= 10 ^ 9

Time Limit: 1-second
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n^3) and Space -> O(1)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n=a.size();
    int maxLen=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            long long sum=0;
            for(int k=i;k<=j;k++)
            {
                sum+=a[k];
            }
            if(sum==k)
            {
                maxLen=max(maxLen,j-i+1);
            }
        }
    }
    return maxLen;
    
}

// Better Approach
// Time complexity -> O(n^2) and Space -> O(1)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n=a.size();
    int maxLen=0;
    for(int i=0;i<n;i++)
    {
        long long sum=0;
        for(int j=i;j<n;j++)
        {
            
            sum+=a[j];
            if(sum==k)
            {
                maxLen=max(maxLen,j-i+1);
            }
        }
    }
    return maxLen;
    
}


// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n=a.size();
    map<long long,int> mpp;
    long long prefixsum=0;
    int maxLen=0;
    for(int i=0;i<n;i++)
    {
        prefixsum+=a[i];
        if(prefixsum==k)
        {
            maxLen=max(maxLen,i+1);
        }
        long long remainingsum=prefixsum-k;
        if(mpp.find(remainingsum)!=mpp.end())
        {
            maxLen=max(maxLen,i-mpp[remainingsum]);
        }
        if(mpp.find(prefixsum)==mpp.end())
        {
            mpp[prefixsum]=i;   
        }
    }
    return maxLen;
    
    
}


// Most Optimized Approach
// Time complexity -> O(n) and Space -> O(1)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n=a.size();
    int left=0,right=0;
    long long sum=a[0];
    int maxLen=0;
    while(right<n)
    {
        while(left<=right && sum>k)
        {
            sum-=a[left];
            left++;
        }
        if(sum==k)
        {
            maxLen=max(maxLen, right-left+1);
        }
        right++;
        if(right<n)
        {
            sum+=a[right];
        }
    }
    return maxLen;
    
}


/*
1. Question link -- https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399

2. Video Link -- https://youtu.be/frf7qxiN2qU
*/