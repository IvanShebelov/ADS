#ifndef TORDEREDTABLE_H
#define TORDEREDTABLE_H

#include "ITable.h"
#include "TPair.h"
#include <vector>
#include <algorithm>

template <typename TKey, typename TVal>
class TOrderedTable : public ITable<TKey, TVal> {
private:
    std::vector<TPair<TKey, TVal>> _data;  // Массив для хранения данных

    // Бинарный поиск
    int binarySearch(const TKey& key) const;

public:
    void insert(const TKey& key, const TVal& value) override;
    void remove(const TKey& key) override;
    TVal* find(const TKey& key) override;
    size_t size() const override;
};

#endif // TORDEREDTABLE_H