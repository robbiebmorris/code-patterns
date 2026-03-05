//
// MORRIS TRAVERSAL
//

// This algorithm allows us to perform an in order traversal of
// a binary tree in O(1) space.


/*
 *
 *  1. For each node, check if it has a left child. 
 *  2. If NOT: visit it and move to the right child.
 *  3. If it DOES: 
 *      - Find the *inorder predecessor* of said node. 
 *      - Make the current node the right child of the inorder predecessor (temporarily)
 *      - Move to the left child.
 *  4. When you encounter a temporary link, it means the left subtree is fully visited.
 *      - Remove the temporary link
 *      - Visit the current node
 *      - Move to the right child.
 *
 *
 *  The inorder predecessor of a node is the right most node in the left subtree.
 *
 *
 */

// SAMPLE CODE:
class Node {
    constructor(data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

function inOrder(root) {
    let res = [];
    let curr = root;

    while (curr !== null) {
        if (curr.left === null) {

            // If no left child, visit this 
            // node and go right
            res.push(curr.data);
            curr = curr.right;
        } 
        else {

            // Find the inorder predecessor of curr
            let prev = curr.left;
            while (prev.right !== null
                              && prev.right !== curr) {
                prev = prev.right;
            }

            // Make curr the right child of its 
            // inorder predecessor
            if (prev.right === null) {
                prev.right = curr;
                curr = curr.left;
            } 
            else {

                // Revert the changes made in the 
                // tree structure
                prev.right = null;
                res.push(curr.data);
                curr = curr.right;
            }
        }
    }

    return res;
}

// Driver Code

// Representation of input binary tree:
//           1
//          / \
//         2   3
//        / \  
//       4   5
let root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);

let res = inOrder(root);

console.log(...res);
