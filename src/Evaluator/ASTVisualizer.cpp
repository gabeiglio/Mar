//
//  ASTVisualizer.cpp
//  Mar
//
//  Created by Gabriel Igliozzi on 11/25/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#include "ASTVisualizer.hpp"

void ASTVisualizer::evaluate(std::vector<std::unique_ptr<Node>>& nodes) {
    print("Program", true);
    for (unsigned int index = 0; index < nodes.size(); index++)
        eval(*nodes[index]);
    
    print("", true);
}

void ASTVisualizer::eval(Node& node) {
    node.accept(*this);
}

//Expr
void ASTVisualizer::visit(IdentifierExpr& expr) {
    if (expr.property != "")
        print(expr.lexeme + "." + expr.property, false);
    else  print(expr.lexeme, false);
}

void ASTVisualizer::visit(IntegerExpr& expr) {
    print(expr.lexeme, false);
}

void ASTVisualizer::visit(DoubleExpr& expr) {
    print(expr.lexeme, false);
}

void ASTVisualizer::visit(StringExpr& expr) {
    print(expr.lexeme, false);
}

void ASTVisualizer::visit(CharExpr& expr) {
    print(expr.lexeme, false);
}

void ASTVisualizer::visit(BoolExpr& expr) {
    if (expr.lexeme) print("true", false);
    else print("false", false);
}

void ASTVisualizer::visit(UnaryExpr& expr) {
    print(expr.op, false);
    eval(*expr.expr);
}

void ASTVisualizer::visit(BinaryOpExpr& expr) {
    eval(*expr.lhs);
    print(" ", false);
    print(expr.op, false);
    print(" ", false);
    eval(*expr.rhs);
}

void ASTVisualizer::visit(CallExpr& expr) {
	print(scope, false);
	print("call expr", false);
}

void ASTVisualizer::visit(AssignExpr& expr) {
    for (unsigned int i = 0; i < level; i++)
        std::cout << "  ";
    print(scope, false);
    
    eval(*expr.identifier);
    print(" = ", false);
    eval(*expr.expr);
    print("", true);
}

//Stmt
void ASTVisualizer::visit(ExprStmt& stmt) {
    eval(*stmt.expr);
    print("", false);
}

void ASTVisualizer::visit(IfStmt& stmt) {
    for (unsigned int i = 0; i < level; i++)
        std::cout << "  ";
    print(scope, false);
    
    print("if ", false);
    eval(*stmt.expr);
    print("", true);
    eval(*stmt.block);
}

void ASTVisualizer::visit(WhileStmt& stmt) {
    for (unsigned int i = 0; i < level; i++)
        std::cout << "  ";
    print(scope, false);
    
    print("while ", false);
    eval(*stmt.expr);
    print("", true);
    eval(*stmt.block);
}

void ASTVisualizer::visit(ForInStmt& stmt) {
    for (unsigned int i = 0; i < level; i++)
        std::cout << "  ";
    print(scope, false);
    
    print("for ", false);
    eval(*stmt.identifier);
    print(" in ", false);
    eval(*stmt.range);
    print("", true);
    eval(*stmt.block);
}

void ASTVisualizer::visit(ReturnStmt& stmt) {
    for (unsigned int i = 0; i < level; i++)
        std::cout << "  ";
    print(scope, false);
    
    print("return ", false);
    eval(*stmt.expr);
    print("", true);
}

//Block
void ASTVisualizer::visit(Block& block) {
    level++;
    for (const auto& node: block.nodes)
        eval(*node);
    level--;
}

//Decl
void ASTVisualizer::visit(ParamDecl& decl) {
    eval(*decl.name);
    print(" ", false);
    print(decl.type, false);
}

void ASTVisualizer::visit(VarDecl& decl) {
    for (unsigned int i = 0; i < level; i++)
        std::cout << "  ";
    print(scope, false);
    
    print("var ", false);
    eval(*decl.identifier);
    print(" ", false);
    print(decl.type, false);
    
    if (decl.expr != nullptr) {
        print(" = ", false);
        eval(*decl.expr);
    }
    print("", true);
}

void ASTVisualizer::visit(ConstDecl& decl) {
    for (unsigned int i = 0; i < level; i++)
        std::cout << "  ";
    print(scope, false);
    
    print("const ", false);
    eval(*decl.identifier);
    print(" ", false);
    print(decl.type, false);
    
    if (decl.expr != nullptr) {
        print(" = ", false);
        eval(*decl.expr);
    }
    print("", true);
}

void ASTVisualizer::visit(FuncDecl& decl) {
    for (unsigned int i = 0; i < level; i++)
        std::cout << "  ";
    print(scope, false);
    
    print("func ", false);
    eval(*decl.identifier);
    print("(", false);
    
    for (unsigned int index = 0; index < decl.params.size(); index++) {
        eval(*decl.params[index]);
        if (index < decl.params.size() - 1) {
            print(", ", false);
        }
    }
    
    print(") ", false);

    print(decl.type, true);
    eval(*decl.body);
    
    print("", true);
}

void ASTVisualizer::visit(ClassDecl& decl) {
    for (unsigned int i = 0; i < level; i++)
        std::cout << "  ";
    print(scope, false);
    
    print("class ", false);
    eval(*decl.identifier);
    print("", true);
    eval(*decl.body);
}

void ASTVisualizer::visit(StructDecl& decl) {
    for (unsigned int i = 0; i < level; i++)
        std::cout << "  ";
    print(scope, false);
    
    print("struct ", false);
    eval(*decl.identifier);
    print("", true);
    eval(*decl.body);

}

template <typename T>
void ASTVisualizer::print(T object, bool newLine) {
    std::cout << object;
    if (newLine) std::cout << '\n';
}


