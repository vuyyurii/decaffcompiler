
#ifndef POSTFIXVISITOR_H
#define POSTFIXVISITOR_H

#include "ast.h"

class PostFixVisitor: public ASTvisitor
{
  public:

    virtual void visit(ProgramNode& node)
    {
        std::cout << "start\n";
        if(node.getNode())
        node.getNode()->accept(*this);
        std::cout << "end\n";
    }

    virtual void visit(Expr& node)
    {
        std::cout << "start of expression\n";
        if(node.getNode())
        node.getNode()->accept(*this);
        std::cout << "end of expression\n";
    }

    virtual void visit(MthdNode& node)
    {
        std::cout << "start method decl\n";
        if(node.getblock())
        node.getblock()->accept(*this);
        if(node.getarg())
        node.getarg()->accept(*this);
        std::cout << "end method decl\n";
    }

    virtual void visit(ReturnNode& node)
    {
        std::cout << "Start Statement return field\n";
        if(node.getexpr())
        node.getexpr()->accept(*this);
        std::cout << " End statement return field\n";
    }

    virtual void visit(BlockNode& node)
    {
        std::cout << "Start Statement block field\n";
        if(node.getblock())
        node.getblock()->accept(*this);
        std::cout << "End statement block field\n";
    }

    virtual void visit(StTerminateNode& node)
    {
        std::cout << "stf start\n";
        string a = node.getstr();
        std::cout << "stf end\n";
    }

    virtual void visit(IfElseNode& node)
    {
        std::cout << "Statement if else field started\n";
        if(node.getblock1())
        node.getblock1()->accept(*this);
        if(node.getexpr())
        node.getexpr()->accept(*this);
        if(node.getblock2())
        node.getblock2()->accept(*this);
        std::cout << "statement ifelse field ended\n";
    }

    virtual void visit(ForAst& node)
    {
        std::cout << "Statement for field started\n";
        if(node.getblock())
        node.getblock()->accept(*this);
        if(node.getexpr2())
        node.getexpr2()->accept(*this);
        if(node.getexpr1())
        node.getexpr1()->accept(*this);
        // std::cout << "statement for field ended\n";
    }

    virtual void visit(MStNode& node)
    {
        std::cout << "methodcall field started\n";
        if(node.getmethodcall())
        node.getmethodcall()->accept(*this);
        std::cout << "methodcall field ended\n";
    }

    virtual void visit(VariaNode& node)
    {
        std::cout << "var started\n";
        vector <string> temp = node.getlist();
        for(unsigned int i=0;i<temp.size();i++){
            std::cout << "varstart" <<"\n";
            std::cout << temp[i];
            std::cout <<"varend\n";
        }
        std::cout <<"end\n";
    }

    virtual void visit(VarDecsnode& node)
    {
        std::cout << "var declarations started\n";
        vector <ASTnode*> temp = node.getlist();
        for(unsigned int i=0;i<temp.size();i++){
            std::cout << "vardeclarationstart" <<"\n";
            temp[i]->accept(*this);
            std::cout <<"var declarations end\n";
        }
        std::cout <<"end\n";
    }

    virtual void visit(FuncNode& node)
    {
        std::cout << "function declarations started\n";
        vector <ASTnode*> temp = node.getlist();
        for(unsigned int i=0;i<temp.size();i++){
            std::cout << "function start" <<"\n";
            temp[i]->accept(*this);
            std::cout <<"function declrations end\n";
        }
        std::cout <<"end\n";
    }

    virtual void visit(StrLitNode& node)
    {
        std::cout << "<string>";
        std::cout << node.getString() << " ";
        std::cout << "</string>\n";
    }

    virtual void visit(VarNode& node)
    {
        std::cout << "<variable>";
        if(node.getNode())
            node.getNode()->accept(*this);
        std::cout << node.getVariable() << " ";
        std::cout << "</variable>\n";
    }
    
    virtual void visit(CalloutArgNode& node)
    {
        std::cout << "<calloutarg>";
        if(node.getNode())
            node.getNode()->accept(*this);
        std::cout << "</calloutarg>\n";
    }

    virtual void visit(UnaryOPNode& node)
    {
        std::cout << "<unary>";
        if(node.getexpr())
        node.getexpr()->accept(*this);
        std::cout << node.getUnaryOperator() << " ";
        std::cout << "</unary>\n";
    }
    
    virtual void visit(Locnode& node)
    {
        std::cout << "<location>";
        if (node.getNode())
        node.getNode()->accept(*this);
        std::cout << node.getLocation() << " ";
        std::cout << "</location>\n";
    }

    virtual void visit(MethodNode& node)
    {
        std::cout << "<methodname>";
        std::cout << node.getString() << " ";
        std::cout << "</methodname>\n";
    }
    
