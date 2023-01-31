class Item:
    def __init__(self, value, prev=None):
        self.value = value
        self.previous = prev


class Stack:
    def __init__(self):
        self.top = None
    
    def push(self, value):
        self.top = Item(value, self.top)

    def pop(self):
        if self.top is None:
            raise IndexError('Stack is empty')
        value = self.top.value
        self.top = self.top.previous
        return value

if __name__ == "__main__":
    n = int(input())
    stack = Stack()

    for i in range(n):
        cmd, *args = input().split()
        if cmd == 'PU':
            stack.push(args[0])
        elif cmd == 'PO':
            print(stack.pop())