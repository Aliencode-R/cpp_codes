int Solution::t2Sum(TreeNode* root, int x) {
	if (!root) return 0;
	TreeNode *r1=root, *r2=root;
	stack<TreeNode *>s1, s2;
	while ((r1||!s1.empty())&&(r2||!s2.empty())) {
		while (r1) {
			s1.push(r1);
			r1=r1->left;
		}
		while (r2) {
			s2.push(r2);
			r2=r2->right;
		}
		r1=s1.top();
		r2=s2.top();
		if (r1->val + r2->val ==x && r1!=r2)
			return 1;
		else if (r1->val + r2->val >x) {
			s2.pop();
			r2=r2->left;
			r1=NULL;
		}
		else {
			s1.pop();
			r1=r1->right;
			r2=NULL;
		}
	}
	return 0;
}