class RLEIterator {

        int pos;
        int index;
        int[] data;

        public RLEIterator(int[] A) {
            this.pos = 0;
            this.index = 0;
            this.data = A;
        }

        public int next(int n) {
            while (pos < data.length && index + n > data[pos]) {
                n -= data[pos] - index;
                pos += 2;
                index = 0;
            }
            if (pos >= data.length) {
                return -1;
            }
            index += n;
            return data[pos + 1];
        }
    }

