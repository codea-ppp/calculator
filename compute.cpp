#include "compute.h"
#include "checkstring.h"

Compute::Compute(QWidget *parent) : QWidget(parent)
{
    container = nullptr;

    status = Binary;

    capacity = 0;

    type = -1;

    nextNeg = false;
    nextNode = false;

    isNew = true;
}

void Compute::containerProgramGetter(QString* _container, int _capacity, int _type)
{
    package.clear();
    tempPackage.clear();

    container = _container;
    capacity = _capacity;
    type = _type;

    // add "(" before formal compute
    // ")" is added when send the message
    changeFormatStackProgram.push(92);

    computeProgram();
}

void Compute::containerScienceGetter(QString* _container, int _capacity, int _type)
{
    package.clear();
    tempPackage.clear();

    container = _container;
    capacity = _capacity;
    type = _type;

    // add "(" before formal compute
    // ")" is added when send the message
    changeFormatStackScience.push(92);

    computeScience();
}

void Compute::setBinary()
{
    status = Binary;
}

void Compute::setOctal()
{
    status = Octal;
}

void Compute::setHexadecimal()
{
    status = Hexadecimal;
}
