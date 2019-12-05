//A是要打印的二叉树，left是它的左儿子，right是它的右儿子，subscript是它的下标，value是它的值

void PrintBinaryTree(BinaryTree *A){
	if(A->left!=NULL){
		PrintBinaryTree(A->left);
	}
	if(A->right!=NULL){
		PrintBinaryTree(A->left);
	}
	cout<<"the value of "<<A->subscript<<" is "<<A->value<<endl;
}