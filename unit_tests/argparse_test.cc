#include <argparse/argparse.hh>
#include <gtest/gtest.h>


TEST(argparse, parse_args)
{
  const std::string gates{"and|or|nand|nor|xor"};
  const std::string argv{"--gateand--threads4--optimizersgd--loss_functionmse--batch_size10--learning_rate0.9--save"};
  zinhart::parsers::argparse ap;
  ap.add_argument("--threads", zinhart::parsers::expressions::pos_integer, "number of threads to use 1 - N", true );
  ap.add_argument("--gate", "and|or|nand|nor|xor", "valid logic_gates are <and, or, nand, nor, xor>", true);
  ap.process(argv);
}
