#include "avl/avl.c"
#include "libs/gerarAbp/gerarAbp.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    file = fopen("data/data.csv", "r");
    struct Node *root = gerarAbp(100, file);
    

    printPreOrder(root);
    fclose(file);
    free(root);
    return 0;
}

// deallocate (node):
//     //do nothing if passed a non-existent node
//     if node is null
//         return

//     //now onto the recursion
//     deallocate(left node)
//     deallocate(right node)

//     free node