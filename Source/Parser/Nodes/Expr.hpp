//
//  Expr.hpp
//  Mar
//
//  Created by Gabriel Igliozzi on 11/14/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#pragma once
#ifndef Node_hpp
#define Node_hpp

#include <string>
#include <vector>

#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Lexer/Token.hpp"

#endif /* Expr_hpp */

//Parent Node of Everything
struct Node {
    virtual ~Node() {};
};

struct Expr: public Node {
    virtual ~Expr() {};
};

struct IdentifierExpr: public Expr {
    std::string lexeme;
    IdentifierExpr(std::string& lexeme): lexeme(lexeme) {}
};

struct IntergerExpr: public Expr {
    int lexeme;
    IntergerExpr(int lexeme): lexeme(lexeme) {}
};

struct DoubleExpr: public Expr {
    double lexeme;
    DoubleExpr(double lexeme): lexeme(lexeme) {}
};

struct StringExpr: public Expr {
    std::string lexeme;
    StringExpr(std::string& lexeme): lexeme(lexeme) {}
};

struct BoolExpr: public Expr {
    bool lexeme;
    BoolExpr(bool lexeme): lexeme(lexeme) {}
};

struct CharExpr: public Expr {
    char lexeme;
    CharExpr(char lexeme): lexeme(lexeme) {}
};

struct UnaryExpr: public Expr {
    TokenType op;
    std::unique_ptr<Expr> expr;
    UnaryExpr(TokenType op, std::unique_ptr<Expr> expr): op(op), expr(std::move(expr)) {}
};

struct CallExpr: public Expr {
    std::unique_ptr<IdentifierExpr> identifier;
    std::vector<std::unique_ptr<Expr>> arguments;
    CallExpr(std::unique_ptr<IdentifierExpr> identifier, std::vector<std::unique_ptr<Expr>> arguments): identifier(std::move(identifier)), arguments(std::move(arguments)) {}
};

struct AssignExpr: public Expr {
    std::unique_ptr<IdentifierExpr> identifier;
    std::unique_ptr<Expr> expr;
    AssignExpr(std::unique_ptr<IdentifierExpr>& identifier, std::unique_ptr<Expr> expr): identifier(std::move(identifier)), expr(std::move(expr)) {}
};


struct BinaryOpExpr: public Expr {
    std::unique_ptr<Expr> rhs;
    std::unique_ptr<Expr> lhs;
    TokenType op;
    BinaryOpExpr(std::unique_ptr<Expr>& rhs, std::unique_ptr<Expr> lhs, TokenType op): rhs(std::move(rhs)), lhs(std::move(lhs)), op(op) {}
};
