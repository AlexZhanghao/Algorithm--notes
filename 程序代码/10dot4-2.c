//A��Ҫ��ӡ�Ķ�������left����������ӣ�right�������Ҷ��ӣ�subscript�������±꣬value������ֵ

void PrintBinaryTree(BinaryTree *A){
	if(A->left!=NULL){
		PrintBinaryTree(A->left);
	}
	if(A->right!=NULL){
		PrintBinaryTree(A->left);
	}
	cout<<"the value of "<<A->subscript<<" is "<<A->value<<endl;
}