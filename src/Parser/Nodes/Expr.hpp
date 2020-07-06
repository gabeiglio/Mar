//
//  Expr.hpp
//  Mar
//
//  Created by Gabriel Igliozzi on 11/14/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#pragma once

#ifndef Expr_hpp
#define Expr_hpp

#include <string>
#include <vector>

#include "Lexer/Token.hpp"
#include "Evaluator/Visitor/Visitor.hpp"

//Parent Node of Expr, Stmt, Decl
struct Node {
    virtual ~Node() {};
    virtual void accept(Visitor<void>& visitor) = 0;
    
};

struct Expr: public Node {
    virtual ~Expr() {};
    virtual void accept(Visitor<void>& visitor) = 0;
    
};

struct IdentifierExpr: public Expr {
    std::string lexeme;
    std::string property;

    IdentifierExpr(std::string& lexeme): lexeme(lexeme) {}
    IdentifierExpr(std::string& lexeme, std::string& property): lexeme(lexeme), property(property) {}

    void accept(Visitor<void>& visitor) { visitor.visit(*this); }

};

struct IntegerExpr: public Expr {
    int lexeme;
    IntegerExpr(int lexeme): lexeme(lexeme) {}
    
    void accept(Visitor<void>& visitor) override { visitor.visit(*this); }

};

struct DoubleExpr: public Expr {
    double lexeme;
    DoubleExpr(double lexeme): lexeme(lexeme) {}
    
    void accept(Visitor<void>& visitor) { visitor.visit(*this); }

};

struct StringExpr: public Expr {
    std::string lexeme;
    StringExpr(std::string& lexeme): lexeme(lexeme) {}
    
    void accept(Visitor<void>& visitor) { visitor.visit(*this); }

};

struct BoolExpr: public Expr {
    bool lexeme;
    BoolExpr(bool lexeme): lexeme(lexeme) {}
    
    void accept(Visitor<void>& visitor) { visitor.visit(*this); }

};

struct CharExpr: public Expr {
    char lexeme;
    CharExpr(char lexeme): lexeme(lexeme) {}
    
    void accept(Visitor<void>& visitor) { visitor.visit(*this); }

};

struct UnaryExpr: public Expr {
    TokenType op;
    std::unique_ptr<Expr> expr;
    UnaryExpr(TokenType op, std::unique_ptr<Expr> expr): op(op), expr(std::move(expr)) {}
    
    void accept(Visitor<void>& visitor) { visitor.visit(*this); }

};

struct CallExpr: public Expr {
    std::unique_ptr<IdentifierExpr> identifier;
    std::vector<std::unique_ptr<Expr>> arguments;
    CallExpr(std::unique_ptr<IdentifierExpr> identifier, std::vector<std::unique_ptr<Expr>> arguments): identifier(std::move(identifier)), arguments(std::move(arguments)) {}
    
    void accept(Visitor<void>& visitor) { visitor.visit(*this); }

};

struct AssignExpr: public Expr {
    std::unique_ptr<IdentifierExpr> identifier;
    std::unique_ptr<Expr> expr;
    AssignExpr(std::unique_ptr<IdentifierExpr>& identifier, std::unique_ptr<Expr> expr): identifier(std::move(identifier)), expr(std::move(expr)) {}
    
    void accept(Visitor<void>& visitor) { visitor.visit(*this); }

};


struct BinaryOpExpr: public Expr {
    std::unique_ptr<Expr> rhs;
    std::unique_ptr<Expr> lhs;
    TokenType op;
    BinaryOpExpr(std::unique_ptr<Expr>& rhs, std::unique_ptr<Expr> lhs, TokenType op): rhs(std::move(rhs)), lhs(std::move(lhs)), op(op) {}
    
    void accept(Visitor<void>& visitor) { visitor.visit(*this); }

};

#endif /* Expr_hpp */
