#ifndef PATTERNCREATOR_PARSER_HPP
#define PATTERNCREATOR_PARSER_HPP

#include <string>
#include <vector>
#include <iostream>

namespace pc::utils {

	/**
	 * @class Parser for all pc files formats.
	 */
	class Parser {
		 public:
			/**
			 * @enum Types of line in all pc files formats.
			 */
			enum LineType {
				COMMENT,
				CONTAINER,
				VALUE,
				UNKNOWN
			};
			/**
			 * Set and get type of given line as parameter.
			 * @param line the line to compute its type.
			 * @return type of line.
			 */
			static LineType computeType(const std::string& line);
			/**
			 * Get value(s) of given line as parameter.
			 * @param line the line to get its value(s).
			 * @return all values in vector.
			 */
			static std::vector<std::string> getValues(const std::string& line);

			//static bool checkFile(const std::string& file); << TODO

		 private:
			static LineType current;

	};

}


#endif //PATTERNCREATOR_PARSER_HPP
