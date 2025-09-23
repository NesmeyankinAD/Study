#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>


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

        Builder& AddColumns(const std::vector<std::string>& columns) noexcept
        {
            columns_.insert(columns_.end(), columns.begin(), columns.end());
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

        Builder& AddWhere(const std::map<std::string, std::string>& kv) noexcept
        {
            for (const auto& [key, val] : kv)
            {
                conditions_.push_back(key + "=" + val);
            }
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

    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept
    {
        builder_.AddColumns(columns);
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

    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept
    {
        builder_.AddWhere(kv);
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

    // Добавление нескольких столбцов сразу
    query_builder.AddColumns({ "name", "phone", "email" }).AddFrom("students");

    // Добавление нескольких условий сразу
    query_builder.AddWhere({ {"id", "42"}, {"name", "John"} });

    // Можно также комбинировать с одиночными добавлениями
    query_builder.AddWhere("age", "20");

    std::string query = query_builder.BuildQuery();
    std::cout << query << std::endl;
    // Выведет: SELECT name, phone, email FROM students WHERE id=42 AND name=John AND age=20;

    return 0;
}
