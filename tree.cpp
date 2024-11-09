#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "tree.h"


node_t* CreateNode(int value){

    node_t* node = (node_t*)calloc(1, sizeof(node_t));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void Insert(node_t* node, int value){
    if(value < node->data){
        if(node->left == NULL){
            node->left = CreateNode(value);
        }
        else{
            Insert(node->left, value);
        }
    }
    else{
        if(node->right == NULL){
            node->right = CreateNode(value);
        }
        else{
            Insert(node->right, value);
        }
    }
}

void Print (node_t* node){
    if(node == NULL) return;

    printf("(");
    printf("%d", node->data);

    if(node->left) Print (node->left);
     //printf(")");
    if(node->right) Print(node->right);
    //printf("%d", node->data);

    printf(")");


}

void DestructNode(node_t* node){
    if(node->left) DestructNode(node->left);
    if(node->right) DestructNode(node->right);
    free(node);
}

// void GraphDump(node_t* node){

//     FILE* f_dot = fopen("tree.dot", "w");

//     assert(f_dot);
//     assert(node);
//     if(ferror(f_dot)) fprintf(stderr, "FILE OPEN ERROR!!!\n");

//     fprintf(f_dot, "diagraf T{ \n node[fontsize = 9]; ");



    

//     fclose(f_dot);
// }

// void PrintRangForNode(node_t* node, FILE* f_dot, int i, int j){
//     if(node == NULL) return;

//     i++;
//     j++;

//     fprintf(f_dot, "{ rank = same; \"node_%d\"; \"rank_%d\"; \"a\"; } \n", j, i);

//     fprintf(f_dot, "\tnode%zu -> node%d;\n", i, list -> node[i].next);


//     fprintf(f_dot, "\tnode%zu [shape=record, color=blue,"
//                        "label=\" index=%zu | data=%d | next=%d | prev=%d \" ];\n",
//                        i, i, list -> node[i].data, list -> node[i].next, list -> node[i].prev);





// }
void write_dot(node_t* root, FILE* file) {
    if (root == NULL) {
        return;
    }

    // Запись текущего узла
    fprintf(file, "    node_%d [label=\"%d\"];\n", root, root->data);

    // Если у узла есть левое поддерево, запишем связь
    if (root->left) {
        fprintf(file, "    node_%d -> node_%d;\n", root, root->left);
        write_dot(root->left, file);
    }

    // Если у узла есть правое поддерево, запишем связь
    if (root->right) {
        fprintf(file, "    node_%d -> node_%d;\n", root, root->right);
        write_dot(root->right, file);
    }
}

// Основная функция для записи дерева в формате DOT
void export_tree_to_dot(node_t* root, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Ошибка: Не удалось открыть файл для записи.\n");
        return;
    }

    // Запись заголовка DOT файла
    fprintf(file, "digraph G {\n");

    // Запись дерева
    write_dot(root, file);

    // Закрываем граф в DOT формате
    fprintf(file, "}\n");

    fclose(file);
}

