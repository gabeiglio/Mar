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

class Codegen: public Visitor<llvm::Value*> {
    std::vector<std::unique_ptr<Node>> nodes;
    SymbolTable* enviroment;
    
    static llvm::LLVMContext context;
    static llvm::IRBuilder<> builder; //builder(context) ?
    static std::unique_ptr<llvm::Module> module;
    static std::map<std::string, llvm::Value*> namedValues;
    
    //Expr
    llvm::Value* visit(IdentifierExpr& expr) override;
    llvm::Value* visit(IntegerExpr& expr) override;
    llvm::Value* visit(DoubleExpr& expr) override ;
    llvm::Value* visit(StringExpr& expr) override;
    llvm::Value* visit(CharExpr& expr) override;
    llvm::Value* visit(BoolExpr& expr) override;
    llvm::Value* visit(UnaryExpr& expr) override;
    llvm::Value* visit(BinaryOpExpr& expr) override;
    llvm::Value* visit(CallExpr& expr) override;
    llvm::Value* visit(AssignExpr& expr) override;
        
    //Stmt
    llvm::Value* visit(ExprStmt& stmt) override;
    llvm::Value* visit(IfStmt& stmt) override;
    llvm::Value* visit(WhileStmt& stmt) override;
    llvm::Value* visit(ForInStmt& stmt) override;
    llvm::Value* visit(ReturnStmt& stmt) override;
        
    //Block
    llvm::Value* visit(Block& block) override;
    
    //Decl
    llvm::Value* visit(ParamDecl& decl) override;
    llvm::Value* visit(VarDecl& decl) override;
    llvm::Value* visit(ConstDecl& decl) override;
    llvm::Value* visit(FuncDecl& decl) override;
    llvm::Value* visit(ClassDecl& decl) override;
    
public:
    Codegen(std::vector<std::unique_ptr<Node>>& nodes, SymbolTable* enviroment): nodes(std::move(nodes)), enviroment(enviroment) {}
    
};

#endif
