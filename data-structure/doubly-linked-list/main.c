#include <stdio.h>
#include <stdlib.h>

/*
 * Example for data structure double linked list.
 * Allows operations push, pop, remove node.
 */

typedef struct d_linked_list
{
    size_t node_data;
    struct d_linked_list *next;
    struct d_linked_list *prev;

} d_linked_list_t;

d_linked_list_t *create_node()
{
    d_linked_list_t *head = NULL;

    head = (d_linked_list_t*)malloc(sizeof(d_linked_list_t));
    if(head == NULL)
    {
        printf("Allocation memory failed!");
        return NULL;
    }

    head->next = NULL;
    head->prev = NULL;
    head->node_data = 0;

    return head;
}

d_linked_list_t* create_list(size_t n)
{
    d_linked_list_t *curr = NULL;
    d_linked_list_t *first = NULL;

    if(n > 0)
    {
        for(size_t i = 0; i < n; i++)
        {
            curr = create_node();
            curr->next = first;
            curr->prev = NULL;
            curr->node_data = i;

            if(first)
            {
                first->prev = curr;
            }

            first = curr;
        }
    }
    return first;
}

int print_length_list(d_linked_list_t *head)
{
    int length = 0;
    d_linked_list_t *curr = NULL;
    for(curr = head; curr != NULL; curr = curr->next)
    {
        length = length + 1;
    }

    return length;
}

void print_foward_list(d_linked_list_t *node)
{
    d_linked_list_t *temp = node;

    if(node == NULL)
    {
        printf("List is empty!\n");
    }

    while (temp != NULL)
    {
        printf("Forward list item : current is %p; next is %p; prev is %p;\n",
               (void*)temp,
               (void*)temp->next,
               (void*)temp->prev);

        temp = temp->next;
    }
}


void print_backward_list(d_linked_list_t *node)
{
    d_linked_list_t *temp = node;

    if(node == NULL)
    {
        printf("List is empty!\n");
    }

    // Go to for last node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        printf("Backward list item : current is %p; next is %p; prev is %p;\n",
               (void*)temp,
               (void*)temp->next,
               (void*)temp->prev);

        temp = temp->prev;
    }
}

void push_to_end(d_linked_list_t *head)
{
    d_linked_list_t *temp = head;
    d_linked_list_t *node = create_node();

    if(head == NULL)
    {
        head = node;
    }

    while(temp->next != NULL)
    {
        //printf("while : %zu\n", temp->node_data);
        temp->node_data = temp->node_data + 1;
        temp = temp->next;
    }

    temp->next = node;
    node->prev = temp;

    //printf("List item: current is %zu \n", temp->next->node_data);
}

void remove_list(d_linked_list_t *node)
{
    d_linked_list_t *temp = NULL;

    while(node != NULL)
    {
        temp = node;
        node = node->next;
        free(temp);
    }
}

int main()
{
    d_linked_list_t *head_list= NULL;
    head_list = create_list(10);

    print_foward_list(head_list);
    print_backward_list(head_list);

    push_to_end(head_list);

    printf("Count of node in list : %d \n", print_length_list(head_list));

    remove_list(head_list);

    return 0;
}
