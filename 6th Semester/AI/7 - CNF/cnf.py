"""
    The below program works for most scenarios.
    This program does not take into account 3 variables.
    Ex: (A ^ B ^ C)
    This program also almost blinding applies the distributive property without taking into regards the constraints of CNF
"""


def get_postfix(infix):
    precedence = {"_": 0, "-": 0, "v": 1, "^": 2, "~": 3, "(": -1}
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
        elif character in "_-v^~":
            while stack != [] and precedence[character] <= precedence[stack[-1]]:
                postfix += stack.pop()
            stack.append(character)
        # Operand
        else:
            postfix += character

    while stack:
        postfix += stack.pop()

    return postfix


def split(expression):
    # Expression must be enclosed in brackets
    bracket = 0
    first_bracket_done, get_second = False, False
    first, second, operator = str(), str(), str()

    for character in expression:
        insert = True
        if character == "(":
            bracket += 1
            # Skip first bracket
            if bracket == 1:
                if first_bracket_done:
                    # if expression is not enclosed in brackets
                    return None, None, None
                first_bracket_done = True
                insert = False
        elif character == ")":
            # Skip last bracket
            if bracket == 1:
                insert = False
            bracket -= 1
        elif bracket == 1 and character in "v^":
            get_second = True
            insert = False
            operator = character

        if insert:
            if get_second:
                second += character
            else:
                first += character

    return first, second, operator


def evaluate_bi_directional(first, second):
    first_second_implies = evaluate_implies(first, second)
    second_first_implies = evaluate_implies(second, first)
    return "({}^{})".format(first_second_implies, second_first_implies)


def evaluate_implies(first, second):
    not_first = evaluate_not(first)
    return "({}v{})".format(not_first, second)


def evaluate_not(operand):
    if "v" in operand or "^" in operand:
        first, second, operator = split(operand)
        # Middle Operator is reversed (De Morgan's Law)
        if operator == "^":
            operator = "v"
        else:
            operator = "^"

        # print(first, second, operator)

        return "(" + evaluate_not(first) + \
               operator + evaluate_not(second) + ")"

    if operand[0] == "~":
        return operand[1]
    return "~" + operand


def evaluate_and(first, second):
    return "({}^{})".format(first, second)


def evaluate_or(first, second):
    return "({}v{})".format(first, second)


def get_distributive_result(operand, expression, operator):
    first_half, last_half, split_operator = split(expression)
    return apply_distributive(first=operand, second=first_half, operator=operator) + \
           split_operator + \
           apply_distributive(first=operand, second=last_half, operator=operator)


def apply_distributive(first, second, operator):
    if len(first) > 2 and len(second) > 2:
        if operator == '^':
            return check_distributive(first) + operator + check_distributive(second)
        return get_distributive_result(operand=first, expression=second, operator=operator)
    elif len(first) > 2:
        return get_distributive_result(operand=second, expression=first, operator=operator)
    elif len(second) > 2:
        return get_distributive_result(operand=first, expression=second, operator=operator)
    else:
        return "({}{}{})".format(first, operator, second)


def check_distributive(expression):
    first, second, operator = split(expression)
    if first is None:
        return expression

    if len(first) > 2 or len(second) > 2:
        return apply_distributive(first, second, operator)
    else:
        return expression


def main():
    statement = input().replace("<=>", "_").replace("=>", "-")
    expression = get_postfix(statement)

    stack = []
    for character in expression:
        if character in "_-v^~":
            second = stack.pop()
            first = stack.pop()

            if character == '_':
                result = evaluate_bi_directional(first, second)
            elif character == '-':
                result = evaluate_implies(first, second)
            elif character == '^':
                result = evaluate_and(first, second)
            elif character == 'v':
                result = evaluate_or(first, second)
            elif character == '~':
                result = evaluate_not(first)
            else:
                print("Unknown Character:", character)
                exit()

            stack.append(result)
        else:
            stack.append(character)

    result = check_distributive(stack.pop())
    first, second, operator = split(result)
    # Remove trailing brackets if any
    if first is None:
        print(result)
    else:
        print(first + operator + second)


if __name__ == '__main__':
    main()
    # A<=>B<=>C
    # A<=>(B^C)
