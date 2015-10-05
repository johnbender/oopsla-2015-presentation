...
# ifndef TL2_EAGER
#   ifdef TL2_OPTIM_HASHLOG
for (wr = logs; wr != end; wr++)
#   endif
{
  // write the deferred stores
  WriteBackForward(wr);
}
# endif

// make stores visible before unlock
MEMBARSTST();

// release locks and increment version
DropLocks(Self, wv);

// ensure loads are from global writes
MEMBARSTLD();

return 1;
...
