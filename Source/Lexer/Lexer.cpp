//
//  Lexer.cpp
//  Mar
//
//  Created by Gabriel Igliozzi on 11/13/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#include "Lexer.hpp"

Lexer::Lexer(std::string& sourceFile) {
    
    //Open and check file
    file.open(sourceFile, std::ifstream::binary);
    if (!file.is_open()) throw "[ERROR] Source file could not be opened";
    
    //Dont know what is seekg
    file.seekg(0, file.end);
    fileSize = file.tellg();
    file.seekg(0, file.beg);
    
    //Load buffers
    file.read(buffer1, chunkSize);
    file.read(buffer2, chunkSize);
    
    //Load pointers
    lexemeBegin = buffer1;
    forward = buffer1;
    
}

//Construct with direct source code
Lexer::Lexer(char* sourceCode) {
	//Load buffer
	buffer1 = sourceCode;
	
	//Load pointers
	lexemeBegin = buffer1;
	forward = buffer1;
}

Lexer::~Lexer() {
    file.close();
    delete[] buffer1;
    delete[] buffer2;
}

//Advance the forward pointer by default argument 1, though it can be more
void Lexer::advance(int by) {
    for (int i = 0; i < by; i++)
        ++forward;
}

void Lexer::retract() {
    --forward;
}

//Peek next character without incrementing the original pointer
char Lexer::peek() {
    char* val = forward;
    return *++val;
}

//Return token if not null
Token Lexer::parseNumber() {
    std::string result;
    TokenType type = TokenType::intLiteral;
    
    while (isdigit(*forward) || *forward == '.') {
        if (*forward == '.') type = TokenType::doubleLiteral;
        result += *forward;
        advance();
    }
    
    return Token {type, result};
}

//Return identifier or keyword token, if not null
Token Lexer::parseIdentifierOrKeyword() {
    std::string lexeme;
    
    while (isalpha(*forward) || *forward == '_' || isdigit(*forward)) {
        lexeme += *forward;
        advance();
    }
   
	//If true then the lexeme is not a reserved word therefore is an identifier
    if (keywords.find(lexeme) == keywords.end())
        return Token {TokenType::identifier, lexeme};
    
    //Lexeme was found in the reserved words
    return Token {keywords.find(lexeme)->second, lexeme};
}

//Omit single line and multiline comments
//return true if it is a comment and false if is not a comment
//Comments need some kind of exception if the multiline comments does not close
bool Lexer::readComment() {
    if (peek() != '/' && peek() != '*') return false;
    
    //Read single line comments
    if (peek() == '/') {
        while (peek() != '\n') advance();
        lineNumber++;
        advance();
    }
    
    //Read multiline comments
    if (peek() == '*') {
        advance(2);
        while (*forward != '*' || peek() != '/') {
            if (*forward == '\0') throw "[ERROR] Comment at line: " + std::to_string(lineNumber) + " was not closed";
            if (*forward == '\n') lineNumber++;
            advance();
        }
        advance(2);
    }
    return true;
}

//Parse string literal
Token Lexer::parseStringLiteral() {
    advance();
    std::string result;
    while (*forward != '"') {
        if (*forward == '\0') throw "[Error] String at line: " + std::to_string(lineNumber) + " was not closed";
        result += *forward++;
    }
    return Token {TokenType::stringLiteral, result};
}


std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    
    while (*forward != '\0') {
        switch (*forward) {
			case '\n': lineNumber++; break;
            case '{': tokens.push_back(Token {TokenType::openBrace, std::string(1, *forward)}); break;
            case '}': tokens.push_back(Token {TokenType::closeBrace, std::string(1, *forward)}); break;
            case '(': tokens.push_back(Token {TokenType::openParen, std::string(1, *forward)}); break;
            case ')': tokens.push_back(Token {TokenType::closeParen, std::string(1, *forward)}); break;
            case '=':
                
                if (peek() == '=') {
                    advance();
                    tokens.push_back(Token {TokenType::doubleEqual, "=="});
                } else tokens.push_back(Token {TokenType::equal, std::string(1, *forward)});
                
                break;
            case '<':
                
                if (peek() == '=') {
                    advance();
                    tokens.push_back(Token {TokenType::leftEqual, "<="});
                } else tokens.push_back(Token {TokenType::arrowLeft, std::string(1, *forward)});
                
                break;
            case '>':
                
                if (peek() == '=') {
                    advance();
                    tokens.push_back(Token {TokenType::rightEqual, ">="});
                } else tokens.push_back(Token {TokenType::arrowRight, std::string(1, *forward)});
                
                break;
            case '!':
                
                if (peek() == '=') {
                    advance();
                    tokens.push_back(Token {TokenType::notEqual, "!="});
                } else tokens.push_back(Token {TokenType::notOperator, std::string(1, *forward)});
                
                break;
            case '"': tokens.push_back(parseStringLiteral()); break;
            case ',': tokens.push_back(Token {TokenType::comma, std::string(1, *forward)}); break;
            case '.': tokens.push_back(Token {TokenType::point, std::string(1, *forward)}); break;
            case '+': tokens.push_back(Token {TokenType::plus, std::string(1, *forward)}); break;
            case '-': tokens.push_back(Token {TokenType::hyphen, std::string(1, *forward)}); break;
            case '/':
                //Decide if it is a comment or just a slash
                if (!readComment())
                    tokens.push_back(Token {TokenType::slash, std::string(1, *forward)});
                break;
            case '*': tokens.push_back(Token {TokenType::star, std::string(1, *forward)}); break;
            case '^': tokens.push_back(Token {TokenType::pow, std::string(1, *forward)}); break;
            case '%': tokens.push_back(Token {TokenType::mod, std::string(1, *forward)}); break;
            case '|':
                if (peek() == '|') {
                    tokens.push_back(Token {TokenType::orOperator, "||"});
                    advance();
                } else throw "[Error] Unexpected Token '" + std::string(1, *forward) + "' at line: " + std::to_string(lineNumber);
                break;
            case '&':
                if (peek() == '&') {
                    tokens.push_back(Token {TokenType::andOperator, "&&"});
                    advance();
                } else throw "[Error] Unexpected Token '" + std::string(1, *forward) + "' at line: " + std::to_string(lineNumber);
                break;
        }
		
		advance();

        //Look for numbers
        if (isdigit(*forward))
            tokens.push_back(parseNumber());
        
        //Look for identifiers / keywords
        if (isalpha(*forward) || *forward == '_')
            tokens.push_back(parseIdentifierOrKeyword());
       
    }
    
    return tokens;
}
