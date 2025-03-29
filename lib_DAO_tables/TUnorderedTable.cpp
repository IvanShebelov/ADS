#include "TUnorderedTable.h"

// Вставка в конец массива
template <typename TKey, typename TVal>
void TUnorderedTable<TKey, TVal>::insert(const TKey& key, const TVal& value) {
    // Проверяем, существует ли уже такой ключ
    for (auto& pair : _data) {
        if (pair.key == key) {
            pair.value = value;  // Обновляем значение
            return;
        }
    }
    // Если ключа нет, добавляем новую пару
    _data.push_back(TPair<TKey, TVal>(key, value));
}

// Удаление элемента
template <typename TKey, typename TVal>
void TUnorderedTable<TKey, TVal>::remove(const TKey& key) {
    auto it = std::remove_if(_data.begin(), _data.end(), [&key](const TPair<TKey, TVal>& pair) {
        return pair.key == key;
        });
    _data.erase(it, _data.end());
}

// Линейный поиск
template <typename TKey, typename TVal>
TVal* TUnorderedTable<TKey, TVal>::find(const TKey& key) {
    for (auto& pair : _data) {
        if (pair.key == key) {
            return &pair.value;
        }
    }
    return nullptr;  // Элемент не найден
}

// Получение размера таблицы
template <typename TKey, typename TVal>
size_t TUnorderedTable<TKey, TVal>::size() const {
    return _data.size();
}