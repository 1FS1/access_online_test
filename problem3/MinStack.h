#define MINSTACK_H
#ifdef MINSTACK_H

struct StackNode
{
	int num;
	StackNode *next = nullptr;
	StackNode *pre = nullptr;
};

class MinStack{
public:
	MinStack();
	void push(int val);
	void pop();
	int top();
	int getmin();

private:
	StackNode *first;
	int count;
	int min;
};

#endif // MINSTACK_H

MinStack::MinStack()
{
	int count = 0;
	int min = 0;
	first->next = first;
	first->pre = first;
}

void MinStack::push(int val)
{
	StackNode *temp = new StackNode;
	temp->num = val;
	temp->next = first;
	temp->pre = first->pre;
	first->pre->next = temp;
	first->pre = temp;
	if (count == 0)
		min = val;
	else
		if (val < min)
			min = val;
}

void MinStack::pop()
{
	StackNode *temp;
	temp = first->pre;
	first->pre = temp->pre;
	temp->pre->next = first;
	delete temp;
}

int MinStack::top()
{
	return(first->pre->num);
}

int MinStack::getmin()
{
	StackNode *temp;
	temp = first->next;
	while (temp != first)
		if (temp->num < min)
			min = temp->num;
	return min;
}