namespace mylib
{
    class Stack
    {
    private:
        int stack[128];
        int index = -1;

    public:
        void push(int value) { stack[++index] = value; };
        int pop() { return stack[index--]; };
        int peek() { return stack[index]; };
    };
}