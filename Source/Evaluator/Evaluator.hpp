//
//  Evaluator.hpp
//  Mar
//
//  Created by Gabriel Igliozzi on 11/25/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#ifndef Evaluator_hpp
#define Evaluator_hpp

#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Parser/Nodes/Stmt.hpp"
#include "/Users/gabeiglio/Desktop/Developer/Mar/Source/Parser/Nodes/Decl.hpp"
#include <iostream>

#endif /* Evaluator_hpp */

class Evaluator {
private:
    void evaluateStmt(Stmt* ptr, int tabs = 0);
    void evaluateExpr(Expr* ptr, int tabs = 0);
    void evaluateDecl(Decl* ptr, int tabs = 0);
    void evaluateBlock(Block* ptr, int tabs = 0);

    //Helper fucntion to print tabs
    void printTabs(int tabs);
    
public:
    void evaluate(Node* ptr);
};
