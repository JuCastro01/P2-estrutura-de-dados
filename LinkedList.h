//P2 estrutura de dados
// Julia carvalho de souza castro TIA:32022298


#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>
#include <clocale>
#include <string>

using namespace std;

struct Node
{
    int id;
    string name;
    Node* previous;
    Node* next;
};

struct LinkedList
{
    int count;
    Node* head;
    Node* tail;
};


LinkedList* Create();

void Destroy(LinkedList* list);

void Insert(LinkedList* list, int id, string name);

void Append(LinkedList* list, int id, string name);

Node* RemoveHead(LinkedList* list);

Node* RemoveTail(LinkedList* list);

Node* RemoveNode(LinkedList* list, int id);

Node* GetHead(const LinkedList* list);

Node* GetTail(const LinkedList* list);

Node* GetNode(const LinkedList* list, int id);

int Count(const LinkedList* list);

bool IsEmpty(const LinkedList* list);

void Clear(LinkedList* list);

Node* CreateNode(string name, int id, Node* next, Node* previous);

void DestroyNode(Node* node);

bool InsertAfter(LinkedList* list, int afterid, int id, string name);

bool InsertBefore(LinkedList* list, int beforeid, int id, string name);



#endif 
