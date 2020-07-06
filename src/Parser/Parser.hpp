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
#include "Lexer/Token.hpp"

class Parser {
private:
    std::vector<Token> tokens;
	unsigned long int index = 0;

    //Expressions
    std::unique_ptr<Expr> parsePrimaryExpr();
    std::unique_ptr<Expr> parseCallOrAssignmentExpr();
    std::unique_ptr<Expr> parseUnaryExpr();
    std::unique_ptr<Expr> parseTermExpr();
    std::unique_ptr<Expr> parseSumExpr();
    std::unique_ptr<Expr> parseRelationalExpr();
    std::unique_ptr<Expr> parseAndLogicalExpr();
    std::unique_ptr<Expr> parseOrLogicalExpr();
    
    //Statements
    std::unique_ptr<Stmt> parseExprStmt();
    std::unique_ptr<Stmt> parseReturnStmt();
    std::unique_ptr<Stmt> parseIfStmt();
    std::unique_ptr<Stmt> parseWhileStmt();
    std::unique_ptr<Stmt> parseForInStmt();

    //Parse block
    std::unique_ptr<Block> parseBlock();
    
    //Declarations
    std::unique_ptr<Decl> parseVariableDecl();
    std::unique_ptr<Decl> parseConstDecl();
    std::unique_ptr<Decl> parseFuncDecl();
    std::unique_ptr<Decl> parseClassDecl();
    std::unique_ptr<Decl> parseStructDecl();

    //Consume a token if current token != type an exception is thrown
    void consume(TokenType type);
    std::vector<std::unique_ptr<Expr>> parseArgumentList();
    std::vector<std::unique_ptr<ParamDecl>> parseParameterList();
    
    
public:
    Parser(std::vector<Token>& tokens): tokens(tokens) {}
    std::vector<std::unique_ptr<Node>> parse();

};

#endif /* Parser_hpp */
