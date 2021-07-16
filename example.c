#include <stdio.h>
#include <string.h>
#include "stack.h"

typedef struct
{
    char *name;
    int age;
} example_data;

void print_example_data(void *d)
{
    if (!d)
    {
        printf("NULL!\n");
        return;
    }

    // typecase data to example data struct
    example_data *data = d;

    printf("{name: %s, age: %d}", data->name, data->age);
}

int main(int argc, char *argsv[])
{
    // create an example data
    example_data data = {
        .name = "Naman Tamrakar",
        .age = 21};

    // creating a new queue q1 along with data
    stack *q1 = create_stack(sizeof(example_data), &data);
    // creating a new stack q2 without initial data
    stack *q2 = create_stack(sizeof(example_data), NULL);

    // printing the stack
    printf("length: %d, q1: ", length(q1));
    print_stack(q1, print_example_data);
    printf("length: %d, q2: ", length(q2));
    print_stack(q2, print_example_data);

    // adding new data
    push(q1, &(example_data){
                 .name = "Test user",
                 .age = 15});
    push(q2, &(example_data){
                 .name = "Test user",
                 .age = 15});
    push(q1, &(example_data){
                 .name = "Test user 1",
                 .age = 15});
    push(q2, &(example_data){
                 .name = "Test user 1",
                 .age = 15});

    // printing the stack
    printf("length: %d, q1: ", length(q1));
    print_stack(q1, print_example_data);
    printf("length: %d, q2: ", length(q2));
    print_stack(q2, print_example_data);

    // get the peek data of stack
    print_example_data(peek(q1));
    printf(" length: %d\n", length(q1));
    print_example_data(peek(q2));
    printf(" length: %d\n", length(q2));

    // remove some stackes
    example_data temp1, temp2;

    pop(q1, &temp1);
    printf("q1 => length: %d, temp1: ", length(q1));
    print_example_data(&temp1);
    printf("\n");

    pop(q2, &temp2);
    printf("q2 => length: %d, temp2: ", length(q2));
    print_example_data(&temp2);
    printf("\n");

    // exhuast stack
    pop(q1, NULL);
    pop(q2, NULL);

    // // check for empty
    printf("q1 => empty: %d, length: %d\n", is_empty(q1), length(q1));
    printf("q2 => empty: %d, length: %d\n", is_empty(q2), length(q2));

    // releasing the memory
    destroy_stack(&q1);
    destroy_stack(&q2);
    return 0;
}
