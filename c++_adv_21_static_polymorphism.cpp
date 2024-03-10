
//############################################################################
/*
 *  Polymorphism
 */
//############################################################################

#include <iostream>

using namespace std;

// Non-virtual Interface Idiom (NVI)

struct TreeNode {
    TreeNode *left, *right;
};

class Generic_Parser {
public:
    void parse_preorder(TreeNode* node) {
        if (node) {
            process_node(node);
            parse_preorder(node->left);
            parse_preorder(node->right);
        }
    }

private:
    virtual void process_node(TreeNode* node) {}
};

class EmployeeChart_Parser : public Generic_Parser {
private:
    void process_node(TreeNode* node) { cout << "Customized process_node() for EmployeeChart.\n"; }
};

int main() {
    EmployeeChart_Parser ep;
    ep.parse_preorder(root);
}

// Benefits: clean, elegant, generic code
/*
 * 1. is-a relationship between base class and derived class
 * 2. Base class defines a "generic" algorithm that's used by derived class
 * 3. The "generic" algorithm is customized by the derived class
 */

/*
 * Alternatives for Virtual Function
 */
// class A {
//     X x; // dynamically controls what task to be performed.

//     /* X could be:
//     * 1. Function pointer
//     * 2. tr1::function, a generalized function pointer.
//     * 3. Strategy class
//     */
//     ...
// };

// struct TreeNode {
//     TreeNode *left, *right;
// };

// template <typename T> class Generic_Parser {
// public:
//     void parse_preorder(TreeNode* node) {
//         if (node) {
//             process_node(node);
//             parse_preorder(node->left);
//             parse_preorder(node->right);
//         }
//     }
//     void process_node(TreeNode* node) {
//         static_cast<T*>(this)->process_node(node);
//     }
// };

// class EmployeeChart_Parser : public Generic_Parser<EmployeeChart_Parser> {
// public:
//     void process_node(TreeNode* node) {
//         cout << "Customized process_node() for EmployeeChart.\n";
//     }
// };

// int main() {
//     EmployeeChart_Parser ep;
//     ep.parse_preorder(root);
// }

// Curiously Recurring Template Pattern
//   (Static Polymorphism, Simulated Polymorphism)

// TMP

//###########################################################################
