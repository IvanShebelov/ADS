// Copyright 2024 Ivan Shebelov

#include <gtest.h>
#include "../lib_DSU/DSU.h"

TEST(DSUTest, MakeSetTest) {
    DSU dsu(10);
    for (int i = 0; i < 10; ++i) {
        dsu.make_set(i);
        EXPECT_EQ(dsu.find(i), i);
    }
}

TEST(DSUTest, UnionSetsTest) {
    DSU dsu(10);
    dsu.union_sets(0, 1);
    EXPECT_EQ(dsu.find(0), dsu.find(1));

    dsu.union_sets(2, 3);
    EXPECT_EQ(dsu.find(2), dsu.find(3));

    dsu.union_sets(0, 2);
    EXPECT_EQ(dsu.find(0), dsu.find(3));
}

TEST(DSUTest, PathCompressionTest) {
    DSU dsu(10);
    dsu.union_sets(0, 1);
    dsu.union_sets(1, 2);
    dsu.union_sets(2, 3);

    EXPECT_EQ(dsu.find(0), dsu.find(3));
    EXPECT_EQ(dsu.find(1), dsu.find(3));
    EXPECT_EQ(dsu.find(2), dsu.find(3));
}

TEST(DSUTest, ClearTest) {
    DSU dsu(10);
    dsu.union_sets(0, 1);
    dsu.union_sets(2, 3);
    dsu.clear();

    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(dsu.find(i), i);
    }
}