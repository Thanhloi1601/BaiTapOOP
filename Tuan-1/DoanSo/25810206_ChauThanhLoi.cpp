#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int duDoan(int luotChoiThu, int SBM);

int main()
{
    srand(time(0));
    int SBM = rand() % 100 + 1;
    int ketQua = 0;

    for (int luot = 1; luot <= 3; luot++)
    {
        ketQua = duDoan(luot, SBM);

        if (ketQua > 0)

        {
            cout << "Chuc mung ban da doan dung va dat duoc "
                 << ketQua << " diem!!" << endl;
            break;
        }
    }

    if (ketQua <= 0)
    {
        cout << "\nGame over!! So bi mat la: " << SBM << endl;
    }

    return 0;
}

int duDoan(int luotChoiThu, int SBM)
{
    int SDD;
    cout << "Luot choi " << luotChoiThu << " - So du doan (1-100): ";
    cin >> SDD;

    if (SBM == SDD)
    {
        if (luotChoiThu == 1)
            return 100;
        if (luotChoiThu == 2)
            return 50;
        return 30;
    }

    if (SDD > SBM)
    {
        cout << "So cua ban lon qua! \n";
    }

    else
    {
        cout << "So cua ban be qua! \n";
    }

    return -1;
}
