//
//  Evaluator.cpp
//  Mar
//
//  Created by Gabriel Igliozzi on 11/25/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#include "Evaluator.hpp"

void Evaluator::printTabs(int tabs) {
    for (int i = 0; i < tabs; i++)
        std::cout << "  ";
}

void Evaluator::evaluateExpr(Expr* ptr, int tabs) {
    if (IdentifierExpr* result = dynamic_cast<IdentifierExpr*>(ptr)) {
        std::cout << "Identifier expr: " + result->lexeme;
    }
    
    if (IntergerExpr* result = dynamic_cast<IntergerExpr*>(ptr)) {
        std::cout << "Integer expr: " + std::to_string(result->lexeme);
    }
    
    if (DoubleExpr* result = dynamic_cast<DoubleExpr*>(ptr)) {
        std::cout << "Double expr: " + std::to_string(result->lexeme);
    }
    
    if (StringExpr* result = dynamic_cast<StringExpr*>(ptr)) {
        std::cout << "String expr: " + result->lexeme;
    }
    
    if (BoolExpr* result = dynamic_cast<BoolExpr*>(ptr)) {
        std::cout << "Bool expr: " + std::to_string(result->lexeme);
    }
    
    if (CharExpr* result = dynamic_cast<CharExpr*>(ptr)) {
        std::cout << "Char expr: " + std::string(1, result->lexeme);
    }
    
    if (UnaryExpr* result = dynamic_cast<UnaryExpr*>(ptr)) {
        std::cout << "Unary expr: " + std::to_string(result->op);
        evaluateExpr(result->expr.get());
    }
    
    if (CallExpr* result = dynamic_cast<CallExpr*>(ptr)) {
        printTabs(tabs + 1);
        std::cout << "Call expr: " + result->identifier->lexeme + " ";
        
        for (unsigned long int i = 0; i < result->arguments.size(); i++) {
            evaluateExpr(result->arguments[i].get());
        }
    }
    
    if (AssignExpr* result = dynamic_cast<AssignExpr*>(ptr)) {
        printTabs(tabs + 1);
        std::cout << "Assign expr: ";
        evaluateExpr(result->identifier.get());
        std::cout << " = ";
        evaluateExpr(result->expr.get());
        std::cout << '\n';
    }
    
    if (BinaryOpExpr* result = dynamic_cast<BinaryOpExpr*>(ptr)) {
        std::cout << "Binary expr: (";
        evaluateExpr(result->rhs.get());
        std::cout << " ";
        std::cout << std::to_string(result->op);
        std::cout << " ";
        evaluateExpr(result->lhs.get());
        std::cout << ")";
    }
}

void Evaluator::evaluateStmt(Stmt *ptr, int tabs) {

    if (tabs == 0) printTabs(tabs);
    else printTabs(tabs + 1);

    if (WhileStmt* result = dynamic_cast<WhileStmt*>(ptr)) {
        std::cout << "While Stmt: ";
        evaluateExpr(result->expr.get());
        std::cout << '\n';
        evaluateBlock(result->block.get());
    }
    
    if (ReturnStmt* result = dynamic_cast<ReturnStmt*>(ptr)) {
        std::cout << "Return Stmt: ";
        evaluateExpr(result->expr.get());
        std::cout << '\n';
    }
    
    if (IfStmt* result = dynamic_cast<IfStmt*>(ptr)) {
        std::cout << "If Stmt: ";
        evaluateExpr(result->expr.get());
        std::cout << '\n';
        evaluateBlock(result->block.get());
    }
    
    if (ExprStmt* result = dynamic_cast<ExprStmt*>(ptr)) {
        evaluateExpr(result->expr.get());
        std::cout << '\n';
    }

	if (ForInStmt* result = dynamic_cast<ForInStmt*>(ptr)) {
		std::cout << "For stmt: ";
		evaluateExpr(result->identifier.get());
		std::cout << " in range: :";
		evaluateExpr(result->range.get());
		std::cout << '\n';
		evaluateBlock(result->block.get());
	}

}

void Evaluator::evaluateDecl(Decl *ptr, int tabs) {
    if (VarDecl* result = dynamic_cast<VarDecl*>(ptr)) {
        printTabs(tabs + 1);
        std::cout << "Var decl: ";
        evaluateExpr(result->identifier.get());
        std::cout << " " + std::to_string(result->type);
        std::cout << " = ";
        evaluateExpr(result->expr.get());
        std::cout << '\n';
    }
    
    if (ConstDecl* result = dynamic_cast<ConstDecl*>(ptr)) {
        printTabs(tabs + 1);
        std::cout << "Const decl: ";
        evaluateExpr(result->identifier.get());
        std::cout << " " + std::to_string(result->type);
        std::cout << " = ";
        evaluateExpr(result->expr.get());
        std::cout << '\n';
    }
    
    if (FuncDecl* result = dynamic_cast<FuncDecl*>(ptr)) {
        printTabs(tabs + 1);
        std::cout << "Func decl: ";
        evaluateExpr(result->identifier.get());
        
        std::cout << '\n';
        
        for (int i = 0; i < result->params.size(); i++) {
            evaluateDecl(result->params[i].get());
        }

        evaluateBlock(result->body.get());
        
        std::cout << '\n';
    }
    
    if (ClassDecl* result = dynamic_cast<ClassDecl*>(ptr)) {
        printTabs(tabs + 1);
        std::cout << "Class decl: ";
        evaluateExpr(result->identifier.get());        
        evaluateBlock(result->body.get());
        std::cout << '\n';
    }
    
    if (ParamDecl* result = dynamic_cast<ParamDecl*>(ptr)) {
        printTabs(tabs + 2);
        std::cout << "Param delc: ";
        evaluateExpr(result->name.get());
        std::cout << " " << result->type << '\n';
    }
}

void Evaluator::evaluateBlock(Block *ptr, int tabs) {
    for (int i = 0; i < ptr->nodes.size(); i++) {
        evaluate(ptr->nodes[i].get());
    }
}


//Public method
void Evaluator::evaluate(Node *ptr) {
    if (Stmt* result = dynamic_cast<Stmt*>(ptr)) {
        evaluateStmt(result);
    }
    
    if (Decl* result = dynamic_cast<Decl*>(ptr)) {
        evaluateDecl(result);
    }
}
