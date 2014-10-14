/***************
 * ↓  bob.h  ↓ *
 ***************/

#if !defined(BOB_H)
#define BOB_H

#include <string>
#include <map>


class bob
{
public:
	static const std::string hey(const std::string& sentence);

private:
	enum sentence_type { SENTENCE_QUESTION, SENTENCE_YELL, SENTENCE_EMPTY, SENTENCE_ELSE };
	static const std::map<sentence_type, std::string> answers;

	static const sentence_type sentenceType(const std::string& sentence);

	static const bool isQuestion(const std::string& sentence);
	static const bool     isYell(const std::string& sentence);
	static const bool    isEmpty(const std::string& sentence);

	static const bool containsCharacter(const std::string& sentence);
};

#endif

/***************
 * ↓ bob.cpp ↓ *
 ***************/

#include "bob.h"
#include <map>
#include <boost/algorithm/string/trim.hpp> 


//public:
const std::string bob::hey(const std::string& sentence)
{
	return answers.at(sentenceType(sentence));
}

//private:
const std::map<bob::sentence_type, std::string> bob::answers =
	{
		{ SENTENCE_QUESTION, std::string("Sure.") },
		{ SENTENCE_YELL,     std::string("Whoa, chill out!") },
		{ SENTENCE_EMPTY,    std::string("Fine. Be that way!") },
		{ SENTENCE_ELSE,     std::string("Whatever.") }
	};

const bob::sentence_type bob::sentenceType(const std::string& sentence)
{
	if (isEmpty(sentence))    return SENTENCE_EMPTY;
	if (isYell(sentence))     return SENTENCE_YELL;
	if (isQuestion(sentence)) return SENTENCE_QUESTION;
	return SENTENCE_ELSE;
}

const bool bob::isQuestion(const std::string& sentence)
{
	return sentence.back() == '?';
}

const bool bob::isYell(const std::string& sentence)
{
	if (!containsCharacter(sentence)) return false;

	for (const char& ch : sentence)
	{
		if (islower(ch)) return false;
	}

	return true;
}

const bool bob::isEmpty(const std::string& sentence)
{
	return boost::algorithm::trim_copy(sentence).empty();
}

const bool bob::containsCharacter(const std::string& sentence)
{
	for (const char& ch : sentence)
	{
		if (isalpha(ch)) return true;
	}

	return false;
}