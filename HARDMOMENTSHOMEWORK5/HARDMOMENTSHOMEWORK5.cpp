#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include <string>
#include <sstream>
#include <unordered_set>
#include <map>
#include <algorithm>

using namespace std;

void obzac()
{
    cout << "\n\n//====================================HomeWork====================================//\n\n";
}
void obzac1()
{
    cout << "\n\n//======================================END======================================//\n\n";
}
void obzac2()
{
    cout << "\n\n//-------------------------------------------------------------------------------//\n\n";
}

/*HOMEWORK1
Создать шаблонную функцию, которая принимает итераторы на начало и конец последовательности слов, 
и выводящую в консоль список уникальных слов (если слово повторяется больше 1 раза, то вывести его надо один раз). 
Продемонстрировать работу функции, передав итераторы различных типов.
*/
template<typename iter>
void PrintUnique(const iter& begin, const iter& end) 
{
    auto new_end = std::unique(begin, end);
    auto print = [&](auto val) 
    {
        std::cout << val << std::endl;
    };
    std::for_each(begin, new_end, print);
}

template<typename iter>
void PrintUniqueSet(const iter& begin, const iter& end) 
{
    std::unordered_set<typename std::iterator_traits<iter>::value_type> sorted_words{ begin, end };
    auto print = [&](auto const& item) 
    {
        std::cout << item << " ";
    };
    for_each(sorted_words.begin(), sorted_words.end(), print);
}
void HWOne() 
{
    std::cout << "vector_iterator: " << std::endl;
    std::vector<std::string> vocabulary;
    std::sort(vocabulary.begin(), vocabulary.end());
    vocabulary.push_back("pokemon");
    vocabulary.push_back("pokemon");
    vocabulary.push_back("red");
    vocabulary.push_back("banana");
    vocabulary.push_back("qiwi");
    vocabulary.push_back("dekorator");
    PrintUniqueSet(vocabulary.begin(), vocabulary.end());

    std::cout << "\nlist_iterator: " << std::endl;
    std::list<std::string> vocabulary2{ {"C", "plus", "plus", "has", "at", "least", "two", "pluses"} };
    PrintUniqueSet(vocabulary2.begin(), vocabulary2.end());

    std::cout << "\ndeque_iterator: " << std::endl;
    std::deque<std::string> vocabulary3;
    vocabulary3.push_front("C");
    vocabulary3.push_front("plus");
    vocabulary3.push_front("plus");
    vocabulary3.push_front("has");
    vocabulary3.push_front("quite");
    vocabulary3.push_front("a");
    vocabulary3.push_front("complex");
    vocabulary3.push_front("syntax");
    PrintUniqueSet(vocabulary3.begin(), vocabulary3.end());
}




/*HOMEWORK2
Используя ассоциативный контейнер, напишите программу, которая будет считывать данные введенные пользователем из стандартного потока ввода и разбивать их на предложения. 
Далее программа должна вывести пользователю все предложения, отсортировав их по длине.
*/
std::multimap<int, std::string> StringToMap2() 
{
    std::string word;
    std::string sentence;
    std::multimap<int, std::string> sentences;
    while (std::cin >> word) {
        if (word.back() != '.' || word.back() != '!' || word.back() != '?') 
        {
            sentence.append(word);
            sentence.push_back(' ');
        }
        if (*(sentence.end() - 2) == '.' || *(sentence.end() - 2) == '!' ||
            *(sentence.end() - 2) == '?') 
        {
            sentence.pop_back();
            int words = count(sentence.begin(), sentence.end(), ' ') + 1;
            sentences.insert({ words, sentence });
            sentence.clear();
        }
    }
    return sentences;
}

void HWTwo() 
{
    std::string str;
    std::multimap<int, std::string> sentences;
    std::cout << "Please, enter some text: ";
    sentences = StringToMap2();
    for_each(sentences.begin(), sentences.end(), [](std::pair<int, std::string> item) 
        {
        std::cout << item.first << " " << item.second << std::endl;
        });
}

int main() 
{
    {
        obzac();
        HWOne();
        obzac2();
    }

    {
        obzac();
        HWTwo();
        obzac1();
    }
    return 0;
}