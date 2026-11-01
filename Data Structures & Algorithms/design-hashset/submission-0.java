class MyHashSet {
    private Integer hashCode = 500;
    private List<List<Integer>> hashTable;

    public MyHashSet() {
        hashTable = new ArrayList<>(hashCode);

        for (int i = 0; i < hashCode; i++) {
            hashTable.add(new ArrayList<>());
        }
    }
    
    public void add(int key) {
        int bucketIdx = key % hashCode;
        List<Integer> bucket = hashTable.get(bucketIdx);

        for (Integer n : bucket) {
            if (n == key) {
                return;
            }
        }
        bucket.add(key);
    }
    
    public void remove(int key) {
        int bucketIdx = key % hashCode;

        hashTable.get(bucketIdx).removeIf(a -> a == key);
    }
    
    public boolean contains(int key) {
        int bucketIdx = key % hashCode;
        List<Integer> bucket = hashTable.get(bucketIdx);

        for (Integer n : bucket) {
            if (n == key) {
                return true;
            }
        }
        return false;
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */