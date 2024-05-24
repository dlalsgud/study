#include <iostream>
#include <cstdlib>
#include <ctime>

typedef struct Node {
    int data;
    Node* prev;
    Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
} LinkedList;

LinkedList* Init()
{
    LinkedList* list = new LinkedList;

    list->head = NULL;
    list->tail = NULL;

    return list;
}

void InsertNode(LinkedList* list, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->tail != NULL)
        list->tail->next = newNode;
    else
        list->head = newNode;

    list->tail = newNode;
}

void DeleteNode(LinkedList* list, int value)
{
    Node* delNode = list->head;

    while (delNode != NULL)
    {
        if (delNode->data == value)
        {
            Node* nextNode = delNode->next;

            if (delNode->prev != NULL)
                delNode->prev->next = delNode->next;
            else
                list->head = delNode->next;

            if (delNode->next != NULL)
                delNode->next->prev = delNode->prev;
            else
                list->tail = delNode->prev;

            delete delNode;
            delNode = nextNode; 
        }
        else
        {
            delNode = delNode->next;
        }
    }
}

void PrintList(LinkedList* list)
{
    Node* current = list->head;

    while (current != NULL) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

int main()
{
    LinkedList* list = Init();
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        InsertNode(list, rand() % 100);
    }

    PrintList(list);

    DeleteNode(list, list->tail->data);

    PrintList(list);

    return 0;
}
