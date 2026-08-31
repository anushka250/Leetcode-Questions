class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return ans;
        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;

        while (curr->next != nullptr){
            ListNode* next = curr->next;
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                if(first == -1){
                    first = pos;
                }
                else{
                    minDist = min(minDist, pos - last);
                }
                last = pos;
            } 
            prev = curr;
            curr = next;
            pos++;
        }
        if(first == last)
            return {-1, -1};
        int maxDist = last - first;
        return {minDist, maxDist};
    }
};