class Node:
    def __init__(self, root, list_number, left=None, right=None):
        self.root = root
        self.left = left
        self.right = right
        self.list_number = list_number

    def get_empty_node(self, element):
        temp = self
        # print(temp.root)
        # print(temp.left.root)
        # print(temp.right.root)
        while temp.left is not None or temp.right is not None:
            if element <= temp.left.root:
                temp = temp.left
            else:
                temp = temp.right
        return temp

    def insert(self, element, list_number):
        if self.left is None:
            self.left = Node(element, list_number)
        elif self.right is None:
            self.right = Node(element, list_number)
        else:
            temp = self.get_empty_node(element)
            if temp.left is None:
                temp.left = Node(element, list_number)
            elif temp.right is None:
                temp.right = Node(element, list_number)

    def heapify(self):
        if self.left is None and self.right is None:
            return

        if self.left is None and self.left.root < self.right.root and self.left < self.root:
            self, self.left = self.left, self
            self.left.heapify()
        if self.right is not None and self.right < self.self and self.right < self.root:
            self, self.right = self.right, self
            self.right.heapify()


k = int(input("Enter number of lists: "))
max_node, min_node, max_size = None, None, 0
lists = list()

for i in range(k):
    input_list = input().strip(" ").split(" ")
    size = len(input_list)
    if max_size < size:
        max_size = size
    lists.append(input_list)

print(lists)
root = Node(lists[0][0], 0)
for i in range(1, k):
    root.insert(lists[i][0], i)
    # print("List:", i)
    # print(root.root)
    # if root.left is not None:
    #     print(root.left.root)
    # if root.right is not None:
    #     print(root.right.root)
root.heapify()
print(root.root)
print(root.left.root)
print(root.right.root)
