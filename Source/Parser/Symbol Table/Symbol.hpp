//
//  Symbol.hpp
//  Mar
//
//  Created by Gabriel Igliozzi on 11/14/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#ifndef Symbol_h
#define Symbol_h

#include <string>
#include "Token.hpp"

#endif /* Symbol_h */

struct Symbol {
    std::string& lexeme;
    int lineLocation;
    TokenType type;
};
