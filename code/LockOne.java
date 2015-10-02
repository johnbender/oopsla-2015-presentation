class LockOne implements Lock {
  private boolean[] flag = new boolean[2];
  // thread-local index, 0 or 1
  private static ThreadLocal<Integer> myIndex;
  public void lock() {
    int i = ThreadID.get();
    int j = i-1;
    flag[i] = true;
    while (flag[j]) {} // wait
  }
  public void unlock() {
    int i = ThreadID.get();
    flag[i] = false;
  }
}
