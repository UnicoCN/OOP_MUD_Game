#include<bits/stdc++.h>
#include <Windows.h>
using namespace std;

class Map {

    void Print_ (int num)

};


void Echo_Static() {
    cout << "属性:" << endl;
    cout << "当前所在楼层：" << endl;
    cout << "物品" << endl;
}

void Echo_Map() {
    cout << "---------------------------" << endl;
    cout << "    门        人     楼梯  " << endl;
    cout << "---------------------------" << endl;
}

void Echo_Map2() {
    cout << "---------------------------" << endl;
    cout << "    怪        人     楼梯  " << endl;
    cout << "---------------------------" << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Echo_Map();
    getchar();
    system("cls");
    Echo_Map2();
    // system("pause");
    while (1);
    return 0;
}