def ArePair(open,close):
    if open == '(' and close == ')':
        return True
    elif open == '{' and close == '}':
        return True
    elif open =='[' and close ==']':
        return True
    else:
        return False

def top(l):
    return l(0)

def isEmpty(l):
    if l(0) is None:
        return True
    else:
        return False

def chkParanthesis(test):
    s = []
    open = ['(','{','[']
    close = [')','}',']']

    for i in test:
        if i in open:
            s.append(i)
        elif i in close:
            if not ArePair(top(s),i) or isEmpty(s):
                return False
            else:
                s.pop()



test = "{[}(])"
test2 = "{()}[]({})"
test3 = ")(}[]{"
test4 = "{)()}"
if(chkParanthesis(test)):
    print("Balanced")
else:
    print("Not balanced")