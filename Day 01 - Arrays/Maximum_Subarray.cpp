#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n^3) and Space --> O(1)
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n=nums.size();
//         int max_sum=INT_MIN;
//         if(n==1)
//         {
//             return nums[0];
//         }
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i;j<n;j++)
//             {
//                 int sum=0;
//                 for(int k=i;k<=j;k++)
//                 {
//                     sum=sum+nums[k];
//                 }
//                 if(sum>max_sum)
//                 {
//                     max_sum=sum;
//                 }
//             }
//         }
//         return max_sum;
        
//     }
// };

// Above code ❌ give Time limit exceeded due to high time complexity O(n^3) 

// Better Approach
// Time complexity --> O(n^2) and Space --> O(1)
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n=nums.size();
//         int max_sum=INT_MIN;
//         if(n==1)
//         {
//             return nums[0];
//         }
//         for(int i=0;i<n;i++)
//         {
//             int sum=0;
//             for(int j=i;j<n;j++)
//             {
//                 sum+=nums[j];
//                 if(sum>max_sum)
//                 {
//                     max_sum=sum;
//                 }
//             }
//         }
//         return max_sum;
        
//     }
// };

// Above code ❌ give Time limit exceeded due to high time complexity O(n^2) 

// Optimized Approach [Kadane's Algorithm]
// Time complexity --> O(n) and Space --> O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int maxi=nums[0];
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0)
            {
                sum=0;
            }
        }
        return maxi;
        
    }
};


// Follow up Question
class Solution {
public:
      int maxSubArray(vector<int>& nums) {
            int n=nums.size();
            int sum=0,start=0;
            int ansStart=-1,ansEnd=-1;
            int maxi=INT_MIN;
            for(int i=0;i<n;i++)
            {
                if(sum==0)
                {
                      start=i;
                }
                sum+=nums[i];

                if(sum>maxi)
                {
                      maxi=sum;
                      ansStart=start;
                      ansEnd=i;
                }
                if(sum<0)
                {
                    sum=0;
                }
            }

            // Printing the subarray:
            cout<<"The Subarray is : [ ";
            for(int i=ansStart;i<=ansEnd;i++)
            {
                  cout<<nums[i]<<" ";
            }
            cout<<" ]"<<endl;
            return maxi;
      }
};

int main()
{
      Solution s1;
      int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
      int n = sizeof(arr) / sizeof(arr[0]);
      vector<int> nums(arr,arr+n);
      long long maxSum = s1.maxSubArray(nums);
      cout << "The maximum subarray sum is: " << maxSum << endl;
      return 0;
}



/*
1. Question link -- https://leetcode.com/problems/maximum-subarray/

2. My Solution link -- https://leetcode.com/problems/maximum-subarray/solutions/3206363/3-approach-to-solve-a-problem-easy-c-solution-dry-run-of-optimized-solution/

3. Video link --

      i) https://youtu.be/AHZpyENo7k4

      ii) https://youtu.be/w_KEocd__20

      iii) https://youtu.be/w4W6yya1PIc
*/