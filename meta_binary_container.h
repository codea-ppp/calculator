#ifndef METABINARYCONTAINER_H
#define METABINARYCONTAINER_H

#include "QString"

#include "pool.h"
#include "bit_node.h"

class MetaBinaryContainer
{
public:
    MetaBinaryContainer();

    MetaBinaryContainer(double n);

    MetaBinaryContainer const operator&&(MetaBinaryContainer& source);
    MetaBinaryContainer const operator||(MetaBinaryContainer& source);
    MetaBinaryContainer const operator^(MetaBinaryContainer& source);
    MetaBinaryContainer const operator!(void);

    void ROR(void);
    void ROL(void);
    void LSR(void);
    void LSL(void);

    QString getBinary(void) const;
    QString getOctal(void) const;
    QString getHexadecimal(void) const;

    double getDecimal(void) const;

    // these functions set the container
    void setBitRear(Bit bit, bool isNode);
    void setContainer(double n);
    void setContainer(int n);

private:
    void formatLength(MetaBinaryContainer& source);

    // they are handled capacity
    // fill the black with false
    // n means expand to n bits
    bool extandInteger(int n);
    bool extandNode(int n);

    bool isNegative;
    bitNode container;

    int capacity;

};

#endif // METABINARYCONTAINER_H
