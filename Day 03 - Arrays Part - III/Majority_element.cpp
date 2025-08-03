#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity --> O(n^2) and O(1)
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int maxcount=0;
//         int index=-1;
//         int n=nums.size();

//         for(int i=0;i<n;i++)
//         {
//             int count=0;
//             for(int j=0;j<n;j++)
//             {
//                 if(nums[i]==nums[j])
//                 {
//                     count++;
//                 }
//             }

//             // update maxcount if count of current element is greater

//             if(count>maxcount)
//             {
//                 maxcount=count;
//                 index=i;
//             }
//         }

//         if(maxcount>n/2)
//         {
//             return nums[index];
//         }
        
//         return -1;
//     }
// };

// Better Approach [Sorting]
// Time complexity --> O(nlogn) and Space -> O(1)

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         return nums[n/2];
//     }
// };

// Hash Map Approach 
//Time complexity ---> O(n) and space ---> O(n/2)~ O(n)
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {

//         int n=nums.size();
//         map<int, int> mp;
//         for(auto it: nums)
//         {
//             mp[it]++;
//             if(mp[it]>n/2)
//             {
//                 return it;
//             }
//         }
//         return -1;
//     }
// };

// Optimizating the above code to reduce the space complexity, by using moore's voting algorithm


// Optimized Approach [Moore's Voting Algorithm]
// Time complexity --> O(n) and space --> O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                ele=nums[i];
                count=1;
            }
            else if(nums[i]==ele)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return ele;
    }
};



/*
1. Question link --> https://leetcode.com/problems/majority-element/description/

2. Video Link --> https://youtu.be/nP_ns3uSh80

3. Solution link -> https://leetcode.com/problems/majority-element/solutions/3796648/4-approach-easy-c-solution-brute-force-sorting-hashmap-optimized-approach/

4. Helpful Resource --> https://www.geeksforgeeks.org/majority-element/

*/

/*
Follow UP: Verifying the element -> Majority Element

The task is to complete the function majorityElement() which 
returns the majority element in the array. If no majority exists, return -1
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                ele=nums[i];
                count=1;
            }
            else if(nums[i]==ele)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ele)
            {
                count++;
            }
        }
        if(count>nums.size()/2)
        {
            return ele;
        }
        return -1;
    }
};
