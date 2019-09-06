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

    def set_age(self, age):
        if self.validate_age(age):
            self.age = age

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
