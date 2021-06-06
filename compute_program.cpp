#include "meta_binary_container.h"
#include "compute.h"

#include "limits"

#include "QString"

double Compute::R_computeProgram(MetaBinaryContainer& op1, MetaBinaryContainer& op2, int instruction)
{
    double temp_1 = op2.getDecimal();
    double temp_2 = op1.getDecimal();

    switch (instruction)
    {
    case OP_ADD:
        if (temp_2 > 0 && temp_1 > 0 && std::numeric_limits<double>::max() - temp_2 < temp_1)
            throw QString("error: result upflowing");
        if (temp_2 < 0 && temp_1 < 0 && std::numeric_limits<double>::min() - temp_2 > temp_1)
            throw QString("error: result downflowing");

        return temp_1 + temp_2;

    case OP_SUB:
        if (temp_1 > 0 && temp_2 < 0 && std::numeric_limits<double>::max() - temp_2 < temp_1)
            throw QString("error: result upflowing");
        if (temp_1 < 0 && temp_2 > 0 && std::numeric_limits<double>::min() + temp_2 > temp_1)
            throw QString("error: result downflowing");

        return temp_1 - temp_2;

    case OP_MUL:
        if (temp_2 > 1 && std::numeric_limits<double>::max() / temp_2 < temp_1)
            throw QString("error: result upflowing");
        if (temp_2 < -1 && std::numeric_limits<double>::min() / temp_2 > temp_1)
            throw QString("error: result downflowing");

        return temp_1 * temp_2;

    case OP_DIV:
        if (temp_2 > -1 && temp_2 < 1 && std::numeric_limits<double>::max() * temp_2 < temp_1)
            throw QString("error: result upflowing");

        return temp_1 / temp_2;

    case OP_AND:
        return (op1 && op2).getDecimal();

    case OP_OR:
        return (op1 || op2).getDecimal();

    case OP_XOR:
        return (op1 ^ op2).getDecimal();

    default:
        throw QString("oop!~, you find a bug, tell me you will keep the sercet");
    }
}
