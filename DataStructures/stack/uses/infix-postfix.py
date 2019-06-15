#infix to postfix transformation

def Infix_Postfix(exp):
    opans = []
    ans = []
    dans = []
    operand = IdentifyOperand(exp.split(" "))
    operator = IdentifyOperator(exp.split(" "))
    explist = exp.split(" ") 

    for i in explist:
        if i in operand:
            ans.append(i)
            #empty the dans and ans only after pushing one more operand
            if len(dans) is not 0:
                ans.append(dans.pop())
                ans.append(opans.pop())
        elif i in operator:
            if len(opans) is not 0 and HighPresedence(i,opans[-1]):
                dans.append(i)
            else:
                opans.append(i)

    #for any leftovers
    for i in opans:   
        ans.append(i)

    return ''.join(ans)

def IdentifyOperand(explist):
    op = ['-','+','*','/']
    operandlist = []
    for i in explist:
        if i not in op:
            operandlist.append(i)

    return operandlist

def IdentifyOperator(explist):
    op = ['-','+','*','/']
    operatorlist = []
    for i in explist:
        if i in op:
            operatorlist.append(i)

    return operatorlist

def HighPresedence(op1,op2):

    op = ['-','+','*','/']
    if op.index(op1) > op.index(op2):
        return True
    else:
        return False
 


line = "a + b * n - g / k" #abn*+gk/-
line2 = "r * p / k + o - h * g + f / m - d"#rpk/*ohg*-fm/+d+-
HighPresedence('*','+')
print("Postfix Form: ",Infix_Postfix(line2))