
#ifndef AST_H
#define AST_H

#include <string>
#include <vector>

using namespace std;

class IfNode;
class IfElseNode;
class ForAst;
class ReturnNode;
class StTerminateNode;
class BlockNode;
class StNode;
class BlockASTnode;
class MthdNode;
class MethodtypedeclASTnode;
class BinaryASTnode;
class Typenode;
class VarNode;
class VarsNode;
class MethodNode;
class StrLitNode;
class CalloutArgNode;
class CalloutNode;
class MethodArgNode;
class UnaryOPNode;
class TernaryASTnode;
class IntLitNode;
class ProgramNode;
class StLocationNode;
class MStNode;
class FuncNode;
class Statement;
class Expr;
class VariaNode;
class VarDeclNode;
class VarDecsnode;
class Locnode;
class BoolLitNODe;
class CharLitNode;
class FieldDecNode;
class ArgNode;
class MethodCallNode;

class ASTvisitor
{
  public:
    virtual void visit(MethodNode& node) = 0;
    virtual void visit(StrLitNode& node) = 0;
    virtual void visit(CalloutArgNode& node) = 0;
    virtual void visit(CalloutNode& node) =0;
    virtual void visit(MethodArgNode& node) = 0;
    virtual void visit(ArgNode& node) = 0;
    virtual void visit(MethodCallNode& node) = 0;
    virtual void visit(VarDeclNode& node) = 0;
    virtual void visit(VarDecsnode& node) = 0;
    virtual void visit(Locnode& node) = 0;
    virtual void visit(MthdNode& node) = 0;
    virtual void visit(FuncNode& node) =0;
    virtual void visit(Statement& node) = 0;
    virtual void visit(Expr& node) = 0;
    virtual void visit(BoolLitNODe& node) = 0;
    virtual void visit(CharLitNode& node) = 0;
    virtual void visit(FieldDecNode& node) = 0;
    virtual void visit(VarNode& node) = 0;
    virtual void visit(VarsNode& node) = 0;
    virtual void visit(StLocationNode& node) = 0;
    virtual void visit(MStNode& node) = 0;
    virtual void visit(IfNode& node) = 0;
    virtual void visit(IfElseNode& node) = 0;
    virtual void visit(ForAst& node) = 0;
    virtual void visit(ReturnNode& node) =0;
    virtual void visit(BinaryASTnode& node) = 0;
    virtual void visit(UnaryOPNode& node) = 0;
    virtual void visit(TernaryASTnode& node) = 0;
    virtual void visit(IntLitNode& node) = 0;
    virtual void visit(ProgramNode& node) = 0;
    virtual void visit(VariaNode& node) = 0;
    virtual void visit(StTerminateNode& node) = 0;
    virtual void visit(BlockNode& node) = 0;
    virtual void visit(StNode& node) = 0;
    virtual void visit(BlockASTnode& node) = 0;
};

class Cgenvisitor
{
  public:
    virtual void cgen(MethodNode& node) = 0;
    virtual void cgen(StrLitNode& node) = 0;
    virtual void cgen(CalloutArgNode& node) = 0;
    virtual void cgen(CalloutNode& node) =0;
    virtual void cgen(MethodArgNode& node) = 0;
    virtual void cgen(ArgNode& node) = 0;
    virtual void cgen(MethodCallNode& node) = 0;
    virtual void cgen(VarDeclNode& node) = 0;
    virtual void cgen(VarDecsnode& node) = 0;
    virtual void cgen(Locnode& node) = 0;
    virtual void cgen(MthdNode& node) = 0;
    virtual void cgen(FuncNode& node) =0;
    virtual void cgen(Statement& node) = 0;
    virtual void cgen(Expr& node) = 0;
    virtual void cgen(BoolLitNODe& node) = 0;
    virtual void cgen(CharLitNode& node) = 0;
    virtual void cgen(FieldDecNode& node) = 0;
    virtual void cgen(VarNode& node) = 0;
    virtual void cgen(VarsNode& node) = 0;
    virtual void cgen(StLocationNode& node) = 0;
    virtual void cgen(MStNode& node) = 0;
    virtual void cgen(IfNode& node) = 0;
    virtual void cgen(IfElseNode& node) = 0;
    virtual void cgen(ForAst& node) = 0;
    virtual void cgen(ReturnNode& node) =0;
    virtual void cgen(BinaryASTnode& node) = 0;
    virtual void cgen(UnaryOPNode& node) = 0;
    virtual void cgen(TernaryASTnode& node) = 0;
    virtual void cgen(IntLitNode& node) = 0;
    virtual void cgen(ProgramNode& node) = 0;
    virtual void cgen(VariaNode& node) = 0;
    virtual void cgen(StTerminateNode& node) = 0;
    virtual void cgen(BlockNode& node) = 0;
    virtual void cgen(StNode& node) = 0;
    virtual void cgen(BlockASTnode& node) = 0;
};





