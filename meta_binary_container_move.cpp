#include "meta_binary_container.h"

void MetaBinaryContainer::ROL()
{
    if (capacity > 1)
    {
        metaBit* temp = container.chainRear;
        container.chainRear = container.chainRear->father;
        container.chainRear->next = nullptr;

        temp->next = container.chainHead;
        container.chainHead->father = temp;
        container.chainHead = temp;
        container.chainHead->father = nullptr;
    }
    else
        throw QString("error: moving one bit");
}

void MetaBinaryContainer::ROR()
{
    if (capacity > 1)
    {
        metaBit* temp = container.chainHead;
        container.chainHead = container.chainHead->next;
        container.chainHead->father = nullptr;

        container.chainRear->next = temp;
        container.chainRear = container.chainRear->next;
        container.chainRear->next = nullptr;
    }
    else
        throw QString("error: moving one bit");
}

void MetaBinaryContainer::LSL()
{
    ROL();
    container.chainHead->bit = false;
}

void MetaBinaryContainer::LSR()
{
    ROR();
    container.chainRear->bit = false;
}
