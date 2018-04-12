//
// Created by Reid Woodbury Jr on 4/11/18.
//

#ifndef DISKERROR_PCRE2_FLAGS_MATCH_H
#define DISKERROR_PCRE2_FLAGS_MATCH_H

#include "FlagsBase.h"

class Match : public FlagsBase
{
public:
	Match() : FlagsBase() {}

	const int64_t NOTBOL = PCRE2_NOTBOL;    //	Subject string is not the beginning of a line
	const int64_t NOTEOL = PCRE2_NOTEOL;    //	Subject string is not the end of a line
	const int64_t NOTEMPTY = PCRE2_NOTEMPTY;    //	An empty string is not a valid match
	const int64_t NOTEMPTY_ATSTART = PCRE2_NOTEMPTY_ATSTART;    //	An empty string at the start is not a valid match
};

#endif //DISKERROR_PCRE2_FLAGS_MATCH_H
