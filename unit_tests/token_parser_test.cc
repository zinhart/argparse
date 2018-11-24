#include <token_parser/token_parser.hh>
#include <gtest/gtest.h>


TEST(token_parser, parse_args)
{
  const std::string gates{"and|or|nand|nor|xor"};
  const std::string argv{"--gateand--threads4--optimizersgd--loss_functionmse--layerinput10--layersigmoid10--layerrelu6--batch_size10"};
//  const std::string argv{"--gateand--threads4--optimizersgd--loss_functionmse--layerrelu10--layersigmoid10--layerrelu6--batch_size10--learning_rate0.9--save"};

  zinhart::parsers::token_parser ap;
  ap.add_token("--gate", "and|or|nand|nor|xor", "valid logic_gates are <and, or, nand, nor, xor>", true);
  ap.add_token("--threads", zinhart::parsers::expressions::pos_integer, "number of threads to use 1 - N", true );
  ap.add_token("--optimizer", "sgd|momentum", "the optimizer to use");
  ap.add_token("--loss_function", "ce|mse", "the loss function to use");
  ap.add_token("--batch_size", zinhart::parsers::expressions::pos_integer, "the number of cases to process before a weight update", true );
  ap.add_token("--layer", "(input|relu|sigmoid)([1-9][0-9]*)", "layer name and size", true);
  ap.process(argv);
  auto token_values = ap.get_parsed_tokens();
  for(auto it = token_values.begin(); it != token_values.end(); ++it)
  {
	std::cout<<it->first<<" ";
	for(auto inner_it = it->second.begin(); inner_it != it->second.end(); ++inner_it)
	{
	  std::cout<<*inner_it<<" ";
	}
	std::cout<<"\n";
  }
}
