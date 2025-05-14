// Подключение необходимых заголовочных файлов
#include <iostream>       // Для ввода/вывода
#include <vector>         
#include <list>           // Для использования std::list
#include <utility>        // Для std::pair
#include <stdexcept>      // Для стандартных исключений
#include <random>         // Для генерации случайных ключей
#include <optional>       

// Абстрактный интерфейс таблицы с ключами типа TKey и значениями TVal
template <class TKey, class TVal>
class ITable {
public:
    // Вставка значения с автоматической генерацией ключа. Возвращает сгенерированный ключ.
    virtual TKey insert(TVal value) = 0;
    // Вставка пары ключ-значение. Если ключ уже существует, генерирует исключение.
    virtual void insert(TKey key, TVal value) = 0;
    // Удаление элемента по ключу. Если ключ не найден, генерирует исключение.
    virtual void remove(TKey key) = 0;
    // Поиск значения по ключу. Возвращает указатель на значение или nullptr.
    virtual TVal* _find(TKey key) = 0;
    // Поиск пары ключ-значение. Возвращает пару или генерирует исключение.
    virtual std::pair<TKey, TVal>& find(TKey key) = 0;
    // Вывод содержимого таблицы в консоль.
    virtual void print() = 0;
    // Генерация уникального ключа.
    virtual TKey generate_key() = 0;
    // Получение текущего количества элементов в таблице.
    virtual size_t get_size() = 0;
};

// Реализация таблицы на основе std::list (несмотря на название, элементы не сортируются)
template <class TKey, class TVal>
class sorted : public ITable<TKey, TVal> {
    // Хранение данных в виде списка пар (ключ, значение)
    std::list<std::pair<TKey, TVal>> _data;
    // Текущее количество элементов
    size_t _size;

public:
    // Конструктор по умолчанию
    sorted() {
        _size = 0;
    }

    // Конструктор из существующего списка пар
    sorted(std::list<std::pair<TKey, TVal>>& data) : _data(data) {
        _size = _data.size();
    }

    // Конструктор копирования
    sorted(const sorted& tab) {
        _data = (tab._data);
        _size = (tab._size);
    }

    // Генерация случайного ключа в диапазоне [1, 100]
    TKey generate_key() override {
        static std::random_device rd;          // Источник энтропии
        static std::mt19937 gen(rd());         // Генератор случайных чисел
        static std::uniform_int_distribution<> dis(1, 100); // Равномерное распределение
        return dis(gen);
    }

    // Вставка значения с автоматической генерацией ключа
    TKey insert(TVal value) override {
        TKey key = generate_key();
        _data.emplace_back(key, value); // Добавление в конец списка
        _size++;
        return key;
    }

    // Получение текущего размера таблицы
    size_t get_size() override {
        return _size;
    }

    // Вывод всех элементов таблицы в формате "Key: X Value: Y"
    void print() override {
        for (const auto& item : _data) {
            std::cout << " Key: " << item.first << " Value: " << item.second << "\n";
        }
    }

    // Вставка пары с указанным ключом
    void insert(TKey key, TVal val) override {
        if (_find(key)) { // Проверка на существование ключа
            throw std::logic_error("Key busy! \n");
        }
        _data.emplace_back(key, val);
        _size++;
    }

    // Поиск значения по ключу (возвращает указатель или nullptr)
    TVal* _find(TKey key) override {
        for (auto& item : _data) {
            if (item.first == key) {
                return &item.second;
            }
        }
        return nullptr;
    }

    // Удаление элемента по ключу
    void remove(TKey key) override {
        auto it = _data.begin();
        bool found = false;
        while (it != _data.end()) {
            if (it->first == key) {
                it = _data.erase(it); // Удаление элемента и получение следующего итератора
                _size--;
                found = true;
            }
            else {
                ++it;
            }
        }
        if (!found) {
            throw std::logic_error("No key");
        }
    }

    // Поиск и возврат пары по ключу (бросает исключение при отсутствии)
    std::pair<TKey, TVal>& find(TKey key) override {
        for (auto& item : _data) {
            if (item.first == key) {
                return item;
            }
        }
        throw std::logic_error("No key");
    }
};
 