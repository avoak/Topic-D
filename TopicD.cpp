#pragma warning( disable: 4290 )  // disable warnings about the use of throw in function headers

/********************************************************************

Maximillian Brain
CSM20
TopicD.cpp
Compiling and Running (Somehow)

********************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include "BinaryNodeTree.h"
#include "BinarySearchTree.h"
#include "Soundtrack.h"


using namespace std;


template<class ItemType>
void preorder(const BinarySearchTree<ItemType>& BinSearchTree);

template<class ItemType>
void inorder(const BinarySearchTree<ItemType>& BinSearchTree);

template<class ItemType>
void postorder(const BinarySearchTree<ItemType>& BinSearchTree);

template<class ItemType>
void display(ItemType& entries);

int main()
{
	ifstream inputFile; 
	string fileName = "Topic A Soundtrack.txt"; 
	vector<soundtrack> soundTrackVector;

	cout << "Create default int tree bst1" << endl;
	BinarySearchTree<int> bst1;

	cout << "Display bst1" << endl;

	preorder(bst1);
	inorder(bst1);
	postorder(bst1);
	

	cout << endl << endl << endl;
	cout << "Read values from input file" << endl;

	cout << "Put release year values into bst1" << endl << endl << endl;

	inputFile.open(fileName);
	while (!inputFile.eof()) 
	{
		soundtrack* temp = new soundtrack;
		inputFile >> *temp;
		soundTrackVector.push_back(*temp);
		bst1.add(temp->getDateReleased());
		delete temp;
		temp = nullptr;
	}
	inputFile.close();

	cout << "Next, insert following values into bst1 in this order: 1 2 -10 15 -20 0 10" << endl;

	bst1.add(1);
	bst1.add(2);
	bst1.add(-10);
	bst1.add(15);
	bst1.add(-20);
	bst1.add(0);
	bst1.add(10);

	cout << "Display bst1" << endl;

	preorder(bst1);
	inorder(bst1);
	postorder(bst1);
	

	cout << endl << "Height of bst1 is " << bst1.getHeight();
	cout << endl << endl << "Number of nodes in bst1 is " << bst1.getNumberOfNodes();

	cout << endl << endl << "Retrieve value using getEntry -10 from the tree:" << endl << endl;
	try 
	{
		bst1.getEntry(-10);
		cout << "Found -10 in tree bst1";
	}
	catch (exception exc) 
	{
		cout << "-10 NOT found in bst1";
	}

	cout << endl << endl << "Use contains to see if value 11 is in the tree:" << endl << endl;
	try 
	{
		bst1.getEntry(11);
		cout << "Found 11 in tree bst1";
	}
	catch (exception exc)
	{
		cout << "11 NOT found in bst1";
	}

	cout << endl << endl << "Create bst2, a pointer to BinarySearchTree, from bst1" << endl << endl;
	BinarySearchTree<int>* bst2 = new BinarySearchTree<int>(bst1);

	cout << "Display bst2" << endl;
	
	preorder(*bst2);
	inorder(*bst2);
	postorder(*bst2);
	

	cout << endl << "Height of bst2 is " << bst2->getHeight();
	cout << endl << endl << "Number of nodes in bst2 is " << bst2->getNumberOfNodes();

	cout << endl << endl << "Delete 2014 from bst2" << endl;
	bst2->remove(2014) ? cout << "2014 deleted from bst2" : cout << " NOT deleted from bst2";
	cout << endl;

	cout << endl << endl << "Delete 2014 from bst2" << endl;
	bst2->remove(2014) ? cout << "2014 deleted from bst2" : cout << " NOT deleted from bst2";
	cout << endl;

	cout << "Display bst2";
	preorder(*bst2);
	inorder(*bst2);
	postorder(*bst2);

	cout << endl << "Height of bst2 is " << bst2->getHeight();
	cout << endl << endl << "Number of nodes in bst2 is " << bst2->getNumberOfNodes();

	cout << endl << endl << "Create bst3 then assign bst2 to bst3" << endl;
	BinarySearchTree<int> bst3;
	bst3 = *bst2;

	cout << "Display bst3";
	preorder(bst3);
	inorder(bst3);
	postorder(bst3);
	

	cout << endl << endl;
	cout << "****************************************************************" << endl;
	cout << "Press Enter to continue -->  ";
	cin.ignore();

	BinarySearchTree<soundtrack> bstST1;

	cout << endl << endl << endl << "Put soundtrack records into bstST1" << endl << endl;
	for (unsigned int i = 0; i < soundTrackVector.size(); i++)
		bstST1.add(soundTrackVector[i]);


	cout << "Display bstST1";
	preorder(bstST1);
	inorder(bstST1);
	postorder(bstST1);
	

	cout << endl << "Height of bstST1 is " << bstST1.getHeight();
	cout << endl << endl << "Number of nodes in bstST1 is " << bstST1.getNumberOfNodes();


	cout << endl << endl << "Create bstST2 from bstST1" << endl << endl << endl;
	BinarySearchTree<soundtrack> bstST2(bstST1);
	cout << "Display bstST2" << endl;
	preorder(bstST2);
	inorder(bstST2);
	postorder(bstST2);
	

	cout << endl << "Height of bstST2 is " << bstST2.getHeight();
	cout << endl << endl << "Number of nodes in bstST2 is " << bstST2.getNumberOfNodes();

	cout << endl << endl;
	cout << "****************************************************************" << endl;
	cout << "Press Enter to continue -->  ";
	cin.ignore();

	cout << endl << endl << "Search bstST2 using getEntry for the object that has Godzilla as a title" << endl << endl;

	soundtrack godzilla;
	godzilla.setTitle("Godzilla");

	try 
	{
		bstST2.getEntry(godzilla);
		cout << "Found.  The object consists of " << bstST2.getEntry(godzilla);
	}
	catch (exception exc)
	{
		cout << exc.what() << endl;
	}

	cout << endl << endl << "Search bstST2 using getEntry for the object that has godzilla as a title" << endl << endl;

	godzilla.setTitle("godzilla");

	try
	{
		bstST2.getEntry(godzilla);
		cout << "Found.  The object consists of " << bstST2.getEntry(godzilla);
	}
	catch (exception exc)
	{
		cout << exc.what() << endl;
	}


	cout << endl << endl << "Search bstST2 using getEntry for the object that has Elmer Bernstein as the composer" << endl << endl;
	soundtrack elmer;
	elmer.setComposer("Elmer Bernstein");
	try 
	{
		bstST2.getEntry(elmer);
		cout << "Found.  The object consists of " << bstST2.getEntry(elmer);
	}
	catch (exception e) 
	{
		cout << e.what() << endl;
	}


	cout << endl << endl << endl << "Delete the object from bstST2 with the title Much Ado About Nothing, a leaf" << endl << endl << endl;
	soundtrack MuchAdo;
	MuchAdo.setTitle("Much Ado About Nothing");
	bstST2.remove(MuchAdo) ? cout << "\"Much Ado About Nothing, a leaf\" deleted from bstST2" : cout << "\"Much Ado About Nothing, a leaf\" NOT deleted from bstST2";

	cout << endl << endl << "Display bstST2" << endl;
	preorder(bstST2);
	inorder(bstST2);
	postorder(bstST2);

	cout << endl << "Height of bstST2 is " << bstST2.getHeight();
	cout << endl << endl << "Number of nodes in bstST2 is " << bstST2.getNumberOfNodes();


	cout << endl << endl << "Delete the object from bstST2 with the title Moonfleet, a tree with only a right subtree" << endl << endl << endl;
	soundtrack Moonfleet;
	Moonfleet.setTitle("Moonfleet");
	bstST2.remove(Moonfleet) ? cout << "\"Moonfleet\" deleted from bstST2" : cout << "\"Moonfleet\" NOT deleted from bstST2";

	cout << endl << endl << "Display bstST2" << endl;
	preorder(bstST2);
	inorder(bstST2);
	postorder(bstST2);

	cout << endl << "Height of bstST2 is " << bstST2.getHeight();
	cout << endl << endl << "Number of nodes in bstST2 is " << bstST2.getNumberOfNodes();


	cout << endl << endl << endl << "Delete the object from bstST2 with title Godzilla, a tree with two subtrees whose right child is the inorder successor" << endl << endl << endl;
	godzilla.setTitle("Godzilla");
	bstST2.remove(godzilla) ? cout << "\"Godzilla\" deleted from bstST2" : cout << "\"Godzilla\" NOT deleted from bstST2";

	cout << endl << endl << "Display bstST2" << endl;
	preorder(bstST2);
	inorder(bstST2);
	postorder(bstST2);

	
	cout << endl << "Height of bstST2 is " << bstST2.getHeight();
	cout << endl << endl << "Number of nodes in bstST2 is " << bstST2.getNumberOfNodes();


	cout << endl << endl << endl << "Delete from bstST2 with the title King of Hearts, a tree successor with two children whose right child is NOT the inorder successor" << endl << endl << endl;
	soundtrack KingOfHearts;
	KingOfHearts.setTitle("King of Hearts");
	bstST2.remove(KingOfHearts) ? cout << "\"King of Hearts\" deleted from bstST2" : cout << "\"King of Hearts\" NOT deleted from bstST2";

	cout << endl << endl << "Display bstST2" << endl;
	preorder(bstST2);
	inorder(bstST2);
	postorder(bstST2);
	

	cout << endl << "Height of bstST2 is " << bstST2.getHeight();
	cout << endl << endl << "Number of nodes in bstST2 is " << bstST2.getNumberOfNodes();


	cout << endl << endl << endl << "Retrieve the object with title Psycho using contains" << endl << endl << endl;
	soundtrack psycho;
	psycho.setTitle("Psycho");
	bstST2.remove(psycho) ? cout << "\"Psycho\" deleted from bstST2" : cout << "\"Psycho\" NOT deleted from bstST2";

	cout << endl << endl << "Display bstST2" << endl;
	preorder(bstST2);
	inorder(bstST2);
	postorder(bstST2);
	

	cout << endl << "Height of bstST2 is " << bstST2.getHeight();
	cout << endl << endl << "Number of nodes in bstST2 is " << bstST2.getNumberOfNodes();

	cout << endl << "Create bstST3, a pointer to BinarySearchTree, and then assign bstST2 to it" << endl << endl;
	BinarySearchTree<soundtrack>* bstST3 = new BinarySearchTree<soundtrack>;
	*bstST3 = bstST2;

	cout << endl << endl << "Display bstST3" << endl;
	preorder(*bstST3);
	inorder(*bstST3);
	postorder(*bstST3);
	

	cout << endl << "Height of bstST3 is " << bstST3->getHeight();
	cout << endl << endl << "Number of nodes in bstST2 is " << bstST3->getNumberOfNodes();

	cout << endl << endl;
	cout << "Program Over" << endl << endl;
	cout << "Press Enter to continue --> ";
	cin.ignore();

	return 0;
}

template<class ItemType>
void preorder(const BinarySearchTree<ItemType>& BinSearchTree)
{
	cout << endl << "Preorder:" << endl;
	BinSearchTree.preorderTraverse(display);
}

template<class ItemType>
void inorder(const BinarySearchTree<ItemType>& BinSearchTree)
{
	cout << endl << "Inorder:" << endl;
	BinSearchTree.inorderTraverse(display);
}

template<class ItemType>
void postorder(const BinarySearchTree<ItemType>& BinSearchTree)
{
	cout << endl << "PostOrder:" << endl;
	BinSearchTree.postorderTraverse(display);
}

template<class ItemType>
void display(ItemType& entries)
{
	cout << entries << endl;
} 
