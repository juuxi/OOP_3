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
    EPrintMode printMode;
    number* roots;
    number* coefficients;
    int N;
public:
    TPolinom();
    TPolinom(number, number*, int);
    friend ostream& operator<< (ostream&, TPolinom);
    void set_print_mode (EPrintMode);
    number count_value (number);
    void change_an (number);
    void change_root (number, size_t);
private:
    void count_coefficients(number);
};

#endif // POLINOM_H
