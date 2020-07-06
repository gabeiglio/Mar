//
//  Evaluator.hpp
//  Mar
//
//  Created by Gabriel Igliozzi on 11/25/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#ifndef ASTVisualizer_hpp
#define ASTVisualizer_hpp

#include <iostream>

#include "Parser/Nodes/Stmt.hpp"
#include "Parser/Nodes/Decl.hpp"
#include "Evaluator/Visitor/Visitor.hpp"

class ASTVisualizer: public Visitor<void> {
private:
    int level = 1;
    std::string scope = "|-- ";
    
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

    //Inner evaluate method
    void eval(Node& node);

    //Helper fucntion to print tabs
    template <typename T>
    void print(T object, bool newLine);
    
public:
    void evaluate(std::vector<std::unique_ptr<Node>>& nodes);
};

#endif /* Evaluator_hpp */
