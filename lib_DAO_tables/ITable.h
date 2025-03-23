#ifndef ITABLE_H
#define ITABLE_H

template <typename TKey, typename TVal>
class ITable {
public:
    virtual ~ITable() = default;
    virtual void insert(const TKey& key, const TVal& value) = 0;
    virtual void remove(const TKey& key) = 0;
    virtual TVal* find(const TKey& key) = 0;
    virtual size_t size() const = 0;
};

#endif // ITABLE_H