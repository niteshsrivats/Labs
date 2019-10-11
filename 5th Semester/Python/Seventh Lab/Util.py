from CallDetail import CallDetail


class Util:
    def __init__(self, call_objects=list()):
        self.call_objects = call_objects

    def get_call_objects(self):
        return self.call_objects

    def set_call_objects(self, call_objects):
        self.call_objects = call_objects

    def parse_customer(self, call_strings):
        call_objects = self.get_call_objects()
        for string in call_strings:
            caller, callee, duration, call_type = string.strip(" ").split(", ")
            call_objects.append(CallDetail(
                caller, callee, duration, call_type))
        for call_object in call_objects:
            print(call_object)
        self.set_call_objects(call_objects)


if __name__ == "__main__":
    call_strings = ["9900000001, 9800000001, 30, STD",
                    "9900000002, 9800000002, 20, Local",
                    "9900000003, 9800000003, 40, ISD"]
    demo = Util()
    demo.parse_customer(call_strings)
