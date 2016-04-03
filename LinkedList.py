#!/usr/bin/python3

# Linked list implementation in python (python 3)

class Node:
	def __init__ (self, data):
		self.data = data
		self.next= None


class LinkedList:
	def __init__ (self):
		self.head = None

	def count (self):
		tmp = self.head
		ctr = 0
		while (tmp != None):
			tmp = tmp.next
			ctr=ctr+1
		return ctr
	
	def display (self):
		tmp = self.head
		while (tmp != None):
			print(tmp.data);
			tmp = tmp.next
		return None

	def insertAtBeg (self, data):
		new_node = Node(data)
		new_node.next = self.head
		self.head = new_node
	
	def delAtBeg (self):
		if (self.head is None):
			print ("List is already empty!");
			return None
		val = self.head.data
		self.head = self.head.next
	
	def insertAtEnd (self,data):
		if (self.head is None):
			new_node = Node(data)
			new_node.next = None
			self.head = new_node
		tmp = self.head
		while (tmp.next is not None):
			tmp = tmp.next
		tmp.next = Node(data)
	
	def delAtEnd (self):
		if (self.head is None):
			print ("List is empty!")
			return None
		if (self.head.next is None):
			del self.head
			self.head = None
			return None
		tmp = self.head
		while (tmp.next.next != None):
			tmp = tmp.next
		var = tmp.next.data
		del tmp.next
		tmp.next = None


l = LinkedList()
l.insertAtBeg(10)
l.insertAtEnd(100)
l.insertAtBeg(1000)
l.delAtBeg()
l.delAtEnd()
print(l.count())
l.display()
