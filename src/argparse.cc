#include <argparse/argparse.hh>
#include <algorithm>
#include <iostream>
#include <exception>
namespace zinhart
{
  namespace parsers
  {

	void argparse::process(std::int32_t argc, char ** argv)
	{
	 // parse args 
	  std::string args;
	  std::smatch matches;
	  //convert args to one string
	  std::for_each(argv, argv + argc, [&](const std::string & init){ args+= init;} );
	  auto search_start = args.cbegin();
	  
	  for(std::uint32_t nth_arg{0}; nth_arg < argument_and_regex.size(); ++ nth_arg)
	  {
		auto it{argument_and_regex.begin()};
		std::regex expr{it->second};
		if(std::regex_search(search_start, args.cend(), matches, expr))
		{
		  for (auto match : matches)
		  {
			std::cout<<match<<" ";
		  }
		  search_start += matches.position() + matches.length();
		  std::cout<<"\n";
		}
	  }
	}

	void argparse::process(const std::string & argv)
	{
	  try
	  {
		// parse args 
		if(argv.size() == 0)
		  throw std::logic_error("argv size cannot be 0");
		if(argument_and_regex.size() == 0)
		  throw std::logic_error("zero arguments to process were added");
		std::string args_to_be_processed{argv};
		std::smatch matches;
		// process all the cmdline arguments
		for(auto it = argument_and_regex.begin(); it != argument_and_regex.end(); ++it)
		{
		  std::regex arg(it->first);
		  std::regex expr{it->second};
		  std::uint32_t arg_position_start;
		  std::uint32_t arg_value_position_start;
		  std::uint32_t length{0};

		  // search relative to here
		  auto search_start = args_to_be_processed.cbegin();
		  // if the argument was found in argv
		  if(std::regex_search(search_start, args_to_be_processed.cend(), matches, arg))
		  {
			length += it->first.length();
			arg_position_start = matches.position();
			for (auto match : matches)
			{
			  std::cout<<match<<" ";
			}
			
			// now apply the regex to get the arguments value		  
			if(std::regex_search(search_start + arg_position_start, args_to_be_processed.cend(), matches, expr))
			{
			  length += matches[0].length();
			  arg_value_position_start = matches.position();
			  for (auto match : matches)
			  {
				std::cout<<match<<" ";
			  }
			  std::cout<<"\n";
			}
		  std::cout<<"argv before : "<<args_to_be_processed<<"\n";
		  std::cout<<"length to chop: "<<length<<"\n";
		  // chop off argmument and argument value from args_to_be_processed	
		  args_to_be_processed.erase(args_to_be_processed.begin() + arg_position_start, args_to_be_processed.begin() + arg_position_start + length);
		  std::cout<<"argv after: "<<args_to_be_processed<<"\n";
		  }
		}// end for
	  }
	  catch(std::exception & e)
	  {
		std::cerr<<e.what();
	  }
	}
	void argparse::add_argument(const std::string arg,  const std::string expression, const std::string support, bool required)
	{
      argument_and_requirement[arg] = required;
	  argument_and_regex[arg] = expression;
	  argument_and_support[arg] = support;
	}
	void argparse::remove_argument(const std::string arg)
	{
      argument_and_requirement.erase(arg);
	  argument_and_regex.erase(arg);
	  argument_and_support.erase(arg);
	}
	void argparse::print_help()
	{
	  for(const auto  & it : argument_and_support)
		std::cout<<it.first<< " " <<it.second<<"\n";
	}
	template<class T>
	  void argparse::get(std::string arg, T & value, std::uint32_t nth_value)//where 0 is no arg
	  {
		// to do
	  }

  }
}
