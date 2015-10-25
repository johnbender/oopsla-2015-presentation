class LockOne implements Lock {
  private boolean[] flag = new boolean[2];

  public void lock() {
    int i = ThreadID.get();
    int j = 1-i;
    flag[i] = true;
    while (flag[j]) {}
  }

  public void unlock() {
    int i = ThreadID.get();
    flag[i] = false;
  }
}
