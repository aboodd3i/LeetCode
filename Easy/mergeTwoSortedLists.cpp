#include "iostream"
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
This code has very high time complwxity
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list_1, ListNode *list_2)
    {
        ListNode dummyNode(0); // the dummy node acts as the head of the resulting final list
        ListNode *tail = &dummyNode;
        while (list_1 != nullptr && list_2 != nullptr)
        {
            if (list_1->val <= list_2->val)
            {
                tail->next = list_1;
                list_1 = list_1->next;
            }
            else
            {
                tail->next = list_2;
                list_2 = list_2->next;
            }
            tail = tail->next;
        }

        if (list_1 != nullptr)
        {
            tail->next = list_1;
        }
        else
        {
            tail->next = list_2;
        }

        return dummyNode.next;
    }
};
*/

class Solution
{
    // recursive apporach
public:
    ListNode *mergeTwoLists(ListNode *L1, ListNode *L2)
    {
        if (!L1)
            return L2;
        if (!L2)
            return L1;

        if (L1->val <= L2->val)
        {
            L1->next = mergeTwoLists(L1->next, L2);
            return L1;
        }
        else
        {
            L2->next = mergeTwoLists(L1, L2->next);
            return L2;
        }
    }
};

int main()
{
    Solution sol;
    ListNode *L1 = new ListNode(1);
    L1->next = new ListNode(3);
    L1->next->next = new ListNode(4);

    ListNode *L2 = new ListNode(1);
    L2->next = new ListNode(5);
    L2->next->next = new ListNode(7);

    ListNode *answer = sol.mergeTwoLists(L1, L2);

    ListNode *curr = answer;

    while (curr != nullptr)
    {
        cout << curr->val << " --> ";
        curr = curr->next;
    }
    cout << endl;

    while (answer != nullptr)
    {
        ListNode *temp = answer;
        answer = answer->next;
        delete temp;
    }

    return 0;
}
