/********************************************************************

Maximillian Brain
CSM20
TopicD.cpp
Compiling and Running 

I deleted the InsertInOrder function as my balancedAdd does the same thing.
Only Thing the BST really does is call the base class functions of BinaryNodeTree.
I know they should just be inherited, but my version of Visual Studio, Visual Studio
2015 is throwing linker errors at me if I don't. 
********************************************************************/
#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType>
{
   
protected:
   //------------------------------------------------------------
   // Protected Utility Methods Section:
   // Recursive helper methods for the public methods.
   //------------------------------------------------------------

   
   // Removes the given target value from the tree while maintaining a
   // binary search tree.
   BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr,
                                     const ItemType target,
                                     bool& success);
   
   // Removes a given node from a tree while maintaining a
   // binary search tree.
   BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodePtr);
   
   // Removes the leftmost node in the left subtree of the node
   // pointed to by nodePtr.
   // Sets inorderSuccessor to the value in this node.
   // Returns a pointer to the revised subtree.
   BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* subTreePtr,
                                            ItemType& inorderSuccessor);
   
   // Returns a pointer to the node containing the given value,
   // or nullptr if not found.
   BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr,
                                  const ItemType& target) const;
   
public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BinarySearchTree();
   BinarySearchTree(const ItemType& rootItem);
   BinarySearchTree(const BinarySearchTree<ItemType>& tree);
   virtual ~BinarySearchTree();
   
   //------------------------------------------------------------
   // Public Methods Section.
   //------------------------------------------------------------
   bool isEmpty() const;
   int getHeight() const;
   int getNumberOfNodes() const;
   ItemType getRootData() const throw(PrecondViolatedExcep);
   void setRootData(const ItemType& newData) const
   throw(PrecondViolatedExcep);
   bool add(const ItemType& newEntry);
   bool remove(const ItemType& anEntry);
   void clear();
   ItemType getEntry(const ItemType& anEntry) const
   throw(NotFoundException);
   bool contains(const ItemType& anEntry) const;
   
   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------
   void preorderTraverse(void visit(ItemType&)) const;
   void inorderTraverse(void visit(ItemType&)) const;
   void postorderTraverse(void visit(ItemType&)) const;
   
   //------------------------------------------------------------
   // Overloaded Operator Section.
   //------------------------------------------------------------
   BinarySearchTree<ItemType>& operator=(const BinarySearchTree<ItemType>& rightHandSide);   
}; // end BinarySearchTree


template <class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success)
{
	return BinaryNodeTree<ItemType>::removeValue(subTreePtr, target, success);
}

template <class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* treePtr, const ItemType& target) const
{
	return BinaryNodeTree<ItemType>::findNode(treePtr, target);
}

template <class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry)
{
	return BinaryNodeTree<ItemType>::add(newEntry);
}

template <class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& anEntry)
{
	return BinaryNodeTree<ItemType>::remove(anEntry);
}
template <class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const
{
	return BinaryNodeTree<ItemType>::getEntry(anEntry);
}

template <class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const
{
	return BinaryNodeTree<ItemType>::contains(anEntry);
}

template <class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
	return BinaryNodeTree<ItemType>::preorderTraverse(visit);
}

template <class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
	return BinaryNodeTree<ItemType>::inorderTraverse(visit);
}

template <class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
	return BinaryNodeTree<ItemType>::postorderTraverse(visit);
}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{
	BinaryNodeTree<ItemType>::BinaryNodeTree();
}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
{
	BinaryNodeTree<ItemType>::BinaryNodeTree(rootItem);
}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree)
{
	*this = tree;
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
	BinaryNodeTree<ItemType>::clear();
}

template <class ItemType>
int BinarySearchTree<ItemType>::getHeight() const 
{
	return BinaryNodeTree<ItemType>::getHeight();
}

template <class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const 
{
	return BinaryNodeTree<ItemType>::getNumberOfNodes();
}

template<class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::operator=(const BinarySearchTree<ItemType>& rightHandSide)
{
	BinaryNodeTree<ItemType>::operator = (rightHandSide);
	return *this;
} 

#endif
