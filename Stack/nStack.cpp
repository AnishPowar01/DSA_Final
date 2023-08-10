class NStack
{
    int *arr, *top, *next;
    int size;
    int m; 
    int freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        this->m = N;
        this->size = S;
        freespot = 0;
        arr = new int[S];
        top = new int[N];
        next = new int[S];

        for(int i = 0; i<N; i++)
        {
            top[i] = -1;
        }


        for(int i = 0; i<S; i++)
        {
            next[i] = i+1;
        }

        next[S-1] = -1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if(freespot == -1)
        {
            return false;
        }

        // find the freeSpot'
        
        int index = freespot;

        // update the freespot;

        freespot = next[index];

        // insert the element;

        arr[index] = x;

        // update the next[index];

        next[index] = top[m-1];

        // update the top

        top[m-1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.


        if(top[m-1] == -1)
        {
            return -1;
        }

        int index = top[m-1];

        int elem = arr[index];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return elem;

    }
};