#pragma once

#ifndef Visitor_hpp
#define Visitor_hpp

//#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Parser/Nodes/Decl.hpp"
//#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Parser/Nodes/Stmt.hpp"
//#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Parser/Nodes/Expr.hpp"

#endif

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

struct ExprStmt;
struct IfStmt;
struct WhileStmt;
struct ForInStmt;
struct ReturnStmt;

struct ParamDecl;
struct VarDecl;
struct ConstDecl;
struct FuncDecl;
struct ClassDecl;

struct Block;


struct Visitor {
    
    //Expr
    virtual void visit(IdentifierExpr& expr) = 0;
    virtual void visit(IntegerExpr& expr) = 0;
    virtual void visit(DoubleExpr& expr) = 0;
    virtual void visit(StringExpr& expr) = 0;
    virtual void visit(CharExpr& expr) = 0;
    virtual void visit(BoolExpr& expr) = 0;
    virtual void visit(UnaryExpr& expr) = 0;
    virtual void visit(BinaryOpExpr& expr) = 0;
    virtual void visit(CallExpr& expr) = 0;
    virtual void visit(AssignExpr& expr) = 0;
    
    //Stmt
    virtual void visit(ExprStmt& stmt) = 0;
    virtual void visit(IfStmt& stmt) = 0;
    virtual void visit(WhileStmt& stmt) = 0;
    virtual void visit(ForInStmt& stmt) = 0;
    virtual void visit(ReturnStmt& stmt) = 0;
    
    //Block
    virtual void visit(Block& block) = 0;
    
    //Decl
    virtual void visit(ParamDecl& decl) = 0;
    virtual void visit(VarDecl& decl) = 0;
    virtual void visit(ConstDecl& decl) = 0;
    virtual void visit(FuncDecl& decl) = 0;
    virtual void visit(ClassDecl& decl) = 0;
    
};
