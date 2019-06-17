class Queue:
    def __init__(self, max_size, size = 0, front = 0, rear = 0):
        self.queue = [[] for i in range(max_size)]# creates a list [0,0,0,0,0]
        self.max_size = max_size
        self.size = size
        self.front = front
        self.rear = rear

    def enqueue(self,data):
        if not self.isFull():
            self.queue[self.rear] = data
            self.rear = (self.rear + 1)%self.max_size
            self.size += 1
        else:
            print("Queue is full")

    def dequeue(self):
        if not self.isEmpty():
            print(self.queue[self.front], 'is removed')
            self.front = (self.front + 1)%self.max_size
            self.size -= 1
        else:
            print('Queue is empty')

    def isEmpty(self):
        return self.size == 0

    def isFull(self):
        return self.size == self.max_size

    def show(self):
        print("Queue contents are:",end = " ")
        for i in range(self.size):
            print(self.queue[int((i+self.front)%self.max_size)], end=" ")

q = Queue(5)

q.dequeue()
q.enqueue(4)
q.enqueue(8)
q.enqueue(7)
q.enqueue(3)
q.dequeue()
q.enqueue(9)
q.enqueue(2)

q.show()