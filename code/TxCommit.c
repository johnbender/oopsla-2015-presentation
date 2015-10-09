...

# ifndef TL2_EAGER
for (wr = logs; wr != end; wr++) {
  // write the deferred stores
  WriteBackForward(wr);
}
# endif

// make stores visible before unlock
MEMBARSTST();

// release locks and increment version
DropLocks(Self, wv);

// ensure later loads from above writes
MEMBARSTLD();

...
