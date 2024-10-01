#include "polinom.h"

TPolinom::TPolinom()
{
    roots = nullptr;
    coefficients = nullptr;
    N = 0;
}

TPolinom::TPolinom(number _an, number* _roots, int _size)
{
    N = _size;
    roots = new number[N];
    coefficients = new number[N + 1];
    for (int i = 0; i < N; i++)
        roots[i] = _roots[i];
    for (int i = 0; i < N; i++)
        coefficients[i] = 0;
    coefficients[N] = _an;
    count_coefficients(_an);
}

void TPolinom::count_coefficients (number _an)

{
    coefficients[1] = 1;
    coefficients[0] = -roots[0];
    number& a = coefficients[0];
    number& b = coefficients[1];
    number& c = coefficients[2];
    for (int k = 2; k <= N; k++)
    {
        coefficients[k] = coefficients[k-1];
        for (int i = k-1; i > 0; i--)
            coefficients[i] = coefficients[i-1] - coefficients[i] * roots[k-1];
        coefficients[0] = -coefficients[0] * roots[k-1];
    }
    for (int i = 0; i <= N; i++)
          coefficients[i] = coefficients[i] * _an;
}

void TPolinom::set_print_mode (EPrintMode _printMode)
{
    printMode = _printMode;
}

ostream& operator<< (ostream& os, TPolinom pol)
{
    if (pol.printMode == EPrintModeClassic)
    {
        for (int i = pol.N; i > 0; i--)
            os << pol.coefficients[i] << " x^" << i << " ";
        os << pol.coefficients[0] << std::endl;
    }
    return os;
}
