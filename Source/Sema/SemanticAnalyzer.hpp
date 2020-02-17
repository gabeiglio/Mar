
#ifndef SemanticAnalyzer_hpp
#define SemanticAnalyzer_hpp

#import <vector>

#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Lexer/Token.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Parser/Nodes/Decl.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Parser/Nodes/Expr.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Parser/Nodes/Stmt.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Evaluator/Visitor/Visitor.hpp"
#include "SymbolTable/SymbolTable.hpp"

#pragma once

class SemanticAnalyzer: public Visitor {
private:
    std::vector<std::unique_ptr<Node>> nodes;
    
    //Inner perfrom analysis with recursive property and scoped symbol table
    void analyze(std::unique_ptr<Node>& node, SymbolTable* enviroment);

    //Expr
    void visit(IdentifierExpr& expr) override;
    void visit(IntegerExpr& expr) override;
    void visit(DoubleExpr& expr) override ;
    void visit(StringExpr& expr) override;
    void visit(CharExpr& expr) override;
    void visit(BoolExpr& expr) override;
    void visit(UnaryExpr& expr) override;
    void visit(BinaryOpExpr& expr) override;
    void visit(CallExpr& expr) override;
    void visit(AssignExpr& expr) override;
       
    //Stmt
    void visit(ExprStmt& stmt) override;
    void visit(IfStmt& stmt) override;
    void visit(WhileStmt& stmt) override;
    void visit(ForInStmt& stmt) override;
    void visit(ReturnStmt& stmt) override;
       
    //Block
    void visit(Block& block) override;
    
    //Decl
    void visit(ParamDecl& decl) override;
    void visit(VarDecl& decl) override;
    void visit(ConstDecl& decl) override;
    void visit(FuncDecl& decl) override;
    void visit(ClassDecl& decl) override;
    
public:
    void performAnalysis(SymbolTable* enviroment);
    SemanticAnalyzer(std::vector<std::unique_ptr<Node>>& nodes): nodes(std::move(nodes)) {}
};

#endif
