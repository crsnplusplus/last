// last: last abstract syntax tree
#include <cstdlib>
#include <iostream>

#include <lastconfig.h>

#include <lexer.h>
#include <parser.h>
#include <interpreter.h>
#include <last_exceptions.h>
 
int main (int argc, char *argv[])
{
  if (argc < 2) {
    fprintf(stdout,"%s Version %d.%d\n",
            argv[0],
            last_VERSION_MAJOR,
            last_VERSION_MINOR);
    fprintf(stdout,"Usage: %s number\n",argv[0]);
    return EXIT_FAILURE;
  }

  std::string expression;
  // collecting args
  for (int i = 1; i < argc; ++i) {
    expression += *(argv + i);
  }

  Lexer lex(expression);
  Parser parser(&lex);
  Interpreter interpreter;
  int value = 0;

  NodeAST* root = nullptr;

  try {
    root = parser.parse();
    value = interpreter.evaluate(root);
  }
  catch (LastException& e) {
    std::cout << e.what() << std::endl;

    delete root;

    return EXIT_FAILURE;
  }

  std::cout << "Expression: " << expression
            << " equals to: " << value << std::endl;

  delete root;

  return EXIT_SUCCESS;
}
