#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

struct node {
	node* left;
	node* right;
	int value;

	node(node*, node*, int);
};

node::node(node* a, node* b, int c) {
	left = a;
	right = b;
	value = c;
}

struct binarySearchtree {
	node* root = nullptr;

	void insert(int val);
	void insert_impl(node*, int);
	void print_tree();
	node* find(int val);
	node* find_impl(node*, int);
	void Order(node*);
};

void binarySearchtree::insert(int val) {

	//루트노드가 비었다면
	if (!root)
		root = new node(nullptr, nullptr, val);
	else {
		insert_impl(root, val);
	}
}

void binarySearchtree::insert_impl(node* current, int val) {
	
	//현재 노드가 없음
	if (!current) { current = new node(nullptr, nullptr, val); }
	
	//현재 노드의 값보다 val이 작음 - 왼쪽으로
	if (current->value > val) {
		//왼쪽이 없다면 - 대입
		if (!current->left) {
			current->left = new node(nullptr, nullptr, val);
		}

		//왼쪽이 있다면 - 다시 왼쪽을 타고 내려간다.
		else {
			return insert_impl(current->left, val);
		}
	}

	//현재 노드의 값보다 val 이 크다 -> 오른쪽
	else if (current->value < val) {
		//오른쪽이 없다면 - 대입
		if (!current->right) {
			current->right = new node(nullptr, nullptr, val);
		}

		//오른쪽이 있다면 - 다시 오른쪽을 타고 내려간다.
		else {
			return insert_impl(current->right, val);
		}
	}
}

node* binarySearchtree::find(int val) {
	return find_impl(root, val);
}

node* binarySearchtree::find_impl(node* current, int val) {
	//현재 노드가 없다면
	if (!current) { return NULL;  }

	//현재 노드가 찾던 값이라면 - 끝
	else if (current->value == val) {
		return current; 
	}

	// 현재 노드의 값보다 찾는 값이 작다면 - 왼쪾으로
	else if (val < current->value) {
		return find_impl(current->left, val);
	}

	else {
		return find_impl(current->right, val);
	}
}

//BFS로 돌면서 for문이 끝날 때마다 "\n"하면 되지 않을까? - 심지어 트리라 방문 표시가 필요 없다!
//다만... cout >> 을 어떻게 할지가 고민이다.
//그냥, 이진트리를 배열에 저장했다치고 그거 가지고 하는건 어떨까?
void binarySearchtree::print_tree() {
	queue<node*> BFS_Queue;

	BFS_Queue.push(root);

	while (!BFS_Queue.empty()) {
		int levelSize = BFS_Queue.size(); // 현재 큐에있는 노드수 -> 현재 레벨의 노드 수

		for (int i = 0; i < levelSize; i++) {
			auto a = BFS_Queue.front();
			BFS_Queue.pop();

			cout << a->value << " ";

			if (a->left != nullptr) BFS_Queue.push(a->left);
			if (a->right != nullptr ) BFS_Queue.push(a->right);

		}

		cout << endl;
	}
}

void binarySearchtree::Order( node* start) {
	// 현재 노드가 null이라면 -> 끝
	if (!start) { return; }

	//현재 노드를 방문 했을 때, 후위 -> 왼쪽, 오른쪽, 루트
	Order(start->left);
	Order(start->right);
	cout << start->value << "\n";
}



int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;

	binarySearchtree BST;
	
	while (cin >> num) {
		BST.insert(num);
	}

	BST.Order(BST.root);
	



}

//전위 순회 ( 루트 왼쪽 오른쪽 ) 한 결과가 주어질 때, 후위 순회한 결과를 출력하라 ( 왼쪽 오른쪽 루트 )
//그런데, 같은 원소를 가지는 이진 검색트리는 모두 결과가 같나?
//그러면, 원소로 트리를 만든 다음. 후위 순회를 하면 된다.
//이진 검색 트리 - 왼쪽 < 가운데 < 오른쪽