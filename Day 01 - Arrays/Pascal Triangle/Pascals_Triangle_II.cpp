#include <bits/stdc++.h>
using namespace std;

/*
Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.
*/

// Brute Force Approach
// Time complexity --> O(n^2) and space --> O(1) where n=rowIndex
// class Solution {
// public:
//     vector<int> getRow(int rowIndex) {

//         vector<int> result(rowIndex+1,1);
//         for(int i=1;i<rowIndex;i++)
//         {
//             for(int j=i;j>0;j--)
//             {
//                 result[j]=result[j]+result[j-1];
//             }
//         }
//         return result;
//     }
// };

// Better Approach
// Time complexity -> O(n*c) and Space -> O(n) 
// where n=rowIndex and c = columnIndex
// class Solution {
// private:
//     int nCr(int n, int r)
//     {
//         long long res=1;
//         for(int i=0;i<r;i++)
//         {
//             res=res*(n-i);
//             res=res/(i+1);
//         }
//         return res;
//     }
// public:
//     vector<int> getRow(int rowIndex) {

//         vector<int> result;
//         for(int c=0;c<=rowIndex;c++)
//         {
//             result.push_back(nCr(rowIndex,c));
//         }
//         return result;
//     }
// };


// Optimized Approach
// Time complexity -> O(n) and Space -> O(n)
// where n= rowIndex
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        long long ans=1;
        result.push_back(ans);
        for(int i=1;i<rowIndex+1;i++)
        {
            ans=ans*(rowIndex+1-i);
            ans=ans/i;
            result.push_back(ans);
        }
        return result;
    }
};

/*

1. Question link -- https://leetcode.com/problems/pascals-triangle-ii/

2. Solution link -- https://leetcode.com/problems/pascals-triangle-ii/solutions/3007877/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/

3. Video Link -- https://youtu.be/bR7mQgwQ_o8

*/