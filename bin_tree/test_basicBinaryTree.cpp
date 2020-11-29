#include <iostream>

#include "basicBinaryTree.hpp"
#include "../assert.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    BasicBinaryTreeNode<char, int>* node0 = new BasicBinaryTreeNode<char, int>('e', 50);
    BasicBinaryTreeNode<char, int>* node1 = new BasicBinaryTreeNode<char, int>('a', 40);
    cout << "testing BasicBinaryTreeNode..." << endl;

    assert(node0->getKey() == 'e', "BasicBinaryTreeNode::getKey failed");
    assert(node0->getValue() == 50, "BasicBinaryTreeNode::getValue failed");
    assert(node0->getLeftChild() == nullptr, "BasicBinaryTreeNode::getLeftChild failed");
    assert(node0->getRightChild() == nullptr, "BasicBinaryTreeNode::getRightChild failed");
    assert(*node0 != *node1 == true, "BasicBinaryTreeNode::operator!= failed");
    assert(*node0 > *node1 == true, "BasicBinaryTreeNode::operator> failed");
    node0->setLeftChild(node1);
    assert(node0->getLeftChild() == node1, "BasicBinaryTreeNode::setLeftChild failed");

    cout << "BasicBinaryTreeNode passed." << endl;

    return 0;
}
