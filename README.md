# Stack Implementation in C Language

## Features - 
1. Generic Data type support.
2. Auto garbage collection while poping out the data from stack.
3. No size restriction due to implementation with the help of linked list.
4. Better data structure management.

## How to use -

- Clone this project.
```bash
git clone https://github.com/namantam1/stack
cd stack
```
- Run the example file with make or command line.
```bash
make && ./example.out
# or
gcc stack.c example.c -o example.out && ./example.out
```
- To use this stack in another project import this libary as -
```c
#include "stack/stack.h"

int main() {
    int data = 10;
    // create a new stack
    stack q = create_stack(&data);

    // do you stuff
    // ...
    // ...

    // destroy the stack if not in use to free the memory.
    destroy_stack(&q);
}
```

## Issue

If you find any please don't hesitate to create an [issue](https://github.com/namantam1/stack/issues).

Any Contribution or suggestion are welcome.

## License
This project is [MIT](LICENSE) License.