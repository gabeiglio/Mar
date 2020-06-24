#pragma once

#ifndef SymbolTable_hpp
#define SymbolTable_hpp

#include "/Users/gabeiglio/Desktop/Developer/Mar/src/Lexer/Token.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/src/Parser/Nodes/Decl.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/src/Parser/Nodes/Expr.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/src/Parser/Nodes/Stmt.hpp"
#include <map>

struct Symbol {
    std::string identifier;
    TokenType type;
    bool isConstant;
	Node* value;

	Symbol(const std::string& identifier, TokenType type, bool isConstant, Node*  value):
		identifier(identifier), type(type), isConstant(isConstant), value(value) {}
};

class SymbolTable {
private:
	std::map<std::string, Symbol> symbols;
    SymbolTable* enclosing; //parent scope
    
    //Debug only
    std::vector<SymbolTable*> children;
    

public:
	void define(const std::string& identifier, TokenType type, bool isConstant, Node* value);
    void assign(const std::string& identifier, Node* value);
    void setEnclosing(SymbolTable* enclosing);
    
    Symbol* get(const std::string& identifier);
    SymbolTable* getEnclosing();
};

#endif
