#pragma once

#ifndef Visitor_hpp
#define Visitor_hpp

//Expressions
struct IdentifierExpr;
struct IntegerExpr;
struct DoubleExpr;
struct StringExpr;
struct CharExpr;
struct BoolExpr;
struct UnaryExpr;
struct BinaryOpExpr;
struct CallExpr;
struct AssignExpr;

//Statements
struct ExprStmt;
struct IfStmt;
struct WhileStmt;
struct ForInStmt;
struct ReturnStmt;

//Declarations
struct ParamDecl;
struct VarDecl;
struct ConstDecl;
struct FuncDecl;
struct ClassDecl;

//Block
struct Block;

template <typename T>
struct Visitor {
    
    //Expr
    virtual T visit(IdentifierExpr& expr) = 0;
    virtual T visit(IntegerExpr& expr) = 0;
    virtual T visit(DoubleExpr& expr) = 0;
    virtual T visit(StringExpr& expr) = 0;
    virtual T visit(CharExpr& expr) = 0;
    virtual T visit(BoolExpr& expr) = 0;
    virtual T visit(UnaryExpr& expr) = 0;
    virtual T visit(BinaryOpExpr& expr) = 0;
    virtual T visit(CallExpr& expr) = 0;
    virtual T visit(AssignExpr& expr) = 0;
    
    //Stmt
    virtual T visit(ExprStmt& stmt) = 0;
    virtual T visit(IfStmt& stmt) = 0;
    virtual T visit(WhileStmt& stmt) = 0;
    virtual T visit(ForInStmt& stmt) = 0;
    virtual T visit(ReturnStmt& stmt) = 0;
    
    //Block
    virtual T visit(Block& block) = 0;
    
    //Decl
    virtual T visit(ParamDecl& decl) = 0;
    virtual T visit(VarDecl& decl) = 0;
    virtual T visit(ConstDecl& decl) = 0;
    virtual T visit(FuncDecl& decl) = 0;
    virtual T visit(ClassDecl& decl) = 0;
    
};

#endif
