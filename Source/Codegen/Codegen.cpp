#include "Codegen.hpp"

void Codegen::generate() {
    module = std::make_unique<llvm::Module>("Program", context);
    
    DoubleExpr expr(1.2);
    visit(expr);
    
    DoubleExpr expr1(1.2);
    visit(expr1);

    
    module->print(llvm::errs(), nullptr);
}

llvm::Value* Codegen::visit(IdentifierExpr& expr) {
    return nullptr;
}

llvm::Value* Codegen::visit(IntegerExpr& expr) {
    return nullptr;
}

llvm::Value* Codegen::visit(DoubleExpr& expr) {
    return builder.CreateFAdd(llvm::ConstantFP::get(context, llvm::APFloat(expr.lexeme)), llvm::ConstantFP::get(context, llvm::APFloat(expr.lexeme)), "addtmp");
}

llvm::Value* Codegen::visit(StringExpr& expr) {
    return nullptr;
}

llvm::Value* Codegen::visit(CharExpr& expr) { return nullptr; }

llvm::Value* Codegen::visit(BoolExpr& expr) { return nullptr; }

llvm::Value* Codegen::visit(UnaryExpr& expr) { return nullptr; }

llvm::Value* Codegen::visit(BinaryOpExpr& expr) {
//    Value* rhs = expr.rhs->accept(*this);
//    Value* lhs = expr.lhs->accept(*this);
//
//    if (!rhs || !lhs) return nullptr;
//
//    switch (expr.op) {
//        case TokenType::plus:
//            builder.createFAdd(lhs, rhs, "addtmp");
//            break;
//        case TokenType::hyphen:
//            builder.createFSub(lhs, rhs, "subtmp");
//            break;
//        case TokenType::star:
//            builder.createFMul(lhs, rhs, "multmp");
//            break;
//        case TokenType::slash:  break;
//        default: break;
//    }
    return nullptr; 
}

llvm::Value* Codegen::visit(CallExpr& expr) { return nullptr; }

llvm::Value* Codegen::visit(AssignExpr& expr) { return nullptr; }
       
//Stmt
llvm::Value* Codegen::visit(ExprStmt& stmt) { return nullptr; }

llvm::Value* Codegen::visit(IfStmt& stmt) { return nullptr; }

llvm::Value* Codegen::visit(WhileStmt& stmt) { return nullptr; }

llvm::Value* Codegen::visit(ForInStmt& stmt) { return nullptr; }

llvm::Value* Codegen::visit(ReturnStmt& stmt) { return nullptr; }
       
//Block
llvm::Value* Codegen::visit(Block& block) { return nullptr; }
   
//Decl
llvm::Value* Codegen::visit(ParamDecl& decl) { return nullptr; }

llvm::Value* Codegen::visit(VarDecl& decl) { return nullptr; }

llvm::Value* Codegen::visit(ConstDecl& decl) { return nullptr; }

llvm::Value* Codegen::visit(FuncDecl& decl) { return nullptr; }

llvm::Value* Codegen::visit(ClassDecl& decl) { return nullptr; }
