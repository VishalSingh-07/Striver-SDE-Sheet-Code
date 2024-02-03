/*
Key Pair

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].


Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]


Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++

// Brute Force Approach
// Time complexity -> O(n^2) and Space -> O(1)
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    for(int i=0;i<n;i++)
	    {
	        for(int j=i+1;j<n;j++)
	        {
	            if(arr[i]+arr[j]==x)
	            {
	                return true;
	            }
	        }
	    }
	    return false;
	}
};

// Above code give time limit Exceeded due to high time complexity.

// Better Approach
// Time complexity -> O(n) and Space -> O(n)
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    unordered_map<int,int> mpp;
	    for(int i=0;i<n;i++)
	    {
	        if(mpp.find(x-arr[i])!=mpp.end())
	        {
	            return true;
	        }
	        mpp[arr[i]]=i;
	    }
	    return false;
	}
};


// Optimized Approach
// Time complexity -> O(nlogn) and Space -> O(1)
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    sort(arr,arr+n);
	    int left=0;
	    int right=n-1;
	    while(left<right)
	    {
	        if(arr[left]+arr[right]==x)
	        {
	            return true;
	        }
	        else if(arr[left]+arr[right]<x)
	        {
	            left++;
	        }
	        else
	        {
	            right--;
	        }
	    }
	    return false;
	}
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}

// } Driver Code Ends


/*

1. Question link -- https://practice.geeksforgeeks.org/problems/key-pair5616/1

2. Video Link -- https://youtu.be/UXDSeD9mN-k

*/