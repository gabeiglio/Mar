//
//  Lexer.hpp
//  Mar
//
//  Created by Gabriel Igliozzi on 11/13/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#ifndef Lexer_hpp
#define Lexer_hpp

#include <fstream>
#include <iostream>
#include <vector>
#include <map>

#include "Token.hpp"

#endif /* Lexer_hpp */

class Lexer {
private:
    
    //Constants
    const ssize_t chunkSize = 1094;
    
    //Properties to initialize
    std::ifstream file;
    long long fileSize;
    
    //Track line number
    unsigned int lineNumber = 1;
    
    //Allocate buffers
    char* buffer1 = new char[chunkSize];
    char* buffer2 = new char[chunkSize];
    
    //Pointers to read the buffers
    char* lexemeBegin;
    char* forward;
    
    //Helper methods
    void advance(int by = 1);
    void retract();
    char peek();
    
    //Parsing helper methods
    Token parseNumber();
    Token parseIdentifierOrKeyword();
    Token parseStringLiteral();
    bool  readComment();
    
    //Reserved Keywords
    std::map<std::string, TokenType> keywords = {
        {"var", TokenType::varKey}, {"const", TokenType::constKey}, {"if", TokenType::ifKey}, {"else", TokenType::elseKey},
        {"int", TokenType::intType}, {"double", TokenType::doubleType}, {"bool", TokenType::boolType}, {"char", TokenType::charType},
        {"string", TokenType::stringType}, {"void", TokenType::voidType}, {"for", TokenType::forKey}, {"in", TokenType::inKey},  {"true", TokenType::boolLiteral}, {"false", TokenType::boolLiteral}, {"func", TokenType::funcKey}, {"class", TokenType::classKey}, {"nil", TokenType::nilLiteral}, {"while", TokenType::whileKey}, {"return", TokenType::returnKey}
    };

public:

	//Construct with filepath
    Lexer(std::string& sourceFile);

	//Construct with small source code (REPL)
	Lexer(char* sourceCode);

    ~Lexer();
    std::vector<Token> tokenize();
};
