from __future__ import annotations
from typing import Any, Type
import sys
sys.setrecursionlimit(10000)

class Node:
    def __init__(self, key: Any, value: Any, left: Node = None, right: Node = None):
        self.key = key
        self.value = value
        self.left = left
        self.right = right


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def search(self, key: Any) -> Any:
        p = self.root
        while True:
            if p is None:
                return None
            if key == p.key:
                return p.value
            elif key < p.key:
                p = p.left
            else:
                p = p.right

    def add(self, key: Any, value: Any) -> bool:
        if self.root is None:
            self.root = Node(key, value)
            return True

        def add_node(node: Node, key: Any, value: Any) -> None:
            if key == node.key:
                return False
            elif key < node.key:
                if node.left is None:
                    node.left = Node(key, value, None, None)
                else:
                    add_node(node.left, key, value)
            else:
                if node.right is None:
                    node.right = Node(key, value, None, None)
                else:
                    add_node(node.right, key, value)
            return True

        if self.root is None:
            self.root = Node(key, value, None, None)
            return True
        else:
            return add_node(self.root, key, value)


def postorder(node: Node):
    if node:
        postorder(node.left)
        postorder(node.right)
        print(node.key)

input = sys.stdin.readline
bst = BinarySearchTree()
while True:
    try:
        n = int(input())
        bst.add(n, n)
    except:
        break

postorder(bst.root)
