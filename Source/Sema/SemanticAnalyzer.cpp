#include "SemanticAnalyzer.hpp"

void SemanticAnalyzer::performAnalysis(SymbolTable* enviroment) {
    for (unsigned long int index = 0; index < nodes.size(); index++)
        analyze(nodes[index], enviroment);
}

void SemanticAnalyzer::analyze(std::unique_ptr<Node>& node, SymbolTable* enviroment) {
    node->accept(*this);
}

void SemanticAnalyzer::visit(IdentifierExpr& expr) {

}

void SemanticAnalyzer::visit(IntegerExpr& expr) {

}

void SemanticAnalyzer::visit(DoubleExpr& expr) {
    
}

void SemanticAnalyzer::visit(StringExpr& expr) {
    
}

void SemanticAnalyzer::visit(CharExpr& expr) {
    
}

void SemanticAnalyzer::visit(BoolExpr& expr) {
    
}

void SemanticAnalyzer::visit(UnaryExpr& expr) {
    
}

void SemanticAnalyzer::visit(BinaryOpExpr& expr) {
    
}

void SemanticAnalyzer::visit(CallExpr& expr) {
    
}

void SemanticAnalyzer::visit(AssignExpr& expr) {
    if (IdentifierExpr* identifier = dynamic_cast<IdentifierExpr*>(expr.identifier.get())) {}
        //enviroment->assign(identifier->lexeme, expr.expr.get());
}
   
//Stmt
void SemanticAnalyzer::visit(ExprStmt& stmt) {
    
}

void SemanticAnalyzer::visit(IfStmt& stmt) {
    
}

void SemanticAnalyzer::visit(WhileStmt& stmt) {
    
}

void SemanticAnalyzer::visit(ForInStmt& stmt) {
    
}

void SemanticAnalyzer::visit(ReturnStmt& stmt) {
    
}
   
//Block
void SemanticAnalyzer::visit(Block& block) {
    
}

//Decl
void SemanticAnalyzer::visit(ParamDecl& decl) {
    
}

void SemanticAnalyzer::visit(VarDecl& decl) {
    //Get identifier
    if (IdentifierExpr* identifier = dynamic_cast<IdentifierExpr*>(decl.identifier.get())) {
        //Define to symbol table
        //enviroment->define(identifier->lexeme, decl.type, false, decl.expr.get());
    }
}

void SemanticAnalyzer::visit(ConstDecl& decl) {
    //Get identifier
    if (IdentifierExpr* identifier = dynamic_cast<IdentifierExpr*>(decl.identifier.get())) {
        //Define to symbol table
        //enviroment->define(identifier->lexeme, decl.type, true, decl.expr.get());
    }
}

void SemanticAnalyzer::visit(FuncDecl& decl) {
   //Get identifier
    if (IdentifierExpr* identifier = dynamic_cast<IdentifierExpr*>(decl.identifier.get())) {
        //Define to symbol table
        //enviroment->define(identifier->lexeme, decl.type, true, nullptr);
    }
    
    SymbolTable* enviroment = new SymbolTable();
    
}

void SemanticAnalyzer::visit(ClassDecl& decl) {
    //Get identifier
    if (IdentifierExpr* identifier = dynamic_cast<IdentifierExpr*>(decl.identifier.get())) {
        //Define to symbol table
        //enviroment->define(identifier->lexeme, TokenType::classKey, false, nullptr);
    }
}
