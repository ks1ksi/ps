import sys
input = sys.stdin.readline

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
    
    def __str__(self):
        return str(self.data)

    

class Tree:
    def __init__(self, root):
        self.root = root

    def find_node(self, node, data):
        if node is None:
            return
        if node.data == data:
            return node
        
        cur = self.find_node(node.left, data)
        if cur is not None:
            return cur
        cur = self.find_node(node.right, data)
        if cur is not None:
            return cur

    def add_node(self, parent, data, lr):
        pnode = self.find_node(self.root, parent)
        new_node = Node(data)
        if lr == 0:
            pnode.left = new_node
        else:
            pnode.right = new_node

    def preorder(self, node):
        if node is not None:
            print(node, end='')
            self.preorder(node.left)
            self.preorder(node.right)

    def inorder(self, node):
        if node is not None:
            self.inorder(node.left)
            print(node, end='')
            self.inorder(node.right)

    def postorder(self, node):
        if node is not None:
            self.postorder(node.left)
            self.postorder(node.right)
            print(node, end='')


N = int(input())
root, l, r = input().split()
rt = Node(root)
t = Tree(rt)
t.root = rt
if l != '.':
    t.add_node(root, l, 0)
if r != '.':
    t.add_node(root, r, 1)

for _ in range(N-1):
    p, l, r = input().split()
    if l != '.':
        t.add_node(p, l, 0)
    if r != '.':
        t.add_node(p, r, 1)    

t.preorder(t.root)
print()
t.inorder(t.root)
print()
t.postorder(t.root)
