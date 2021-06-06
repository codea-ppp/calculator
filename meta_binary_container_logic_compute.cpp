#include "meta_binary_container.h"
#include "global.h"

void MetaBinaryContainer::formatLength(MetaBinaryContainer& source)
{
    if (-1 == this->container.nodeIndex && -1 != source.container.nodeIndex)
    {
        extandNode(source.container.nodeIndex);
        capacity > (source.capacity - source.container.nodeIndex) ?
                    source.extandInteger(capacity - source.capacity + source.container.nodeIndex) :
                    extandInteger(source.capacity - source.container.nodeIndex - capacity);
    }
    else if (-1 != this->container.nodeIndex && -1 == source.container.nodeIndex)
    {
        source.extandNode(container.nodeIndex);
        (capacity - container.nodeIndex) > source.capacity ?
                    source.extandInteger(capacity - container.nodeIndex - source.capacity) :
                    extandInteger(source.capacity - capacity + container.nodeIndex);
    }
    else if (-1 != this->container.nodeIndex && -1 != source.container.nodeIndex)
    {
        capacity > source.capacity ?
                    source.extandInteger(capacity - source.capacity) :
                    extandInteger(source.capacity - capacity);
    }
    else if (-1 == this->container.nodeIndex && -1 == source.container.nodeIndex)
    {
        container.nodeIndex > source.container.nodeIndex ?
                    source.extandNode(container.nodeIndex - source.container.nodeIndex) :
                    extandNode(source.container.nodeIndex - container.nodeIndex);
        (capacity - container.nodeIndex) > (source.capacity - source.container.nodeIndex) ?
                    source.extandInteger(capacity - container.nodeIndex + source.container.nodeIndex - source.capacity) :
                    extandInteger(source.capacity - source.container.nodeIndex + container.nodeIndex - capacity);
    }
}

MetaBinaryContainer const MetaBinaryContainer::operator&&(MetaBinaryContainer& source)
{
    formatLength(source);

    MetaBinaryContainer temp;
    bool ini = true;

    metaBit* temp_this = this->container.chainHead;
    metaBit* temp_source = source.container.chainHead;

    metaBit* temp_temp = temp.container.chainHead;

    for (int i = 0; i < capacity; i++)
    {
        temp_temp = temp.container.chainRear;

        temp.container.chainRear = Pool::getInstance()->getRelax();

        if (!ini)
        {
            temp_temp->next = temp.container.chainRear;
            temp.container.chainRear->father = temp_temp;
        }

        if (ini)
        {
            temp.container.chainHead = temp.container.chainRear;
            ini = false;
        }

        temp.container.chainRear->bit = temp_this->bit && temp_source->bit;

        temp_this = temp_this->next;
        temp_source = temp_source->next;
    }

    return temp;
}

MetaBinaryContainer const MetaBinaryContainer::operator||(MetaBinaryContainer& source)
{
    formatLength(source);

    MetaBinaryContainer temp;
    bool ini = true;

    metaBit* temp_this = this->container.chainHead;
    metaBit* temp_source = source.container.chainHead;

    metaBit* temp_temp = temp.container.chainHead;

    for (int i = 0; i < capacity; i++)
    {
        temp_temp = temp.container.chainRear;

        temp.container.chainRear = Pool::getInstance()->getRelax();

        if (!ini)
        {
            temp_temp->next = temp.container.chainRear;
            temp.container.chainRear->father = temp_temp;
        }

        if (ini)
        {
            temp.container.chainHead = temp.container.chainRear;
            ini = false;
        }

        temp.container.chainRear->bit = temp_this->bit || temp_source->bit;

        temp_this = temp_this->next;
        temp_source = temp_source->next;
    }

    return temp;
}

MetaBinaryContainer const MetaBinaryContainer::operator^(MetaBinaryContainer& source)
{
    formatLength(source);

    MetaBinaryContainer temp;
    bool ini = true;

    metaBit* temp_this = this->container.chainHead;
    metaBit* temp_source = source.container.chainHead;

    metaBit* temp_temp = temp.container.chainHead;

    for (int i = 0; i < capacity; i++)
    {
        temp_temp = temp.container.chainRear;

        temp.container.chainRear = Pool::getInstance()->getRelax();

        if (!ini)
        {
            temp_temp->next = temp.container.chainRear;
            temp.container.chainRear->father = temp_temp;
        }

        if (ini)
        {
            temp.container.chainHead = temp.container.chainRear;
            ini = false;
        }

        temp.container.chainRear->bit = temp_this->bit ^ temp_source->bit;

        temp_this = temp_this->next;
        temp_source = temp_source->next;
    }

    return temp;
}

MetaBinaryContainer const MetaBinaryContainer::operator!()
{
    for (metaBit* i = container.chainHead; i != nullptr; i = i->next)
    {
        i->bit = !i->bit;
    }

    return *this;
}
