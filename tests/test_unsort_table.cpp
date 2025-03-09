// Copyright 2024 Ivan Shebelov

#include <gtest.h>
#include "../lib_DSU/DSU.h"
#include "unsort_table.h"

TEST(TUnsortedTableTest, InsertAndFind) {
    TUnsortedTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(2, "two");

    ASSERT_EQ(*table.find(1), "one");
    ASSERT_EQ(*table.find(2), "two");
    ASSERT_EQ(table.find(3), nullptr);
}

TEST(TUnsortedTableTest, Remove) {
    TUnsortedTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(2, "two");

    table.remove(1);
    ASSERT_EQ(table.find(1), nullptr);
    ASSERT_EQ(*table.find(2), "two");
}

TEST(TUnsortedTableTest, Size) {
    TUnsortedTable<int, std::string> table;
    ASSERT_EQ(table.size(), 0);

    table.insert(1, "one");
    ASSERT_EQ(table.size(), 1);

    table.insert(2, "two");
    ASSERT_EQ(table.size(), 2);

    table.remove(1);
    ASSERT_EQ(table.size(), 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
