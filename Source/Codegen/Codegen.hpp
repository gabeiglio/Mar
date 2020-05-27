#ifndef Codegen_hpp
#define Codegen_hpp

#pragma once

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Lexer/Token.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Parser/Nodes/Decl.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Parser/Nodes/Expr.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Parser/Nodes/Stmt.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Evaluator/Visitor/Visitor.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Sema/SymbolTable/SymbolTable.hpp"

class Codegen: public Visitor<void> {
    std::vector<llvm::Value*> representation;
    std::vector<std::unique_ptr<Node>> nodes;
    SymbolTable* enviroment;
    
    //LLVM properties
    llvm::LLVMContext context;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::Module> module;
    
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
    Codegen(std::vector<std::unique_ptr<Node>>& nodes, SymbolTable* enviroment): nodes(std::move(nodes)), enviroment(enviroment), builder(context) {}
    std::vector<llvm::Value*> generate();
};

#endif
