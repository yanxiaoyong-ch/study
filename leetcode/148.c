struct ListNode * SortedListMerge(struct ListNode *list1,struct ListNode *list2)
{
	struct ListNode *head,*tmp;

	if(!list1)
		return list2;
	if(!list2)
		return list1;

	if(list1->val < list2->val)
	{
		tmp = list1;
		list1 = list1->next;
	}else {

		tmp = list2;
		list2 = list2->next;
	}
	head = tmp;
	while(list1&&list2)
	{
		if(list1->val < list2->val)
		{
			tmp->next = list1;
			list1 = list1->next;
			tmp = tmp->next;
		}else {

			tmp->next = list2;
			list2 = list2->next;
			tmp = tmp->next;
		}
	}

	if(list1)
		tmp->next =list1;
	else if(list2)
		tmp->next = list2;
	else
		tmp->next = NULL;
	return head;
}
struct ListNode *sortList(struct ListNode *head)
{
	struct ListNode *slow,*fast;
	struct ListNode *mid;
	struct ListNode *list1,*list2,*list;

    struct ListNode *curr;

	if(!head || !head->next)
		return head;

	slow = fast = head;

	while(fast&&fast->next&&fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	mid = slow->next;
	slow->next = NULL;
    
    curr = head;
	list1 = sortList(head);
	list2 = sortList(mid);
	list = SortedListMerge(list1,list2);

	return list;
}