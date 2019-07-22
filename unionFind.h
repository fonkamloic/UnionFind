//
// Created by fonkam on 7/18/19.
//

#ifndef UNIONFIND_UNIONFIND_H
#define UNIONFIND_UNIONFIND_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct link_list{
    int rank;
    int value;
    bool checked;
    struct link_list *next;
    struct link_list *parent;
}list;


//list *createList();
list *search(list *headList, int nodeToSearch);

list *insertNode(list *HeadList, int item);

list *sameClass(list *headList, int value0, int value2);

list *join(list *headList, int first, int second);

void printList(list *headList);

void showSets(list *headlist);

void resetMem(list *headList);
#endif //UNIONFIND_UNIONFIND_H
