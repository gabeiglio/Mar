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
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Lexer/Token.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Evaluator/Visitor/Visitor.hpp"

#endif /* Expr_hpp */

//Parent Node of Expr, Stmt, Decl
struct Node {
    virtual ~Node() {};
    virtual void accept(Visitor& visitor) = 0;
};

struct Expr: public Node {
    virtual ~Expr() {};
};

struct IdentifierExpr: public Expr {
    std::string lexeme;
    IdentifierExpr(std::string& lexeme): lexeme(lexeme) {}
    
    virtual void accept(Visitor& visitor) { visitor.visit(*this); }

};

struct IntegerExpr: public Expr {
    int lexeme;
    IntegerExpr(int lexeme): lexeme(lexeme) {}
    
    virtual void accept(Visitor& visitor) { visitor.visit(*this); }

};

struct DoubleExpr: public Expr {
    double lexeme;
    DoubleExpr(double lexeme): lexeme(lexeme) {}
    
    virtual void accept(Visitor& visitor) { visitor.visit(*this); }

};

struct StringExpr: public Expr {
    std::string lexeme;
    StringExpr(std::string& lexeme): lexeme(lexeme) {}
    
    virtual void accept(Visitor& visitor) { visitor.visit(*this); }

};

struct BoolExpr: public Expr {
    bool lexeme;
    BoolExpr(bool lexeme): lexeme(lexeme) {}
    
    virtual void accept(Visitor& visitor) { visitor.visit(*this); }

};

struct CharExpr: public Expr {
    char lexeme;
    CharExpr(char lexeme): lexeme(lexeme) {}
    
    virtual void accept(Visitor& visitor) { visitor.visit(*this); }

};

struct UnaryExpr: public Expr {
    TokenType op;
    std::unique_ptr<Expr> expr;
    UnaryExpr(TokenType op, std::unique_ptr<Expr> expr): op(op), expr(std::move(expr)) {}
    
    virtual void accept(Visitor& visitor) { visitor.visit(*this); }

};

struct CallExpr: public Expr {
    std::unique_ptr<IdentifierExpr> identifier;
    std::vector<std::unique_ptr<Expr>> arguments;
    CallExpr(std::unique_ptr<IdentifierExpr> identifier, std::vector<std::unique_ptr<Expr>> arguments): identifier(std::move(identifier)), arguments(std::move(arguments)) {}
    
    virtual void accept(Visitor& visitor) { visitor.visit(*this); }

};

struct AssignExpr: public Expr {
    std::unique_ptr<IdentifierExpr> identifier;
    std::unique_ptr<Expr> expr;
    AssignExpr(std::unique_ptr<IdentifierExpr>& identifier, std::unique_ptr<Expr> expr): identifier(std::move(identifier)), expr(std::move(expr)) {}
    
    virtual void accept(Visitor& visitor) { visitor.visit(*this); }

};


struct BinaryOpExpr: public Expr {
    std::unique_ptr<Expr> rhs;
    std::unique_ptr<Expr> lhs;
    TokenType op;
    BinaryOpExpr(std::unique_ptr<Expr>& rhs, std::unique_ptr<Expr> lhs, TokenType op): rhs(std::move(rhs)), lhs(std::move(lhs)), op(op) {}
    
    virtual void accept(Visitor& visitor) { visitor.visit(*this); }

};

