# Compiler for Decaf language

Compiler for a given code in decaf language with specifications as explained in the above Decaf spec pdf.

## Prerequisites

> Bison and Flex installed to work with C++, llvm

## Usage

move to the Directory containing these folders and then run

> make

Then run 

> ./calc


## Files

> Bison File: calc.yy

> Flex File: calc.ll

> AST Files: ast.h ast.cc

> Visitor Pattern: PostFixVisitor.h

> Driver Files: diver.cc driver.h

> Scanner Files: scanner.h

## Features
> If this does not works with any other linux distro, try to reinstall bison, flex and llvm for that particular distro.
> Make file might not work with all the linux distros, so you need to change the linking part in the compilation process yourself.
> Can Parse Decaf syntax and 
> Can Create AST for any and all valid syntax of decaf language.
