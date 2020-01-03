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
		
		for (Token token: tokens)
			std::cout << token.lexeme << " " << token.type;

		Parser parser(tokens);
		std::vector<std::unique_ptr<Node>> nodes = parser.parse();

		Evaluator eval;

		for (unsigned long int i = 0; i < nodes.size(); i++)
			eval.evaluate(nodes[i].get());

	} catch (std::string& error) {
		std::cout << error << std::endl;
	}
}

void initReplWithSource(const char* source) {
	while (strcmp(source, "#stop"))  
		compile(source);
}

int main() {
	std::string code = "var age int = 19";
	initReplWithSource(code);	
}
