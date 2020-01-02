//
//  SymbolTable.hpp
//  Mar
//
//  Created by Gabriel Igliozzi on 11/14/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#ifndef SymbolTable_hpp
#define SymbolTable_hpp

#include <stdio.h>
#include <string>
#include <map>

#include "Symbol.hpp"

#endif /* SymbolTable_hpp */

class SymbolTable {
private:
    std::map<std::string, Symbol> entries;
    
public:
    Symbol lookup(std::string& identifier);
    void insert(int lineNumber, std::string& identifier, TokenType type);
    
};
