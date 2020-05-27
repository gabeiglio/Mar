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
#include "Evaluator/ASTVisualizer.hpp"
#include "Sema/SemanticAnalyzer.hpp"
#include "Sema/SymbolTable/SymbolTable.hpp"
#include "Codegen/Codegen.hpp"

template<typename T>
void compile(T source) {
	try {
		Lexer lexer(source);
		std::vector<Token> tokens = lexer.tokenize();
		
		std::cout << "\n***** Tokens List: *****\n \n"; 
		for (Token token: tokens)
			std::cout << " " << token.lexeme << " " << token.type << std::endl;

		std::cout << "\n***** Abstract Syntax Tree *****\n\n";
		Parser parser(tokens);
		std::vector<std::unique_ptr<Node>> nodes = parser.parse();
        
        //AST Node visualizator
		ASTVisualizer visual;
        visual.evaluate(nodes);

        //Create global symbol table
        SymbolTable* enviroment = new SymbolTable();
        SemanticAnalyzer sema(nodes);
        sema.performAnalysis(enviroment);
        
        std::cout << "\n***** IR Code Generation *****\n\n";
        
        //Code generation
        std::cout << nodes.size() << std::endl;
        Codegen codegen(nodes, enviroment);
        codegen.generate();
        //std::cout << "Codegen: " << nodes.size() << std::endl;

        
        
    } catch (const char* error) {
        std::cerr << error << std::endl;
    } catch (const std::string& error) {
        std::cerr << error << std::endl;
    }
}

//Init compiler with repl
void initRepl() {
	while (true) {
		char* source = new char[1094];
		std::cout << "\n> ";
		std::cin.getline(source, 1094);

		if (!strcmp(source, "#stop")) 
			return;

		compile(source);
	}
}

//Init compiler with file 
void initCompilerWithFile(std::string& filePath) {
	compile(filePath);
}

int main(int argc, char* argv[]) {
	if (argc == 2) {
		if (!strcmp(argv[1], "--repl")) initRepl();
		else {
			std::ifstream test(argv[1]);
			if (!test) {
			   	std::cout << "[ERROR] File does not exist" << std::endl;
			   	return 1;
			}
			std::string path (argv[1]);
			initCompilerWithFile(path);
		}
	}
}
