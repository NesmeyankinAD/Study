#include <string>
#include <iostream>
#include <algorithm>

class Text 
{
public:
    virtual void render(const std::string& data) const 
    {
        std::cout << data;
    }
};

class DecoratedText : public Text 
{
public:
    Text* text_;

    explicit DecoratedText(Text* text) : text_(text) {}
};

class ItalicText : public DecoratedText 
{
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}

    void render(const std::string& data) const override 
    {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText 
{
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}

    void render(const std::string& data) const override 
    {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph : public DecoratedText 
{
public:
    explicit Paragraph(Text* text) : DecoratedText(text) {}

    void render(const std::string& data) const override 
    {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed : public DecoratedText 
{
public:
    explicit Reversed(Text* text) : DecoratedText(text) {}

    void render(const std::string& data) const override 
    {
        std::string reversed_data = data;
        std::reverse(reversed_data.begin(), reversed_data.end());
        text_->render(reversed_data);
    }
};

// Отдельный класс Link, т.к. метод render отличается по сигнатуре
class Link : public Text 
{
private:
    Text* text_;

public:
    explicit Link(Text* text) : text_(text) {}

    void render(const std::string& href, const std::string& data) const 
    {
        std::cout << "<a href=" << href << ">";
        text_->render(data);
        std::cout << "</a>";
    }
};

int main() 
{
    // Пример с Paragraph
    {
        Text* text_block = new Paragraph(new Text());
        text_block->render("Hello world");
        std::cout << std::endl;
        delete text_block;
    }

    // Пример с Reversed
    {
        Text* text_block = new Reversed(new Text());
        text_block->render("Hello world");
        std::cout << std::endl;
        delete text_block;
    }

    // Пример с Link
    {
        Link* link_block = new Link(new Text());
        link_block->render("netology.ru", "Hello world");
        std::cout << std::endl;
        delete link_block;
    }

    // Комбинация декораторов
    {
        Text* decorated = new ItalicText(new BoldText(new Paragraph(new Text())));
        decorated->render("Hello world");
        std::cout << std::endl;
        delete decorated;
    }

    return 0;
}