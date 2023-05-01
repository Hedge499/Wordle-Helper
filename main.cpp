#include "list.hpp"
#include "wordle.hpp"
#include <list>
#include <string>
#include <iostream>
#include <cctype>

// overload << Operator for easy list printing
std::ostream &operator<<(std::ostream &os, const std::list<std::string> &list)
{
    for (auto const &i : list)
    {
        os << i << "\n";
    }
    return os;
}
std::ostream &operator<<(std::ostream &os, const std::list<char> &list)
{
    for (auto const &i : list)
    {
        os << i << "\n";
    }
    return os;
}

// overload << Operator for easy map printing
std::ostream &operator<<(std::ostream &os, const std::map<char, int> &map)
{
    for (auto const &[key, val] : map)
    {
        os << "Letter " << key << " at the position " << val << ".\n";
    }
    return os;
}

// Enter Letters with position and return them in a map.
// Only lowercase letters. Each input consists of a letter, a space and a digit.
// If input stays empty the input process ends
std::map<char, int> inputLettersWithPosition()
{
    std::map<char, int> newLetters{};

    while (bool more{true})
    {
        // get input from user; char + int = new entrance; empty string ends input.
        std::string input{""};
        std::cout << "Enter a letter with its position split by a space. If you do not want to add another letter leave the input empty.\n";
        std::cin >> input;

        // validate input
        if (input.empty())
        {
            more = false;
        }
        else
        {
            if (std::islower(input[0]))
            {
                if (std::isdigit(input[2]))
                {
                    newLetters[input[0]] = input[2];
                }
                else
                {
                    std::cout << "split the input with an space and enter a digit as second part of the input.\n";
                }
            }
            else
            {
                std::cout << "pls enter a lowercase letter as first input.\n";
            }
        }
    }
    return newLetters;
}

// Enter new Letters where the position is unknown/irrelevant.
// Only lowercase Letters and one per input.
// End input loop by leaving the input empty.
std::list<char> inputLetters()
{
    std::list<char> newLetters{};

    while (bool more{true})
    {
        // get input
        std::string input{};
        std::cout << "Enter one Letter(only lowercase). Leave empty to end input of new Letters.\n";
        std::cin >> input;

        // validate input
        if (input.empty())
        {
            more = false;
        }
        else
        {
            if (std::islower(input[0]))
            {
                newLetters.push_back(input[0]);
            }
            else
            {
                std::cout << "pls only enter a lowercase letter\n";
            }
        }
    }

    return newLetters;
}

int main()
{
    std::list<std::string> wordlist{loadWordlistFromFile()};
    std::map<char, int> lettersWithPosition{/* {'a', 2}, {'b', 3} */};
    std::list<char> lettersWithoutPosition{/* 'i', 'o' */};
    std::list<char> lettersNotInWord{/* 's' */};
    bool running{true};

    while (running)
    {
        std::cout << "Known information:\n"
                  << "Letters that are in the word and their Position(0-4):\n"
                  << lettersWithPosition
                  << "Letters that are in the word without Position:\n"
                  << lettersWithoutPosition
                  << "Letters that are not in the word\n"
                  << lettersNotInWord
                  << "\n"
                  << "Next action?\n"
                  << "1) show potential answers\n"
                  << "2) show good next words\n"
                  << "3) add new Letters with Position\n"
                  << "4) add new Letters without Position\n"
                  << "5) add new Letters that are not in the Word\n"
                  << "6) erase information\n"
                  << "7) exit\n"
                  << "Choose by entering a number(1-5): ";

        bool input{true};
        while (input)
        {
            int choice{0};
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                std::cout << getAnswer(lettersWithPosition, lettersWithoutPosition, lettersNotInWord, wordlist) << "\n";
                input = false;
                break;
            case 2:
                std::cout << nextWords(lettersWithPosition, lettersWithoutPosition, lettersNotInWord, wordlist) << "\n";
                input = false;
                break;
            case 3:
                for (auto [c, i] : inputLettersWithPosition())
                {
                    lettersWithPosition[c] = i;
                }
                input = false;
                break;
            case 4:
                lettersWithoutPosition.merge(inputLetters());
                lettersWithoutPosition.unique();
                input = false;
                break;
            case 5:
                lettersNotInWord.merge(inputLetters());
                lettersNotInWord.unique();
                input = false;
                break;
            case 6:
                lettersWithPosition.clear();
                lettersWithoutPosition.clear();
                lettersNotInWord.clear();
                input = false;
                break;
            case 7:
                running = false;
                input = false;
                break;
            default:
                std::cout << "Not a valid input!!!\n";
                break;
            }
        }
    }

    return 0;
}