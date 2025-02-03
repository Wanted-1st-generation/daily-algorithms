#include <iostream>

struct SinglyLinkedListNode
{
	int data;
	SinglyLinkedListNode* next;
};

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
	SinglyLinkedListNode* prev = nullptr;
	SinglyLinkedListNode* current = head;
	SinglyLinkedListNode* next = nullptr;
	while (current != nullptr)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

int main(void)
{
	int NumberOfTestcases = 0;
	int NumberOfNodes = 0;
	SinglyLinkedListNode* head = new SinglyLinkedListNode();
	SinglyLinkedListNode* temp = head;

	std::cin >> NumberOfTestcases;

	for (int i = 0; i < NumberOfTestcases; ++i)
	{
		std::cin >> NumberOfNodes;
		if (head != nullptr) {
			std::cin >> head->data;
			head->next = nullptr;
		}
		temp = head;

		for (int j = 0; j < NumberOfNodes - 1; ++j)
		{
			SinglyLinkedListNode* newNode = new SinglyLinkedListNode();
			std::cin >> newNode->data;
			newNode->next = nullptr;
			temp->next = newNode;
			temp = newNode;
		}

		head = reverse(head);

		temp = head;
		for (int j = 0; j < NumberOfNodes; ++j)
		{
			if (temp != nullptr)
			{
				std::cout << temp->data << " ";
				temp = temp->next;
			}
		}
		std::cout << std::endl;
	}

	return 0;
}
