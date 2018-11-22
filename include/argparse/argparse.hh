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
		void process(std::int32_t argc, char ** argv);
		void add_argument(const std::string arg,  const std::string expression, const std::string support, bool required = false);
		void remove_argument(const std::string arg);
		template<class T>
		  void get(std::string arg, T & value, std::uint32_t nth_value = 0);//where 0 is no arg
		void print_help();

	  private:
		std::string total_args;
		std::unordered_map<std::string, bool> arg_and_req;
		std::unordered_map<std::string, std::string> arg_and_regex;// maybe a multi_map
		std::unordered_map<std::string, std::string> arg_and_support;
	};
  }// NAMESPACE PARSERS
}// NAMESPACE ZINHART
