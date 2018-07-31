Binary Search Tree

\* Sample Output (with our test case):

```shell
    TEST #1: Create an empty tree
    ========================PASS========================
    TEST #2: Insert values into the Tree
    ========================PASS========================
    TEST #3: Cannot insert duplicate values into the Tree
    ========================PASS========================
    TEST #4: Insert 1000 Values into the Tree
    ========================PASS========================
    TEST #5: Find values in the tree
    ========================PASS========================
    TEST #6: Find doesn't segfault on empty tree
    ========================PASS========================
    TEST #7: Cannot remove node that is not in the tree
     [1]  [2]  [3]  [5]  [6]  [7]  [8]  [9]  [10]  [11]  [12]  [13]
    ========================PASS========================
    TEST #8: Remove a leaf node
     [2]  [3]  [5]  [6]  [7]  [8]  [9]  [10]  [11]  [12]  [13]
    ========================PASS========================
    TEST #9: Remove single branch using the Short Circuit algorithm
     [2]  [3]  [5]  [6]  [8]  [9]  [10]  [11]  [12]  [13]
    ========================PASS========================
    Test #10: Remove two branch node promoting a leaf node
     [2]  [3]  [5]  [6]  [8]  [9]  [11]  [12]  [13]
    ========================PASS========================
    TEST #11: Remove two branch node promoting a 1 branch node using Short Circuit
     [2]  [3]  [5]  [6]  [8]  [9]  [12]  [13]
    ========================PASS========================
    TEST #12: Remove root with two branches
     [2]  [3]  [6]  [8]  [9]  [12]  [13]
    ========================PASS========================
    TEST #13: Remove root with one branch
     [8]  [9]  [12]  [13]
    ========================PASS========================
    TEST #14: Remove root as leaf
    ========================PASS========================
    TEST #15: Deep copy for a tree of 100 random values
    ========================PASS========================
    TEST #16: Test deletion and Destructor
    ========================PASS========================
    TEST #17: Test Balancing Tree
    ========================PASS========================
    All Tests Passed.
```
