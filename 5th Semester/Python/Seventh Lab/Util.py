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
            caller, callee, duration, call_type = string.strip(" ").split(",")
            call_objects.append(CallDetail(
                caller, callee, duration, call_type))
        print(call_objects)
        self.set_call_objects(call_objects)
