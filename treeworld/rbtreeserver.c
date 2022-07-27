void left_rotate(rbtree* rb_tree_head,rbnode* newnode){
rbnode* parent=newode->parent;
rbnode* child=newnode->right;
rbnode* lnode=parent->left;
rbnode* rr=child->right;
rbnode* lr=child->left;
parent->right=child;
child->left=newnode;
}