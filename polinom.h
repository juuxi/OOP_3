#ifndef POLINOM_H
#define POLINOM_H

#include "number.h"

enum EPrintMode
{
    EPrintModeClassic,
    EPrintModeCanonic,
};

class TPolinom
{
    number* roots;
    number* coefficients;
    int N;
public:
    TPolinom();
    TPolinom(number, number*, int);
    friend ostream& operator<< (ostream&, TPolinom);
private:
    void count_coefficients(number);
};

#endif // POLINOM_H
