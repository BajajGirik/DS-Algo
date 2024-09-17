class NumberContainers {
    private HashMap<Integer, Integer> numberList;
    private HashMap<Integer, SortedSet> numberToIndices;

    public NumberContainers() {
        numberList = new HashMap<>();
        numberToIndices = new HashMap<>();
    }
    
    private void addNumber(int index, int number) {
        numberList.put(index, number);
        SortedSet<Integer> earlierIndices = numberToIndices.get(number);
        
        if (earlierIndices == null) {
            earlierIndices = new TreeSet<Integer>();
        }
        
        earlierIndices.add(index);
        numberToIndices.put(number, earlierIndices);
    }
    
    public void change(int index, int number) {
        Integer earlierNumber = numberList.get(index);
        
        if (earlierNumber != null) {
            SortedSet<Integer> indices = numberToIndices.get(earlierNumber);
            indices.remove(index);
        }
        
        addNumber(index, number);
    }
    
    public int find(int number) {
        SortedSet<Integer> indices = numberToIndices.get(number);
        
        return (indices == null || indices.isEmpty()) ? -1 : indices.first();
    }
}
