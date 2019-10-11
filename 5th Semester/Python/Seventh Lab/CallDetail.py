class CallDetail:
    def __init__(self, caller=None, callee=None, duration=None, call_type=None):
        self.caller = caller
        self.callee = callee
        self.duration = duration
        self.call_type = call_type

    def __str__(self):
        return "Caller: " + self.get_caller() + "\nCallee: " + self.get_callee() + "\nDuration: " + self.get_duration() + "\nCallType: " + self.get_call_type() + "\n"

    def get_caller(self):
        return self.caller

    def get_callee(self):
        return self.callee

    def get_duration(self):
        return self.duration

    def get_call_type(self):
        return self.call_type

    def set_caller(self, caller):
        self.caller = caller

    def set_callee(self, callee):
        self.callee = callee

    def set_duration(self, duration):
        self.duration = duration

    def set_call_type(self, call_type):
        self.call_type = call_type
