class MyHashMap {
    class Pair {
        public int k;
        public int v;

        public Pair(int k, int v) {
            this.k = k;
            this.v = v;
        }
    }

    private List<List<Pair>> buckets;
    private Integer hashKey = 500;

    public MyHashMap() {
        buckets = new ArrayList<>(hashKey);

        for (int i = 0; i < hashKey; i++) {
            buckets.add(new ArrayList<>());
        }
    }
    
    public void put(int key, int value) {
        Integer bucketIdx = Math.floorMod(key, hashKey);

        List<Pair> bucket = buckets.get(bucketIdx);
        for (Pair pair : bucket) {
            if (pair.k == key) {
                pair.v = value;
                return;
            }
        }
        bucket.add(new Pair(key, value));
    }
    
    public int get(int key) {
        Integer bucketIdx = Math.floorMod(key, hashKey);

        List<Pair> bucket = buckets.get(bucketIdx);
        for (Pair pair : bucket) {
            if (pair.k == key) {
                return pair.v;
            }
        }
        return -1;
    }
    
    public void remove(int key) {
        Integer bucketIdx = Math.floorMod(key, hashKey);

        List<Pair> bucket = buckets.get(bucketIdx);
        bucket.removeIf(pair -> pair.k == key);
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */