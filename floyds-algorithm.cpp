// 
// LINKED LIST ALGORITHMS
//

// Floyds Cycle Detection Algorithm

// 1. Create two pointers slow and fast at head of the list
// 2. Advance slow by one and fast by two.
// 3. If the pointers meet, there is a cycle


// If there are k steps before the cycle starts, and m steps in the cycle
// slow and fast will meet m-k steps into the cycle. 
// This means the point they meet is k steps from the start of the cycle.


// Case where this property is used: LC 287: Find the Duplicate Number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(slow == 0 || slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
