// Copyright 2025 Ivan Shebelov

#include "unsort_table.h"
#include <stdexcept>
#include "../lib_easy_example/easy_example.h"

// Вставка элемента в таблицу
template <typename TKey, typename TVal>
void TUnsortedTable<TKey, TVal>::insert(const TKey& key, const TVal& value) {
    // Создаем пару ключ-значение
    TPair<TKey, TVal> pair(key, value);

    // Проверяем, существует ли уже такой ключ
    TPair<TKey, TVal>* existingPair = _data.find(pair);
    if (existingPair) {
        // Если ключ уже существует, обновляем значение
        existingPair->value = value;
    }
    else {
        // Если ключа нет, добавляем новую пару в список
        _data.push_back(pair);
    }
}

// Удаление элемента из таблицы
template <typename TKey, typename TVal>
void TUnsortedTable<TKey, TVal>::remove(const TKey& key) {
    // Создаем временную пару для поиска
    TPair<TKey, TVal> pair(key, TVal());

    // Удаляем пару из списка
    _data.remove(pair);
}

// Поиск элемента по ключу
template <typename TKey, typename TVal>
TVal* TUnsortedTable<TKey, TVal>::find(const TKey& key) {
    // Создаем временную пару для поиска
    TPair<TKey, TVal> pair(key, TVal());

    // Ищем пару в списке
    TPair<TKey, TVal>* foundPair = _data.find(pair);
    if (foundPair) {
        // Если пара найдена, возвращаем указатель на значение
        return &(foundPair->value);
    }
    else {
        // Если пара не найдена, возвращаем nullptr
        return nullptr;
    }
}

// Получение размера таблицы
template <typename TKey, typename TVal>
size_t TUnsortedTable<TKey, TVal>::size() const {
    return _data.getSize();
}