// Подключение заголовочных файлов Google Test и класса для тестирования
#include <gtest.h>                     // Библиотека Google Test
#include "../lib_list_unsorted/List_unsorted.h" // Реализация несортированной таблицы

// Тест вставки с автоматической генерацией ключа
TEST(listUnsortedTableTest, InsertWithGeneratedKey) {
    sorted<int, std::string> table;          // Создание пустой таблицы
    int key = table.insert("Value1");        // Вставка значения с генерацией ключа

    // Проверка, что ключ в допустимом диапазоне (1-100)
    EXPECT_TRUE(key >= 1 && key <= 100);
    // Проверка корректности сохранения значения
    EXPECT_EQ(table.find(key).second, "Value1");
}

// Тест вставки с указанием ключа вручную
TEST(listUnsortedTableTest, InsertWithSpecifiedKey) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");               // Явная вставка с ключом 1
    EXPECT_EQ(table.find(1).second, "Value1"); // Проверка наличия записи
}

// Тест удаления элемента
TEST(listUnsortedTableTest, RemoveElement) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");               // Добавление элемента
    table.remove(1);                          // Удаление по ключу

    // Попытка повторного удаления должна вызвать исключение
    EXPECT_THROW(table.remove(1), std::logic_error);
}

// Тест поиска существующего элемента
TEST(listUnsortedTableTest, FindElement) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    EXPECT_EQ(table.find(1).second, "Value1"); // Проверка возвращаемого значения
}

// Тест поиска несуществующего элемента
TEST(listUnsortedTableTest, FindNonExistentElement) {
    sorted<int, std::string> table;
    EXPECT_THROW(table.find(1), std::logic_error); // Ожидаемое исключение
}

// Тест поиска удаленного элемента
TEST(listUnsortedTableTest, FindDeletedElement) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    table.remove(1);                         // Удаление элемента
    EXPECT_THROW(table.find(1), std::logic_error); // Элемент не должен находиться
}

// Тест вставки дубликата ключа
TEST(listUnsortedTableTest, InsertDuplicateKey) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    // Попытка вставки с тем же ключом должна вызвать ошибку
    EXPECT_THROW(table.insert(1, "Value2"), std::logic_error);
}

// Тест удаления несуществующего ключа
TEST(listUnsortedTableTest, RemoveNonExistentElement) {
    sorted<int, std::string> table;
    EXPECT_THROW(table.remove(1), std::logic_error); // Ожидаемое исключение
}

// Тест корректности подсчета размера таблицы
TEST(listUnsortedTableTest, GetSize) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    table.insert(2, "Value2");
    EXPECT_EQ(table.get_size(), 2); // Проверка счетчика элементов
}

// Тест вывода содержимого таблицы
TEST(listUnsortedTableTest, PrintTable) {
    sorted<int, std::string> table;
    table.insert(1, "Value1");
    table.insert(2, "Value2");

    testing::internal::CaptureStdout(); // Перехват вывода в консоль
    table.print();                      // Вызов метода вывода
    std::string output = testing::internal::GetCapturedStdout();

    // Проверка наличия ожидаемых строк в выводе
    EXPECT_TRUE(output.find("Key: 1 Value: Value1") != std::string::npos);
    EXPECT_TRUE(output.find("Key: 2 Value: Value2") != std::string::npos);
}

// Тест работы конструктора копирования
TEST(listUnsortedTableTest, CopyConstructor) {
    sorted<int, std::string> table1;
    table1.insert(1, "Value1");
    table1.insert(2, "Value2");

    sorted<int, std::string> table2(table1); // Создание копии

    // Проверка целостности скопированных данных
    EXPECT_EQ(table2.find(1).second, "Value1");
    EXPECT_EQ(table2.find(2).second, "Value2");
}

// Тест конструктора с передачей начальных данных
TEST(listUnsortedTableTest, ConstructorWithData) {
    std::list<std::pair<int, std::string>> data = {
        {1, "Value1"},
        {2, "Value2"}
    };
    sorted<int, std::string> table(data); // Инициализация таблицы данными

    // Проверка корректности инициализации
    EXPECT_EQ(table.find(1).second, "Value1");
    EXPECT_EQ(table.find(2).second, "Value2");
    EXPECT_EQ(table.get_size(), 2);        // Проверка размера
}