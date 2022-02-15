//--------------------------- Lecture 12 ------------------------//
// --------------------- Stacks/Queues---------------//
/* 
Stacks are an abstract data type that have LIFO (Last in First Out), or FILO order
    - Peek = read the top elements
    - Pop = remove the top element
    - Push = add element to the top

Possible implementations of stacks:
    - Linked List implementation
        - Add to front, remove from front
        - Add to back, rmove from back
    - Dynamic Array implementation
        - Add to end, remove from end
        - Add to front, remove from front

Queue are an abstract data type that have FIFO (First in First Out ordering), or LILO.
    - Insertion and deletion occur at opposite positions
    - Keep track of back and front

    - Peek: Read the front element
    - Dequeue: remove element from the front
    - Enqueue: Add element to the back

Possible Implementations
    - Linked List implementation
        - Add to back, remove from front
            - Add: traverse or use tail pointer
        - Add to front, rmove from back
            -Remove: traverse or use previous node pointers

    - Dynamic Array implementation
        - Add to end, remove from end
        - Add to front, remove from front

        - In both cases, shuffle elements when modifying the front
            - Or loop the queue around


Complexity:
    - Stacks
        - Linked List: operations using the head pointer/front of the lsit as the top
            - Peek, pop, push all O(1)
        - Dynamic Array - Lst element as top
            - Peek, pop, push are all O(1) - if you don't have to resize

    - Queues
        - Linked List: enqueue at back, dequeue at front
            - Peek and dequeue are O(1), enqueue is O(n)
            Add to tail pointer to make enqueue O(1)
        
        - Dynamic array: enqueue at back, tracking last element index
            - Peek, push are O(1), pop is O(n) - if you don't have to resize
            - Pop can be O(1) if you track the front index or don't reshuffle the elements


Both stacks and queues can operate at O(1)
    - Use stacks when prioritizing the most recent data
    - Function call stack, displaying notifications, undo typing

    - Use queues when there is an ordered lineup
        - Priority
            - Every element has a priority value
            - Dequeue by priority value
        - Circular
            - Back of queue loops to front




The runtime of stack queue operations depends implementation

        Linked Lists vs Arrays
Indexing    O(i)        O(1)

Inserting   O(i)        O(n-1)

Delete      O(i)        O(n-i)

*/

//------------ Stack Operations ------------//
/* 

Implemented with a standard Linked List, with the head as the tip of the stack.
    - Peek (returns first element): O(1) 
    - Pop (Removes element): O(1) --> Changes head pointer in constant time
    - Push (Adds element): O(1) --> Changes head pointer in constant time

*/

//----------- Stack Operations pt 2------------//
/*

We can implement a stack with a dynamic array, with teh end of the array as the top of the stack.

We can keep track of the length of the array so
    - Peek: We can peek to the last index (since we know the length) --> O(1)
    - Pop: We can pop the last index by using the length - 1 --> O(1)
    - Push: If we push to the back, you may have to realloc, therefore either O(1) or O(n) if realloc is needed.*/

//----------- Stack Operations pt 3------------//

/* We can implement a stack with a dynamic array, with teh end of the array as the top of the stack.

    - Peek: O(1), returns first value
    - Pop: O(n), removes first value and shifts everything back
    - Push: O(n), reshifts all values and adds one to the front


//----------- Queue Operations------------//
/* We can implement a queue with a standard linked lists, with the end of the list as the top of the queue.

    - Peek: O(1)
    - Dequeue: O(1)
    - Enqueue: O(n)

/* We can implement a queue with a modified linked lists, with the head as the front of the queue, and a tail to keep track of the end.

    - Peek: O(1)
    - Enqueue: O(1) at the end
        tail->next = smthsmth
        tail = tail->next

    - Dequeue: O(1) = Pop --> values are popped form the front


/* We can implement a queue with a dynamic array, with teh end of the array as the start of the queue.
    - Peek: O(1)
    - Enqueue: O(1)
    - Dequeue: O(n)

/* We can implement a queue with a dynamic array, with the start of the array as the start of the queue.
    - Peek: O(1)
    - Enqueue: O(n)
    - Dequeue: O(n)???


//----------- Queue/Stack applications -----------//
/*

Stacks: function call stack
Queues: anywhere you want to maintain ordered line-ups
    - Customer service, applications, etc. */