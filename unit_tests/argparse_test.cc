#include <argparse/argparse.hh>
#include <gtest/gtest.h>


TEST(argparse, parse_args)
{
  const std::string gates{"and|or|nand|nor|xor"};
  const std::string argv{"--gateand--threads4--optimizersgd--loss_functionmse--layerinput10--layersigmoid10--layerrelu6--batch_size10"};
//  const std::string argv{"--gateand--threads4--optimizersgd--loss_functionmse--layerrelu10--layersigmoid10--layerrelu6--batch_size10--learning_rate0.9--save"};

  zinhart::parsers::argparse ap;
  ap.add_argument("--gate", "and|or|nand|nor|xor", "valid logic_gates are <and, or, nand, nor, xor>", true);
  ap.add_argument("--threads", zinhart::parsers::expressions::pos_integer, "number of threads to use 1 - N", true );
  ap.add_argument("--optimizer", "sgd|momentum", "the optimizer to use");
  ap.add_argument("--loss_function", "ce|mse", "the loss function to use");
  ap.add_argument("--batch_size", zinhart::parsers::expressions::pos_integer, "the number of cases to process before a weight update", true );
  ap.add_argument("--layer", "(input|relu|sigmoid)([1-9][0-9]*)", "layer name and size", true);
  ap.process(argv);
}
