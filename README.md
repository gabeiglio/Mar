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

Now as Im building the Grammar I am also researching how to implement input buffering with buffer pairs, I know the theory, but I have no idea how to implement it 😅.
