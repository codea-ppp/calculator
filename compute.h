#ifndef COMPUTE_H
#define COMPUTE_H

#include <cmath>
#include <QStack>
#include <QWidget>
#include <QString>
#include <QTextEdit>

#include "commands.h"
#include "checkstring.h"
#include "myarray.h"
#include "meta_binary_container.h"

class Compute : public QWidget
{
    Q_OBJECT
public:
    explicit Compute(QWidget *parent = nullptr);

signals:
    // flesh text signal
    // the bool value is true means the program text browser
    void fleshTextSender(QString, bool);

    void resultScienceSender(QString* result, int capacity);

    void resultProgramSender(QString* result, int capacity);

public:
    // actually it just change the format
    void computeScience(void);

    void computeProgram(void);

public slots:
    void containerScienceGetter(QString* _container, int capacity, int type);

    void containerProgramGetter(QString* _container, int capacity, int type);

    void setBinary(void);
    void setOctal(void);
    void setHexadecimal(void);

private:
    double R_computeScience(double op1, double op2, int instruction);

    double R_computeScience(double op, int instruction);


    double R_computeProgram(MetaBinaryContainer& op1, MetaBinaryContainer& op2, int instruction);

    // actully this function used both in science and program
    int R_computeForMode(int op1, int op2);


    // it will return the capacity of the tempPackage
    int makeTheSciencePackageToMessageGetter(bool isSuccess);

    int makeTheProgramPackageToMessageGetter(bool isSuccess);

    QStack<double> storeOperandsStackScience;
    QStack<int> changeFormatStackScience;


    QStack<MetaBinaryContainer> storeOperandsStackProgram;
    QStack<int> changeFormatStackProgram;

    enum Decimal { Binary, Octal, Hexadecimal };
    Decimal status;

    // attention
    // the pointer below must not be new and delete
    // it is used to get the pointer from other widgets
    // and the memory mannagement belong to them
    QString* container;

    MyArray package;
    MyArray tempPackage;
    QString resultString;

    int capacity;
    int type;

    bool nextNeg;
    bool nextNode;

    bool isNew;

};

#define     OP_OR       -41
#define     OP_XOR      -42

#define     OP_AND      -21

#define     OP_ADD      1
#define     OP_SUB      2

#define     OP_MUL      21
#define     OP_DIV      22
#define     OP_MOD      23

#define     OP_NOT      41

#define     OP_POW      42

#define     BRACKET_LEFT    92
#define     BRACKET_RIGHT   93

#endif // COMPUTE_H
