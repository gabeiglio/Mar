#include "Codegen.hpp"

llvm::Value* Codegen::visit(IdentifierExpr& expr) {
    return nullptr;
}

llvm::Value* Codegen::visit(IntegerExpr& expr) {
    return nullptr;
}

llvm::Value* Codegen::visit(DoubleExpr& expr) {
    //return llvm::ConstantFP::get(context, APFloat());
    return nullptr;
}

llvm::Value* Codegen::visit(StringExpr& expr) {
    
}

llvm::Value* Codegen::visit(CharExpr& expr) {

}

llvm::Value* Codegen::visit(BoolExpr& expr) {

}

llvm::Value* Codegen::visit(UnaryExpr& expr) {

}

llvm::Value* Codegen::visit(BinaryOpExpr& expr) {

}

llvm::Value* Codegen::visit(CallExpr& expr) {

}

llvm::Value* Codegen::visit(AssignExpr& expr) {

}
       
//Stmt
llvm::Value* Codegen::visit(ExprStmt& stmt) {

}

llvm::Value* Codegen::visit(IfStmt& stmt) {

}

llvm::Value* Codegen::visit(WhileStmt& stmt) {

}

llvm::Value* Codegen::visit(ForInStmt& stmt) {

}

llvm::Value* Codegen::visit(ReturnStmt& stmt) {

}
       
//Block
llvm::Value* Codegen::visit(Block& block) {

}
   
//Decl
llvm::Value* Codegen::visit(ParamDecl& decl) {

}

llvm::Value* Codegen::visit(VarDecl& decl) {

}

llvm::Value* Codegen::visit(ConstDecl& decl) {

}

llvm::Value* Codegen::visit(FuncDecl& decl) {

}

llvm::Value* Codegen::visit(ClassDecl& decl) {

}
