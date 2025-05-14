#include <gtest.h>
#include "../lib_mas_unsorted/mas_unsorted.h" 


TEST(UnsortedTableTest, InsertWithGeneratedKey) {
    sorted<int, std::string> table;
    int key = table.insert("Value1");
    EXPECT_TRUE(key >= 1 && key <= 100); 
    EXPECT_EQ(table.find(key).second, "Value1");
}


TEST(UnsortedTableTest, InsertWithSpecifiedKey) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    EXPECT_EQ(table.find(1).second, "Value1"); 
}


TEST(UnsortedTableTest, RemoveElement) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    table.remove(1);
    EXPECT_THROW(table.find(1), std::logic_error); 
}


TEST(UnsortedTableTest, FindElement) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    EXPECT_EQ(table.find(1).second, "Value1");
}

TEST(UnsortedTableTest, FindNonExistentElement) {
    sorted<int, std::string> table;
    EXPECT_THROW(table.find(1), std::logic_error); 
}


TEST(UnsortedTableTest, InsertDuplicateKey) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    EXPECT_THROW(table.insert(1, "Value2"), std::logic_error); 
}


TEST(UnsortedTableTest, RemoveNonExistentElement) {
    sorted<int, std::string> table;
    EXPECT_THROW(table.remove(1), std::logic_error); 
}