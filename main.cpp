#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "tree.h"

int main(){

    node_t* node = CreateNode(50);
    printf("1");

    int a[10] = {70, 30, 10, 65, 80, 20, 5, 10, 60, 90};

    for(int i = 0; i < 10; i++){
        Insert(node, a[i]);
        printf("%i \n", a[i]);
    }

    Print(node);
    export_tree_to_dot(node, "tree.dot");
    DestructNode(node);
    // fflush(stdout);
    return 0;
}