#include "pool.h"

#include "stdlib.h"
#include "new"
#include "global.h"

// inialization
int Pool::times = 1;

metaBit* Pool::elements = new(std::nothrow) metaBit[POOL_BASIC_CAPACITY * times]();
bool* Pool::busy = new(std::nothrow) bool[POOL_BASIC_CAPACITY]();

int Pool::currentCapacity = 0;
int Pool::maxCapacity = POOL_BASIC_CAPACITY;


metaBit* Pool::getRelax()
{
    if (currentCapacity < maxCapacity)
    {
        for (int i = 0; i < maxCapacity; i++)
        {
            if (!busy[i])
            {
                currentCapacity++;
                busy[i] = true;

                (elements + i)->index = i;
                (elements + i)->bit = false;
                (elements + i)->next = nullptr;
                (elements + i)->father = nullptr;

                return elements + i;
            }
        }
    }

    while (extand())
    {
        for (int i = currentCapacity; i < maxCapacity; i++)
        {
            if (!busy[i])
            {
                currentCapacity++;
                busy[i] = true;

                (elements + i)->index = i;

                return elements + i;
            }
        }
    }

    return nullptr;
}

void Pool::sendBackToPool(long int index)
{
    if (index >= 0 && index < maxCapacity)
    {
        busy[index] = false;
        currentCapacity--;
    }
}

bool Pool::isOccupted(long int index)
{
    return busy[index];
}

bool Pool::extand()
{
    times *= 2;

    metaBit* temp_elements = new(std::nothrow) metaBit[POOL_BASIC_CAPACITY * times]();
    bool* temp_busy = new(std::nothrow) bool[POOL_BASIC_CAPACITY * times]();
    if (nullptr == temp_busy || nullptr == temp_elements)
    {
        return false;
    }

    maxCapacity = POOL_BASIC_CAPACITY * times;

    for (int i = 0; i < currentCapacity; i++)
    {
        temp_elements[i] = elements[i];
        temp_busy[i] = busy[i];
    }

    delete [] elements;
    delete [] busy;

    elements = temp_elements;
    busy = temp_busy;

    return true;
}
