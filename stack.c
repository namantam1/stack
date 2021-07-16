/*
MIT License

Copyright (c) 2021 Naman Tamrakar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

IDEA:
Stack works on the principle of LIFO
that is last in first out concept.

So the idea here is that we use linked list for
storing the data in chain.

Strategy :- 
========
PUSH: put the element in front of linked list i.e. head 
POP: pull the element from the head of linked list i.e. head
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"

#define FAIL_IF_MSG(EXP, MSG)                               \
    {                                                       \
        if (EXP)                                            \
        {                                                   \
            printf("Error: %s, LINE: %d\n", MSG, __LINE__); \
            exit(EXIT_FAILURE);                             \
        }                                                   \
    }

#ifdef DEBUG
#define LOG(...) printf(__VA_ARGS__);
#else
#define LOG(...)
#endif

// Linked list node definitions
typedef struct Node
{
    void *data;
    struct Node *next;
} node;
typedef node *node_ptr;
typedef const node *c_node_ptr;

// NODE IMPLEMENTATION
static void _copy_generic_data(void_ptr *target, c_void_ptr data, size_t size)
{
    *target = malloc(size);

    FAIL_IF_MSG(!target, "Stackoverflow!");

    // copy data to target
    memcpy(*target, data, size);
}

static node_ptr _create_node(c_void_ptr data, node_ptr next, size_t size)
{
    // printf("create node\n");
    node_ptr new = (node_ptr)malloc(sizeof(node));

    FAIL_IF_MSG(!new, "Stackoverflow!");

    // copy data to data pointer after assigning memory
    _copy_generic_data(&(new->data), data, size);
    new->next = next;
    return new;
}

static void _destroy_node(node_ptr n)
{
    LOG("destroy node\n");
    free(n->data);
    free(n);
}

// ##################################################################################
//  QUEUE IMPLEMENTATION                                                            #
// ##################################################################################

typedef struct Stack
{
    node_ptr head;
    int length;
    size_t size;
} stack;

stack_ptr create_stack(size_t size, c_void_ptr data)
{
    LOG("create stack %p\n", data);
    // allocated the memory to queue pointer
    stack_ptr s = (stack_ptr)malloc(sizeof(stack));
    s->size = size;

    node *head = NULL;
    int length = 0;

    // if data is passed the copy the data to new
    // memory and point the head to it.
    if (data)
    {
        head = _create_node(data, NULL, s->size);
        length = 1;
    }

    s->head = head;
    s->length = length;

    return s;
}

void push(stack_ptr s, c_void_ptr data)
{
    LOG("push\n");
    // creating a new node from givin data
    // point the new node next to head and head to new
    node_ptr new = _create_node(data, s->head, s->size);
    s->head = new;
    s->length += 1;
}

bool pop(stack_ptr s, void_ptr data)
{
    // check for empty
    if (!s->head)
    {
        LOG("stack is empty\n");
        return false;
    }

    // point head to next and copy the data
    if (data)
        memcpy(data, s->head->data, s->size);

    node_ptr temp = s->head;
    s->head = s->head->next;
    s->length -= 1;
    _destroy_node(temp);
    return true;
}

void *peek(stack_ptr s)
{
    return s->head ? s->head->data : s->head;
}

// TODO: To Implement Search Method

void print_stack(
    stack_ptr s,
    void (*print_data)(void_ptr))
{
    if (s == NULL)
    {
        LOG("Stack pointer is NULL, %p\n", s);
        return;
    }
    // get the first pointer of node
    node_ptr head = s->head;

    printf("[");
    while (head)
    {
        print_data(head->data);
        head = head->next;
        if (head)
            printf(", ");
    }
    printf("]\n");
}

int length(stack_ptr s)
{
    return s->length;
}

bool is_empty(stack_ptr s)
{
    return s->head ? false : true;
}

void destroy_stack(stack_ptr *s)
{
    while ((*s)->head)
    {
        pop((*s), NULL);
    }
    free((*s));
    *s = NULL;
}
