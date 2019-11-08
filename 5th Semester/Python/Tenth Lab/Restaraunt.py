
from tkinter import Tk, Frame, Label, Button, Checkbutton, W, S, Text, WORD, END, BooleanVar


class Application(Frame):
    def __init__(self, root):
        Frame.__init__(self, root)
        self.grid()
        self.create_widgets()

    def create_widgets(self):
        self.create_food_items()
        self.create_prices()
        self.create_botton()
        self.create_text()

    def create_food_items(self):
        self.selected_items = [BooleanVar(), BooleanVar(), BooleanVar()]
        Label(self, text="Foods:").grid(row=0, column=0, sticky=W)
        Checkbutton(self, text="Babycorn",
                    variable=self.selected_items[0]).grid(row=1, column=0, sticky=W)
        Checkbutton(self, text="Mushroom",
                    variable=self.selected_items[1]).grid(row=2, column=0, sticky=W)
        Checkbutton(self, text="Coke",
                    variable=self.selected_items[2]).grid(row=3, column=0, sticky=W)

    def create_prices(self):
        self.prices = [10, 15, 20]
        Label(self, text="Prices:").grid(row=0, column=1, sticky=W)
        Label(self, text=str(self.prices[0]) +
              "$").grid(row=1, column=1, sticky=W)
        Label(self, text=str(self.prices[1]) +
              "$").grid(row=2, column=1, sticky=W)
        Label(self, text=str(self.prices[2]) +
              "$").grid(row=3, column=1, sticky=W)

    def create_botton(self):
        Button(self, text="Order", command=self.update_text).grid(sticky=S)

    def create_text(self):
        Label(self, text="Total").grid(sticky=S)
        self.text = Text(self, width=12, height=1, wrap=WORD)
        self.text.grid()

    def update_text(self):
        total = 0
        index = 0
        for selected_item in self.selected_items:
            if selected_item.get():
                total += self.prices[index]
            index += 1
        self.text.delete(0.0, END)
        self.text.insert(0.0, str(total))


root = Tk()
root.title("Restaraunt Order")
root.geometry("500x500")
app = Application(root)
root.mainloop()
