#include "SymbolTable.hpp"
#include <iostream>

void SymbolTable::define(const std::string& identifier, TokenType type, Node*  value) {
	std::pair<std::string, Symbol> entry {identifier, Symbol {identifier, type, value}};	
	
	//Check if symbol is already declared
	if (symbols.find(identifier) == symbols.end()) {
		symbols.insert(entry);
		return;
	}

	throw "[ERROR] '" + identifier + "' is already declared";	
}

void SymbolTable::assign(const std::string& identifier, Node* value) {
    Symbol* node = get(identifier);
    
    if (node->type == TokenType::constKey)
        throw "[ERROR] Trying to assign a value to constant '" + identifier + "'";

    node->value = value;
}

Symbol* SymbolTable::get(const std::string& identifier) {
	if (symbols.find(identifier) == symbols.end())
	   throw "[ERROR] Symbol '" + identifier + "' not found";	
	
	return &symbols.find(identifier)->second;
}

void SymbolTable::showAllSymbols() {
	for (auto const& [key, val]: symbols) {
		std::cout << " " << val.identifier << " | " << val.type << " | " << val.value << " | \n" << std::endl;
	}
}
