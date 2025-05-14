// Подключение необходимых заголовочных файлов
#include <iostream>       // Для ввода/вывода
#include <vector>         // Для использования std::vector
#include <list>           // Не используется, можно удалить
#include <utility>        // Для std::pair
#include <stdexcept>      // Для стандартных исключений
#include <random>         // Для генерации случайных ключей
#include <optional>       // Не используется, можно удалить

// Абстрактный интерфейс таблицы с ключом TKey и значением TVal
template <class TKey, class TVal>
class ITable {
public:
    virtual ~ITable() = default;
    // Вставка со сгенерированным ключом. Возвращает созданный ключ
    virtual TKey insert(TVal value) = 0;
    // Вставка с указанием ключа. Бросает исключение при дубликате
    virtual void insert(TKey key, TVal value) = 0;
    // Удаление элемента по ключу
    virtual void remove(TKey key) = 0;
    // Поиск значения по ключу. Возвращает nullptr если не найдено
    virtual TVal* _find(TKey key) = 0;
    // Поиск пары ключ-значение. Бросает исключение при отсутствии
    virtual std::pair<TKey, TVal>& find(TKey key) = 0;
    // Вывод содержимого таблицы
    virtual void print() = 0;
    // Генерация уникального ключа
    virtual TKey generate_key() = 0;
};

// Реализация таблицы на основе std::vector (несортированное хранение)
template <class TKey, class TVal>
class sorted : public ITable<TKey, TVal> {
    std::vector<std::pair<TKey, TVal>> _data; // Хранилище пар ключ-значение
    size_t _size; // Текущее количество элементов

public:
    // Конструктор по умолчанию
    sorted() : _size(0) {}

    // Конструктор с инициализацией из существующего вектора
    sorted(std::vector<std::pair<TKey, TVal>>& data) : _data(data), _size(data.size()) {}

    // Конструктор копирования (глубокое копирование)
    sorted(const sorted& tab) : _data(tab._data), _size(tab._size) {}

    // Вставка со случайной генерацией ключа
    TKey insert(TVal value) override {
        TKey key = generate_key();
        _data.emplace_back(key, value); // Добавление в конец вектора
        _size++;
        return key;
    }

    // Генерация случайного ключа в диапазоне [1, 100]
    TKey generate_key() override {
        static std::random_device rd;          // Источник энтропии
        static std::mt19937 gen(rd());         // Генератор Mersenne Twister
        static std::uniform_int_distribution<> dis(1, 100); // Распределение
        return dis(gen);
    }

    // Вывод содержимого таблицы в консоль
    void print() override {
        for (const auto& item : _data) {
            std::cout << " Key: " << item.first << " Value: " << item.second << "\n";
        }
    }

    // Поиск значения по ключу (безопасная версия)
    TVal* _find(TKey key) override {
        for (auto& item : _data) {
            if (item.first == key) {
                return &item.second; // Возврат указателя на значение
            }
        }
        return nullptr; // Ключ не найден
    }

    // Поиск пары по ключу (небезопасная версия)
    std::pair<TKey, TVal>& find(TKey key) override {
        for (auto& item : _data) {
            if (item.first == key) {
                return item; // Возврат ссылки на пару
            }
        }
        throw std::logic_error("No key"); // Генерация исключения
    }

    // Вставка с указанием ключа
    void insert(TKey key, TVal val) override {
        if (_find(key)) { // Проверка на существование ключа
            throw std::logic_error("Key busy!");
        }
        _data.emplace_back(key, val);
        _size++;
    }

    // Удаление элемента по ключу
    void remove(TKey key) override {
        for (auto it = _data.begin(); it != _data.end(); ++it) {
            if (it->first == key) {
                _data.erase(it); // Удаление элемента
                _size--;
                return;
            }
        }
        throw std::logic_error("No key"); // Если ключ не найден
    }
};