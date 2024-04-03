import sys

input = sys.stdin.readline
n = int(input())


class Node:
    def __init__(self, item, left, right):
        self.item = item
        self.left = left
        self.right = right


def preorder(node):
    if node.item == ".":
        return
    print(f"{node.item}", end="")
    if node.left != ".":
        preorder(tree[node.left])
    if node.right != ".":
        preorder(tree[node.right])


def inorder(node):
    if node.item == ".":
        return
    if node.left != ".":
        inorder(tree[node.left])
    print(f"{node.item}", end="")
    if node.right != ".":
        inorder(tree[node.right])


def postorder(node):
    if node.item == ".":
        return
    if node.left != ".":
        postorder(tree[node.left])
    if node.right != ".":
        postorder(tree[node.right])
    print(f"{node.item}", end="")


tree = {}
for _ in range(n):
    item, left, right = input().split()
    tree[item] = Node(item, left, right)

preorder(tree["A"])
print()
inorder(tree["A"])
print()
postorder(tree["A"])
