class Solution {
    public int[] sortArrayByParity(int[] A) {
        int index = -1;
        for (int i = 0; i < A.length; ++i) {
            if ((A[i] & 1) == 0) {
                swap(A, ++index, i);
            }
        }
        return A;
    }

    private void swap(int[] A, int a, int b) {
        if (a != b) {
            int x = A[a];
            A[a] = A[b];
            A[b] = x;
        }
    }
}
