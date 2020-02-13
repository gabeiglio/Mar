//
//  Parser.hpp
//  Mar
//
//  Created by Gabriel Igliozzi on 11/14/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include <stdio.h>
#include <vector>

#include "Nodes/Expr.hpp"
#include "Nodes/Stmt.hpp"
#include "Nodes/Decl.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Lexer/Token.hpp"
#include "SymbolTable/SymbolTable.hpp"

#endif /* Parser_hpp */

class Parser {
private:
    std::vector<Token> tokens;
	unsigned long int index = 0;
   
	//Declare symbol table for use in the parsing step
	SymbolTable enviroment = SymbolTable();

    //Expressions
    std::unique_ptr<Expr> parsePrimaryExpr();
    std::unique_ptr<Expr> parseCallOrAssignmentExpr(SymbolTable* enviroment);
    std::unique_ptr<Expr> parseUnaryExpr();
    std::unique_ptr<Expr> parseTermExpr();
    std::unique_ptr<Expr> parseSumExpr();
    std::unique_ptr<Expr> parseRelationalExpr();
    std::unique_ptr<Expr> parseAndLogicalExpr();
    std::unique_ptr<Expr> parseOrLogicalExpr();
    
    //Statements
    std::unique_ptr<Stmt> parseExprStmt();
    std::unique_ptr<Stmt> parseReturnStmt();
    std::unique_ptr<Stmt> parseIfStmt(SymbolTable* enviroment);
    std::unique_ptr<Stmt> parseWhileStmt(SymbolTable* enviroment);
	std::unique_ptr<Stmt> parseForInStmt(SymbolTable* enviroment);

    //Parse block
    std::unique_ptr<Block> parseBlock(SymbolTable* enviroment);
    
    //Declarations
    std::unique_ptr<Decl> parseVariableDecl(SymbolTable* enviroment);
    std::unique_ptr<Decl> parseConstDecl(SymbolTable* enviroment);
    std::unique_ptr<Decl> parseFuncDecl(SymbolTable* enviroment);
    std::unique_ptr<Decl> parseClassDecl(SymbolTable* enviroment);
        
    //Consume a token if current token != type an exception is thrown
    void consume(TokenType type);
    std::vector<std::unique_ptr<Expr>> parseArgumentList();
    std::vector<std::unique_ptr<ParamDecl>> parseParameterList();
    
    
public:
    Parser(std::vector<Token>& tokens): tokens(tokens) {}
    std::vector<std::unique_ptr<Node>> parse();

	//Debug
	void showAllDeclarations();
};
