class Brackets:
    def __init__(self, string=None):
        self.string = string

    def validate(self):
        if self.string is None:
            return False
        stack = list()
        for character in self.string:
            if character in "{[(":
                stack.append(character)
            else:
                if character == "]" and stack[-1] == "[":
                    stack.pop()
                elif character == "}" and stack[-1] == "{":
                    stack.pop()
                elif character == ")" and stack[-1] == "(":
                    stack.pop()
                else:
                    return False
        return True


if __name__ == "__main__":
    sequence = input("Enter a sequence: ")
    demo = Brackets(sequence)
    print("Sequence Validity: ", demo.validate())
