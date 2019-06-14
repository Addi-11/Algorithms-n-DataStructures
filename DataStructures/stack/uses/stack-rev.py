class Stack:
    def __init__(self):
        self.items = []
    
    def __str__(self):
        return str(self.items)

    def rev(self):
        return self.items[::-1]

    def isEmpty(self):
        return self.items == []

    def pop(self):
        return self.items.pop(0)

    def push(self, item):
        self.items.insert(0,item)

    def size(self):
        return len(self.items)

s = Stack()
print(s.isEmpty())
s.push('hi')
s.push('mississipi')
s.push(54)
s.pop()
s.push('jglkdjh5dg4')
print(s)
print(s.rev())
print(s.isEmpty())