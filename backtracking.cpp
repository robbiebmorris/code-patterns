//
// BACKTRACKING
//
//
//
//
// There are two primary patterns for backtracking:
//
//
// 1. Binary Choice (Include/Exclude) [NOT RECOMMENDED]
//
// We make a binary choice when there is a yes/no decision to be made.
// This is most intuitive when order does NOT matter. If order does matter,
// this is hard to use. This is because in cases where order does matter,
// the decision is not just whether to include the number but rather
// *where* AND *whether* to include this number.


// Why start+1? We start+1 when we want to not reconsider that number in the
// next decision. If this is not true, then we just use start.

// Example: LC 78: Subsets
class Solution {
private:
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& cur, int start) {
        if (start == nums.size()) {
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[start]);
        dfs(res, nums, cur, start+1);
        cur.pop_back();
        dfs(res, nums, cur, start+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, nums, cur, 0);
        return res;
    }
};


// The decision tree for a sample input [1,2,3] would look like:

// start=0                         []   
//                        /                 \
// start=1             [1]                  []
//                   /     \              /      \
// start=2        [1,2]      [1]        [2]       []
//               /   \      /    \     /   \     /  \
// start=3   [1,2,3] [1,2] [1,3] [1] [2,3]  [2] [3]  []

// So our subsets are all found at start=3.  


// 2. Loop Pattern

// Better for Permutations and Partitioning, but can also be used for the
// binary decision case. In general, I think its better to just always
// use this pattern and way of thinking.
//
// Rather than thinking about include exclude of 1 element at every 
// level of the tree, we consider ALL elements we can use at each level of 
// the tree

// For the same LC 78: Permutations:

class Solution {
private:
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& cur, int start) {
        res.push_back(cur);
        for (int i=start; i<nums.size(); ++i) {
            cur.push_back(nums[i]);
            dfs(res, nums, cur, i+1);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, nums, cur, 0);
        return res;
    }
};

// The decision tree for a sample input [1,2,3] would look like:

//                                []   
//                          /      |     \
//                     [1]        [2]     [3]
//                   /     \       |             
//                 [1,2]  [1,3]   [2,3]
//                   |
//                [1,2,3]   

// Notice the tree nodes no longer always have 2 children, and all nodes
// are part of our result. Our decision is 'Use 1? use 2? or use 3?' rather
// than 'Use 1 or not use 1'.

// A quesiton which is easy with this pattern but hard with binary choice
// is LC 46: Permutations

class Solution {
private:
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& cur, vector<int>& visited) {
        if (nums.size() == cur.size()) {
            res.push_back(cur);
        }
        for (int i=0; i<nums.size(); ++i) {
            if (visited[i] == 1) continue;
            cur.push_back(nums[i]);
            visited[i] = 1;
            dfs(res, nums, cur, visited);
            visited[i] = 0;
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<int> visited(nums.size(),0);
        dfs(res, nums, cur, visited);
        return res;
    }
};

// This pattern is important for partitioning problems, where we need
// to figure out how to partition our input.

// One such problem is LC 131. Palindrome Partitioning

// In this case, we our decision is 'substring(start, how long?)'. 
// E.g. for input 'aab', choose 'a', 'aa', or 'aab'.

class Solution {
private:
    bool isPali(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    // [a], i=1
    void dfs(vector<vector<string>>& res, string& s, vector<string>& cur, int start) {

        // base case
        if (s.size() == start) {
            res.push_back(cur);
            return;
        }

        for (int i=start; i<s.size(); ++i) {
            // s.size() - 1
            // if start is 0, then currentlyConsidering=a, aa, aab for i=0,1,2
            string currentlyConsidering = s.substr(start, i-start+1);
            if (isPali(currentlyConsidering)) {
                cur.push_back(currentlyConsidering);
                dfs(res, s, cur, i+1);
                cur.pop_back();
            }
        }

    }
public:
    vector<vector<string>> partition(string s) {
        // backtracking:

        // s = "aab"
        // cur is a vector of strings
        // base cases: 
        // if any string in cur is not a palindrome, then return;
        // if size of all strings added together = s.size(), add to our result

        // step cases / decisions:
        // partition the string.
        // e.g. level 1: we have s = "aab"
        
        // is 'a' a palidrome? yes. recurse with [a], i=1
            // now we have 'ab' to consider.
            // is 'a' a palindrome? yes. recurse with [a, a], i=2
                // now we have 'b' to consider
                // is 'b' a palindrome? yes. recursive with [a,a,b], i =3
                    // size == s.size(). base case return. add [a,a,b] to result
            // is 'ab' a palindrome? no. skip
        // is 'aa' a plaindrome? yes. recurse with [aa], i=2
            // now we have 'b' to consider.
            // is 'b' a palindorme? yes. recurse with [aa, b], i=3
                // size = s.size(). base case return. add [aa, b] to result
        // is 'aab' a plaindrome? no. skip
            //...


        // n is the size of s. this is O(n * 2^(n)) time, O(n) space

        vector<vector<string>> res;
        vector<string> cur;
        dfs(res, s, cur, 0);
        return res;

    }
};

