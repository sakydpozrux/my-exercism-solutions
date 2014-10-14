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
