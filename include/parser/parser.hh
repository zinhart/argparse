#include <unordered_map>
#include <regex>
#include <string>
#include <cstdint>
#include <memory>
namespace zinhart
{
  namespace parsers
  {
	namespace expressions
	{
	  const std::string pos_integer{"([1-9][0-9]*)"};
 	  const std::string floating_point{"[-+]?[0-9]*.?[0-9]+([eE][-+]?[0-9]+)?"};
	}
	
	class parser
	{
	  public:
		parser() = default;
		parser(const parser &) = delete;
		parser(parser &&) = delete;
		const parser & operator = (const parser &) = delete;
		const parser & operator = (parser &&) = delete;
		~parser() = default;

		void process(std::int32_t argc, char ** argv);
		void process(const std::string & total_args);
		void add_token(const std::string arg,  const std::string expression, const std::string support, bool required = false);
		void remove_token(const std::string arg);
		std::multimap<std::string, std::vector<std::string>> get_parsed_tokens()const;
		void print_support();

	  private:
		std::string total_args;
		std::unordered_map<std::string, bool> token_and_requirement;
		std::unordered_map<std::string, std::string> token_and_regex;
		std::unordered_map<std::string, std::string> token_and_support;
		// multimap because an token may appear more than once and have more than one value (hence vector) and,
		// multimap map gurantees duplicates are stored in insertion order which may be relevant
		std::multimap<std::string, std::vector<std::string>> token_values;
	};
  }// NAMESPACE PARSERS
}// NAMESPACE ZINHART
