#ifndef MYARRAY_H
#define MYARRAY_H

#include "QString"

class MyArray
{
public:
    MyArray();
    ~MyArray();

    MyArray(MyArray const& src);
    MyArray const& operator=(MyArray const& src);

    QString& operator[](int n);

    bool addRear(QString _element);
    void deleteRear(void);

    QString* getContainer(void);

    QString& top(void);

    int getCapacity(void);
    void clear(void);

private:
    bool extand(void);

#define     INI_ARRAY_LEN   16
    QString* container;

    int capacity;
    int power;
};

#endif // MYARRAY_H
