#ifndef BIT_NODE_H
#define BIT_NODE_H

#define     Bit     bool

class metaBit
{
public:
    metaBit()
    {
        index = -1;
        bit = false;
        next = nullptr;
        father = nullptr;
    }
    ~metaBit() {}

    metaBit(metaBit const& source)
    {
        next = source.next;
        father = source.father;

        index = source.index;
        bit = source.bit;
    }

    metaBit const& operator=(metaBit const& source)
    {
        if (this == &source)
            return *this;
        else
        {
            next = source.next;
            father = source.father;

            index = source.index;
            bit = source.bit;
        }

        return *this;
    }

    // the index is set for return to the pool
    int index;

    Bit bit;
    // the next must not be deleted
    // it belong to pool
    metaBit* next;
    metaBit* father;
};

class bitNode
{
public:
    bitNode()
    {
        nodeIndex = -1;
        chainHead = chainRear = nullptr;
    }

    bitNode(bitNode const& source);
    bitNode const& operator=(bitNode const& source);
    ~bitNode();

    metaBit* chainHead;
    metaBit* chainRear;

    // nodeIndex is to tell whether there is a "." as
    // the MetaBinaryContainer is just one number
    // -1 means no node
    int nodeIndex;
};


#endif // BIT_NODE_H
