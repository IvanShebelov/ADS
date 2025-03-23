#ifndef TUNORDEREDTABLE_H
#define TUNORDEREDTABLE_H

#include "ITable.h"
#include "TPair.h"
#include <vector>

template <typename TKey, typename TVal>
class TUnorderedTable : public ITable<TKey, TVal> {
private:
    std::vector<TPair<TKey, TVal>> _data;  // Массив для хранения данных

public:
    void insert(const TKey& key, const TVal& value) override;
    void remove(const TKey& key) override;
    TVal* find(const TKey& key) override;
    size_t size() const override;
};

#endif // TUNORDEREDTABLE_H