#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Lexer/Token.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Parser/Nodes/Decl.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Parser/Nodes/Expr.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Parser/Nodes/Stmt.hpp"
#include <map>

#pragma once

struct Symbol {
	const std::string identifier;
	TokenType type;
	Node* value;

	Symbol(const std::string& identifier, TokenType type, Node*  value):
		identifier(identifier), type(type), value(value) {}
};

class SymbolTable {
private:
	std::map<std::string, Symbol> symbols;
    SymbolTable* enclosing; //parent scope
    
    //Debug only
    std::vector<SymbolTable*> children;
    
    //Helper method
    Symbol* get(const std::string& identifier);

public:
	void define(const std::string& identifier, TokenType type, Node* value);
    void assign(const std::string& identifier, Node* value);
    void setEnclosing(SymbolTable* enclosing);
    
    //Debug
    void showAllSymbols();
};

