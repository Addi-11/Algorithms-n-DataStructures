#python lists are implemented as c arrays rather than linked lists..which explains the time-complexity of each operation to be O(n)..unlike the required queue operations to be O(1)
class Queue:
    def __init__(self):
        self.queue = []
        self.size = 0
        self.maxsize = 10

    def enqueue(self,item):
        if self.size < self.maxsize:
            self.queue.append(item)
            #list imlementation in python in worst case may even take O(n) time

    def dequeue(self):
        self.queue.pop()
    
    def __str__(self):
        return str(self.queue)

line  = Queue()
line.enqueue(5)
line.enqueue(4)
line.enqueue(3)
print(line)
line.dequeue()
line.enqueue(2)
print(line)