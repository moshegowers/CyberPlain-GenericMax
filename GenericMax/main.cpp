#include <iostream>

template <typename T, typename COMP>
T Max(T first, T sconde, T three, COMP comp)
{
	return comp(first, sconde, three);
}

class StringComperer
{
public:
	StringComperer(bool isCaseSensitive):m_isCaseSensitive(isCaseSensitive)
	{}
	char * operator()(char *first, char *sconde, char *three)
	{
		char *res = m_isCaseSensitive ?
			strcmp(first, sconde) > 0 ? (strcmp(first, three) > 0 ? first : three) : (strcmp(sconde, three) > 0 ? sconde : three)
			: stricmp(first, sconde) > 0 ? (strcmp(first, three) > 0 ? first : three) : (strcmp(sconde, three) > 0 ? sconde : three);

		return res;
	}
private:
	bool m_isCaseSensitive;
};

void main(void)
{
	char *s1 = "abc", *s2 = "ABC", *s3 = "Acd";
	std::cout << "Sensitive: " << Max(s1, s2, s3, StringComperer(true)) << std::endl;
	std::cout << "Insensitive: " << Max(s1, s2, s3, StringComperer(false)) << std::endl;
}