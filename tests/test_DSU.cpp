// Copyright 2024 Ivan Shebelov

#include <gtest.h>         // Подключение библиотеки Google Test
#include "../lib_DSU/DSU.h" // Подключение заголовка класса DSU

// Тест корректности инициализации элементов через make_set
TEST(DSUTest, MakeSetTest) {
    DSU dsu(10); // Создание структуры на 10 элементов
    // Проверка, что каждый элемент после инициализации является корнем своего множества
    for (int i = 0; i < 10; ++i) {
        dsu.make_set(i);          // Создание множества для элемента i
        EXPECT_EQ(dsu.find(i), i); // Проверка: find(i) должен вернуть i (корень)
    }
}

// Тест объединения множеств и проверки связности элементов
TEST(DSUTest, UnionSetsTest) {
    DSU dsu(10);

    // Объединение элементов 0 и 1, проверка их принадлежности к одному множеству
    dsu.union_sets(0, 1);
    EXPECT_EQ(dsu.find(0), dsu.find(1)); // Корни должны совпадать

    // Объединение элементов 2 и 3, проверка их связности
    dsu.union_sets(2, 3);
    EXPECT_EQ(dsu.find(2), dsu.find(3));

    // Объединение множеств (0-1) и (2-3), проверка каскадного объединения
    dsu.union_sets(0, 2);
    EXPECT_EQ(dsu.find(0), dsu.find(3)); // Все 4 элемента теперь в одном множестве
}

// Тест оптимизации "сжатия пути" в методе find
TEST(DSUTest, PathCompressionTest) {
    DSU dsu(10);

    // Последовательное объединение элементов в цепочку: 0 ↔ 1 ↔ 2 ↔ 3
    dsu.union_sets(0, 1);
    dsu.union_sets(1, 2);
    dsu.union_sets(2, 3);

    // Проверка, что все элементы цепочки имеют общего корня
    EXPECT_EQ(dsu.find(0), dsu.find(3));
    EXPECT_EQ(dsu.find(1), dsu.find(3));
    EXPECT_EQ(dsu.find(2), dsu.find(3));

    // При вызове find происходит сжатие путей: родители элементов обновляются напрямую к корню
}

// Тест сброса структуры в исходное состояние методом clear
TEST(DSUTest, ClearTest) {
    DSU dsu(10);

    // Объединение элементов перед сбросом
    dsu.union_sets(0, 1);
    dsu.union_sets(2, 3);

    dsu.clear(); // Сброс структуры

    // После clear все элементы должны быть изолированы
    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(dsu.find(i), i); // Каждый элемент — корень своего множества
    }
}