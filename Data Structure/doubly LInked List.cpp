#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>


typedef struct node {
    int data;
    struct node* link;
}Node;

Node* create_node(int value) {

    Node* temp = NULL;
    temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed!!\n");
        exit(1);
    }

    temp->data = value;
    temp->link = NULL;

    return temp;
}

Node* insert_first(Node* head, int value) {

    Node* temp = NULL;

    temp = create_node(value);
    if (temp != NULL) {
        // Make temp node as the first node
        // The next node of the temp is the previously first node
        temp->link = head;

        // Make head pointer point to temp node
        head = temp;
    }
    return head;
}
Node* insert(Node* head,Node *pre, int value) {

    Node* p = NULL;
    p = create_node(value);
       
    if (p == NULL) {
        printf("Memoey allocation is failed\n");
        exit(1);
    }
    p->link = pre->link;
    pre->link = p;
    return head;
}

int is_in_list(Node* head, int item)
{
    Node* temp = head;
    for (temp; temp != NULL; temp = temp->link)
        if (temp->data == item)
        {
            return 1;
        }
        else return 0;
}

int count_list(Node* head)
{
    Node* p = head;
    int count = 0;
    for (p = head; p != NULL; p = p->link) {
        count++;
    }
    return count;
}
Node * clear(Node* head)
{
    Node* p = NULL;
    Node* temp = head;
    while (temp !=NULL) 
    {
        p = temp;
        temp = temp->link;
        free(p);
    }
    head = NULL;

    return head;
}
int is_empty(Node* head)
{
    return head == NULL;
}
Node* delete_first(Node* head) {

    // Make temp as the first node
    Node* temp = head;

    if (temp != NULL)

        // If temp is the only node (i.e, first & last at the same time),
        // then, temp->link is NULL
        // Otherwise, temp is not the only node in the list,
        // then, temp->link points to the second node
        // Make head pointer point to either NULL or the address of the 2nd node
        head = temp->link;

    free(temp);

    return head;
}
Node* delete_node(Node* head, int item){

    Node* p;
    if (head == NULL)
    {
        printf("List is empty!!\n");
        
    }

    else if (head->data == item)
    {
        p = head;
        head = head->link;
        free(p);
    }
    else
    {
        Node* pre = head;
        for (pre; pre->link->data != item; pre = pre->link);
        p = pre->link;
        pre->link = p->link;
        free(p);
    }
    return head;
}


Node* sorted_List(Node* head)
{
    Node* p, * temp;
    p = head;
    while (p->link != NULL) {
        if (p->data > p->link->data)
        {
            temp = p->link; 
            p->link = p->link->link;
            temp->link = head; 
            head = p = temp; 
            continue;
        }
        p = p->link;

    }
    return head;
}
void print_list(Node* head) {

    Node* p = head;
    if (head == NULL) {
        printf("Node is NULL");
        return;
    }
   for (p = head; p != NULL; p = p->link) {
        printf("data is %d\n", p->data);
    }
   
   
}
int main() {
    int fid = 0;
    int num, num2, input;
    Node* head = NULL;

    while (1) {
        printf("1.add first 2.add 3. delete first 4.delete node 5.Node count 6.Search 7.is empty 8. SortiedList 9.print list 10. clear 0.exit \n");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            scanf("%d", &num2);
            head = insert_first(head, num2);
            break;
        case 2:
            scanf("%d", &num2);
            head = insert(head, head, num2);
            break;
        case 3:
            head = delete_first(head);
            break;
        case 4:
            scanf("%d", &num2);
            head = delete_node(head, num2);
            break;
        case 5:
            printf("%d\n", count_list(head));
            break;
        case 6:

            printf("Enter the number you want to find :");
            scanf("%d", &fid);
            if (is_in_list(head, fid) == 1)
                printf("numbers exist\n");
            else
                printf("numbers not exist\n");
            break;

        case 7:
            if (is_empty(head) == 1)
                printf("empty");
            else
                printf("not empty");
            break;
        case 8:
            head = sorted_List(head);
            break;
        case 9:
            print_list(head);
            break;
        case 10:
            head = clear(head);
        case 0:
            exit(1);





            

        }

    }
    return 0; 
}
