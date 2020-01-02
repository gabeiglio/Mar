//
//  SymbolTable.cpp
//  Mar
//
//  Created by Gabriel Igliozzi on 11/14/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#include "SymbolTable.hpp"

void SymbolTable::insert(int lineNumber, std::string &identifier, TokenType type) {
    
    if (entries.find(identifier) != entries.end())
        throw "[Error] Already declared entry";
    
    Symbol data {identifier, lineNumber, type};
    entries.insert({identifier, data});
}

Symbol SymbolTable::lookup(std::string &identifier) {
    if (entries.find(identifier) == entries.end())
        throw "Error, symbol not found";
    
    return entries.find(identifier)->second;
}
