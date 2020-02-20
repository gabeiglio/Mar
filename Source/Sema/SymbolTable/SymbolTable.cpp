#include "SymbolTable.hpp"

void SymbolTable::define(const std::string& identifier, TokenType type, bool isConstant, Node*  value) {
	std::pair<std::string, Symbol> entry {identifier, Symbol {identifier, type, isConstant, value}};	
	
	//Check if symbol is already declared
	if (symbols.find(identifier) == symbols.end()) {
		symbols.insert(entry);
		return;
	}

	throw "[ERROR] '" + identifier + "' is already declared";	
}

void SymbolTable::assign(const std::string& identifier, Node* value) {
    Symbol* node = get(identifier);
        
    if (node->isConstant)
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
    //Add to the pass enclosing one (the parent table)
    enclosing->children.push_back(this);
    this->enclosing = enclosing;
}

SymbolTable* SymbolTable::getEnclosing() {
    return enclosing;
}
