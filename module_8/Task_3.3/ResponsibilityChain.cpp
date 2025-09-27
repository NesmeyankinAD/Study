#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <stdexcept>
#include <vector>

// Перечисление типов сообщений
enum class Type 
{
    Warning,
    Error,
    Fatal,
    Unknown
};


class LogMessage 
{
private:
    Type type_;
    std::string message_;

public:
    LogMessage(Type t, const std::string& msg) : type_(t), message_(msg) {}

    Type type() const { return type_; }
    const std::string& message() const { return message_; }
};

// Базовый класс обработчика
class Handler 
{
private:
    std::shared_ptr<Handler> next_;

protected:
    virtual bool canHandle(Type type) const = 0;
    virtual void process(const LogMessage& msg) = 0;

public:
    virtual ~Handler() = default;

    void setNext(std::shared_ptr<Handler> nextHandler) 
    {
        next_ = nextHandler;
    }

    void handle(const LogMessage& msg) 
    {
        if (canHandle(msg.type())) 
        {
            process(msg);
        }
        else if (next_) 
        {
            next_->handle(msg);
        }
        else 
        {
            // Нет обработчика для этого типа
            throw std::runtime_error("No handler for message type");
        }
    }
};

// Обработчик фатальных ошибок
class FatalHandler : public Handler 
{
protected:
    bool canHandle(Type type) const override 
    {
        return type == Type::Fatal;
    }

    void process(const LogMessage& msg) override 
    {
        throw std::runtime_error("Fatal error: " + msg.message());
    }
};

// Обработчик ошибок
class ErrorHandler : public Handler 
{
private:
    std::string filepath_;

public:
    explicit ErrorHandler(const std::string& filepath) : filepath_(filepath) {}

protected:
    bool canHandle(Type type) const override 
    {
        return type == Type::Error;
    }

    void process(const LogMessage& msg) override 
    {
        std::ofstream ofs(filepath_, std::ios::app);

        if (ofs) 
        {
            ofs << "Error: " << msg.message() << std::endl;
        }
        else 
        {
            throw std::runtime_error("Cannot open log file");
        }
    }
};

// Обработчик предупреждений
class WarningHandler : public Handler 
{
protected:
    bool canHandle(Type type) const override 
    {
        return type == Type::Warning;
    }

    void process(const LogMessage& msg) override 
    {
        std::cout << "Warning: " << msg.message() << std::endl;
    }
};

// Обработчик неизвестных сообщений
class UnknownHandler : public Handler 
{
protected:
    bool canHandle(Type type) const override 
    {
        return type == Type::Unknown;
    }

    void process(const LogMessage& msg) override 
    {
        throw std::runtime_error("Unrecognized message type: " + msg.message());
    }
};

int main() 
{
    using namespace std;

    // Создаем обработчики
    auto fatalHandler = std::make_shared<FatalHandler>();
    auto errorHandler = std::make_shared<ErrorHandler>("errors.log");
    auto warningHandler = std::make_shared<WarningHandler>();
    auto unknownHandler = std::make_shared<UnknownHandler>();

    // Формируем цепочку
    fatalHandler->setNext(errorHandler);
    errorHandler->setNext(warningHandler);
    warningHandler->setNext(unknownHandler);

    std::vector<LogMessage> messages = 
    {
        LogMessage(Type::Warning, "This is a warning"),
        LogMessage(Type::Error, "This is an error"),
        LogMessage(Type::Fatal, "This is a fatal error"),
        LogMessage(Type::Unknown, "Unknown message")
    };

    for (const auto& msg : messages) 
    {
        try 
        {
            fatalHandler->handle(msg);
        }
        catch (const std::exception& ex) 
        {
            std::cerr << "Exception is done: " << ex.what() << std::endl;
        }
    }

    return 0;
}