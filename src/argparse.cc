#include <argparse/argparse.hh>
#include <algorithm>
#include <iostream>
namespace zinhart
{
  namespace parsers
  {

	void argparse::process(std::int32_t argc, char ** argv)
	{
	 // parse args 
	  std::string args;
	  std::for_each(argv, argv + argc, [&](const std::string & init){args+= init;});
	}
	void argparse::add_argument(const std::string arg,  const std::string expression, const std::string support, bool required)
	{
      arg_and_req[arg] = required;
	  arg_and_regex[arg] = expression;
	  arg_and_support[arg] = support;
	}
	void argparse::remove_argument(const std::string arg)
	{
      arg_and_req.erase(arg);
	  arg_and_regex.erase(arg);
	  arg_and_support.erase(arg);
	}
	void argparse::print_help()
	{
	  for(const auto  & it : arg_and_support)
		std::cout<<it.first<< " " <<it.second<<"\n";
	}
	template<class T>
	  void argparse::get(std::string arg, T & value, std::uint32_t nth_value)//where 0 is no arg
	  {
		// to do
	  }

  }
}
