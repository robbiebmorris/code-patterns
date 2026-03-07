//
// PRIORITY QUEUES
//

// MAX HEAP COMPARISON: A < B

auto cmp = [](int a, int b){
    return a < b;
};

// The maximum element will be at the top of the max heap, ready to be popped.
// The max heap maintains the k SMALLEST elements from a stream of elements,
// popping the MAX when we reach our size limit.


// MIN HEAP COMPARISON: A > B

auto cmp = [](int a, int b){
    return a > b;
};

// The minimum element will be at the top of the min heap, ready to be popped.
// The min heap maintains the k LARGEST elements from a stream of elements,
// popping the smallest when we reach our size limit.


// aka: max heap pops max element, min heap pops min element
