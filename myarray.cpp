#include "myarray.h"
#include <new>
#include <limits>
#include <stdlib.h>

QString& MyArray::top()
{
    return container[capacity - 1];
}

bool MyArray::extand()
{    
    if (std::numeric_limits<int>::max() / INI_ARRAY_LEN < power)
        return false;
    QString* temp = new(std::nothrow) QString[power * INI_ARRAY_LEN]();
    if (nullptr == temp)
        return false;

    if (std::numeric_limits<int>::max() / 2 > power)
        power *= 2;
    else
        return false;

    for (int i = 0; i < capacity; i++)
    {
        temp[i] = container[i];
    }

    delete [] container;
    container = temp;

    return true;
}

MyArray::MyArray()
{
    capacity = 0;
    power = 1;

    container = new(std::nothrow) QString[power * INI_ARRAY_LEN]();
    if (nullptr == container)
        abort();

    power *= 2;
}

MyArray::~MyArray()
{
    delete [] container;
}

MyArray::MyArray(MyArray const& src)
{
    capacity = src.capacity;
    power = src.power;

    container = new(std::nothrow) QString[power * INI_ARRAY_LEN]();
    if (nullptr == container)
        abort();

    for (int i = 0; i < src.capacity; i++)
    {
        container[i] = src.container[i];
    }
}

MyArray const& MyArray::operator=(MyArray const& src)
{
    if (this == &src)
        return *this;

    while (src.power > power)
        if (!this->extand())
            abort();

    power = src.power;
    capacity = src.capacity;

    delete [] container;

    container = new(std::nothrow) QString[power * INI_ARRAY_LEN]();
    if (nullptr == container)
        abort();

    for (int i = 0; i < src.capacity; i++)
    {
        container[i] = src.container[i];
    }

    return src;
}

QString& MyArray::operator[](int n)
{
    return container[n];
}

bool MyArray::addRear(QString _element)
{
    if ((capacity * 2) / INI_ARRAY_LEN == power)
        if (extand())
            container[capacity++] = _element;
        else
            return false;
    else
        container[capacity++] = _element;

    return false;
}

void MyArray::deleteRear()
{
    if (0 == capacity)
        return;

    capacity--;

    return;
}

void MyArray::clear()
{
    power = 1;
    capacity = 0;

    delete [] container;

    container = new(std::nothrow) QString[power * INI_ARRAY_LEN]();
    if (nullptr == container)
        abort();

    return;
}

int MyArray::getCapacity()
{
    return capacity;
}

QString* MyArray::getContainer()
{
    return container;
}
