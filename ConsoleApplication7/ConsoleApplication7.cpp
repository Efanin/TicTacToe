// ConsoleApplication7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

vector<string> field =
{ "0","0", "0", "0", "0", "0", "0", "0", "0"};

void print()
{
    for (int i = 0; i < field.size(); i++)
    {
        cout << field[i];
        if (i % 3 == 2)
            cout << endl;
    }
}

class Player
{
public:
    string name;
    int score=1;
    Player(string name)
    {
        this->name = name;
    }
};
int main()
{
    vector<Player> players =
    {Player("A"),Player("B"), Player("C"), Player("D"), Player("E"),Player("F"),Player("X") };
    vector<int> combo = { 30,238,506,627,935,1001,1495,7429 };
    vector<int> simple = { 2,3,5,7,11,13,17,19,23 };
    int steps = 0;
    int step = 0;
    while (true)
    {
        
        print();
        int x;
        cin >> x;
        x--;
        field[x] = players[step].name;
        for (int i = 0; i < players.size(); i++)
        {
            if (players[i].score % simple[x] == 0)
                players[i].score /= simple[x];
        }
        players[step].score *= simple[x];
        for (int i = 0; i < combo.size(); i++)
        {
            if (players[step].score % combo[i] == 0)
            {
                system("cls");
                print();
                cout << players[step].name << " WIN";
                return 0;
            }
        }
        steps++;
        step = steps % players.size();
        system("cls");
    }
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
