#ifndef TPAIR_H
#define TPAIR_H

template <typename TKey, typename TVal>
class TPair {
public:
    TKey key;
    TVal value;

    TPair() = default;
    TPair(const TKey& k, const TVal& v) : key(k), value(v) {}
};

#endif // TPAIR_H