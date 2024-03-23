#include <bits/stdc++.h>

using namespace std;


template<typename K>
class BinarySearchTree
{
public:
	struct Item
	{
		K key = K();	
	};

	struct Node
	{
		Item item;

		Node* left = nullptr;
		Node* right = nullptr;
	};

	void Postorder()
	{
		using namespace std;
		Postorder(root_);
		cout << endl;
	}

	void Postorder(Node* node)
	{
		using namespace std;
		if (node)
		{
			Postorder(node->left);
			Postorder(node->right);
			cout << node->item.key << " ";
		}
	}

	void Insert(const Item& item)
	{
		
		root_ = Insert(root_, item);
	}

	Node* Insert(Node* node, const Item& item)
	{
		// 힌트: RecurGet()
		if (!node) {
			return new Node{ item, nullptr, nullptr };
		}

		if (node->item.key < item.key) {
			node->right = Insert(node->right, item);
		}
		else if (node->item.key > item.key) {
			node->left = Insert(node->left, item);
		}
		else {
			node->item = item;
		}

		return node;
	}

protected:
	Node* root_ = nullptr;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    using Item = BinarySearchTree<int>::Item;
    BinarySearchTree<int> bst;

	int n = 0;
	while (cin >> n) {
		if (cin.eof())break;
		bst.Insert(Item{ n });
	}

	bst.Postorder();

}