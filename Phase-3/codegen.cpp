#include "codegen.h"

int validity;
static IRBuilder<> Builder(getGlobalContext());

void CodeGenContext::generateCode(ASTProgram* root)
{
	std::cout << "Generating code...\n";

	vector<const Type*> argTypes;
	FunctionType *ftype = FunctionType::get(Type::getVoidTy(getGlobalContext()), argTypes, false);
	mainFunction = Function::Create(ftype, GlobalValue::InternalLinkage, "Class Program", module);
	BasicBlock *bblock = BasicBlock::Create(getGlobalContext(), "entry", mainFunction, 0);

	pushBlock(bblock);
	*root->codeGen(*this); /* emit bytecode for the toplevel block */
	popBlock();

		std::cout << "Code is generated.\n";
		PassManager pm;
		pm.add(createPrintModulePass(&outs()));
		pm.run(*module);

}
