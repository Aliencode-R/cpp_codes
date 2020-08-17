// class BSTIterator {
// public:
//     stack<TreeNode*>s1, s2;
//     BSTIterator(TreeNoderoot) {
//         TreeNodecur=root;
//         while (cur) {
//             s1.push(cur);
//             cur=cur->left;
//         }
//         while (root) {
//             s2.push(root);
//             root=root->right;
//         }
//     }
//     TreeNodenexts() {
//         TreeNodecur=s2.top();
//         s2.pop();
//         if (cur->left!=NULL) {
//             TreeNodetemp=cur->left;
//             while (temp) {
//                 s2.push(temp);
//                 temp=temp->right;
//             }
//         }
//         return cur;
//     }
//     TreeNodenextb() {
//         TreeNodecur=s1.top();
//         s1.pop();
//         if (cur->right!=NULL) {
//             TreeNodetemp=cur->right;
//             while (temp) {
//                 s1.push(temp);
//                 temp=temp->left;
//             }
//         }
//         return cur;
//     }
// };
// int Solution::t2Sum(TreeNode* root, int k) {
//     if (root==NULL||(root->left==NULL&&root->right==NULL)) {
//         return 0;
//     }
//     BSTIterator b=new BSTIterator(root);
//     TreeNode l=b->nextb(), *r=b->nexts();
//     while (l!=r) {
//         if (l->val+r->val==k) {
//             return 1;
//         }
//         else if (l->val+r->val>k) {
//             r=b->nexts();
//         }
//         else {
//             l=b->nextb();
//         }
//     }
//     return 0;
// }