// 31-08-2022-Spisok_Stek_queue.cpp : Этот файл содержит функцию "main". 
// Здесь начинается и заканчивается выполнение программы.
//методичка C___urok_07_2020_1597154734
// Д/З создать базовый класс список. Реализовать на базе списка
// стэк и очередь с виртуальными функциями вставки и вытаскивания.

#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
class Stack
{
private:
    //Нижняя и верхняя границы стека
    enum { EMPTY = -1, FULL = 20 };
    //Массив для хранения данных
    char st[FULL + 1];
    //Указатель на вершину стека
    int top{0};
public:
    //Конструктор
    Stack();
    //Добавление элемента
    void Push(char c);
    //Извлечение элемента
    char Pop();
    //Очистка стека
    void Clear();
    //Проверка существования элементов в стеке
    bool IsEmpty();
    //Проверка на переполнение стека
    bool IsFull();
    //Количество элементов в стеке
    int GetCount();
    // добавим элемент в стек
    void Push1(char h);
};
Stack::Stack()
{
    //Изначально стек пуст
    top = EMPTY;
}
void Stack::Clear()
{
    //Эффективная "очистка" стека
    //(данные в массиве все еще существуют,
    //но функции класса, ориентированные
    //на работу с вершиной стека,
    //будут их игнорировать)
    top = EMPTY;
}
    bool Stack::IsEmpty()
    {
        //Пуст?
        return top == EMPTY;
    }
    bool Stack::IsFull()
    {
        //Полон?
        return top == FULL;
    }
    int Stack::GetCount()
    {
        //Количество присутствующих в стеке элементов
        return top + 1;
    }
    void Stack::Push1(char h)
    {
        //Если в стеке нет места, то увеличиваем стек на 1
        //на вершину стека и вставляем новый элемент
        if (IsFull())
            ++st[++top] = h;
    }
    void Stack::Push(char c)
    {
        //Если в стеке есть место, то увеличиваем указатель
        //на вершину стека и вставляем новый элемент
        if (!IsFull())
            st[++top] = c;
    }
    char Stack::Pop()
    {
        //Если в стеке есть элементы, то возвращаем
        //верхний и уменьшаем указатель на вершину стека
        if (!IsEmpty())
            return st[top--];
        else //Если в стеке элементов нет
            return 0;
    }
    int main()
    {
        char c{ NULL };
        srand(time(0));
        Stack ST;
       // пока стек не заполнится
        while (!ST.IsFull()) {
            c = rand() % 4 + 2;
            ST.Push(c);
        }
        //пока в стеке что- то есть выводим это
        int znach = ST.GetCount();
        while (znach > 0) {
            cout << c << " ";
            
            znach--;
        }
        cout << ST.GetCount() << endl;
        cout << "\n\n";
        if (ST.IsFull())
        {
            char c1 { 'g' } ;
            ST.Push1(c1);
        }
        cout << ST.GetCount() ;
   /*    int cou = ST.GetCount();
       while (cou>0)
       {
           cout <<"stek" << cou << endl;
           --cou;
       }*/
        //пока стек не освободится
        while (c = ST.Pop()) {
            cout << c << " ";
        }
        
        cout << ST.GetCount() << endl;
    }
