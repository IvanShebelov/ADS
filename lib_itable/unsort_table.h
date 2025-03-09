#ifndef TUNSORTEDTABLE_H
#define TUNSORTEDTABLE_H

#include "ITable.h"
#include "TList.h"
#include "TPair.h"

template <typename TKey, typename TVal>
class TUnsortedTable : public ITable<TKey, TVal> {
private:
    TList<TPair<TKey, TVal>> _data;

public:
    void insert(const TKey& key, const TVal& value) override;
    void remove(const TKey& key) override;
    TVal* find(const TKey& key) override;
    size_t size() const override;
};

template <typename TKey, typename TVal>
void TUnsortedTable<TKey, TVal>::insert(const TKey& key, const TVal& value) {
    TPair<TKey, TVal> pair(key, value);
    _data.push_back(pair);
}

template <typename TKey, typename TVal>
void TUnsortedTable<TKey, TVal>::remove(const TKey& key) {
    TPair<TKey, TVal> pair(key, TVal());
    _data.remove(pair);
}

template <typename TKey, typename TVal>
TVal* TUnsortedTable<TKey, TVal>::find(const TKey& key) {
    TPair<TKey, TVal> pair(key, TVal());
    TPair<TKey, TVal>* found = _data.find(pair);
    return found ? &(found->value) : nullptr;
}

template <typename TKey, typename TVal>
size_t TUnsortedTable<TKey, TVal>::size() const {
    return _data.getSize();
}

#endif // TUNSORTEDTABLE_H