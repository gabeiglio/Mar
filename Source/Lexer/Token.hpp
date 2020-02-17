//
//  Token.hpp
//  Mar
//
//  Created by Gabriel Igliozzi on 11/14/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#pragma once

#ifndef Token_h
#define Token_h

#include <string>

enum TokenType {
    
    identifier,
    
    //Separators
    openParen, closeParen, comma, point, openBrace, closeBrace, openBracket, closeBracket,
    
    //Operators
    star, hyphen, slash, plus, pow, mod,
    equal, doubleEqual, arrowLeft, arrowRight, leftEqual, rightEqual, notEqual, notOperator, andOperator, orOperator,
    
    //Type literal
    intLiteral, stringLiteral, charLiteral, boolLiteral, doubleLiteral, nilLiteral,
    
    //Types (when you declare)
    intType, stringType, charType, boolType, doubleType, voidType,
    
    //Keywords
    varKey, constKey, ifKey, elseKey, funcKey, classKey, whileKey, returnKey, forKey, inKey
    
};

struct Token {
    TokenType type;
    std::string lexeme;
    
    bool isType() {
        switch (type) {
            case 31:
            case 32:
            case 33:
            case 34:
            case 35:
            case 36: return true;
            default: return false;
        }
    }
};

#endif /* Token_hpp */
