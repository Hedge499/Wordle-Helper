#ifndef WORDLEHELPER_LIST_HPP
#define WORDLEHELPER_LIST_HPP

#include <list>
#include <string>
#include <map>

std::list<std::string> loadWordlistFromFile();
std::map<char, int> createLetterCount(std::list<std::string>);

#endif