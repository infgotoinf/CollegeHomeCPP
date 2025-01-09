#include <iostream>
#include <queue>

struct SetElement
{
	int value;
	SetElement* left;
	SetElement* right;

	SetElement(int v)
	{
		value = v;
		left = nullptr;
		right = nullptr;
	}
};

struct IntSet
{
	SetElement* root;

	IntSet()
	{
		root = nullptr;
	}

	~IntSet()
	{
		std::queue<SetElement*> q;
		q.push(root);
		while (!q.empty())
		{
			SetElement* cur = q.front();
			q.pop();
			if (cur != nullptr)
			{
				q.push(cur->left);
				q.push(cur->right);
				delete cur;
			}
		}
		root = nullptr;
	}

	void add(int key)
	{
		if (root == nullptr)
		{
			root = new SetElement(key);
		}
		else
		{
			SetElement* cur = root;
			while (cur != nullptr)
			{
				if (key < cur->value)
				{
					if (cur->left == nullptr)
					{
						cur->left = new SetElement(key);
						break;
					}
					else
					{
						cur = cur->left;
					}
				}
				else if (key > cur->value)
				{
					if (cur->right == nullptr)
					{
						cur->right = new SetElement(key);
						break;
					}
					else
					{
						cur = cur->right;
					}
				}
				else
				{
					break;
				}
			}
		}
	}

	void print()
	{
		std::queue<SetElement*> q;
		q.push(root);
		while (!q.empty())
		{
			SetElement* cur = q.front();
			q.pop();
			if (cur != nullptr)
			{
				q.push(cur->left);
				q.push(cur->right);
				std::cout << cur->value << " ";
			}
		}
		std::cout << '\n';
	}

	void Remove(int rm) {
		SetElement* cur = root;
		while (1) {
			if (cur->value == rm) {
				Remover(cur);
				break;
			}
			else if (cur->left->value == rm) {
				if (check(cur->left)) {
					cur->left = nullptr;
				}
				else {
					cur = cur->left;
					Remover(cur);
				}
				break;
			}
			else if (cur->right->value == rm) {
				if (check(cur->right)) {
					cur->right = nullptr;
				}
				else {
					cur = cur->right;
					Remover(cur);
				}
				break;
			}
			else if (rm < cur->value) {
				cur = cur->left;
			}
			else {
				cur = cur->right;
			}
		}
	}

	bool check(SetElement* cur) {
		return (cur->left == cur->right ? true : false);
	}
	int get_cur_value(SetElement* cur) {
		return (cur->right != nullptr ? cur->right->value : cur->left->value);
	}
	void Remover(SetElement* cur) {
		if (get_cur_value(cur) > cur->value) {
			cur->value = get_cur_value(cur) - 1;
			Remove(get_cur_value(cur));
			cur->value += 1;
		}
		else {
			cur->value = get_cur_value(cur) + 1;
			Remove(get_cur_value(cur));
			cur->value -= 1;
		}
	};
};

int main()
{
	IntSet set;
	set.add(5);
	set.add(10);
	set.add(2);
	set.add(2);
	set.add(4);
	set.add(3);
	set.add(8);
	set.add(0);

	set.print();
	set.Remove(3);
	set.print();
	set.Remove(10);
	set.print();
	set.Remove(2);
	set.print();
	set.Remove(5);
	set.print();
	return 0;
}