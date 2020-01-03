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

		std::cout << "\n Abstract Syntax Tree\n";
		Parser parser(tokens);
		std::vector<std::unique_ptr<Node>> nodes = parser.parse();

		Evaluator eval;

		for (unsigned long int i = 0; i < nodes.size(); i++)
			eval.evaluate(nodes[i].get());

	} catch (std::string& error) {
		std::cout << error << std::endl;
	}
}

void initReplWithSource(char* source) {
	while (strcmp(source, "#stop"))  
		compile(source);
}

int main() {

//	char* code = new char[1094];
	std::string filePath = "/Users/gabeiglio/Desktop/Developer/Mar/Tests/Declarations.mar";
//	std::cin >> code;
//	initReplWithSource(filePath);	
	compile(filePath);
//	delete[] code;
}
