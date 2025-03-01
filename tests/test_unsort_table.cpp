// Copyright 2024 Ivan Shebelov

#include <gtest.h>
#include "../lib_DSU/DSU.h"
#include "unsort_table.h"

// Тест на вставку и поиск элементов
TEST(TUnsortedTableTest, InsertAndFind) {
    TUnsortedTable<int, std::string> table;

    // Вставляем элементы
    table.insert(1, "one");
    table.insert(2, "two");

    // Проверяем, что элементы найдены
    ASSERT_NE(table.find(1), nullptr);
    ASSERT_EQ(*table.find(1), "one");
    ASSERT_EQ(*table.find(2), "two");

    // Проверяем, что несуществующий элемент не найден
    ASSERT_EQ(table.find(3), nullptr);
}

// Тест на удаление элементов
TEST(TUnsortedTableTest, Remove) {
    TUnsortedTable<int, std::string> table;

    // Вставляем элементы
    table.insert(1, "one");
    table.insert(2, "two");

    // Удаляем элемент
    table.remove(1);

    // Проверяем, что элемент удален
    ASSERT_EQ(table.find(1), nullptr);

    // Проверяем, что другой элемент остался
    ASSERT_NE(table.find(2), nullptr);
    ASSERT_EQ(*table.find(2), "two");
}

// Тест на получение размера таблицы
TEST(TUnsortedTableTest, Size) {
    TUnsortedTable<int, std::string> table;

    // Проверяем начальный размер
    ASSERT_EQ(table.size(), 0);

    // Вставляем элементы и проверяем размер
    table.insert(1, "one");
    ASSERT_EQ(table.size(), 1);

    table.insert(2, "two");
    ASSERT_EQ(table.size(), 2);

    // Удаляем элемент и проверяем размер
    table.remove(1);
    ASSERT_EQ(table.size(), 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
