#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

// Интерфейс наблюдателя
class Observer 
{
public:
    virtual ~Observer() = default;

    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};

// Класс, за которым наблюдают
class Observable 
{
public:
    // Добавление наблюдателя
    void addObserver(Observer* observer) 
    {
        // Защита от дублирования
        if (observer && std::find(observers_.begin(), observers_.end(), observer) == observers_.end()) 
        {
            observers_.push_back(observer);
        }
    }

    void removeObserver(Observer* observer) 
    {
        observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
    }

    void warning(const std::string& message) const 
    {
        notify(&Observer::onWarning, message);
    }

    void error(const std::string& message) const 
    {
        notify(&Observer::onError, message);
    }

    void fatalError(const std::string& message) const 
    {
        notify(&Observer::onFatalError, message);
    }

private:
    std::vector<Observer*> observers_;

    // Тип указателя на метод наблюдателя
    //using ObserverMethod = void(Observer::*)(const std::string& message);

    // Обобщенный вызов метода уведомления для каждого наблюдателя
    void notify(void (Observer::* method)(const std::string&), const std::string& message) const 
    {
        // Используем копию списка, на случай, если в процессе уведомления кто-то удалит наблюдателя
        auto copy = observers_;

        for (Observer* obs : copy) 
        {
            if (obs) 
            {
                // Вызов метода уведомления
                (obs->*method)(message);
            }
        }
    }
};

// Классы наблюдателей

// Наблюдатель для предупреждений — выводит в консоль warning-сообщения
class WarningObserver : public Observer 
{
public:
    void onWarning(const std::string& message) override 
    {
        std::cout << "Warning: " << message << std::endl;
    }
};

// Наблюдатель для ошибок — пишет error-сообщения в файл
class ErrorObserver : public Observer 
{
private:
    std::string filepath_;

public:
    explicit ErrorObserver(std::string filepath) : filepath_(std::move(filepath)) {}

    void onError(const std::string& message) override 
    {
        std::ofstream file(filepath_, std::ios::app);

        if (file.is_open()) 
        {
            file << "Error: " << message << std::endl;
        }
        else 
        {
            std::cerr << "ErrorObserver: can't open file for writing: " << filepath_ << std::endl;
        }
    }
};

// Наблюдатель для фатальных ошибок — пишет и в консоль, и в файл
class FatalErrorObserver : public Observer 
{
private:
    std::string filepath_;

public:
    explicit FatalErrorObserver(std::string filepath) : filepath_(std::move(filepath)) {}

    void onFatalError(const std::string& message) override 
    {
        
        std::cerr << "FatalError: " << message << std::endl;// В консоль
        
        std::ofstream file(filepath_, std::ios::app);// В файл

        if (file.is_open()) 
        {
            file << "FatalError: " << message << std::endl;
        }
        else 
        {
            std::cerr << "FatalErrorObserver: can't open file for writing: " << filepath_ << std::endl;
        }
    }
};


int main() 
{
    // Создаем наблюдаемый объект
    Observable logger;

    // Создаем наблюдателей
    WarningObserver warningObs;               
    ErrorObserver errorObs("errors.log");     
    FatalErrorObserver fatalObs("fatal.log"); 

    // Регистрируем наблюдателей в логгере
    logger.addObserver(&warningObs);
    logger.addObserver(&errorObs);
    logger.addObserver(&fatalObs);

    // Генерируем разные уведомления
    logger.warning("Low disk space");           
    logger.error("Failed to open config file"); 
    logger.fatalError("Out of memory");         

    return 0;
}