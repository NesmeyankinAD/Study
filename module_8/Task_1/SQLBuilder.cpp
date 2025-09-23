#include <iostream>
#include <string>
#include <vector>
#include <sstream>


class SqlSelectQueryBuilder 
{
public:
    // Внутренний класс-строитель (Builder)
    class Builder 
    {
    private:
        std::vector<std::string> columns_;
        std::string table_;
        std::vector<std::string> conditions_;

    public:

        Builder() : columns_(), table_(), conditions_() {}

        Builder& AddColumn(const std::string& column) 
        {
            columns_.push_back(column);
            return *this;
        }

        Builder& AddFrom(const std::string& table) 
        {
            table_ = table;
            return *this;
        }

        Builder& AddWhere(const std::string& column, const std::string& value) 
        {
            conditions_.push_back(column + "=" + value);
            return *this;
        }

        std::string Build() const 
        {
            std::ostringstream oss;
            oss << "SELECT ";

            if (columns_.empty()) {
                oss << "*";
            }
            else 
            {
                for (size_t i = 0; i < columns_.size(); ++i) 
                {
                    oss << columns_[i];
                    if (i != columns_.size() - 1) 
                    {
                        oss << ", ";
                    }
                }
            }
            oss << " FROM " << (table_.empty() ? "" : table_);

            if (!conditions_.empty()) 
            {
                oss << " WHERE ";

                for (size_t i = 0; i < conditions_.size(); ++i) 
                {
                    oss << conditions_[i];
                    if (i != conditions_.size() - 1) 
                    {
                        oss << " AND ";
                    }
                }
            }
            oss << ";";
            return oss.str();
        }
    };

    SqlSelectQueryBuilder() : builder_() {}


    // Методы делегируют вызов внутреннему билдеру
private:
    Builder builder_;

public:
    SqlSelectQueryBuilder& AddColumn(const std::string& column) 
    {
        builder_.AddColumn(column);
        return *this;
    }
    SqlSelectQueryBuilder& AddFrom(const std::string& table) 
    {
        builder_.AddFrom(table);
        return *this;
    }
    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value) 
    {
        builder_.AddWhere(column, value);
        return *this;
    }

    std::string BuildQuery() const 
    {
        return builder_.Build();
    }

};

int main() 
{

    SqlSelectQueryBuilder query_builder;

    query_builder   .AddColumn("name")
                    .AddColumn("phone")
                    .AddFrom("students")
                    .AddWhere("id", "42")
                    .AddWhere("name", "John");

    std::string query = query_builder.BuildQuery();
    std::cout << query << std::endl; // Выведет: SELECT name, phone FROM students WHERE id=42 AND name=John;
}