class ASTnode
{
  public :
    virtual ~ASTnode()
    {
    }
    virtual void accept(ASTvisitor& V) = 0;
};


class ProgramNode : public ASTnode
{
    public:
    ProgramNode (ASTnode* cParam) {
        this->node = cParam;
    }

    ASTnode* getNode() {
        return node;
    }
    
    virtual void accept(ASTvisitor& v) {
        v.visit(*this);
    }

  private:
    ASTnode* node;
};

class FuncNode : public ASTnode
{
    public:
    FuncNode () {

    }

    void push_back(ASTnode *vuy)
    {
        functions.push_back(vuy);
        return;
    }

    vector  <ASTnode*> getlist(){
        return functions;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    vector <ASTnode*> functions;
};

class VariaNode : public ASTnode
{
    public:
    VariaNode () {

    }
    void push_back(string s)
    {
        vars.push_back(s);
        return;
    }
    vector  <string> getlist(){
        return vars;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    vector <string> vars;
};

class VarNode : public ASTnode
{
    public:
    VarNode (string variableid,ASTnode* intLit){
        this->node = intLit;
        this->variableid = variableid;
    }

    VarNode (string variableid){
        this->node = NULL;
        this->variableid = variableid;
    }

    ASTnode* getNode() {
        return node;
    }

    string getVariable()
    {
        return variableid;
    }
    
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    ASTnode* node;
    string   variableid;
};

class VarDecsnode : public ASTnode
{
    public:
    VarDecsnode () {

    }

    void push_back(ASTnode *vuy)
    {
        vardecls.push_back(vuy);
        return;
    }

    vector  <ASTnode*> getlist(){
        return vardecls;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    vector <ASTnode*> vardecls;
};

class VarsNode : public ASTnode
{
    public:
    VarsNode (){
        
    }

    void push_back(ASTnode *vuy){
        var.push_back(vuy);
    }

    vector <ASTnode*> getlist(){
        return var;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    vector <ASTnode*> var;
};

class StNode : public ASTnode
{
    public:
    StNode (){
        
    }

    void push_back(ASTnode *vuy){
        stms.push_back(vuy);
    }

    vector <ASTnode*> getlist(){
        return stms;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    vector <ASTnode*> stms;
};

class ArgNode : public ASTnode
{
    public:
    ArgNode(){
        this->str1 = "";
        this->str2 = "";
    }

    ArgNode(string type,string id){
        this->str1 = type;
        this->str2 = id;
    }

    void push_back(ASTnode *vuy){
        arg.push_back(vuy);
    }

    vector <ASTnode*> getlist(){
        return arg;
    }

    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    vector <ASTnode*> arg;
    string str1;
    string str2;
};

class CalloutNode : public ASTnode
{
    public:
    CalloutNode (){
        
    }
    void push_back(ASTnode *vuy){
        callout.push_back(vuy);
    }
    vector <ASTnode*> getlist(){
        return callout;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    vector <ASTnode*> callout;
};

class MethodArgNode : public ASTnode
{
    public:
    MethodArgNode (){
        
    }
    void push_back(ASTnode *vuy){
        msriarg.push_back(vuy);
    }
    vector <ASTnode*> getlist(){
        return msriarg;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    vector <ASTnode*> msriarg;
};

class VarDeclNode : public ASTnode
{
    public:
    VarDeclNode (string typevar,ASTnode* variables, string s){
        this->node = variables;
        this->typevariable = typevar;
        this->se = s;
    }

    ASTnode* getNode() {
        return node;
    }
    

    string getVariabletype()
    {
        return typevariable;
    }
    
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    ASTnode* node;
    string   typevariable, se;
};

/*class Typenode : public ASTnode
{
    public:
    Typenode (string typevar){
        this->typevariable = typevar;
    }    
    
    string getVariabletype()
    {
        return typevariable;
    }
    
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    string   typevariable;
};*/


class CalloutArgNode : public ASTnode{
    public:
    CalloutArgNode(ASTnode* callout){
        this->node = callout;
    }
    ASTnode* getNode() {
        return node;
    }
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
    ASTnode* node;
};

class MethodNode : public ASTnode
{
    public:
    MethodNode(string s1){
        this->stringLit = s1;
    }
    string getString(){
        return stringLit;
    }
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        string stringLit;
};


class Statement : public ASTnode
{
    public:
    Statement (ASTnode* statement){
        this->statement = statement;
    }

