/*
Implement the following operations of a queue using stacks. 
• push(x) -- Push element x to the back of queue. 
• pop() -- Removes the element from in front of queue. 
• peek() -- Get the front element. 
• empty() -- Return whether the queue is empty. 
Notes:
 •You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
 •Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
 •You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

class Queue 
{
public:
    // Push element x to the back of queue.
    void push(int x)
    {
        stack_push.push_back(x);
    }

    // Removes the element from in front of queue.
    void pop(void)
    {
    	if (stack_pop.empty())
    	{
    		while (!stack_push.empty())
    		{
	    		stack_pop.push_back(stack_push.back());
	    		stack_push.pop_back();
    		}
    	}
    	stack_pop.pop_back();
    }

    // Get the front element.
    int peek(void)
    {
    	if (stack_pop.empty())
    	{
    		while (!stack_push.empty())
    		{
	    		stack_pop.push_back(stack_push.back());
	    		stack_push.pop_back();
    		}
    	}
    	return stack_pop.back();  
    }

    // Return whether the queue is empty.
    bool empty(void)
    {
        return (stack_push.empty() && stack_pop.empty());
    }

private:
	vector<int> stack_push;
	vector<int> stack_pop;

};