import sqlite3 as sql


class Sequence:
    def __init__(self, current=0):
        self.current = current

    def getCurrent(self):
        return self.current

    def getNextSequence(self):
        self.current += 1
        return self.current


class User:
    def __init__(self, row_id, user_id, name, semester):
        self.row_id = row_id
        self.user_id = user_id
        self.name = name
        self.semester = semester

    def __str__(self):
        return "Row Id: " + str(self.row_id) + "\nUser Id: " + self.user_id + "\nName: " + self.name + "\nSemester: " + str(self.semester)

    def getAsList(self):
        return [self.row_id, self.user_id, self.name, self.semester]


class UserTable:
    def __init__(self):
        self.connection = sql.connect("demo.users")
        self.cursor = self.connection.cursor()
        try:
            self.cursor.execute(
                "CREATE TABLE users (row_id INTEGER PRIMANY KEY, user_id VARCHAR(256) NOT NULL UNIQUE, name VARCHAR(256) NOT NULL, semester INTEGER NOT NULL)")
        except sql.OperationalError:
            pass

    def addUser(self, user):
        try:
            self.cursor.execute(
                "INSERT INTO users VALUES(?, ?, ?, ?)", user.getAsList())
            self.connection.commit()
            return True
        except sql.IntegrityError:
            return False

    def getUsers(self):
        self.cursor.execute("SELECT * FROM users")
        for user_record_tuple in self.cursor.fetchall():
            yield self.getUserFromUserRecordTuple(user_record_tuple)

    def getUserById(self, user_id):
        self.cursor.execute(
            "SELECT * FROM users WHERE user_id='%s'" % user_id)
        return self.getUserFromUserRecordTuple(self.cursor.fetchone())

    def updateUser(self, user):
        db_user = self.getUserById(user.user_id)
        if db_user is not None:
            if user.name != db_user.name and user.semester != db_user.semester:
                self.cursor.execute(
                    "UPDATE users SET name='%s', SET semester='%s'" % user.name % user.semester)
                self.connection.commit()
            elif user.name != db_user.name:
                self.cursor.execute(
                    "UPDATE users SET name = '%s'" % user.name)
                self.connection.commit()
            elif user.semester != db_user.semester:
                self.cursor.execute(
                    "UPDATE users SET semester=%s" % user.semester)
                self.connection.commit()
            return True
        return False

    def deleteUserById(self, user_id):
        if self.getUserById(user_id) is not None:
            self.cursor.execute(
                "DELETE FROM users WHERE users.user_id='%s'" % user_id)
            self.connection.commit()
            return True
        else:
            return False

    def getUserFromUserRecordTuple(self, user_record_tuple):
        if user_record_tuple is None:
            return None
        return User(user_record_tuple[0], user_record_tuple[1], user_record_tuple[2], user_record_tuple[3])


if __name__ == "__main__":
    sequence = Sequence()
    userRepository = UserTable()
    user = User(sequence.getNextSequence(), "1BM17CS037", "Nitesh", 5)
    print("Add User:", userRepository.addUser(user))
    print("\nGet Users:")
    for user in userRepository.getUsers():
        print(user)
    print("\nGet User By Id:")
    print(userRepository.getUserById("1BM17CS037"))
    print("\nUpdate User:", userRepository.updateUser(
        User(user.row_id, user.user_id, "Nitesh Srivats", 5)))
    print(userRepository.getUserById("1BM17CS037"))
    print("\nDelete User By Id:", userRepository.deleteUserById(user.user_id))
