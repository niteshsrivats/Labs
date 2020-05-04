# Create a knowledge base using prepositional logic and show whether the given query entails the knowledge base or not .

# For 2 variables
truthCombinations = [
    {"p": False, "q": False},
    {"p": False, "q": True},
    {"p": True, "q": False},
    {"p": True, "q": True}
]


def isOperator(character):
    if character == "~" or character == "v" or character == "^":
        return True
    return False


def getPostfix(infix):
    precedence = {"v": 1, "^": 2, "~": 3, "(": -1}
    postfix = ""
    stack = []

    for character in infix:
        # Left parenthesis
        if character == "(":
            stack.append(character)
        # Right parenthesis
        elif character == ")":
            while stack[-1] != "(":
                postfix += stack.pop()
            stack.pop()
        # Operator
        elif isOperator(character):
            while (stack != []) and (precedence[character] <= precedence[stack[-1]]):
                postfix += stack.pop()
            stack.append(character)
        # Operand
        else:
            postfix += character

    while stack != []:
        postfix += stack.pop()

    return postfix


def evaluate(expression, truthValue):
    stack = []
    for character in expression:
        if character == "~":
            operand = stack.pop()
            stack.append(not truthValue[operand])

        elif character == "^":
            operand1 = stack.pop()
            operand2 = stack.pop()
            stack.append(operand1 and operand2)

        elif character == "v":
            operand1 = stack.pop()
            operand2 = stack.pop()
            stack.append(operand1 or operand2)

        else:
            stack.append(truthValue[character])

    return stack.pop()


def getEntailment(knowledgeBase, query):
    print("Truth table: ")
    print("P \t Q \t Knowledge Base  Query")
    isEntailed = True
    for truthValue in truthCombinations:
        knowledgeBaseTruth = evaluate(getPostfix(knowledgeBase), truthValue)
        queryTruth = evaluate(getPostfix(query), truthValue)
        print(truthValue["p"], truthValue["q"],
              knowledgeBaseTruth, queryTruth, sep="\t")
        if knowledgeBaseTruth and not queryTruth:
            isEntailed = False
    if isEntailed:
        print("Knowledge base entails the query")
    else:
        print("Knowledge base does not entail the query")


def main():
    knowledgeBase = input("Enter rule: ")
    query = input("Enter query: ")
    getEntailment(knowledgeBase, query)


main()

# Sample input
# Knowledge Base : pvq^(p^q)
# Query : p^q^(pvq)
