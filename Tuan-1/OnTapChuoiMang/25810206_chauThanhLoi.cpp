#include <iostream>
using namespace std;
#include <cmath>
struct PhanSo
{
    int tu;
    int mau;
};
void NhapPhanSo(PhanSo &ps);
void XuatPhanSo(PhanSo ps);
int ucln(int a, int b);
PhanSo RutGonPhanSo(PhanSo ps);
PhanSo Tong(PhanSo a, PhanSo b);
PhanSo Hieu(PhanSo a, PhanSo b);
PhanSo Tich(PhanSo a, PhanSo b);
PhanSo Thuong(PhanSo a, PhanSo b);
int soSanh(PhanSo a, PhanSo b);
bool laAm(PhanSo ps);
// 2
void NhapMang(PhanSo a[], int &n);
void XuatMang(PhanSo a[], int n);
void LietKeAm(PhanSo a[], int n);
PhanSo TongMang(PhanSo a[], int n);
int DemAm(PhanSo a[], int n);
PhanSo TimMax(PhanSo a[], int n);
bool CoTonTaiAm(PhanSo a[], int n);
bool TatCaDeuAm(PhanSo a[], int n);

int main()
{
    int choice;
    cout << "=== MENU ===\n";
    cout << "1. Phep toan hai phan so\n";
    cout << "2. Thao tac mang phan so\n";
    cout << "Chon: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        PhanSo ps1, ps2;
        NhapPhanSo(ps1);
        NhapPhanSo(ps2);
        cout << "Tong: ";
        XuatPhanSo(Tong(ps1, ps2));
        cout << endl;
        cout << "Hieu: ";
        XuatPhanSo(Hieu(ps1, ps2));
        cout << endl;
        cout << "Tich: ";
        XuatPhanSo(Tich(ps1, ps2));
        cout << endl;
        cout << "Thuong: ";
        XuatPhanSo(Thuong(ps1, ps2));
        cout << endl;
        break;
    case 2:
        PhanSo mang[100];
        int n;
        NhapMang(mang, n);
        cout << "Mang phan so: ";
        XuatMang(mang, n);
        LietKeAm(mang, n);
        cout << "Tong mang: ";
        XuatPhanSo(TongMang(mang, n));
        cout << endl;
        cout << "So luong phan so am: " << DemAm(mang, n) << endl;
        cout << "Phan so lon nhat: ";
        XuatPhanSo(TimMax(mang, n));
        cout << endl;
        cout << "Co ton tai so am: " << (CoTonTaiAm(mang, n) ? "Co" : "Khong") << endl;
        cout << "Tat ca deu am: " << (TatCaDeuAm(mang, n) ? "Dung" : "Sai") << endl;
        break;
    default:
        cout << "Lua chon khong hop le!\n";
        break;
    }
    return 0;
}

void NhapPhanSo(PhanSo &ps)
{
    cout << "Nhap tu so:";
    cin >> ps.tu;
    do
    {
        cout << "Nhap mau so khac 0: ";
        cin >> ps.mau;
    } while (ps.mau == 0);
}
void XuatPhanSo(PhanSo ps)
{
    if (ps.mau == 1)
    {
        cout << ps.tu;
    }
    else
    {
        cout << ps.tu << "/" << ps.mau;
    }
}
int ucln(int a, int b)
{
    if (a < 0)
        a = -a; // dùng thay vì abs()
    if (b < 0)
        b = -b;
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    while (b != 0)
    {
        int t = b;
        b = a % b;
        if (b < 0)
            b = -b; 
        a = t;
    }
    return a;
}

PhanSo RutGonPhanSo(PhanSo ps)
{
    if (ps.tu == 0)
    {
        ps.mau = 1;
        return ps;
    }
    int uc = ucln(ps.tu, ps.mau);
    ps.tu /= uc;
    ps.mau /= uc;
    if (ps.mau < 0)
    {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
    return ps;
}

PhanSo Tong(PhanSo a, PhanSo b)
{
    PhanSo tong;
    tong.tu = a.tu * b.mau + b.tu * a.mau;
    tong.mau = a.mau * b.mau;
    return RutGonPhanSo(tong);
}
PhanSo Hieu(PhanSo a, PhanSo b)
{
    PhanSo hieu;
    hieu.tu = a.tu * b.mau - b.tu * a.mau;
    hieu.mau = a.mau * b.mau;
    return RutGonPhanSo(hieu);
}
PhanSo Tich(PhanSo a, PhanSo b)
{
    PhanSo tich;
    tich.tu = a.tu * b.tu;
    tich.mau = a.mau * b.mau;
    return RutGonPhanSo(tich);
}
PhanSo Thuong(PhanSo a, PhanSo b)
{
    PhanSo thuong;
    thuong.tu = a.tu * b.mau;
    thuong.mau = a.mau * b.tu;
    return RutGonPhanSo(thuong);
}
int soSanh(PhanSo a, PhanSo b)
{
    int hs = a.tu * b.mau - b.tu * a.mau;
    if (hs < 0)
        return -1;
    if (hs > 0)
        return 1;
    return 0;
}
bool laAm(PhanSo ps)
{
    return ps.tu * ps.mau < 0;
}

// 2
void NhapMang(PhanSo a[], int &n)
{
    cout << "Nhap so luong phan tu mang: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Phan phan tu mang thu " << i + 1 << ":\n";
        NhapPhanSo(a[i]);
    }
}

void XuatMang(PhanSo a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        XuatPhanSo(a[i]);
        cout << "  ";
    }
    cout << endl;
}
void LietKeAm(PhanSo a[], int n)
{
    cout << "Cac phan so am: ";
    bool co = false;
    for (int i = 0; i < n; i++)
        if (laAm(a[i]))
        {
            XuatPhanSo(a[i]);
            cout << "  ";
            co = true;
        }
    if (!co)
        cout << "Khong co";
    cout << endl;
}
PhanSo TongMang(PhanSo a[], int n)
{
    PhanSo tong = {0, 1};
    for (int i = 0; i < n; i++)
        tong = Tong(tong, a[i]);
    return tong;
}

int DemAm(PhanSo a[], int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (laAm(a[i]))
            dem++;
    return dem;
}
PhanSo TimMax(PhanSo a[], int n)
{
    PhanSo max = a[0];
    for (int i = 1; i < n; i++)
        if (soSanh(a[i], max) > 0)
            max = a[i];
    return max;
}
bool CoTonTaiAm(PhanSo a[], int n)
{
    for (int i = 0; i < n; i++)
        if (laAm(a[i]))
            return true;
    return false;
}
bool TatCaDeuAm(PhanSo a[], int n)
{
    for (int i = 0; i < n; i++)
        if (!laAm(a[i]))
            return false;
    return true;
}