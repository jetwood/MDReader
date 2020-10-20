//
// Created by jetwood on 2020/10/17.
//

#ifndef MDREADER_REGEXRULES_H
#define MDREADER_REGEXRULES_H
#include <regex>
#include <fstream>

#define CODE regex("\\n {4,}(.*)")
#define BLACK_QUOTE regex("\\n {0,3}> *(.*)")
#define UNORDERED_LIST regex("\\n {0,3}[-*+] {1,3}(.*)")
#define UNORDERED_LIST_HEADER regex("\t\t<li>.*</li>")

#define HEADER1 regex("\\n\\s{0,3}={3,}\\n")
#define HEADER2 regex("\\n\\s{0,3}-{1,3}\\n")
#define HEADER3 regex("\\n\\s{1,3}###\\s{1,3}(.*)")
#define HEADER4 regex("\\n\\s{1,3}####\\s{1,3}(.*)")
#define HEADER5 regex("\\n\\s{1,3}#####\\s{1,3}(.*)")
#define HEADER6 regex("\\n\\s{1,3}######\\s{1,3}(.*)")

#define HEADER1_MARK regex("^\\s{0,3}\\={3,}\\s*$")
#define HEADER2_MARK regex("^\\s{0,3}\\-{3,}\\s*$")
#define SPARE_LINE regex("^\\s*$")
#define PARAGRAPH


std::string &code_block(std::string &str);
std::string &blockQuote(std::string& str);
std::string &unordered_list(std::string& str);
bool orderedList(const std::string& prev, const std::string& curr, const std::string& next, std::string&rst);
std::string tripleLineScanning(std::ifstream &src);
std::string copyFile(std::ifstream& src);

#endif //MDREADER_REGEXRULES_H
