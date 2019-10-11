class Student:
    def __init__(self):
        self.marks = None
        self.age = None

    def get_marks(self):
        return self.marks

    def get_age(self):
        return self.age

    def set_marks(self, marks):
        if self.validate_marks(marks):
            self.marks = marks
        else:
            print("Invalid marks")

    def set_age(self, age):
        if self.validate_age(age):
            self.age = age
        else:
            print("Invalid age")

    def validate_marks(self, marks):
        if marks is not None and 0 <= marks <= 100:
            return True
        return False

    def validate_age(self, age):
        if age is not None and age > 20:
            return True
        return False

    def check_qualification(self):
        if self.validate_age(self.age) and self.marks >= 65:
            return True
        return False


if __name__ == "__main__":
    age, marks = input("Enter student age & marks: ").strip(" ").split(" ")
    demo = Student()
    demo.set_age(age)
    demo.set_marks(marks)
    print("Qualified: ", demo.check_qualification())
