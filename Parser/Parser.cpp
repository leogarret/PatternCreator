//
// Created by leo on 21/03/2020.
//

#include "Parser.hpp"

using namespace pc::utils;

Parser::LineType Parser::computeType(const std::string &line)
{
	for (const char character : line)
	{
		if (character != ' ')
		{
			switch (character)
			{
				case '#': return LineType::COMMENT;
				case '.': return LineType::CONTAINER;
				default: return LineType::VALUE;
			}
		}
	}
	return LineType::UNKNOWN;
}

std::vector<std::string> Parser::getValues(const std::string &line)
{
	std::vector<std::string> values;

	if (computeType(line) != LineType::VALUE)
	{
		std::cerr << "Parser::getValues(): invalid line." << std::endl;
		return values;
	}

	std::string tmp;
	for (const char character : line)
	{
		if (character != ' ' && character != '\n' && character != '\0')
		{
			tmp += character;
		}
		else
		{
			values.push_back(tmp);
			tmp.clear();
		}
	}
	values.push_back(tmp);
	return values;
}