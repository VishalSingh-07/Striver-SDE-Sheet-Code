/*

Subarray with xor k

Problem statement
Given an array ‘A’ consisting of ‘N’ integers and an integer ‘B’, find the number of subarrays of array ‘A’ whose bitwise XOR( ⊕ ) of all elements is equal to ‘B’.



A subarray of an array is obtained by removing some(zero or more) elements from the front and back of the array.



Example:
Input: ‘N’ = 4 ‘B’ = 2
‘A’ = [1, 2, 3, 2]

Output: 3

Explanation: Subarrays have bitwise xor equal to ‘2’ are: [1, 2, 3, 2], [2], [2].


Sample Input 1:
4 2
1 2 3 2
Sample Output 1 :
3
Explanation Of Sample Input 1:
Input: ‘N’ = 4 ‘B’ = 2
‘A’ = [1, 2, 3, 2]

Output: 3

Explanation: Subarrays have bitwise xor equal to ‘2’ are: [1, 2, 3, 2], [2], [2].



Sample Input 2:
4 3
1 2 3 3
Sample Output 2:
4

Sample Input 3:
5 6
1 3 3 3 5 
Sample Output 3:
2


Constraints:
1 <= N <= 10^3
1 <= A[i], B <= 10^9

Time Limit: 1-sec

*/
#include <bits/stdc++.h>
using namespace std;


// Brute Force Approach
// Time complexity -> O(n^3) and Space -> O(1)
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int  count=0;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        
        for(int j=i;j<n;j++)
        {
            int xorsum=0;
            for(int k=i;k<=j;k++)
            {
                xorsum^=a[k];
            }
            if(xorsum==b)
            {
                count++;
            }
        }
    }
    return count;
}

// Above code give time limit exceeded due to high time complexity O(n^3)


// Better Approach
// Time complexity -> O(n^2) and Space -> O(1)
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int  count=0;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        int xorsum=0;
        for(int j=i;j<n;j++)
        {
            xorsum^=a[j];
            if(xorsum==b)
            {
                count++;
            }
        }
    }
    return count;
}


// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int count=0,xorsum=0;
    unordered_map<int,int> mpp;
    mpp[xorsum]++; // {0,1}
    for(int i=0;i<a.size();i++)
    {
        xorsum^=a[i];
        int x=xorsum^b;
        count+=mpp[x];
        mpp[xorsum]++;

    }
    return count;
}


/*
1. Question Link -- https://www.codingninjas.com/studio/problems/subarrays-with-xor-k_6826258

2. Video Link -- https://youtu.be/eZr-6p0B7ME
*/