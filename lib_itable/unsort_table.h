#ifndef TUNSORTEDTABLE_H
#define TUNSORTEDTABLE_H

#include "ITable.h"
#include "TList.h"
#include <utility> // Для std::pair

template <typename TKey, typename TVal>
class TUnsortedTable : public ITable<TKey, TVal> {
private:
    TList<std::pair<TKey, TVal>> _data; // Список для хранения пар ключ-значение

public:
    void insert(const TKey& key, const TVal& value) override;
    void remove(const TKey& key) override;
    TVal* find(const TKey& key) override;
    size_t size() const override;
};

#endif // TUNSORTEDTABLE_H