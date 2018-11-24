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
	
	class argparse
	{
	  public:
		argparse() = default;
		argparse(const argparse &) = delete;
		argparse(argparse &&) = delete;
		const argparse & operator = (const argparse &) = delete;
		const argparse & operator = (argparse &&) = delete;
		~argparse() = default;

		void process(std::int32_t argc, char ** argv);
		void process(const std::string & total_args);
		void add_argument(const std::string arg,  const std::string expression, const std::string support, bool required = false);
		void remove_argument(const std::string arg);
		template<class T>
		  void get(std::string arg, T & value, std::uint32_t nth_value = 0);//where 0 is no arg
		void print_help();

	  private:
		std::string total_args;
		std::unordered_map<std::string, bool> argument_and_requirement;
		std::unordered_map<std::string, std::string> argument_and_regex;
		std::unordered_map<std::string, std::string> argument_and_support;
		// multimap because an arg may appear more than once and have more than one value (hence vector) and,
		// multimap map gurantees duplicates are stored in insertion order which may be relevant
		std::multimap<std::string, std::vector<std::string>> arg_values;
	};
  }// NAMESPACE PARSERS
}// NAMESPACE ZINHART
