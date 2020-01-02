//
//  Stmt.hpp
//  Mar
//
//  Created by Gabriel Igliozzi on 12/3/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#pragma once

#ifndef Stmt_h
#define Stmt_h

#include "Expr.hpp"
#include <vector>

#endif /* Stmt_h */

//Init here in order to use in stmts //find a better way?
struct Block;

struct Stmt: public Node {
    virtual ~Stmt() {};
};

struct ExprStmt: public Stmt {
    std::unique_ptr<Expr> expr;
    ExprStmt(std::unique_ptr<Expr> expr): expr(std::move(expr)) {}
};

struct IfStmt: public Stmt {
    std::unique_ptr<Expr> expr;
    std::unique_ptr<Block> block;
    IfStmt(std::unique_ptr<Expr> expr, std::unique_ptr<Block> block): expr(std::move(expr)), block(std::move(block)) {}
};

struct WhileStmt: public Stmt {
    std::unique_ptr<Expr> expr;
    std::unique_ptr<Block> block;
    WhileStmt(std::unique_ptr<Expr> expr, std::unique_ptr<Block> block): expr(std::move(expr)), block(std::move(block)) {}
};

struct ReturnStmt: public Stmt {
    std::unique_ptr<Expr> expr;
    ReturnStmt(std::unique_ptr<Expr> expr): expr(std::move(expr)) {}
};

//Block structure
struct Block: public Node {
    std::vector<std::unique_ptr<Node>> nodes;
    Block(std::vector<std::unique_ptr<Node>>& nodes): nodes(std::move(nodes)) {}
};
