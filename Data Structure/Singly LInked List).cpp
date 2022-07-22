#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char element[100];

typedef struct dnode {
    element data;
    struct dnode* prev;
    struct dnode* next;
    struct dnode* address;
}Node;

Node* create_node(element value) {


    Node* temp = NULL;
    temp = (Node*)malloc(sizeof(Node));

    if (temp == NULL) {
        printf("Memory allocation failed!!\n");
        exit(1);
    }
    strcpy(temp->data, value);
    temp->prev = NULL;
    temp->next = NULL;
    temp->address = NULL;

    return temp;
}

Node* insert(Node* before, element value) {

    Node* p = NULL;


    p = (Node*)create_node(value);


    p->prev = before;
    p->next = before->next;
    before->next->prev = p;
    before->next = p;



    return before;
}

void print_list(Node* head) {

    Node* p = head->next;
    if (p->next == NULL) {
        printf("list is NULL");
        exit(1);
    }
    while (p->next != NULL)
    {
        printf("%s\n", p->data);
        p = p->next;

    }

    printf("\n");


}

Node* delete_list(Node* head, Node* p, element name) {

    Node* del = head->next;



    for (del; del != p; del = del->next)

    {

        if (strcmp(del->data, name) == 0)

            break;

    }



    if (del == p) return head;

    del->next->prev = del->prev;
    del->prev->next = del->next;

    free(del);

    return head;
}

int count_list(Node* head)
{
    Node* p = head->next;
    int count = 0;
    if (p->next == NULL) {
        printf("list is empty!\n");

    }
    else {
        for (p; p->next != NULL; p = p->next) {
            count++;
        }
    }
    return count;
}
int is_empty(Node* head)
{
    Node* p = head->next;
    return p->next == NULL;
}
Node* search(Node* head, Node* p, element name)
{
    Node* del = head->next;

   

    for (del; del != p; del = del->next)

    {

        if (strcmp(del->data, name) == 0)

            return del;
        

    }



    if (del == p) return 0;
}
int is_in_list(Node* head, Node* p, element name)
{
    Node* del = head->next;


    for (del; del != p; del = del->next)

    {

        if (strcmp(del->data, name) == 0)

            return 1;

    }



    if (del == p) return 0;
}

int main() {
    //더미 노드 생성
    Node header, trailer, address;
    //두개의 더미 노드의 초기화 및 연결
    header.prev = NULL;
    header.next = &trailer;
    trailer.prev = &header;
    trailer.next = NULL;
    trailer.address = &address;
    element fid;
    int num, num2, input;
    Node* head = &header;



    while (1) {
        printf("1.add 2.delete 3.is_in_list 4.count_list 5.is_empty 6.print 7.search 0.exit \n");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            scanf("%s", &fid);
            head = insert(head, fid);
            break;
        case 2:
            scanf("%s", &fid);
            head = delete_list(head, trailer.next, fid);
            break;
        case 3:
            scanf("%s", &fid);
            if (is_in_list(head, trailer.next, fid) == 1)
                printf("exist\n");
            else
                printf("not exist\n");
            break;
        case 4:
            printf("리스트 갯수 %d\n", count_list(head));
            break;
        case 5:
            if (is_empty(head) == 1)
                printf("is empty\n");
            else
                printf("not empty\n");
            break;
        case 6:
            print_list(head);
            break;

        case 7:
            printf("Enter the number you want to find and save :");
            scanf("%s", &fid);
            trailer.address = search(head, trailer.next, fid);
            if (trailer.address == 0)
                printf("not exist\n");
            else
            printf("save and address is : 0x%p\n", trailer.address);
            break;

        case 0:
            exit(1);







        }

    }
    return 0;
}
