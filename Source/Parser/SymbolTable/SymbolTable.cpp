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
    //Additional check to not go out of bounds in memory
    if (symbols.find(identifier) == symbols.end()) {
        //Search in enclosing scopes recursively
        if (enclosing != nullptr) return enclosing->get(identifier);
        else throw "[ERROR] Symbol '" + identifier + "' not found";
    }
    
    //Now actually get the symbol from the table
    if (Symbol* value = &symbols.find(identifier)->second)
        return value;
    
    throw "[ERROR] Symbol '" + identifier + "' not found";
}

void SymbolTable::setEnclosing(SymbolTable* enclosing) {
    children.push_back(enclosing);
    this->enclosing = enclosing;
}

void SymbolTable::showAllSymbols() {
	for (auto const& [key, val]: symbols)
		std::cout << " " << val.identifier << " | " << val.type << " | " << val.value << " | \n" << std::endl;
    
    std::cout << "--------------------------" << std::endl;
    
    for (auto result: children)
        for (auto const& [key, val]: symbols)
            std::cout << " " << val.identifier << " | " << val.type << " | " << val.value << " | \n" << std::endl;
    
    if (enclosing != nullptr)
        enclosing->showAllSymbols();
    
}
