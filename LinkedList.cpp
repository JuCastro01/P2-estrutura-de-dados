//P2 estrutura de dados
// Julia carvalho de souza castro TIA:32022298


#include "LinkedList.h"

LinkedList* Create()
{
    LinkedList* list = new LinkedList;
    list->count = 0;
    list->head = nullptr;
    list->tail = nullptr;

    return list;
}

void Destroy(LinkedList* list)
{
    Clear(list);

    delete list;
    list = nullptr;
}

void Insert(LinkedList* list, int id, string name)
{
    Node* node = CreateNode(name, id, list->head, list->tail);

    if (IsEmpty(list))
    {
        list->head = list->tail = node;
    }
    else
    {
        list->head = node;
        list->head->next->previous = list->head;
    }
    
    ++list->count;
}

void Append(LinkedList* list, int id, string name)
{
    Node* node = CreateNode(name, id, list->head, list->tail);

    if (IsEmpty(list))
    {
        list->head = list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail->next->previous = list->tail;
        list->tail = node;
    }

    ++list->count;
}



Node* RemoveHead(LinkedList* list)
{
    if (IsEmpty(list))
    {
        return nullptr;
    }

    Node* toRemove = list->head;

    if (list->head == list->tail)
    {
        list->head = list->tail = nullptr;
    }
    else
    {
        list->head = list->head->next;
        list->head->previous = list->tail;
    }

    --list->count;

    toRemove->next = nullptr;
    toRemove->previous = nullptr;
    return toRemove;
}

Node* RemoveTail(LinkedList* list)
{
    Node* toRemove = list->tail;
    
    if (list->head == list->tail)
    {
        return RemoveHead(list);
    }
    else
    {
        list->tail = list->tail->previous;
        list->tail->next = list->head;
        
    }

    --list->count;

    toRemove->next = nullptr;
    toRemove->previous = nullptr;
    return toRemove;
}

Node* RemoveNode(LinkedList* list, int id)
{
    Node* toRemove = list->head;


    int i = 0;
    while ( i < list->count )
    {
        if (id == list->head->id)
        {
            return RemoveHead(list);
        }
        else if (id == list->tail->id)
        {
            return RemoveTail(list);
        }
        if (toRemove->id == id)
        {
            toRemove->previous->next = toRemove->next;
            toRemove->next->previous = toRemove->previous;
            

            --list->count;

            toRemove->next = nullptr;
            toRemove->previous = nullptr;
            return toRemove;
        }
        toRemove = toRemove->next;
        ++i;
    }

    

    return nullptr;
}

Node* GetHead(const LinkedList* list)
{
    return list->head;
}

Node* GetTail(const LinkedList* list)
{
    return list->tail;
}

Node* GetNode(const LinkedList* list, int id)
{
    Node* node = list->head;
    while (node != nullptr)
    {
        if (node->id == id)
        {
            return node;
        }
        node = node->next;
    }

    return nullptr;
}

int Count(const LinkedList* list)
{
    return list->count;
}

bool IsEmpty(const LinkedList* list)
{
    return list->head == nullptr && list->tail == nullptr;
}

void Clear(LinkedList* list)
{
    Node* node = list->head;
    Node* next = nullptr;
    bool repeat = false;

    while (repeat)
    {
        next = node->next;
        DestroyNode(node);
        node = next;
        if(node == list->head)
        {
            repeat = true;
        }
    }

    list->head = list->tail = nullptr;
    list->count = 0;
}

Node* CreateNode(string name, int id, Node* next, Node* previous)
{
    Node* node = new Node;
    node->name = name;
    node->id = id;
    node->next = next;
    node->previous = previous;

    return node;
}

void DestroyNode(Node* node)
{
    delete node;
    node = nullptr;
    
}
//#####################################################################################################################################################
// Essas novas funções se encaixam no padrão de notação big O O(n), pois a quantidade de nós define o tempo que sera usado já que terá que percorrer todos.
//#####################################################################################################################################################

bool InsertAfter(LinkedList* list, int afterid, int id, string name)
{
    if(IsEmpty(list))
    {
        return false;
    }
    Node* NewNode = list->head;
    int i = 0;
    while ( i < list->count )
    {
        if (afterid == list->head->id)
        {
            Append(list, id, name);
            return InsertAfter;
        }
        else if(NewNode->id == afterid)
        {
            Node* node = CreateNode(name, id, list->head, list->tail);
            node->next = NewNode->next;
            node->previous = NewNode;
            NewNode->next->previous = node;
            NewNode->next = node;
            ++list->count;
            return InsertAfter;
        }
        NewNode = NewNode->next;
        ++i;
    }
    return false;
}

bool InsertBefore(LinkedList* list, int beforeid, int id, string name)
{
    Node* NewNode = list->head;
    int i = 0;
    while ( i < list->count ) {
        if (beforeid == list->head->id)
        {
            Insert(list, id, name);
            return InsertAfter;
        }
        if(NewNode->id == beforeid)
        {
            Node* node = CreateNode(name, id, list->head, list->tail);
            node->next = NewNode;
            node->previous = NewNode->previous;
            NewNode->previous->next = node;
            NewNode->previous = node;
            ++list->count;
            return InsertBefore;
        }
        NewNode = NewNode->next;
        ++i;
    }
    return false;
}