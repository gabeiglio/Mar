#pragma once

#ifndef Decl_hpp
#define Decl_hpp

#include <vector>

#include "Expr.hpp"
#include "Stmt.hpp"
#include "Lexer/Token.hpp"
#include "Sema/Visitor/Visitor.hpp"

struct Decl: public Node {
    virtual ~Decl() {};
    virtual void accept(Visitor<void>& visitor) = 0;
};

struct ParamDecl: public Decl {
    std::unique_ptr<IdentifierExpr> name;
    TokenType type;
    ParamDecl(std::unique_ptr<IdentifierExpr>& name, TokenType type): name(std::move(name)), type(type) {}
    
    void accept(Visitor<void>& visitor) { visitor.visit(*this); }

};

struct VarDecl: public Decl {
    std::unique_ptr<IdentifierExpr> identifier;
    TokenType type;
    std::unique_ptr<Expr> expr;
    VarDecl(std::unique_ptr<IdentifierExpr>& identifier, TokenType type, std::unique_ptr<Expr> expr):
        identifier(std::move(identifier)), type(type), expr(std::move(expr)) {}
    
    void accept(Visitor<void>& visitor) { visitor.visit(*this); }

};

struct ConstDecl: public Decl {
    std::unique_ptr<IdentifierExpr> identifier;
    TokenType type;
    std::unique_ptr<Expr> expr;
    ConstDecl(std::unique_ptr<IdentifierExpr>& identifier, TokenType type, std::unique_ptr<Expr> expr):
        identifier(std::move(identifier)), type(type), expr(std::move(expr)) {}
    
    void accept(Visitor<void>& visitor) { visitor.visit(*this); }

};

struct FuncDecl: public Decl {
    std::unique_ptr<IdentifierExpr> identifier;
    std::vector<std::unique_ptr<ParamDecl>> params;
    TokenType type;
    std::unique_ptr<Block> body;
    FuncDecl(std::unique_ptr<IdentifierExpr>& identifier, std::vector<std::unique_ptr<ParamDecl>>& params, TokenType type, std::unique_ptr<Block>& body):
        identifier(std::move(identifier)), params(std::move(params)), type(type), body(std::move(body)) {}
    
    virtual void accept(Visitor<void>& visitor) { visitor.visit(*this); }

};

struct ClassDecl: public Decl {
    std::unique_ptr<IdentifierExpr> identifier;
    std::unique_ptr<Block> body;
    ClassDecl(std::unique_ptr<IdentifierExpr>& identifier, std::unique_ptr<Block> body): identifier(std::move(identifier)), body(std::move(body)) {}
    
    void accept(Visitor<void>& visitor) { visitor.visit(*this); }

};

struct StructDecl: public Decl {
    std::unique_ptr<IdentifierExpr> identifier;
    std::unique_ptr<Block> body;
    StructDecl(std::unique_ptr<IdentifierExpr>& identifier, std::unique_ptr<Block> body): identifier(std::move(identifier)), body(std::move(body)) {}

    void accept(Visitor<void>& visitor) { visitor.visit(*this); }
};

#endif /* Decl_hpp */
