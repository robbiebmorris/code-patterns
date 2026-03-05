
//
// MONOTONIC STACK PATTERNS
//

// Monotonic stack can be used to find the next greater/smaller element or
// previous greater/smaller element for all elements in a list.
// There are 2 patterns for this which have different intuitions but can 
// both solve all 4 questions.
//
// Example question:
//
// Find the next greater element of every element in the list. Return a list
// of the next greater elements. If there is no next greater element, that 
// entry can be -1.
// e.g. 
// input: [3,2,5,1,6].
// output: [5,5,6,6,-1]

// NEXT GREATER/SMALLER PATTERN
//
// The stack stores elements we don't have an answer for yet. When the
// condition is eventually met, we now have the answer for the top element
// on the stack.
//
// In this case, we are searching for 
// the first case to the right where a rectangle height is smaller than 
// the rectangle height[i].
//
vector<int> rightMax(n, n);
stack<int> stack;
for (int i=0; i<n; ++i) {
    while (!stack.empty() && heights[i] < heights[stack.top()]) {
        rightMax[stack.top()] = i;
        stack.pop();
    }
    stack.push(i);
}



// PREVIOUS GREATER/SMALLER PATTERN
//
// The stack stores history, and for every i we look back at that history
// to find a solution.
//
// In this case, we are searching for
// the first case to the left where a rectangle is smaller than the 
// rectangle height[i].
//
vector<int> leftMax(n, -1);
for (int i=0; i<n; i++) {
    while (!stack.empty() && heights[i] < heights[stack.top()]) {
        stack.pop();
    }
    if (!stack.empty()) {
        leftMax[i] = stack.top();
    }
    stack.push(i);
}

// Both of these patterns can be used to replace each other if we
// reverse our for loop to go from n-1 to 0.
// 
// Code snippets are from LC 84. Largest Rectangle in Histogram
