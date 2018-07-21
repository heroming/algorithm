class Solution {
    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
        while (sx < tx || sy < ty) {
            if (tx < sx || ty < sy || tx == ty) return false;
            if (tx < ty) {
                int y = ty % tx;
                if (y < sy && tx <= ty - sy) {
                    ty = ty - (ty - sy) / tx * tx;
                } else {
                    ty = y;
                }
            } else {
                int x = tx % ty;
                if (x < sx && ty <= tx - sx) {
                    tx = tx - (tx - sx) / ty * ty;
                } else {
                    tx = x;
                }
            }
        }
        return sx == tx && sy == ty;
    }
}
