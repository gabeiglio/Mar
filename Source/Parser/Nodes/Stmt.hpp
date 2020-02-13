//
//  Stmt.hpp
//  Mar
//
//  Created by Gabriel Igliozzi on 12/3/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#pragma once

#ifndef Stmt_hpp
#define Stmt_hpp

#include <vector>
#include "Expr.hpp"

#endif /* Stmt_h */

struct Block;

struct Stmt: public Node {
    virtual ~Stmt() {};
};

struct ExprStmt: public Stmt {
    std::unique_ptr<Expr> expr;
    ExprStmt(std::unique_ptr<Expr> expr): expr(std::move(expr)) {}
    
    virtual void accept(Visitor& visitor) { visitor.visit(*this); }
};

struct IfStmt: public Stmt {
    std::unique_ptr<Expr> expr;
    std::unique_ptr<Block> block;
    IfStmt(std::unique_ptr<Expr> expr, std::unique_ptr<Block> block): expr(std::move(expr)), block(std::move(block)) {}
    
    virtual void accept(Visitor& visitor) { visitor.visit(*this); }

};

struct WhileStmt: public Stmt {
    std::unique_ptr<Expr> expr;
    std::unique_ptr<Block> block;
    WhileStmt(std::unique_ptr<Expr> expr, std::unique_ptr<Block> block): expr(std::move(expr)), block(std::move(block)) {}
    
    virtual void accept(Visitor& visitor) { visitor.visit(*this); }

};

struct ForInStmt: public Stmt {
	std::unique_ptr<IdentifierExpr> identifier;
	std::unique_ptr<Expr> range;
	std::unique_ptr<Block> block;

	ForInStmt(std::unique_ptr<IdentifierExpr>& identifier, std::unique_ptr<Expr> range, std::unique_ptr<Block> block):
		identifier(std::move(identifier)), range(std::move(range)), block(std::move(block)) {}
    
    virtual void accept(Visitor& visitor) { visitor.visit(*this); }

};

struct ReturnStmt: public Stmt {
    std::unique_ptr<Expr> expr;
    ReturnStmt(std::unique_ptr<Expr> expr): expr(std::move(expr)) {}
    
    virtual void accept(Visitor& visitor) { visitor.visit(*this); }

};

//Block structure
struct Block: public Node {
    std::vector<std::unique_ptr<Node>> nodes;
    Block(std::vector<std::unique_ptr<Node>>& nodes): nodes(std::move(nodes)) {}
    
    virtual void accept(Visitor& visitor) { visitor.visit(*this); }
};
