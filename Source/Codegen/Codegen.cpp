#include "Codegen.hpp"
#include <iostream>

std::vector<llvm::Value*> Codegen::generate() {
    module = std::make_unique<llvm::Module>("Program", context);
    
    //Loop through all the nodes and append the generated code to the vector
    for (auto& node: nodes)
        node->accept(*this);
    
    module->print(llvm::errs(), nullptr);
    return representation;
}

void Codegen::visit(IdentifierExpr& expr) {
    
}

void Codegen::visit(IntegerExpr& expr) {
    representation.push_back(llvm::ConstantFP::get(context, llvm::APFloat((float)expr.lexeme)));
}

void Codegen::visit(DoubleExpr& expr) {

}

void Codegen::visit(StringExpr& expr) {
    
}

void Codegen::visit(CharExpr& expr) {
    
}

void Codegen::visit(BoolExpr& expr) {
    
}

void Codegen::visit(UnaryExpr& expr) {
    
}

void Codegen::visit(BinaryOpExpr& expr) {

}

void Codegen::visit(CallExpr& expr) {
    
}

void Codegen::visit(AssignExpr& expr) {
    
}
       
//Stmt
void Codegen::visit(ExprStmt& stmt) {
    
}

void Codegen::visit(IfStmt& stmt) {
    
}

void Codegen::visit(WhileStmt& stmt) {
}

void Codegen::visit(ForInStmt& stmt) {
    
}

void Codegen::visit(ReturnStmt& stmt) {
    
}
       
//Block
void Codegen::visit(Block& block) {
    
}
   
//Decl
void Codegen::visit(ParamDecl& decl) {
    
}

void Codegen::visit(VarDecl& decl) {
    
}

void Codegen::visit(ConstDecl& decl) {
    
}

void Codegen::visit(FuncDecl& decl) {
    
}

void Codegen::visit(ClassDecl& decl) {
    
}