    ASTnode* getNode() {
        return statement;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    ASTnode* statement;
};

class Expr : public ASTnode
{
    public:
    Expr (ASTnode* expr){
        this->expr = expr;
    }

    ASTnode* getNode() {
        return expr;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    ASTnode* expr;
};

class MStNode : public ASTnode
{
    public:
    MStNode (ASTnode* method_call){
        this->methodcall = method_call;
    }
    ASTnode* getmethodcall() {
        return methodcall;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    ASTnode* methodcall;
};

class StLocationNode : public ASTnode
{
    public:
    StLocationNode (ASTnode* location, string op,ASTnode* expr){
        this->location = location;
        this->op = op;
        this->expr = expr;
    }
    ASTnode* getlocation() {
        return location;
    }
    string getop()
    {
        return op;
    }
    ASTnode* getexpr(){return expr;}
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
  private:
    ASTnode* expr;
    ASTnode* location;
    string   op;
};

class IfNode : public ASTnode
{
    public:
    IfNode(ASTnode* expr,ASTnode* block){
        this->expr = expr;
        this->block = block;
    }
    ASTnode* getexpr(){return expr;}
    ASTnode* getblock(){return block;}
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        ASTnode* expr;
        ASTnode* block;
};

class BlockASTnode : public ASTnode
{
    public:
    BlockASTnode(ASTnode* vardecl,ASTnode* stms){
        this->stms = stms;
        this->vardecl = vardecl;
    }
    ASTnode* getvardecl(){return vardecl;}
    ASTnode* getstatements(){return stms;}
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        ASTnode* vardecl;
        ASTnode* stms;
};


class BlockNode : public ASTnode
{
    public:
    BlockNode(ASTnode* block){
        this->block = block;
    }
    ASTnode* getblock(){return block;}
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        ASTnode* block;
};

class ReturnNode : public ASTnode
{
    public:
    ReturnNode(ASTnode* expr){
        this->expr = expr;
    }
    ASTnode* getexpr(){return expr;}
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        ASTnode* expr;
};

class StTerminateNode : public ASTnode
{
    public:
    StTerminateNode(string s1){
        this->stringLit = s1;
    }
    string getstr(){return stringLit;}
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        string stringLit;
};

class IfElseNode : public ASTnode
{
    public:
    IfElseNode(ASTnode* expr,ASTnode* block1,ASTnode* block2){
        this->expr = expr;
        this->block1 = block1;
        this->block2 = block2;
    }
    ASTnode* getexpr(){return expr;}
    ASTnode* getblock1(){return block1;}
    ASTnode* getblock2(){return block2;}    
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        ASTnode* expr;
        ASTnode* block1;
        ASTnode* block2;
};

class MthdNode : public ASTnode
{
    public:
    MthdNode(string type,string id,ASTnode* arg,ASTnode* block){
        this->type = type;
        this->block = block;
        this->arg = arg;
        this->i = id;
    }
    string gettype(){return type;}
    ASTnode* getblock(){return block;}
    ASTnode* getarg(){return arg;}    
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        ASTnode* arg;
        ASTnode* block;
        string type;
        string i;
};


class MethodCallNode : public ASTnode
{
    public:
    MethodCallNode(ASTnode* methodname,ASTnode* msriarg){
        this->name = methodname;
        this->arg = msriarg;
        this->callout = "";
        this->stringLit = NULL;
        this->call = NULL;
    }
    MethodCallNode(string callout,ASTnode* stringlit){
        this->callout = callout;
        this->stringLit = stringlit;
        this->call = NULL;
        this->name = NULL;
        this->arg = NULL;
    }
    MethodCallNode(string callout,ASTnode* stringlit,ASTnode* call){
        this->callout = callout;
        this->stringLit = stringlit;
        this->call = call;
        this->name = NULL;
        this->arg = NULL;
    }
    ASTnode* getname() {return name;}
    ASTnode* getarg(){return arg;}
    ASTnode* getcall(){return call;}
    ASTnode* getstr(){return stringLit;}
    string getcallout(){return callout;}
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
    private:
    ASTnode* name;
    ASTnode* arg;
    ASTnode* call;
    ASTnode*   stringLit;
    string callout;
};

/*class MethodtypedeclASTnode : public ASTnode
{
    public:
    MethodtypedeclASTnode(ASTnode* type,string id,ASTnode* arg,ASTnode* block){
        this->type = type;
        this->block = block;
        this->arg = arg;
    }
    ASTnode* gettype(){return type;}
    ASTnode* getblock(){return block;}
    ASTnode* getarg(){return arg;}    
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        ASTnode* arg;
        ASTnode* block;
        ASTnode* type;
};*/
class ForAst : public ASTnode
{
    public:
    ForAst(string s1,ASTnode* expr1,ASTnode* expr2,ASTnode* block){
        this->expr1 = expr1;
        this->block = block;
        this->expr2 = expr2;
        this->stringLit = s1;
    }
    ASTnode* getexpr1(){return expr1;}
    ASTnode* getblock(){return block;}
    ASTnode* getexpr2(){return expr2;}
    string getstr(){return stringLit;}    
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        ASTnode* expr1;
        ASTnode* block;
        ASTnode* expr2;
        string stringLit;
};

class StrLitNode : public ASTnode
{
    public:
    StrLitNode(string s1){
        this->stringLit = s1;
    }
    string getString(){
        return stringLit;
    }
    virtual void accept(ASTvisitor& v){
        v.visit(*this);
    }
    private:
        string stringLit;
};

class FieldDecNode : public ASTnode
{
    public:
    FieldDecNode (string typefield,ASTnode* variable, string semi){
        this->node = variable;
        this->typefield = typefield;
        this->s = semi;
    }
    ASTnode* getNode() {
        return node;
    }
    string getFieldtype()
    {
        return typefield;
    }   
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    ASTnode* node;
    string   typefield, s;
};


class Locnode : public ASTnode
{
    public:
    Locnode (string locid,ASTnode* exp){
        this->node = exp;
        this->location = locid;
    }
    Locnode (string locid){
        this->node = NULL;
        this->location = locid;
    }
    ASTnode* getNode() {
        return node;
    }
    string getLocation()
    {
        return location;
    }
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }
  private:
    ASTnode* node;
    string   location;
};

class BinaryASTnode : public ASTnode
{
    public:
    BinaryASTnode (string binOp,
                   ASTnode* leftParam,
                   ASTnode* rightParam)
    :pLeft(leftParam)
    ,pRight(rightParam)
    ,mBinaryOperator(binOp)
    {
    }  
    ASTnode* getLeft()
    {
        return pLeft;
    }

