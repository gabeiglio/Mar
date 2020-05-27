# 🌊 Mar

#### Note:
I am building this project while I'm learning about how compilers work, also while Im learning C++, I have tried many times to make this but I ended up deleting it, this time there is not going back. Wecolme to my journey!

Mar will be a static, compiled, high-level language inspired by Swift

## 🏗 Pipeline:
```
 SourceFile.mar
       ↓
 __________________                     __________________                __________________
|                  |                   |                  |              |                  |
|      Lexer       | --- [Tokens] ---> |      Parser      | --- AST ---> |   Sema Analysis  | 
|__________________|                   |__________________|              |__________________|
                                                                                   |
                                                                                   |
                                                                                  AST
                                                                                   |
                                                                                   ↓
 __________________                   __________________                 __________________
|                  |                 |                  |               |                  |
| Target Code Gen  | <---   IR   --- |   Optimization   | <---  IR  --- |   IR Code Gen    | 
|__________________|                 |__________________|               |__________________|
       |
       |
       ↓
       
   Binary File

```

## What I am doing now?

Learning about how to implement static type cheking, and how to properly translate the AST into some kind of intermediate code representation like three address code