    virtual void visit(MethodCallNode& node)
    {
        std::cout << "<methodcall>";
        if(node.getname())
            node.getname()->accept(*this);
        if(node.getarg())
            node.getarg()->accept(*this);
        if(node.getcall())
            node.getcall()->accept(*this);
        if(node.getstr())
            node.getstr()->accept(*this);
        std::cout << "</methodcall>\n";
    }

    virtual void visit(VarsNode& node)
    {
        std::cout << "variables started\n";
        vector <ASTnode*> temp = node.getlist();
        for(unsigned int i=0;i<temp.size();i++){
            std::cout << "<variablesstart>" <<"\n";
            std::cout << temp.size() <<"\n";
            temp[i]->accept(*this);
            std::cout <<"<variables end>\n";
        }
        std::cout <<"end\n";
    }

    virtual void visit(StNode& node)
    {
        std::cout << "statements started\n";
        vector <ASTnode*> temp = node.getlist();
        for(unsigned int i=0;i<temp.size();i++){
            std::cout << "<statstart>" <<"\n";
            std::cout << temp.size() <<"\n";
            temp[i]->accept(*this);
            std::cout <<"<statend>\n";
        }
        std::cout <<"statements end\n";
    }

    virtual void visit(CalloutNode& node)
    {
        std::cout << "callout started\n";
        vector <ASTnode*> temp = node.getlist();
        for(unsigned int i=0;i<temp.size();i++){
            std::cout << "<calloutstart>" <<"\n";
            std::cout << temp.size() <<"\n";
            temp[i]->accept(*this);
            std::cout <<"<calloutstart>\n";
        }
        std::cout <<"end\n";
    }

    virtual void visit(MethodArgNode& node)
    {
        std::cout << "method arg started\n";
        vector <ASTnode*> temp = node.getlist();
        for(unsigned int i=0;i<temp.size();i++){
            std::cout << "<methodstart>" <<"\n";
            std::cout << temp.size() <<"\n";
            temp[i]->accept(*this);
            std::cout <<"<methodend>\n";
        }
        std::cout <<"end\n";
    }

    virtual void visit(ArgNode& node)
    {
        std::cout << "arguments started\n";
        vector <ASTnode*> temp = node.getlist();
        for(unsigned int i=0;i<temp.size();i++){
            std::cout << "<methodstart>" <<"\n";
            // std::cout << temp.size() <<"\n";
            temp[i]->accept(*this);
            std::cout <<"<argumentsend>\n";
        }
        std::cout <<"end\n";
    }

    virtual void visit(BinaryASTnode& node)
    {
        node.getLeft()->accept(*this);
        node.getRight()->accept(*this);
        std::cout << node.getBinOperator() << " ";
    }

    virtual void visit(TernaryASTnode& node)
    {
        node.getFirst()->accept(*this);
        node.getSecond()->accept(*this);
        node.getThird()->accept(*this);
        std::cout << "? ";
    }

     virtual void visit(VarDeclNode& node)
    {
        std::cout << "D var started\n";
        if(node.getNode())
        node.getNode()->accept(*this);
        std::cout << "D ended\n";
    }

    virtual void visit(Statement& node)
    {
        std::cout << "s var started\n";
        if(node.getNode())
        node.getNode()->accept(*this);
        std::cout << "s ended\n";
    }

    virtual void visit(FieldDecNode& node)
    {
        std::cout << "Dfield started\n";
        if(node.getNode())
        node.getNode()->accept(*this);
        std::cout << "D ended\n";
    }

    virtual void visit(StLocationNode& node)
    {
        std::cout << "loc field started\n";
        if(node.getlocation())
        node.getlocation()->accept(*this);
        if(node.getexpr())
        node.getexpr()->accept(*this);
        std::cout << "loc field ended\n";
    }

    virtual void visit(IntLitNode& node) 
    {
        std::cout << node.getIntLit() << " ";
    }

    virtual void visit(BoolLitNODe& node) 
    {
        std::cout << node.getBoolLit() << " ";
    }

    virtual void visit(CharLitNode& node) 
    {
        std::cout << node.getCharLit() << " ";
    }

    virtual void visit(IfNode& node)
    {
        std::cout << "if started\n";
        if(node.getblock())
        node.getblock()->accept(*this);
        if(node.getexpr())
        node.getexpr()->accept(*this);
        std::cout << "if ended\n";
    }
    virtual void visit(BlockASTnode& node)
    {
        std::cout << "block started\n";
        if(node.getvardecl())
        node.getvardecl()->accept(*this);
        if(node.getstatements())
        node.getstatements()->accept(*this);
        std::cout << "block ended\n";
    }
};

#endif

