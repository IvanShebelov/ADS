// Copyright 2025 Ivan Shebelov

#ifndef LIB_ITable
#define LIB_ITable

#include "TList.h"
#include "ITable.h"
#include "TPair.h"

template <typename TKey, typename TVal>
class TUnsortedTable : public ITable<TKey, TVal> {
private:
    TList<TPair<TKey, TVal>> _data;  // Список для хранения пар ключ-значение

public:
    // Вставка элемента в таблицу
    void insert(const TKey& key, const TVal& value) override;

    // Удаление элемента из таблицы
    void remove(const TKey& key) override;

    // Поиск элемента по ключу
    TVal* find(const TKey& key) override;

    // Получение размера таблицы
    size_t size() const override;
};

#endif 