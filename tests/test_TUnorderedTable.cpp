#include <gtest.h>
#include "TUnorderedTable.h"

TEST(TUnorderedTableTest, InsertAndFind) {
    TUnorderedTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(2, "two");

    ASSERT_NE(table.find(1), nullptr);
    ASSERT_EQ(*table.find(1), "one");
    ASSERT_EQ(*table.find(2), "two");
    ASSERT_EQ(table.find(3), nullptr);
}

TEST(TUnorderedTableTest, Remove) {
    TUnorderedTable<int, std::string> table;
    table.insert(1, "one");
    table.insert(2, "two");

    table.remove(1);
    ASSERT_EQ(table.find(1), nullptr);
    ASSERT_NE(table.find(2), nullptr);
    ASSERT_EQ(*table.find(2), "two");
}

TEST(TUnorderedTableTest, Size) {
    TUnorderedTable<int, std::string> table;
    ASSERT_EQ(table.size(), 0);

    table.insert(1, "one");
    ASSERT_EQ(table.size(), 1);

    table.insert(2, "two");
    ASSERT_EQ(table.size(), 2);

    table.remove(1);
    ASSERT_EQ(table.size(), 1);
}