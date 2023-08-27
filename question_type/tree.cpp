#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

template<typename T>
struct TreeNode {
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
};

template<typename T>
void preTraversal(TreeNode<T> *cur, vector<T> &vec) {
    if (cur == nullptr) return;
    vec.push_back(cur->val);
    preTraversal(cur->left, vec);
    preTraversal(cur->right, vec);
}

template<typename T>
void inTraversal(TreeNode<T> *cur, vector<T> &vec) {
    if (cur == nullptr) return;
    inTraversal(cur->left, vec);
    vec.push_back(cur->val);
    inTraversal(cur->right, vec);
}

template<typename T>
void postTraversal(TreeNode<T> *cur, vector<T> &vec) {
    if (cur == nullptr) return;
    postTraversal(cur->left, vec);
    postTraversal(cur->right, vec);
    vec.push_back(cur->val);
}


template<typename T>
TreeNode<T> *inPostBuildTree(vector<T> &inorder, int inorderBegin, int inorderEnd,
                             vector<T> &postorder, int postorderBegin, int postorderEnd) {
    if (postorderBegin == postorderEnd) return nullptr;
    T rootValue = postorder[postorderEnd - 1];
    TreeNode<T> *root = new TreeNode<T>(rootValue);
    if (postorderEnd - postorderBegin == 1) return root;
    int delimiterIndex;
    for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) {
        if (inorder[delimiterIndex] == rootValue) break;
    }
    int leftInorderBegin = inorderBegin;
    int leftInorderEnd = delimiterIndex;
    int rightInorderBegin = delimiterIndex + 1;
    int rightInorderEnd = inorderEnd;
    int leftPostorderBegin = postorderBegin;
    int leftPostorderEnd = postorderBegin + delimiterIndex - inorderBegin;
    int rightPostorderBegin = postorderBegin + (delimiterIndex - inorderBegin);
    int rightPostorderEnd = postorderEnd - 1;
    // 错误处理
    unordered_set<T> leftInorderSet(inorder.begin() + leftInorderBegin, inorder.begin() + leftInorderEnd);
    unordered_set<T> leftPostorderSet(postorder.begin() + leftPostorderBegin, postorder.begin() + leftPostorderEnd);
    if (leftInorderSet != leftPostorderSet) {
        cerr << "Error: Elements on the left of delimiter do not match the left half of postorder." << endl;
        return nullptr;
    }
    unordered_set<T> rightInorderSet(inorder.begin() + rightInorderBegin, inorder.begin() + rightInorderEnd);
    unordered_set<T> rightPostorderSet(postorder.begin() + rightPostorderBegin, postorder.begin() + rightPostorderEnd);
    if (rightInorderSet != rightPostorderSet) {
        cerr << "Error: Elements on the right of delimiter do not match the right half of postorder." << endl;
        return nullptr;
    }

    root->left = inPostBuildTree(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin,
                                 leftPostorderEnd);
    root->right = inPostBuildTree(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin,
                                  rightPostorderEnd);
    return root;
}

template<typename T>
TreeNode<T> *preInBuildTree(vector<T> &inorder, int inorderBegin, int inorderEnd,
                            vector<T> &preorder, int preorderBegin, int preorderEnd) {
    if (preorderBegin == preorderEnd) return nullptr;
    T rootValue = preorder[preorderBegin];
    TreeNode<T> *root = new TreeNode<T>(rootValue);
    if (preorderEnd - preorderBegin == 1) return root;
    int delimiterIndex;
    for (delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++) {
        if (inorder[delimiterIndex] == rootValue) break;
    }
    int leftInorderBegin = inorderBegin;
    int leftInorderEnd = delimiterIndex;
    int rightInorderBegin = delimiterIndex + 1;
    int rightInorderEnd = inorderEnd;
    int leftPreorderBegin = preorderBegin + 1;
    int leftPreorderEnd = preorderBegin + 1 + delimiterIndex - inorderBegin;
    int rightPreorderBegin = preorderBegin + 1 + (delimiterIndex - inorderBegin);
    int rightPreorderEnd = preorderEnd;
    // 错误处理
    unordered_set<T> leftInorderSet(inorder.begin() + leftInorderBegin, inorder.begin() + leftInorderEnd);
    unordered_set<T> leftPreorderSet(preorder.begin() + leftPreorderBegin, preorder.begin() + leftPreorderEnd);
    if (leftInorderSet != leftPreorderSet) {
        cerr << "Error: Elements on the left of delimiter do not match the left half of postorder." << endl;
        return nullptr;
    }
    unordered_set<T> rightInorderSet(inorder.begin() + rightInorderBegin, inorder.begin() + rightInorderEnd);
    unordered_set<T> rightPreorderSet(preorder.begin() + rightPreorderBegin, preorder.begin() + rightPreorderEnd);
    if (rightInorderSet != rightPreorderSet) {
        cerr << "Error: Elements on the right of delimiter do not match the right half of postorder." << endl;
        return nullptr;
    }

    root->left = preInBuildTree(inorder, leftInorderBegin, leftInorderEnd, preorder, leftPreorderBegin,
                                leftPreorderEnd);
    root->right = preInBuildTree(inorder, rightInorderBegin, rightInorderEnd, preorder, rightPreorderBegin,
                                 rightPreorderEnd);
    return root;
}


/*一次只能运行一对样例，选择题要运行4次。
下面的4段，1、2段是int，3、4段是char。
1、3段是中序、后序->前序；2、4段是前序、中序->后序。
如果输出错误信息说明无法构成树。这里默认输入的一对样例的字母集相等（不相等能看出来）*/
int main() {
/*    vector<int> inorder1 = {9, 3, 15, 20, 7};
    vector<int> postorder1 = {9, 15, 7, 20, 3};
    TreeNode<int> *root1 = inPostBuildTree(inorder1, 0, inorder1.size(), postorder1, 0, postorder1.size());
    vector<int> preorder1;
    preTraversal(root1, preorder1);
    for (int i: preorder1) cout << i << " ";
    cout << endl;*/

/*    vector<int> preorder2 = {3, 9, 20, 15, 7};
    vector<int> inorder2 = {9, 3, 15, 20, 7};
    TreeNode<int> *root2 = preInBuildTree(inorder2, 0, inorder2.size(), preorder2, 0, preorder2.size());
    vector<int> postorder2;
    postTraversal(root2, postorder2);
    for (int i: postorder2) cout << i << " ";
    cout << endl;*/

/*    string inorderString3 = "DBEAFC";
    string postorderString3 = "DEBFCA";
    vector<char> inorder3(inorderString3.begin(), inorderString3.end());
    vector<char> postorder3(postorderString3.begin(), postorderString3.end());
    TreeNode<char> *root3 = inPostBuildTree(inorder3, 0, inorder3.size(), postorder3, 0, postorder3.size());
    vector<char> preorder3;
    preTraversal(root3, preorder3);
    for (char i: preorder3) cout << i << " ";
    cout << endl;*/

    string preorderString4 = "ABDECF";
    string inorderString4 = "DBEAFC";
    vector<char> preorder4(preorderString4.begin(), preorderString4.end());
    vector<char> inorder4(inorderString4.begin(), inorderString4.end());
    TreeNode<char> *root4 = preInBuildTree(inorder4, 0, inorder4.size(), preorder4, 0, preorder4.size());
    vector<char> postorder4;
    postTraversal(root4, postorder4);
    for (char i: postorder4) cout << i << " ";
    cout << endl;

    return 0;
}