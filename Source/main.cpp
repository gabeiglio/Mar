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

int main() {
    try {
        Lexer lexer("/Users/gabeiglio/Desktop/Developer/Mar/Tests/Test3.mar");
        std::vector<Token> tokens = lexer.tokenize();

        Parser parser(tokens);
        std::vector<std::unique_ptr<Node>> nodes = parser.parse();

        Evaluator eval;

        for (unsigned long int i = 0; i < nodes.size(); i++)
            eval.evaluate(nodes[i].get());
    } catch (std::string& err) {
        std::cout << err << std::endl;
    }
    
}
