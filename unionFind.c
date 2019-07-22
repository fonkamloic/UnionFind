    //
// Created by fonkam on 7/18/19.
//



#include "unionFind.h"

    list *insertNode(list *headList, int item){
     if(headList == NULL ){
     headList = (list *)malloc(sizeof(list));
        if(headList == NULL) {
            printf("Error creating node using malloc :(\n");
            return NULL;
        }
            headList->value = item;
            headList->rank = 0;
            headList->checked = false;
            headList->parent = headList;
            headList->next = NULL;
            return headList;
     }

     //Insert new node to the head of the link
     list *searchNode = search(headList, item);
     if(searchNode != NULL){
         return searchNode;
     }
      list *newNode = malloc(sizeof(list));
        if(newNode == NULL) {
            printf("Error creating node using malloc :(\n");
            return NULL;
        }

         newNode->value = item;
         newNode->parent = newNode;
         newNode->rank = 0;
         newNode->checked = false;
         newNode->next = headList;
         headList = newNode;
         return headList;
}

list *join(list *headList, int first, int second){
    list *parentFirst= search(headList, first);
    list *parentSecond= search(headList, second);

    if(parentFirst != NULL && parentSecond != NULL){
        if(parentFirst->rank >=  parentSecond->rank ){
            parentFirst->rank += 1;
            parentSecond->parent = parentFirst;
            return parentFirst;
        }
        parentSecond->rank += 1;
        parentFirst->parent = parentSecond;
        return parentSecond;
    }
    return NULL;
}

list *search(list *headList, int nodeToSearch){
    list *temp = headList;
    if(temp == NULL)
        return NULL;
    if(temp->next == NULL && temp->value != nodeToSearch)
        return  NULL;
    while (temp->next != NULL){
        if(temp->value == nodeToSearch){
            while(temp->parent != temp){
                temp = temp->parent;
            }
            if(temp->parent == temp)
                return temp;

        }
        temp = temp->next;
    }
    if(temp->value == nodeToSearch){
            while(temp->parent != temp){
                temp = temp->parent;
            }
            if(temp->parent == temp)
                return temp;

        }
    return  NULL;
}

list *sameClass(list *headList, int value0, int value2){
    list *parent1 = search(headList, value0);
    list *parent2 = search(headList, value2);

    return parent1 == parent2 ? parent1 : NULL;

}


void printList(list *headList){
    list *temp = headList;
    if(temp == NULL)
        return;
    while(temp != NULL){
        printf("node is: %d, rank is %d\n", temp->value, temp->rank);
        temp = temp->next;
    }
}


void showSets(list *headlist){
   if(headlist == NULL)
       return;
   list *current = headlist, *forward = NULL;
   bool firstPast = true, end = false;
   while(current != NULL){
       forward = current->next;
       while(forward != NULL){
           if(current->checked == false || (current->checked == true && firstPast == false)){
               current->checked == false?  printf("{ %d", current->value) : (end = true);
               current->checked = true;
               firstPast = true;
           }
           if(forward->checked == false  && sameClass(headlist, current->value, forward->value) != NULL){
              printf(", %d", forward->value);
              forward->checked = true;
           }
           else if(forward->next == NULL ){
               if(end == false)
                   printf(" }\n");
               else {
                   printf(" \b");
                   end = false;
               }

           }
           forward = forward->next;
       }
       firstPast = false;
       current = current->next;
//       if(current == NULL)
//           printf(" }\n");

   }
    resetMem(headlist);
}

void resetMem(list *headList){
    if(headList != NULL){
        while(headList != NULL){
            headList->checked = false;
            headList = headList->next;
        }
    }
}
