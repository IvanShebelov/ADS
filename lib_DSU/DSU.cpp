// Copyright 2025 Ivan Shebelov

#include <stdexcept>        // Для работы с исключениями
#include "../lib_DSU/DSU.h" // Заголовочный файл класса DSU

// Конструктор DSU. Создает структуру для заданного количества элементов
DSU::DSU(int size) :
    _size(size),             // Инициализация размера
    _parent(new int[size]),  // Выделение памяти под массив родителей
    _rank(new int[size])     // Выделение памяти под ранги
{
    for (int i = 0; i < size; ++i) {
        _parent[i] = i;     // Каждый элемент изначально - корень своего множества
        _rank[i] = 1;       // Начальный ранг каждого множества = 1
    }
}

// Деструктор. Освобождает выделенную память
DSU::~DSU() {
    delete[] _parent;  // Удаление массива родителей
    delete[] _rank;    // Удаление массива рангов
}

// Создание нового множества для элемента (сброс состояния)
void DSU::make_set(int elem) {
    if (elem < 0 || elem >= _size) {
        throw std::logic_error("Input Error: Element out of bounds\n"); // Проверка валидности элемента
    }
    _parent[elem] = elem; // Элемент становится корнем
    _rank[elem] = 1;      // Сброс ранга до начального
}

// Поиск корневого элемента с оптимизацией пути
int DSU::find(int elem) {
    if (elem < 0 || elem >= _size) {
        throw std::logic_error("Input Error: Element out of bounds\n"); // Проверка валидности элемента
    }

    // Рекурсивное обновление родителя до корня (path compression)
    if (_parent[elem] != elem) {
        _parent[elem] = find(_parent[elem]); // Переподчинение напрямую корню
    }
    return _parent[elem]; // Возврат корневого элемента
}

// Объединение двух множеств с оптимизацией по рангу
void DSU::union_sets(int first, int second) {
    int first_root = find(first);   // Находим корень первого множества
    int second_root = find(second); // Находим корень второго множества

    if (first_root == second_root) return; // Если уже в одном множестве - выход

    // Union by rank: меньшее дерево подчиняется большему
    if (_rank[first_root] < _rank[second_root]) {
        _parent[first_root] = second_root; // Переподчиняем первое дерево второму
    }
    else if (_rank[first_root] > _rank[second_root]) {
        _parent[second_root] = first_root; // Переподчиняем второе дерево первому
    }
    else {
        // При равных рангах выбираем произвольный корень и увеличиваем ранг
        _parent[second_root] = first_root;
        _rank[first_root]++; // Увеличиваем ранг только при совпадении рангов
    }
}

// Сброс структуры в начальное состояние
void DSU::clear() {
    for (int i = 0; i < _size; ++i) {
        _parent[i] = i;  // Каждый элемент снова становится корнем
        _rank[i] = 1;    // Сброс рангов до начальных значений
    }
}