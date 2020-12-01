#include <iostream>
#include <cassert>
#include "dataStructure/bin_tree/basicBinaryTree.hpp"

int main(int argc, char const *argv[])
{
    auto *node0 = new BasicBinaryTreeNode<char, int>('e', 50);
    auto *node1 = new BasicBinaryTreeNode<char, int>('a', 40);
    std::cout << "testing BasicBinaryTreeNode..." << std::endl;

    assert(node0->getKey() == 'e');
    assert(node0->getValue() == 50);
    assert(node0->getLeftChild() == nullptr);
    assert(node0->getRightChild() == nullptr);
    assert((*node0 != *node1) == true);
    assert((*node0 > *node1) == true);
    node0->setLeftChild(node1);
    assert(node0->getLeftChild() == node1);

    std::cout << "BasicBinaryTreeNode passed." << std::endl;

    return 0;
}
