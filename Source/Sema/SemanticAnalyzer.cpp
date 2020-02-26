#include "SemanticAnalyzer.hpp"
#include <iostream>

void SemanticAnalyzer::performAnalysis(SymbolTable* enviroment) {
    
    //Assign enviroment to pointer
    this->enviroment = enviroment;
    
    for (unsigned long int index = 0; index < nodes.size(); index++)
        nodes[index]->accept(*this);
}

void SemanticAnalyzer::innerCheck(Node& node) {
    node.accept(*this);
}

//Block
void SemanticAnalyzer::visit(Block& block) {
    enterScope(enviroment);
    //Loop through all the nodes
    for (unsigned int index = 0; index < block.nodes.size(); index++)
        innerCheck(*block.nodes[index]);
    exitScope();
}

//Expr
void SemanticAnalyzer::visit(IdentifierExpr& expr) {
    getEnviroment()->get(expr.lexeme);
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
    innerCheck(*expr.expr);
}

void SemanticAnalyzer::visit(BinaryOpExpr& expr) {

}

void SemanticAnalyzer::visit(CallExpr& expr) {

}

void SemanticAnalyzer::visit(AssignExpr& expr) {
    if (IdentifierExpr* identifier = dynamic_cast<IdentifierExpr*>(expr.identifier.get()))
        getEnviroment()->assign(identifier->lexeme, expr.expr.get());
}
   
//Stmt
void SemanticAnalyzer::visit(ExprStmt& stmt) {
    
}

void SemanticAnalyzer::visit(IfStmt& stmt) {
    innerCheck(*stmt.block);
}

void SemanticAnalyzer::visit(WhileStmt& stmt) {
    innerCheck(*stmt.block);
}

void SemanticAnalyzer::visit(ForInStmt& stmt) {
    innerCheck(*stmt.block);

}

void SemanticAnalyzer::visit(ReturnStmt& stmt) {
    innerCheck(*stmt.expr);
}
   
//Decl
void SemanticAnalyzer::visit(ParamDecl& decl) {
    //add parameters to enviroment
    if (IdentifierExpr* identifier = dynamic_cast<IdentifierExpr*>(decl.name.get())) {
        getEnviroment()->define(identifier->lexeme, decl.type, true, nullptr);
    }
}

void SemanticAnalyzer::visit(VarDecl& decl) {
    //Get identifier
    if (IdentifierExpr* identifier = dynamic_cast<IdentifierExpr*>(decl.identifier.get())) {
        //Define to symbol table
        getEnviroment()->define(identifier->lexeme, decl.type, false, decl.expr.get());
    }
    
    //Check the expression
    //if (decl.expr != nullptr) innerCheck(*decl.expr);
}

void SemanticAnalyzer::visit(ConstDecl& decl) {
    //Get identifier
    if (IdentifierExpr* identifier = dynamic_cast<IdentifierExpr*>(decl.identifier.get())) {
        //Define to symbol table
        getEnviroment()->define(identifier->lexeme, decl.type, true, decl.expr.get());
    }
    
    //Check the expression
    //if (decl.expr != nullptr) innerCheck(*decl.expr);
}

void SemanticAnalyzer::visit(FuncDecl& decl) {
   //Get identifier
    if (IdentifierExpr* identifier = dynamic_cast<IdentifierExpr*>(decl.identifier.get()))
        getEnviroment()->define(identifier->lexeme, decl.type, true, nullptr);

    for (std::unique_ptr<ParamDecl>& node: decl.params)
        innerCheck(*node);
    
    innerCheck(*decl.body);
}

void SemanticAnalyzer::visit(ClassDecl& decl) {
    //Get identifier
    if (IdentifierExpr* identifier = dynamic_cast<IdentifierExpr*>(decl.identifier.get()))
        getEnviroment()->define(identifier->lexeme, TokenType::classKey, false, nullptr);
    
    innerCheck(*decl.body);
}

/* ------- Helper Scoping Methods --------*/

SymbolTable* SemanticAnalyzer::getEnviroment() {
    return enviroment;
}

void SemanticAnalyzer::enterScope(SymbolTable* enclosing) {
    SymbolTable* newEnviroment = new SymbolTable();
    
    //Set to current created enviroment the enclosing (parent table)
    newEnviroment->setEnclosing(enclosing);
    enviroment = newEnviroment;
}

void SemanticAnalyzer::exitScope() {
    if (enviroment->getEnclosing() != nullptr)
        enviroment = enviroment->getEnclosing();
}
