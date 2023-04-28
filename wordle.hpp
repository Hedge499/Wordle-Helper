#ifndef WORDLEHELPER_WORDLE_HPP
#define WORDLEHELPER_WORDLE_HPP

#include <map>
#include <list>
#include <string>

std::list<std::string> getAnswer(std::map<char, int> lettersWithPosition, std::list<char> lettersWithoutPosition, std::list<char> lettersNotInWord, std::list<std::string> wordlist);
std::list<std::string> nextWords(std::map<char, int> lettersWithPosition, std::list<char> lettersWithoutPosition, std::list<char> lettersNotInWord, std::list<std::string> wordlist);

#endif