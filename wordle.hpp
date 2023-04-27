#ifndef WORDLEHELPER_WORDLE_HPP
#define WORDLEHELPER_WORDLE_HPP

#include <map>
#include <list>
#include <string>

std::list<std::string> getAnswer(std::map<char, int>, std::list<char>, std::list<char>, std::list<std::string>);
std::list<std::string> nextWords(std::map<char, int>, std::list<char>, std::list<char>, std::list<std::string>);

#endif