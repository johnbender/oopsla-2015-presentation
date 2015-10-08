void lock() {
  int i = get_thread_id();
  int j = i-1;
  flag[i] = true;
  while (flag[j]) {}
}
