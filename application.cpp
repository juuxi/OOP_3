#include "application.h"
#include "array.h"
#include "polinom.h"
#include <iostream>

using namespace std;

TApplication::TApplication()
{

}

int TApplication::menu()
{
    int ch;
    cout << "1 - Ввод полинома" << endl;
    cout << "2 - Изменить коэффициент a_n или один из корней" << endl;
    cout << "3 - Вычисление полинома в данной точке" << endl;
    cout << "4 - Изменение размера массива" << endl;
    cout << "5 - Изменение значения выбранного элемента массива" << endl;
    cout << "6 - Вывод полинома" << endl;
    cout << "0 - Выход" << endl << "> ";
    cin >> ch;
    return ch;
}

int TApplication::exec()
{
    int ch;
    TArray arr;
    number std_roots[] = {3, 7, 1};
    TPolinom pol(3, std_roots, 3);
    while (true)
    {
        ch = menu();
        switch(ch)
        {
            case 0:
            {
                return 0;
            }
            case 1:
            {
                if (arr.get_size() != 0)
                {
                    cout << "Введите элементы" << endl;
                    cin>>arr;
                }
                else
                    cout << "Массив пуст" << endl;
                break;
            }
           case 2:
            {
                int change_ch;
                cout << "1 - Изменение a_n" << endl;
                cout << "2 - Изменение корня" << endl;
                cout << "> ";
                cin >> change_ch;
                if (change_ch == 1)
                {
                    number an;
                    cout << "Введите новое значение" << endl;
                    cout << "> ";
                    cin >> an;
                    pol.change_an(an);
                }
                if (change_ch == 2)
                {
                    number new_root;
                    size_t index;
                    cout << "Введите новое значение" << endl;
                    cout << "> ";
                    cin >> new_root;
                    cout << "Введите позицию (индекс)" << endl;
                    cout << "> ";
                    cin >> index;
                    pol.change_root(new_root, index);
                }
                break;
            }
           case 3:
            {
                number point;
                cout << "Введите значение, для которого Вы хотите вычислить полином" << std::endl;
                cout << "> ";
                cin >> point;
                cout << pol.count_value(point) << endl;
                break;
            }
           case 4:
            {
                cout << "Введите новый размер" << endl << "> ";
                int num;
                cin >> num;
                arr.change_size(num);
                break;
            }
           case 5:
            {
                cout << "Введите индекс" << endl << "> ";
                int index;
                number elem;
                cin >> index;
                cout << "Введите новое значение" << endl << "> ";
                cin >> elem;
                arr.change_element(index, elem);
                break;
            }
           case 6:
            {
                int mode_ch;
                cout << "1 - Канонический способ" << endl;
                cout << "2 - Классический способ" << endl;
                cout << "> ";
                cin >> mode_ch;
                if (mode_ch == 1)
                    pol.set_print_mode(EPrintModeCanonic);
                if (mode_ch == 2)
                    pol.set_print_mode(EPrintModeClassic);
                cout << pol;
                break;
            }
           default:
            {
                break;
            }
        }
    }
}
