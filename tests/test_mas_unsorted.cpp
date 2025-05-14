#include <gtest.h>                  // Подключение библиотеки Google Test
#include "../lib_mas_unsorted/mas_unsorted.h" // Заголовочный файл тестируемого класса

// Тест вставки с автоматической генерацией ключа
TEST(UnsortedTableTest, InsertWithGeneratedKey) {
    sorted<int, std::string> table;         // Создание пустой таблицы
    int key = table.insert("Value1");       // Вставка значения с генерацией ключа

    // Проверка корректности диапазона ключа (1-100)
    EXPECT_TRUE(key >= 1 && key <= 100);
    // Проверка соответствия сохраненного значения
    EXPECT_EQ(table.find(key).second, "Value1");
}

// Тест вставки с явным указанием ключа
TEST(UnsortedTableTest, InsertWithSpecifiedKey) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");              // Ручная вставка пары (1, "Value1")
    EXPECT_EQ(table.find(1).second, "Value1"); // Проверка наличия записи
}

// Тест удаления существующего элемента
TEST(UnsortedTableTest, RemoveElement) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    table.remove(1);                        // Удаление элемента

    // Попытка поиска удаленного элемента должна вызывать исключение
    EXPECT_THROW(table.find(1), std::logic_error);
}

// Тест поиска существующего элемента
TEST(UnsortedTableTest, FindElement) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    EXPECT_EQ(table.find(1).second, "Value1"); // Проверка возвращаемого значения
}

// Тест поиска несуществующего элемента
TEST(UnsortedTableTest, FindNonExistentElement) {
    sorted<int, std::string> table;
    // Поиск без предварительной вставки должен вызывать ошибку
    EXPECT_THROW(table.find(1), std::logic_error);
}

// Тест обработки дубликатов ключей
TEST(UnsortedTableTest, InsertDuplicateKey) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    // Повторная вставка с тем же ключом должна вызывать исключение
    EXPECT_THROW(table.insert(1, "Value2"), std::logic_error);
}

// Тест удаления несуществующего элемента
TEST(UnsortedTableTest, RemoveNonExistentElement) {
    sorted<int, std::string> table;
    // Попытка удаления без предварительной вставки
    EXPECT_THROW(table.remove(1), std::logic_error);
}