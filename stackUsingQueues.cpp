/*
Implement the following operations of a stack using queues. 
• push(x) -- Push element x onto stack. 
• pop() -- Removes the element on top of the stack. 
• top() -- Get the top element. 
• empty() -- Return whether the stack is empty. 
Notes:
 •You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
 •Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 •You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/

class Stack {
public:
	queue<int> Q1;
	queue<int> Q2;
	int currentQ = 0;
    // Push element x onto stack.
    void push(int x) {
    	if (currentQ)
    		Q2.push(x);
    	else
    		Q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
    	if (currentQ)
    	{
    		while(Q2.size() > 1)
    		{
    			int x = Q2.front();
    			Q2.pop();
    			Q1.push(x);
    		}
    		Q2.pop();
    		currentQ = 0;
    	}
    	else
    	{
    		while(Q1.size() > 1)
    		{
    			int x = Q1.front();
    			Q1.pop();
    			Q2.push(x);
    		}
    		Q1.pop();
    		currentQ = 1;
    	}
    }

    // Get the top element.
    int top() {
    	int res;
    	if (currentQ)
    	{
    		while(Q2.size() > 1)
    		{
    			int x = Q2.front();
    			Q2.pop();
    			Q1.push(x);
    		}
    		res = Q2.front();
    	}
    	else
    	{
    		while(Q1.size() > 1)
    		{
    			int x = Q1.front();
    			Q1.pop();
    			Q2.push(x);
    		}
    		res = Q1.front();
    	}
    	return res;
    }

    // Return whether the stack is empty.
    bool empty() {
    	if (currentQ)
    		return Q2.empty();
    	else
    		return Q1.empty();       
    }
};