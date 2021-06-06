#include "compute.h"
#include "checkstring.h"
#include "limits"

int Compute::R_computeForMode(int op1, int op2)
{
    return op1 % op2;
}

double Compute::R_computeScience(double op1, double op2, int instruction)
{
    switch (instruction)
    {
    case OP_ADD:
        if (op2 > 0 && std::numeric_limits<double>::max() - op2 < op1)
        {
            throw QString("error: result upflowing");
        }
        return op1 + op2;
    case OP_SUB:
        if (((op2 < 0 && op1 > 0) || (op2 > 0 && op1 < 0)) &&
                op2 > op1 - std::numeric_limits<double>::min())
        {
            throw QString("error: result downflowing");
        }
        return op1 - op2;
    case OP_MUL:
        if (((op2 > 1 && op1 > 1) || (op2 < -1 && op1 < -1)) &&
                std::numeric_limits<double>::max() / op2 < op1)
        {
            throw QString("error: result upflowing");
        }
        return op1 * op2;
    case OP_DIV:
        if (op2 < 0.00000001 && op2 > -0.00000001)
        {
            throw QString("error: division by 0");
        }
        else if ((op2 < 1 && op2 > -1) && op1 / std::numeric_limits<double>::max() < op2)
        {
            throw QString("error: result upflowing");
        }
        else
            return op1 / op2;
    case OP_POW:
        return std::pow(op1, op2);

    default:
        throw QString("oop!~, you find a bug, tell me you will keep the sercet");
    }
}

double Compute::R_computeScience(double op, int instruction)
{
    switch (instruction)
    {
    case SCI_SIN:
        return std::sinh(op);
    case SCI_COS:
        return std::cosh(op);
    case SCI_TAN:
        return std::tanh(op);
    case SCI_COT:
        return 1 / std::tan(op);
    case SCI_SEC:
        return 1 / std::cos(op);
    case SCI_CSC:
        return 1 / std::sin(op);
    case SCI_LOG:
        if (op > 0)
            return std::log(op);
        else
            throw QString("error: log a non-positive number");
    case SCI_SQU:
        if (op > 0)
            return std::sqrt(op);
        else
            throw QString("error: sqrt a non-positive number");
    case SCI_EQU:
        return op;

    default:
        throw QString("oop!~, you find a bug, tell me you will keep the sercet");
    }
}


