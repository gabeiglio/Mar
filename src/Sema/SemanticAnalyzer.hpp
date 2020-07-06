
#ifndef SemanticAnalyzer_hpp
#define SemanticAnalyzer_hpp

#import <vector>

#include "Lexer/Token.hpp"
#include "Parser/Nodes/Decl.hpp"
#include "Parser/Nodes/Expr.hpp"
#include "Parser/Nodes/Stmt.hpp"
#include "SymbolTable/SymbolTable.hpp"
#include "Evaluator/Visitor/Visitor.hpp"

#pragma once

class SemanticAnalyzer: public Visitor<void> {
private:
    std::vector<std::unique_ptr<Node>> nodes;
    
    //Pointer of the Symbol Table
    SymbolTable* enviroment;

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
    void visit(StructDecl& decl) override;

    //Helper Scoping methods
    SymbolTable* getEnviroment();
    void enterScope(SymbolTable* enclosing);
    void exitScope();
    
    //Helper function
    void innerCheck(Node& node);
    
public:
    SemanticAnalyzer(std::vector<std::unique_ptr<Node>>& nodes): nodes(std::move(nodes)) {}
    void performAnalysis(SymbolTable* enviroment);
};

#endif
