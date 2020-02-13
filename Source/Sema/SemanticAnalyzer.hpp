
#ifndef SemanticAnalyzer_hpp
#define SemanticAnalyzer_hpp

#import <vector>

#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Lexer/Token.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Parser/Nodes/Decl.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Parser/Nodes/Expr.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Parser/Nodes/Stmt.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Evaluator/Visitor/Visitor.hpp"
#include "SymbolTable/SymbolTable.hpp"
#include <iostream>

#endif

#pragma once

class SemanticAnalyzer: Visitor {
private:
    std::vector<std::unique_ptr<Node>> nodes;
    SymbolTable* enviroment = new SymbolTable();
        
public:
    
    void performAnalysis();
    SemanticAnalyzer(std::vector<std::unique_ptr<Node>> nodes): nodes(std::move(nodes)) {}
     
};
