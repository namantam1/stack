#include <stdlib.h>
#include <stdbool.h>

#ifndef __STACK_H__
#define __STACK_H__

#ifdef __cplusplus
extern "C"
{
#endif

    typedef void *void_ptr;
    typedef const void *c_void_ptr;

    typedef struct Stack stack;
    typedef stack *stack_ptr;
    
    /**
     * Create a new stack from givin data.
     * 
     * @param size: Size of generic data
     * @param data: Generic data (option)
     * 
     * @returns stack pointer
    */
    stack *create_stack(size_t, const void *);

    /**
     * Function to add the element to to stack
     * 
     * @param s: stack pointer
     * @param data: data to add to stack
     * @return void(0)
    */
    void push(stack *, const void *);

    /**
     * Function to remove a node from stack from top
     * 
     * @param s: stack pointer
     * @param data: a mutable data pointer with memory allocated
     * or use static varible pointer.
     * @return true if success else false
    */
    bool pop(stack *, void *);

    /**
     * Function to get top node data of the stack
     * @param s: stack pointer
     * @return data pointer if stack not empty else NULL
    */
    void *peek(stack *);

    /**
     * Function to search a element from given search function
     * and key
     * 
     * @param s: stack pointer
     * @param key: key of which data to be find
     * @param compare_fun: compare function to compare a key with data
     * which take data and key as arguments and return boolean value based on that.
     * @return data ponter if found else NULL
    */
    void *search(stack *, void_ptr key, bool (*compare_fun)(c_void_ptr data, c_void_ptr key));

    /**
     * Print the string representation of stack
     * 
     * @param s: stack pointer
     * @param print: print function with a data pointer argument
     * @return void(0)
    */
    void print_stack(stack *, void (*)(void *));

    /**
     * Function to get the current length of stack
     * 
     * @param s: stack pointer
     * @return length(int)
    */
    int length(stack *);

    /**
     * Function to clear all the memory created along with stack
     * 
     * @param s: stack double pointer
    */
    void destroy_stack(stack **);

    /**
     * Function to check if stack is empty
     * 
     * @param s: stack pointer
     * @return boolean
    */
    bool is_empty(stack *);

#ifdef __cplusplus
}
#endif

#endif // __STACK_H__