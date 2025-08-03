/*
Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.
*/
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity -> O(n*n*r) ~ O(n^3) and Space -> O(1)
// Constant space. Because we are creating 2D vector output as per the demand of program.
// class Solution {
// private:
//     int nCr(int n, int r)
//     {
//         long long ans=1;
//         for(int i=0;i<r;i++)
//         {
//             ans=ans*(n-i);
//             ans=ans/(i+1);
//         }
//         return (int)ans;
//     }
// public:
//     vector<vector<int>> generate(int numRows) {

//         vector<vector<int>> triangle;
//         for(int row=1;row<=numRows;row++)
//         {
//             vector<int> temp;
//             for(int col=1;col<=row;col++)
//             {
//                 temp.push_back(nCr(row-1,col-1));
//             }
//             triangle.push_back(temp);
//         }
//         return triangle;
//     }

// };


// Better Approach
// Time complexity --> O(n^2) and Space --> O(1)
// Constant space. Because we are creating 2D vector output as per the demand of program.
// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {

//         vector<vector<int>> ans(numRows);

//         // i--> rows and j--> column
//         for(int i=0;i<numRows;i++)
//         {
//             ans[i].resize(i+1); // increasing the size of column
//             ans[i][0]=ans[i][i]=1; // first and last element is same

//             for(int j=1;j<i;j++)
//             {
//                 ans[i][j]=ans[i-1][j-1]+ans[i-1][j]; // Add element
//             }

//         }
        
//         return ans;
//     }
// };


// Optimized Approach
// Time complexity --> O(n^2) and Space --> O(1)
// Constant space. Because we are creating 2D vector output as per the demand of program.
class Solution {
private:
    vector<int> generateRow(int row)
    {
        long long ans=1;
        vector<int> ansRow;
        ansRow.push_back(ans);
        for(int col=1;col<row;col++)
        {
            ans=ans*(row-col);
            ans=ans/col;
            ansRow.push_back((int)ans);
        }
        return ansRow;
    }
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> triangle;
        for(int i=1;i<=numRows;i++)
        {
            triangle.push_back(generateRow(i));
        }
        return triangle;
    }

};

/*

1. Question link -- https://leetcode.com/problems/pascals-triangle/

2. Solution link --
      a) https://leetcode.com/problems/pascals-triangle/solutions/3649380/3-approach-easy-c-solution-brute-force-better-and-optimized-approach/
      
      b) https://leetcode.com/problems/pascals-triangle/solutions/3002506/pascal-triangle-easy-solution-three-way-to-do-the-pascal-triangle-problem/

3. Video link -- https://youtu.be/bR7mQgwQ_o8

*/

