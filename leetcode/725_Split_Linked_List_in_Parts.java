class Solution {
    public ListNode[] splitListToParts(ListNode root, int k) {
        ListNode[] list = new ListNode[k];
        if (k == 1) {
            list[0] = root;
            return list;
        }

        int count = 0;
        ListNode it = root;
        while (it != null) {
            ++count;
            it = it.next;
        }
        if (count == 0) {
            return list;
        }

        int div = count / k;
        int mod = count % k;
        int index = 0, local = 0;

        ListNode head = root;
        it = root;
        for (int i = 0; i < count; ++i) {
            ++local;
            if ((local == div + 1 && index < mod) || (local == div && index >= mod)) {
                local = 0;
                list[index ++] = head;
                head = it.next;
                it.next = null;
                it = head;
            } else {
                it = it.next;
            }
        }
        return list;
    }
}