    ASTnode* getRight()
    {
        return pRight;
    }

    string getBinOperator()
    {
        return mBinaryOperator;
    }
    
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    ASTnode* pLeft;
    ASTnode* pRight;
    string   mBinaryOperator;
};

class UnaryOPNode : public ASTnode
{
    public:
    UnaryOPNode (string unaryParam,ASTnode* texpr){
                       this->node = texpr;
                       this->op = unaryParam;
                   }
    ASTnode* getexpr()
    {
        return node;
    }
    string getUnaryOperator()
    {
        return op;
    }
    
    virtual void accept(ASTvisitor& v)
    {
        v.visit(*this);
    }

  private:
    ASTnode* node;
    string  op;
};

class TernaryASTnode : public ASTnode
{
    public:

    TernaryASTnode (ASTnode* firstArg,
                    ASTnode* secondArg,
                    ASTnode* thirdArg)
    :fir(firstArg)
    ,sec(secondArg)
    ,thir(thirdArg)
    {
    }
    ASTnode* getFirst()
    {
        return fir;
    }

    ASTnode* getSecond()
    {
        return sec;
    }

    ASTnode* getThird()
    {
        return thir;
    }

     virtual void accept(ASTvisitor& v) 
    {
      v.visit(*this);
    }

  private:
    ASTnode* fir;
    ASTnode* sec;
    ASTnode* thir;
};


class IntLitNode: public ASTnode
{
	public:
	IntLitNode(int intLit)
    : intLit(intLit)
    {
    }

    int getIntLit()
    {
        return intLit;
    }

    virtual void accept(ASTvisitor& v) 
    {
        v.visit(*this);
    }

  private:
	int intLit;
};

class BoolLitNODe: public ASTnode
{
	public:
	BoolLitNODe(bool booleanLit)
    : booleanLit(booleanLit)
    {
    }

    bool getBoolLit()
    {
        return booleanLit;
    }

    virtual void accept(ASTvisitor& v) 
    {
        v.visit(*this);
    }

  private:
	bool booleanLit;
};

class CharLitNode: public ASTnode
{
	public:
	CharLitNode(string s)
    {this->stringLit = s[1];
    }

    char getCharLit()
    {
        return stringLit;
    }

    virtual void accept(ASTvisitor& v) 
    {
        v.visit(*this);
    }

  private:
	char stringLit;
};

class ASTContext
{
  public:
    ASTnode* pRoot;
    ~ASTContext()
    {
	    clearAST();
    }
    void clearAST()
    {
        delete pRoot;
    }
};

#endif
