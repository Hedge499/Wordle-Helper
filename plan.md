# Wordle Helper Plan

- [Wordle Helper Plan](#wordle-helper-plan)
- [Wordlist](#wordlist)
  - [Load Wordlist](#load-wordlist)
  - [Create Letter Count](#create-letter-count)
- [Input](#input)
  - [Command Line](#command-line)
    - [Filter Wordlist](#filter-wordlist)
    - [Answer](#answer)
    - [next Word](#next-word)
    - [add information](#add-information)
    - [exit](#exit)
  - [Gui (Later)](#gui-later)
- [main()](#main)
  - [Variables](#variables)
  - [Loop](#loop)

# Wordlist

A wordlist containing 479k English words from https://github.com/dwyl/english-words is used as a base to calculate/find the best words to use, and find the potential answers. The list is filtered to only contain 5 letter words, since wordle only accepts those. Still 15920 words left. Some seem to be gibberish.

## Load Wordlist

- header: returns `list`, no parameter 
- open file
- `readline()`
- append into a list
- close file
- return list

## Create Letter Count

- header: returns `map<letter, count>`, params: List of words
- iterate through list
- iterate through each string 
- add +1 for each letter in the word to the map
- return map

# Input

## Command Line

### Filter Wordlist

- words with Letters in the right position stay
- words without known letters get filtered out
- words containing eliminated letters get filtered out

### Answer

- header: returns void, params: letters with position in word, letters without position in word, letters not in word and the wordlist
- [filter Wordlist](#filter-wordlist)
- print remaining list 

### next Word

- header: return void, params: letters with position in word, letters without position in word, letters not in word and the wordlist
- variables:
  - top 3 words 
- [filter wordlist](#filter-wordlist)
- create count [map](#create-letter-count) with filtered wordlist
- iterate through wordlist
- give each word a value and save them in a variable if the value is higher than any value of the previous saved word
  - letter with know position in word `value * 0`
  - letter not in word `value * 0`
  - letter in word without position `value * 0.5`
  - other `value * 1`
- print the 3 words saved in variables with the highest calculated values

### add information

- letters with position in word
- letters without position in word
- letters not in word

### exit

set boolean to false &rarr; while loop ends.

## Gui (Later)

# main()

## Variables

- List wordlist: containing wordlist
- map lettersWithPosition: containing letters with position in word
- List lettersWithoutPosition: containing letters without position in word
- List lettersNotInWord: containing letters not in word
- Boolean running: keep program(while loop) running till exit

## Loop

1. print known info from above [variables](#variables)
2. prompt the choices: 
   1. [answer](#answer)
   2. [next Word](#next-word)
   3. [add info](#add-information)
   4. [exit](#exit)
3. ask input from 1 - 4
4. run specified function