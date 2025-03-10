// Copyright 2025 Ivan Shebelov

#include "unsort_table.h"
#include <stdexcept>
#include "../lib_iTable/unsort_table.h"

// Вставка элемента
template <typename TKey, typename TVal>
void TUnsortedTable<TKey, TVal>::insert(const TKey& key, const TVal& value) {
    // Проверяем, существует ли уже такой ключ
    auto* existingPair = _data.find(std::make_pair(key, TVal()));
    if (existingPair) {
        // Если ключ уже существует, обновляем значение
        existingPair->second = value;
    }
    else {
        // Если ключа нет, добавляем новую пару
        _data.push_back(std::make_pair(key, value));
    }
}

// Удаление элемента
template <typename TKey, typename TVal>
void TUnsortedTable<TKey, TVal>::remove(const TKey& key) {
    _data.remove(std::make_pair(key, TVal()));
}

// Поиск элемента
template <typename TKey, typename TVal>
TVal* TUnsortedTable<TKey, TVal>::find(const TKey& key) {
    auto* pair = _data.find(std::make_pair(key, TVal()));
    return pair ? &(pair->second) : nullptr;
}

// Получение размера таблицы
template <typename TKey, typename TVal>
size_t TUnsortedTable<TKey, TVal>::size() const {
    return _data.size();
}