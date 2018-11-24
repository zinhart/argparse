#include <parser/parser.hh>
#include <algorithm>
#include <iostream>
#include <exception>
namespace zinhart
{
  namespace parsers
  {

	void parser::process(std::int32_t argc, char ** argv)
	{
	 // parse args 
	  std::string args;
	  //convert args to one string
	  std::for_each(argv, argv + argc, [&](const std::string & init){ args+= init;} );
	  process(args); 
	}

	void parser::process(const std::string & argv)
	{
	  try
	  {
		// parse args 
		if(argv.size() == 0)
		  throw std::logic_error("argv size cannot be 0");
		if(token_and_regex.size() == 0)
		  throw std::logic_error("zero tokens to process were added");
		std::string args_to_be_processed{argv};
		std::smatch matches;
		// process all the cmdline tokens
		for(auto it = token_and_regex.begin(); it != token_and_regex.end(); ++it)
		{
		  std::regex arg(it->first);
		  std::regex expr{it->second};
		  std::uint32_t arg_position_start;
		  std::uint32_t length{0};

		  // search relative to here
		  auto search_start = args_to_be_processed.cbegin();
		  // if the token was found in argv
		  while(std::regex_search(search_start, args_to_be_processed.cend(), matches, arg))
		  {
			std::vector<std::string> values;
			length += it->first.length();
			arg_position_start = matches.position();
			for (auto match : matches)
			{
			  std::cout<<match<<" ";
			}
			
			// now apply the regex to get the tokens value		  
			if(std::regex_search(search_start + arg_position_start, args_to_be_processed.cend(), matches, expr))
			{
			  length += matches[0].length();
			  for(std::uint32_t i = 1; i < matches.size(); ++i)
				values.push_back(matches[i]);
			  for (auto match : matches)
			  {
				std::cout<<match<<" ";
			  }
			  std::cout<<"\n";
			}
			std::cout<<"argv before : "<<args_to_be_processed<<"\n";
			std::cout<<"length to chop: "<<length<<"\n";
			// chop off argmument and token value from args_to_be_processed	
			args_to_be_processed.erase(args_to_be_processed.begin() + arg_position_start, args_to_be_processed.begin() + arg_position_start + length);
			std::cout<<"argv after: "<<args_to_be_processed<<"\n";
			length = 0;
			token_values.insert({it->first,values});
		  }
		}// end for
	  }
	  catch(std::exception & e)
	  {
		std::cerr<<e.what();
	  }
	}
	void parser::add_token(const std::string arg,  const std::string expression, const std::string support, bool required)
	{
      token_and_requirement[arg] = required;
	  token_and_regex[arg] = expression;
	  token_and_support[arg] = support;
	}
	void parser::remove_token(const std::string arg)
	{
      token_and_requirement.erase(arg);
	  token_and_regex.erase(arg);
	  token_and_support.erase(arg);
	}
	void parser::print_support()
	{
	  for(const auto  & it : token_and_support)
		std::cout<<it.first<< " " <<it.second<<"\n";
	}
	std::multimap<std::string, std::vector<std::string>> parser::get_parsed_tokens()const
	{
	  return token_values;
	}


  }
}
