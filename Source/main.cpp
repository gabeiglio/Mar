//
//  main.cpp
//  Mar
//
//  Created by Gabriel Igliozzi on 11/13/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#include <iostream>
#include <fstream>

#include "Lexer/Lexer.hpp"
#include "Parser/Parser.hpp"
#include "Evaluator/Evaluator.hpp"


template<typename T>
void compile(T source) {
	try {
		Lexer lexer(source);
		std::vector<Token> tokens = lexer.tokenize();
		
		std::cout << "\nTokens List: \n"; 
		for (Token token: tokens)
			std::cout << token.lexeme << " " << token.type << std::endl;

		std::cout << "\nAbstract Syntax Tree\n";
		Parser parser(tokens);
		std::vector<std::unique_ptr<Node>> nodes = parser.parse();

		Evaluator eval;

		for (unsigned long int i = 0; i < nodes.size(); i++)
			eval.evaluate(nodes[i].get());

	} catch (std::string& error) {
		std::cout << error << std::endl;
	}
}

//Init compiler with repl
void initRepl() {
	int tries = 0;
	while (tries++ < 5) {
		char* source = new char[1094];
		std::cout << "\n> ";
		std::cin.getline(source, 1094);
		compile(source);
	}
}

//Init compiler with file 
void initCompilerWithFile(std::string& filePath) {
	compile(filePath);
}

int main() {
	initRepl();
}
