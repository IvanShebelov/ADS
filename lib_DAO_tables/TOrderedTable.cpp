#include "TOrderedTable.h"

// Бинарный поиск
template <typename TKey, typename TVal>
int TOrderedTable<TKey, TVal>::binarySearch(const TKey& key) const {
    int left = 0;
    int right = _data.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (_data[mid].key == key) {
            return mid;  // Элемент найден
        }
        if (_data[mid].key < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;  // Элемент не найден
}

// Упорядоченная вставка
template <typename TKey, typename TVal>
void TOrderedTable<TKey, TVal>::insert(const TKey& key, const TVal& value) {
    int index = binarySearch(key);
    if (index != -1) {
        // Если ключ уже существует, обновляем значение
        _data[index].value = value;
    }
    else {
        // Если ключа нет, добавляем новую пару и сортируем массив
        _data.push_back(TPair<TKey, TVal>(key, value));
        std::sort(_data.begin(), _data.end());
    }
}

// Удаление элемента
template <typename TKey, typename TVal>
void TOrderedTable<TKey, TVal>::remove(const TKey& key) {
    int index = binarySearch(key);
    if (index != -1) {
        _data.erase(_data.begin() + index);
    }
}

// Поиск элемента
template <typename TKey, typename TVal>
TVal* TOrderedTable<TKey, TVal>::find(const TKey& key) {
    int index = binarySearch(key);
    if (index != -1) {
        return &_data[index].value;
    }
    return nullptr;  // Элемент не найден
}

// Получение размера таблицы
template <typename TKey, typename TVal>
size_t TOrderedTable<TKey, TVal>::size() const {
    return _data.size();
}