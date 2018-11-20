#include <map>
#include <regex>
#include <string>
#include <cstdint>
#include <shared_ptr>
namespace zinhart
{
  namespace parsers
  {
	namespace expressions
	{
	  const std::string pos_integer{"([1-9][0-9]*)"};
 	  const std::string floating_point{"[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?"};
	}
	
	class argparse
	{
	  public:
		void register(const std::string key,  std::uint32_t values, const std::string expression, const std::string support, bool required = false);
		void remove(const std::string key);
		template<class T>
		  void get(std::string key, T & value, std::uint32_t nth_value = 0);//where 0 is no arg
		void process(std::int32_t argv, char ** argc);
	  private:
		std::string total_args;
		std::map<std::string, bool> arg_and_req;
		std::map<std::string, std::string> arg_and_expression;// maybe a multi_map
		std::map<std::string, std::string> arg_and_support;
	};
  }// NAMESPACE PARSERS
}// NAMESPACE ZINHART
