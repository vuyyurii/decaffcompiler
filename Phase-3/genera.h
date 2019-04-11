#ifndef CODEGEN_H
#define CODEGEN_H

#include "ClassDefs.h"

class Codegen : public Codegenerator{
public:
	static AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, const std::string &VarName, string type) {
	  /* Allocates memory for local variables  on the stack of the function */

	  /* Get the builder for current context */
	  IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
	  AllocaInst* Alloca;
	  if(type == "int"){
	    Alloca = TmpB.CreateAlloca(Type::getInt32Ty(getGlobalContext()), 0, VarName.c_str());
	  }
	  else if (type == "boolean"){
	    Alloca = TmpB.CreateAlloca(Type::getInt1Ty(getGlobalContext()), 0, VarName.c_str());
	  }
	  return Alloca;
	}


};

#endif /* CODEGEN_H */