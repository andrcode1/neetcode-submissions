class Solution {

    record ReadyTask(int processingTime, int origIdx) {}

    public int[] getOrder(int[][] tasks) {
        Integer[] order = IntStream.range(0, tasks.length).boxed().toArray(Integer[]::new);
        Arrays.sort(order, (a, b) -> Integer.compare(tasks[a][0], tasks[b][0]));

        PriorityQueue<ReadyTask> ready = new PriorityQueue<>(
            Comparator.comparingInt(ReadyTask::processingTime)
                      .thenComparingInt(ReadyTask::origIdx)
        );

        int[] res = new int[tasks.length];
        int resIdx = 0;
        int globalTime = 0;
        int currIdx = 0;

        while (currIdx < tasks.length || !ready.isEmpty()) {
            while (currIdx < tasks.length && tasks[order[currIdx]][0] <= globalTime) {
                ReadyTask newTask = new ReadyTask(tasks[order[currIdx]][1], order[currIdx]);
                ready.add(newTask);
                currIdx++;
            }

            if (ready.isEmpty()) {
                globalTime = tasks[order[currIdx]][0];
                continue;
            }

            ReadyTask processedTask = ready.poll();
            globalTime += processedTask.processingTime();
            res[resIdx] = processedTask.origIdx();
            resIdx++;
        }

        return res;
    }
}