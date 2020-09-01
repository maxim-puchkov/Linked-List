//
//  main.c
//  Assignment1
//
//  Created by admin on 2018-01-26.
//  Copyright © 2018 Maxim Puchkov. All rights reserved.
//

#include <stdio.h>
#include "LIST.h"

void itemFree(void *item) {
    printf("Item freed: %c\n", *(char *)item);
}

int comparator(void *a, void *b) {
    return *(char *)a == *(char *)b;
}

void printList(LIST *list) {
    Node *node = list->head;
    while (node) {
        printf("%c -> ", *(char *)node->item);
        node = node->next;
    }
    printf("NULL\n");
}

int main(int argc, const char * argv[]) {
    
    char alphabet[] = {
        'a','b','c','d','e','f','g','h','i','j',
        'k','l','m','n','o','p','q','r','s','t',
        'u','v','w','x','y','z'
    };
    
    printf("\nTesting...\n");
    printf("Max Lists: %d\n", MAX_LISTS);
    printf("Max Nodes: %d\n", MAX_NODES);
    
    /* Create lists */
    LIST *list_1;
    LIST *list_2;
    LIST *list_3;
    LIST *list_4;
    list_1 = ListCreate();
    list_2 = ListCreate();
    list_3 = ListCreate();
    list_4 = ListCreate();
    printf("\nCreating 4 lists (%d max):\n", MAX_LISTS);
    printf("List 1 created: %c\n", list_1 ? 'Y' : 'N');
    printf("List 2 created: %c\n", list_2 ? 'Y' : 'N');
    printf("List 3 created: %c\n", list_3 ? 'Y' : 'N');
    printf("List 4 created: %c\n", list_4 ? 'Y' : 'N');
    
    /* ListAdd function */
    printf("\nAdding via ListAdd\n");
    printf("List 1 Adds %c. Status: %d\n", alphabet[0], ListAdd(list_1, &alphabet[0]));
    printList(list_1);
    
    /* ListInsert function */
    printf("\nInserting via ListInsert\n");
    printf("List 1 Inserts %c. Status: %d\n", alphabet[4], ListInsert(list_1, &alphabet[4]));
    printList(list_1);
    
    /* ListAppend function */
    printf("\nAppend via ListAppend\n");
    printf("List 1 Appends %c. Status: %d\n", alphabet[9], ListAppend(list_1, &alphabet[9]));
    printList(list_1);
    
    /* ListPrepend function */
    printf("\nPrepend via ListPrepend\n");
    printf("List 1 Prepends %c. Status: %d\n", alphabet[8], ListPrepend(list_1, &alphabet[8]));
    printList(list_1);
    
    /* List 2 */
    printf("\nAdding more elements to List 2\n");
    printf("List 2 Adds %c. Status: %d\n", alphabet[3], ListAdd(list_2, &alphabet[3]));
    printf("List 2 Adds %c. Status: %d\n", alphabet[25], ListAdd(list_2, &alphabet[25]));
    printf("List 2 Adds %c. Status: %d\n", alphabet[9], ListAdd(list_2, &alphabet[9]));
    printList(list_2);
    
    /* Combine Lists */
    printf("\nCombining List 1 and List 2\n");
    ListConcat(list_1, list_2);
    printf("List 1 now: ");
    printList(list_1);
    printf("List 2 now: ");
    printList(list_2);
    printf("List 1 size: %d\n", ListCount(list_1));
    
    /* List 3 */
    printf("\nAdding more elements to List 3\n");
    printf("List 3 Prepends %c. Status: %d\n", alphabet[18], ListPrepend(list_3, &alphabet[18]));
    printf("List 3 Prepends %c. Status: %d\n", alphabet[25], ListPrepend(list_3, &alphabet[25]));
    printList(list_3);
    
    /* Combine Lists */
    printf("\nCombining List 1 and List 3\n");
    ListConcat(list_1, list_3);
    printf("List 1 now: ");
    printList(list_1);
    printf("List 3 now: ");
    printList(list_3);
    printf("List 1 size: %d\n", ListCount(list_1));
    
    /* ListTrim */
    printf("\nList 1 trim via ListTrim\n");
    printf("Last element removed: %c\n", *(char *)ListTrim(list_1));
    printf("Last element removed: %c\n", *(char *)ListTrim(list_1));
    printf("Now ListCurr: %c\n", *(char *)ListCurr(list_1));
    printList(list_1);
    printf("List 1 size: %d\n", ListCount(list_1));
    
    /* ListFirst, ListLast, ListPrev */
    printf("\nListFirst, ListLast, ListPrev, ListCurr tests\n");
    printf("ListFirst(list_1): %c\n", *(char *)ListFirst(list_1));
    printf("ListLast(list_1): %c\n", *(char *)ListLast(list_1));
    printf("ListPrev(list_1): %c\n", *(char *)ListPrev(list_1));
    printf("ListCurr(list_1): %c\n", *(char *)ListCurr(list_1));
    printList(list_1);
    
    /* Free List */
    printf("\nCalling ListFree on List 1\n");
    ListFree(list_1, itemFree);
    printf("\nList 1 size: %d\n", ListCount(list_1));
    
    return 0;
}
