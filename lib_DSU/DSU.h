// Copyright 2024 Ivan Shebelov

#ifndef LIB_DSU_DSU_H_
#define LIB_DSU_DSU_H_

class DSU {
	int _size;
	int* _parent;
	int* _rank;
public:
	DSU(int size = 0);
	~DSU();
	void make_set(int elem);
	int find(int elem);
	void join(int first, int second);
	void clear();
};

DSU::DSU(int size) : _size(size), _parent(new int[size]), _rank(new int[size]) {
    for (int i = 0; i < size; ++i) {
        _parent[i] = i;
        _rank[i] = 1;
    }
}

DSU::~DSU() {
    delete[] _parent;
    delete[] _rank;
}

void DSU::make_set(int elem) {
    if (elem < 0 || elem >= _size) {
        throw std::logic_error("Input Error: Element out of bounds\n");
    }
    _parent[elem] = elem;
    _rank[elem] = 1;
}

int DSU::find(int elem) {
    if (elem < 0 || elem >= _size) {
        throw std::logic_error("Input Error: Element out of bounds\n");
    }
    if (_parent[elem] != elem) {
        _parent[elem] = find(_parent[elem]);  // Path compression
    }
    return _parent[elem];
}

void DSU::union_sets(int first, int second) {
    int first_root = find(first);
    int second_root = find(second);

    if (first_root == second_root) {
        return;
    }

    if (_rank[first_root] < _rank[second_root]) {
        _parent[first_root] = second_root;
    }
    else if (_rank[first_root] > _rank[second_root]) {
        _parent[second_root] = first_root;
    }
    else {
        _parent[second_root] = first_root;
        _rank[first_root]++;
    }
}

void DSU::clear() {
    for (int i = 0; i < _size; ++i) {
        _parent[i] = i;
        _rank[i] = 1;
    }
}

#endif  // LIB_DSU_DSU_H_

