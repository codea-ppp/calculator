#include "meta_binary_container.h"
#include "global.h"

void MetaBinaryContainer::setBitRear(Bit _bit, bool isNode)
{
    if (isNode)
    {
        container.nodeIndex = capacity;
    }
    else
    {
        // whether the chain is empty
        if (container.chainHead == nullptr)
        {
            container.chainHead = container.chainRear = Pool::getInstance()->getRelax();
        }
        else
        {
            metaBit* temp = container.chainRear;

            container.chainRear = Pool::getInstance()->getRelax();
            temp->next = container.chainRear;
            container.chainRear->father = temp;

            container.chainRear->bit = _bit;
        }

        capacity++;
    }
}

void MetaBinaryContainer::setContainer(int n)
{
    if (n < 0)
    {
        isNegative = true;
        n = -n;
    }

    bool ini = false;
    if (container.chainHead == nullptr)
        ini = true;

    // integer part
    for (int i = 0; n > 0; n /= 2)
    {
        i = n % 2;

        metaBit* temp = container.chainRear;

        container.chainRear = Pool::getInstance()->getRelax();
        temp->next = container.chainRear;
        container.chainRear->father = temp;

        if (i)
            container.chainRear->bit = true;

        if (ini)
        {
            container.chainHead = container.chainRear;
            ini = false;
        }

        capacity++;
    }
}

void MetaBinaryContainer::setContainer(double n)
{
    if (n < 0)
    {
        isNegative = true;
        n = -n;
    }

    int _n = int(n);
    int temp_int = _n;

    n -= _n;

    bool ini = false;
    if (container.chainHead == nullptr)
        ini = true;

    // integer part
    for (int i = 0; temp_int > 0; temp_int /= 2)
    {
        i = temp_int % 2;

        metaBit* temp = container.chainRear;

        container.chainRear = Pool::getInstance()->getRelax();
        if (temp)
            temp->next = container.chainRear;
        container.chainRear->father = temp;

        if (i)
            container.chainRear->bit = true;

        if (ini)
        {
            container.chainHead = container.chainRear;
            ini = false;
        }

        capacity++;
    }

    // node part
    for (int i = 0; (n - i) > 0.00000001; )
    {
        i = int(n *= 2);

        metaBit* temp = container.chainHead;

        container.chainHead = Pool::getInstance()->getRelax();
        temp->father = container.chainHead;
        container.chainHead->next = temp;

        if (i)
            container.chainHead->bit = true;

        capacity++;
    }
}

bool MetaBinaryContainer::extandNode(int n)
{
    metaBit* temp;
    for (int i = 0; i < n; i++)
    {
        temp = container.chainHead;

        container.chainHead = Pool::getInstance()->getRelax();
        temp->father = container.chainHead;
        container.chainHead->next = temp;
    }

    capacity += n;

    return true;
}

bool MetaBinaryContainer::extandInteger(int n)
{
    metaBit* temp;
    for (int i = 0; i < n; i++)
    {
        temp = container.chainRear;

        container.chainRear = Pool::getInstance()->getRelax();
        temp->next = container.chainRear;
        container.chainHead->father = temp;
    }

    capacity += n;

    return true;
}
