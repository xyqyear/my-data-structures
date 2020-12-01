#pragma once
#include <iostream>

template <typename KeyType, typename ValueType>
class BasicBinaryTreeNode
{
private:
    KeyType key;
    ValueType value;
    BasicBinaryTreeNode *leftChild = nullptr;
    BasicBinaryTreeNode *rightChild = nullptr;

public:
    BasicBinaryTreeNode(KeyType key, ValueType value)
    {
        this->key = key;
        this->value = value;
    }
    BasicBinaryTreeNode(ValueType value)
    {
        this->value = value;
    }
    BasicBinaryTreeNode(KeyType key, ValueType value, BasicBinaryTreeNode *leftChild, BasicBinaryTreeNode *rightChild)
    {
        this->key = key;
        this->value = value;
        this->leftChild = leftChild;
        this->rightChild = rightChild;
    }
    BasicBinaryTreeNode(ValueType value, BasicBinaryTreeNode *leftChild, BasicBinaryTreeNode *rightChild)
    {
        this->value = value;
        this->leftChild = leftChild;
        this->rightChild = rightChild;
    }
    ~BasicBinaryTreeNode()
    {
        delete leftChild;
        delete rightChild;
    }
    inline KeyType getKey()
    {
        return key;
    }
    inline ValueType getValue()
    {
        return value;
    }
    inline bool isLeaf()
    {
        return leftChild == rightChild == nullptr;
    }
    inline BasicBinaryTreeNode *getLeftChild()
    {
        return leftChild;
    }
    inline void setLeftChild(BasicBinaryTreeNode *leftChild)
    {
        this->leftChild = leftChild;
    }
    inline BasicBinaryTreeNode *getRightChild()
    {
        return rightChild;
    }
    inline void setRightChild(BasicBinaryTreeNode *rightChild)
    {
        this->rightChild = rightChild;
    }
    inline bool operator>(BasicBinaryTreeNode &rightNode)
    {
        return value > rightNode.getValue();
    }
    inline bool operator<(BasicBinaryTreeNode &rightNode) { return rightNode > *this; }
    inline bool operator<=(BasicBinaryTreeNode &rightNode) { return !(*this > rightNode); }
    inline bool operator>=(BasicBinaryTreeNode &rightNode) { return !(*this < rightNode); }
    inline bool operator==(BasicBinaryTreeNode &rightNode)
    {
        return value == rightNode.getValue();
    }
    inline bool operator!=(BasicBinaryTreeNode &rightNode) { return !(*this == rightNode); }
};
