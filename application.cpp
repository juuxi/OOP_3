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
    cout << "1 - Ввод значений массива" << endl;
    cout << "2 - Расчет среднего и СКО элекментов массива" << endl;
    cout << "3 - Сортировка по возрастсанию/убыванию" << endl;
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
    number std_roots[] = {3, -2, 1};
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
                cout<<"среднее значение - "<<arr.count_average()<<endl;
                cout<<"СКО - "<<arr.count_average_square()<<endl;
                break;
            }
           case 3:
            {
                cout << "1 - По возрастанию" << endl;
                cout << "2 - По убыванию" << endl;
                int reverse;
                cin>>reverse;
                if (reverse == 1)
                    arr.sort(false);
                else
                    arr.sort(true);
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
