
from tkinter import Tk, Frame, Label, Button, Checkbutton, Radiobutton, OptionMenu, W, Text, WORD, END, StringVar, BooleanVar


class Application(Frame):
    def __init__(self, root):
        Frame.__init__(self, root)
        self.grid()
        self.create_widgets()

    def create_widgets(self):
        self.create_languages()
        self.create_movies()
        self.create_number_of_tickets()
        self.create_text()
        self.create_botton()

    def create_languages(self):
        self.language = StringVar()
        Label(self, text="Languages:").grid(sticky=W)
        Radiobutton(self, text="English", variable=self.language,
                    value="English").grid(sticky=W)
        Radiobutton(self, text="Hindi", variable=self.language,
                    value="Hindi").grid(sticky=W)
        Radiobutton(self, text="Tamil", variable=self.language,
                    value="Tamil").grid(sticky=W)

    def create_movies(self):
        self.movies = [BooleanVar(), BooleanVar(), BooleanVar()]
        Label(self, text="Movies:").grid(sticky=W)
        Checkbutton(self, text="Good Will Hunting",
                    variable=self.movies[0]).grid(sticky=W)
        Checkbutton(self, text="Beautiful Mind",
                    variable=self.movies[1]).grid(sticky=W)
        Checkbutton(self, text="Rocky Balboa",
                    variable=self.movies[2]).grid(sticky=W)

    def create_botton(self):
        Button(self, text="Book", command=self.update_text).grid(sticky=W)

    def create_number_of_tickets(self):
        self.tickets = StringVar(value="1")
        choices = [i for i in range(1, 6)]
        OptionMenu(self, self.tickets, *choices).grid()

    def create_text(self):
        self.text = Text(self, width=12, height=1, wrap=WORD)
        self.text.grid()

    def update_text(self):
        self.text.delete(0.0, END)
        if self.language.get() == "":
            self.text.insert(0.0, "Unsuccessful")
            return

        for movie in self.movies:
            if movie.get() == True:
                self.text.insert(0.0, "Successful")
                return

        self.text.insert(0.0, "Unsuccessful")


root = Tk()
root.title("Movie Booking")
root.geometry("500x500")
app = Application(root)
root.mainloop()
